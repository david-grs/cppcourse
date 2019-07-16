#include "scoring.h"
#include <cassert>
#include <iostream>

Scoring::Scoring(const GoBasic& gameState) :
	mGameState{gameState}, mBlankComponents{calculateBlankComponents()}
{
	calculateMaps();
	calculateRegions();
}

std::shared_ptr<Component> Scoring::findComponentFromGameState(const Position& element)
{
	GoBasic::SIDE side = mGameState.getCell(element);
	std::shared_ptr<Component> component = std::make_shared<Component>(element);

	bool repeat = true;
	while (repeat)
	{
		repeat = false;
		for (const Position& cell : component->getBoundary())
		{
			if (mGameState.getCell(cell) == side)
			{
				component->add(cell);
				repeat = true;
			}
		}
	}

	return component;
}

std::set<std::shared_ptr<Component>> Scoring::calculateBlankComponents()
{
	std::set<std::shared_ptr<Component>> blankComponents{};

	for (int i=0; i < BOARD_SIZE; ++i)
	{
		for (int j=0; j < BOARD_SIZE; ++j)
		{
			Position pos(i, j);
			if (mGameState.getCell(pos) == GoBasic::SIDE::NONE)
			{
				bool doCalculation = true;
				for (std::shared_ptr<Component> component : blankComponents)
				{
					if (component->contains(pos))
					{
						doCalculation = false;
						break;
					}
				}
				if (doCalculation)
				{
					blankComponents.insert(findComponentFromGameState(pos));
				}
			}
		}
	}

	return blankComponents;
}

void Scoring::calculateMaps()
{
	mPositionToComponentMap.clear();
	mBlankComponentToSideMap.clear();
	for (std::shared_ptr<Component> component : mGameState.getBlackComponents())
	{
		for (const Position& pos : component->getElements())
			mPositionToComponentMap[pos] = component;
	}
	for (std::shared_ptr<Component> component : mGameState.getWhiteComponents())
	{
		for (const Position& pos : component->getElements())
			mPositionToComponentMap[pos] = component;
	}
	for (std::shared_ptr<Component> component : mBlankComponents)
	{
		for (const Position& pos : component->getElements())
			mPositionToComponentMap[pos] = component;
		std::set<GoBasic::SIDE> sides{};
		for (const Position& pos : component->getBoundary())
			sides.insert(mGameState.getCell(pos));
		if (sides.size() == 1)
			mBlankComponentToSideMap[component] = *sides.begin();
		else
			mBlankComponentToSideMap[component] = GoBasic::SIDE::NONE;
	}
}

void Scoring::calculateRegions()
{
	mBlackRegions.clear();
	mWhiteRegions.clear();
	mUndefinedRegions.clear();

	for (std::shared_ptr<Component> component : mBlankComponents)
	{
		GoBasic::SIDE side = mBlankComponentToSideMap[component];
		std::shared_ptr<Component> region = std::make_shared<Component>(*component);

		if (side == GoBasic::SIDE::NONE)
		{
			mUndefinedRegions.insert(region);
			continue;
		}
		
		bool repeat = true;
		while (repeat)
		{
			repeat = false;
			std::set<Position> boundary = region->getBoundary();
			for (const Position& pos : boundary)
			{
				if (mGameState.getCell(pos) == side)
				{
					region->merge(*mPositionToComponentMap[pos]);
					repeat = true;
				}
				else if (mGameState.getCell(pos) == GoBasic::SIDE::NONE)
				{
					std::shared_ptr<Component> boundaryComponent = mPositionToComponentMap[pos];
					if (mBlankComponentToSideMap[boundaryComponent] == side)
					{
						region->merge(*boundaryComponent);
						repeat = true;
					}
				}
			}
			
		}

		if (side == GoBasic::SIDE::BLACK)
			mBlackRegions.insert(region);
		else
			mWhiteRegions.insert(region);
	}

	int count = 0;
	mPositionToRegionMap.clear();

	for (std::shared_ptr<Component> region : mBlackRegions)
	{
		const std::set<Position>& elements = region->getElements();
		count += elements.size();
		for (const Position & element : elements)
		{
			mPositionToRegionMap[element] = region;
		}
	}

	for (std::shared_ptr<Component> region : mWhiteRegions)
	{
		const std::set<Position>& elements = region->getElements();
		count += elements.size();
		for (const Position & element : elements)
		{
			mPositionToRegionMap[element] = region;
		}
	}

	for (std::shared_ptr<Component> region : mUndefinedRegions)
	{
		const std::set<Position>& elements = region->getElements();
		count += elements.size();
		for (const Position & element : elements)
		{
			mPositionToRegionMap[element] = region;
		}
	}

	for (std::shared_ptr<Component> component : mGameState.getBlackComponents())
	{
		const Position& element = *component->getElements().begin();
		if (mPositionToRegionMap.find(element) == mPositionToRegionMap.end())
			mBlackRegions.insert(component);
	}

	for (std::shared_ptr<Component> component : mGameState.getWhiteComponents())
	{
		const Position& element = *component->getElements().begin();
		if (mPositionToRegionMap.find(element) == mPositionToRegionMap.end())
			mWhiteRegions.insert(component);
	}

	if (count != BOARD_SIZE * BOARD_SIZE)
		assert("Regions do not add up to board size!");
}

int getDistance(const Position& pos1, const Position& pos2)
{
	return std::abs(pos1.x - pos2.x) + std::abs(pos1.y - pos2.y);
}

std::pair<float, float> Scoring::calculateScore(bool ignoreUndefined)
{
	float blackScore = 0;
	float whiteScore = 0;
	for (std::shared_ptr<Component> region : mBlackRegions)
		blackScore += region->getElements().size();
	for (std::shared_ptr<Component> region : mWhiteRegions)
		whiteScore += region->getElements().size();

	if (!ignoreUndefined)
	{
		for (std::shared_ptr<Component> region : mUndefinedRegions)
		{
			const std::set<Position>& boundary = region->getBoundary();
			for (const Position& pos : region->getElements())
			{
				int minD = 2 * BOARD_SIZE;
				GoBasic::SIDE minDSide = GoBasic::SIDE::NONE;

				for (const Position& pos2 : boundary)
				{
					GoBasic::SIDE pos2Side = mGameState.getCell(pos2);
					int d = getDistance(pos, pos2);

					if (d < minD)
					{
						minD = d;
						minDSide = pos2Side;
					}
					else if (d == minD)
					{
						if (minDSide == GoBasic::SIDE::NONE)
							minDSide = pos2Side;
						else if (minDSide != pos2Side)
							minDSide = GoBasic::SIDE::NONE;
					}
				}

				if (minDSide == GoBasic::SIDE::BLACK)
				{
					blackScore += 1.0f;
				}
				else if (minDSide == GoBasic::SIDE::WHITE)
				{
					whiteScore += 1.0f;
				}
				else
				{
					blackScore += 0.5f;
					whiteScore += 0.5f;
				}
			}
		}
	}
	return {blackScore, whiteScore};
}

void Scoring::changeRegionSide(const Position& position)
{
	for (std::shared_ptr<Component> region : mBlackRegions)
	{
		if (region->contains(position))
		{
			mWhiteRegions.insert(region);
			mBlackRegions.erase(region);
			return;
		}
	}
	for (std::shared_ptr<Component> region : mWhiteRegions)
	{
		if (region->contains(position))
		{
			mUndefinedRegions.insert(region);
			mWhiteRegions.erase(region);
			return;
		}
	}
	for (std::shared_ptr<Component> region : mUndefinedRegions)
	{
		if (region->contains(position))
		{
			mBlackRegions.insert(region);
			mUndefinedRegions.erase(region);
			return;
		}
	}
}
