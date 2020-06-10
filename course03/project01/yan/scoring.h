#include "go_basic.h"
#include<map>

class Scoring
{
public:
	Scoring(const GoBasic& gameState);

	std::shared_ptr<Component> findComponentFromGameState(const Position& element);
	std::set<std::shared_ptr<Component>> calculateBlankComponents();

	std::pair<float, float> calculateScore(bool ignoreUndefined=false);

	void changeRegionSide(const Position& position);

	const std::set<std::shared_ptr<Component>>& getBlackRegions() const { return mBlackRegions; }
	const std::set<std::shared_ptr<Component>>& getWhiteRegions() const { return mWhiteRegions; }
	const std::set<std::shared_ptr<Component>>& getUndefinedRegions() const { return mUndefinedRegions; }

private:
	const GoBasic& mGameState;
	std::set<std::shared_ptr<Component>> mBlankComponents;

	std::map<Position, std::shared_ptr<Component>> mPositionToComponentMap;
	std::map<std::shared_ptr<Component>, GoBasic::SIDE> mBlankComponentToSideMap;

	std::set<std::shared_ptr<Component>> mBlackRegions;
	std::set<std::shared_ptr<Component>> mWhiteRegions;
	std::set<std::shared_ptr<Component>> mUndefinedRegions;

	std::map<Position, std::shared_ptr<Component>> mPositionToRegionMap;

	void calculateMaps();
	void calculateRegions();
};
