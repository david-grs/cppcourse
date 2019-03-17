#pragma once

#include "types.h"
#include "config.h"


class Pacman : public IGameObject
{
public:
	Pacman(Point center, Point mapPosition, const Config& config)
		:
		mCenter(center),
		mMapPosition(mapPosition),
		mConfig(config),
		mStepSize(mConfig.PACMAN_STEP_IN_PX),
		mRadius(mConfig.PACMAN_RADIUS)
	{		
	}

	// IGameObject
	const Direction GetDirection() const override { return mDirection; }
	void SetDirection(Direction direction) override { mDirection = direction; }
	const Point& GetCenter() const override { return mCenter; }
	void SetCenter(const Point& center) override { mCenter = center; }
	const Point& GetGridPosition() const override { return mMapPosition; }
	void SetGridPosition(const Point& position) override { mMapPosition = position; }
	void MakeStep() override;
	void Draw() override;
	
	void UpdateMouth(const double delta);
	void SetRadius(float radius) { mRadius = radius; }

private:
	std::vector<ci::vec2> GetSkeleton();
	std::vector<ci::vec2> GetBorder(std::vector<ci::vec2>& skeleton);
	void AlignDirectionAngle(float& angle);
	
	enum MouthState
	{
		CLOSING,
		OPENING
	};

private:
	Point mCenter;
	Point mMapPosition;
	const Config& mConfig;
	Direction mDirection{ Direction::LEFT };
	MouthState mMouthState{ MouthState::CLOSING };
	float mOpenMouth{ 1.0f };
	int mStepSize;
	float mRadius;
};
typedef std::unique_ptr<Pacman> PacmanPtr;
