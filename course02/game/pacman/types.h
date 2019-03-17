#pragma once

#include <cinder/gl/gl.h>
#include <cinder/Rect.h>
#include <iostream>
#include <chrono>

enum GameState
{
	NOT_STARTED,
	ACTIVE,
	PAUSED,
	OVER
};

inline const char* GameStateToStr(GameState state) // for debugging
{
	switch (state)
	{
	case NOT_STARTED:   return "NOT_STARTED";
	case ACTIVE:   return "ACTIVE";
	case PAUSED:  return "PAUSED";
	case OVER:     return "OVER";
	default:     return "UNKNOWN";
	}
}

enum Direction
{
	LEFT,
	DOWN,
	RIGHT,
	UP,
	NONE
};

inline const char* DirectionToString(Direction dir) // for debugging
{
	switch (dir)
	{
	case LEFT:   return "LEFT";
	case DOWN:   return "DOWN";
	case RIGHT:  return "RIGHT";
	case UP:     return "UP";
	default:     return "NONE";
	}
}

struct Point
{	
	Point(int row, int column)
		:
		mRow(row),
		mColumn(column)
	{
	}
	int mRow;
	int mColumn;

	bool operator!=(Point pt)
	{
		return pt.mColumn != mColumn || pt.mRow != mRow;
	}

	bool operator!=(const Point pt) const
	{
		return pt.mColumn != mColumn || pt.mRow != mRow;
	}
};

inline std::ostream& operator<<(std::ostream& output, const Point& point) // for debugging
{
	output << "row=" << point.mRow << ", column=" << point.mColumn;
	return output;
}

class IController
{
public:
	virtual ~IController() {}

	virtual void Setup() = 0;
	virtual void Update(double elapsedTime) = 0;
	virtual void Draw() = 0;
	virtual void KeyDown(Direction direction) = 0;
	virtual void UpdateGameState(GameState gameState) = 0;
};
class GameField
{
public:
	virtual ~GameField() {}

	virtual bool IsVisitable() const = 0;
	virtual void SetIsVisitable(bool visitable) = 0;
	virtual void UnsetPoints() = 0;
	virtual const int GetPoints() const = 0;

	virtual const Point& GetCenter() const = 0;
	virtual const Point& GetGridPosition() const = 0;
	virtual void SetCenter(const Point& center) = 0;
	virtual void SetGridPosition(const Point& position) = 0;

	virtual void Draw() = 0;
};

class IGameObject
{
public:
	virtual ~IGameObject() {}

	virtual const Direction GetDirection() const = 0;
	virtual void SetDirection(Direction direction) = 0;
	virtual const Point& GetCenter() const = 0;
	virtual void SetCenter(const Point& center) = 0;
	virtual const Point& GetGridPosition() const = 0;
	virtual void SetGridPosition(const Point& position) = 0;
	virtual void MakeStep() = 0;
	virtual void Draw() = 0;
};

typedef std::unique_ptr<GameField> FieldPtr;
typedef std::unique_ptr<IController> ControllerPtr;
typedef std::vector<std::vector<FieldPtr>> Grid;
typedef std::shared_ptr<Grid> GridPtr;
typedef std::vector<ControllerPtr> Controllers;

struct Boundaries
{
	Point mGrid{ 0,0 };
	Point mMapPixelsMax{ 0, 0 };
	Point mMapPixelsMin{ 0, 0 };
};

struct GameMap
{
	GridPtr mGrid;
	Boundaries mBoundaries;
};

typedef std::chrono::duration<double> DurationSeconds;
typedef std::chrono::milliseconds Milliseconds;