#pragma once

#include "types.h"
#include "config.h"

class Wall : public GameField
{
public:
	Wall(Point center, Point gridPosition, const Config& config)
		:
		mCenter(center),
		mGridPosition(gridPosition),
		mConfig(config),
		mFieldSize(config.FIELD_SIZE)
	{
	}
	
	// GameField
	bool IsVisitable() const override{ return false; }
	void SetIsVisitable(bool visitable) override {}
	const Point& GetCenter() const override { return mCenter; }
	const Point& GetGridPosition() const override { return mGridPosition; }
	void SetCenter(const Point& center) override {};
	void SetGridPosition(const Point& position) override {};
	void UnsetPoints() override {}
	const int GetPoints() const override { return 0;  }
	void Draw() override;

private:
	Point mCenter;
	Point mGridPosition;
	const Config& mConfig;
	const int mFieldSize;
};
