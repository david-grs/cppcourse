#include "application.h"
#include <cinder/Font.h>
#include <tuple>
#include <sstream>

const int PIXELS_PER_SQUARE = 40;
const int FIGURE_WIDTH = BOARD_SIZE * PIXELS_PER_SQUARE;
const int HALF_SQUARE = PIXELS_PER_SQUARE / 2;
const int TEXT_SIZE = 20;
const int FIGURE_HEIGHT = FIGURE_WIDTH + 3 * TEXT_SIZE;
const int CENTER = (BOARD_SIZE - 1) / 2;

const ci::Font STANDARD_FONT("Arial", 20);
const ci::Font INSTRUCTION_FONT("Arial", 16);

static const cinder::ivec2 WindowSize{FIGURE_WIDTH, FIGURE_HEIGHT};

Application::Application() :
	mPosition{Position(CENTER, CENTER)},
	mCurrentGame{GoBasic()},
	mState{GoBasic::STATE::SUCCESS},
	mScoringMode{false},
	mBlackScore{0},
	mWhiteScore{0}
{}

void Application::prepareSettings(Settings* settings)
{
	settings->setWindowSize(WindowSize);
	settings->setFrameRate(10.0f);
	settings->setResizable(false);
	settings->setFullScreen(false);
}

void Application::keyDown(ci::app::KeyEvent event)
{
	char input = event.getChar();
	if (!mScoringMode)
	{
		if (input == 'p' || input == 'P')
		{
			mCurrentGame.pass();
		}
		if (input == 'u' || input == 'U')
		{
			mCurrentGame.undo();
		}
		if (input == 's' || input == 'S')
		{
			mScoringMode = true;
			mScoringPtr = std::make_unique<Scoring>(mCurrentGame);
			std::tie(mBlackScore, mWhiteScore) = mScoringPtr->calculateScore();
		}
	}
	else
	{
		if (input == 'x' || input == 'X')
		{
			mScoringMode = false;
			auto d = mScoringPtr.release();
			delete d;
		}
	}
}

void Application::mouseDown(ci::app::MouseEvent event)
{
	if (event.isLeft())
	{
		ci::ivec2 rawPosition = event.getPos();
		if (rawPosition.y < FIGURE_WIDTH)
		{
			mPosition = Position(int(rawPosition.x / PIXELS_PER_SQUARE), int(rawPosition.y / PIXELS_PER_SQUARE));
			if (!mScoringMode)
				mState = mCurrentGame.makeMove(mPosition);
			else
			{
				mScoringPtr->changeRegionSide(mPosition);
				std::tie(mBlackScore, mWhiteScore) = mScoringPtr->calculateScore();
			}
		}
	}
}

int getCoordinate(int pos)
{
	return HALF_SQUARE + pos * PIXELS_PER_SQUARE;
}

ci::ivec2 Application::getCoordinates(int x, int y)
{
	return {getCoordinate(x), getCoordinate(y)};
}

ci::ivec2 Application::getCoordinates(const Position& pos)
{
	return {getCoordinate(pos.x), getCoordinate(pos.y)};
}

void Application::renderBoard()
{
	ci::gl::color(0.5f, 0.3f, 0.3f);
	ci::gl::drawSolidRect(ci::Rectf(0, 0, FIGURE_WIDTH, FIGURE_HEIGHT));

	ci::gl::color(1.0f, 0.5f, 0.5f);
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		ci::gl::drawLine(getCoordinates(0, i), getCoordinates(BOARD_SIZE - 1, i));
		ci::gl::drawLine(getCoordinates(i, 0), getCoordinates(i, BOARD_SIZE - 1));
	}
	std::vector<int> keypoints{{3, 9, 15}};
	for (int i: keypoints)
	{
		for (int j: keypoints)
		{
			ci::gl::drawSolidCircle(getCoordinates(i, j), (float)PIXELS_PER_SQUARE / 10);
		}
	}
}

void Application::renderMoves()
{
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		for (int j = 0; j < BOARD_SIZE; ++j)
		{
			GoBasic::SIDE side = mCurrentGame.getCell(i, j);
			if (side == GoBasic::SIDE::NONE)
				continue;

			if (side == GoBasic::SIDE::BLACK)
				ci::gl::color(0.0f, 0.0f, 0.0f);
			else
				ci::gl::color(1.0f, 1.0f, 1.0f);

			ci::gl::drawSolidCircle(getCoordinates(i, j), (float)PIXELS_PER_SQUARE / 2.5);
		}
	}

	if (mScoringMode)
	{
		ci::gl::color(0.0f, 0.0f, 0.0f);
		for (std::shared_ptr<Component> component : mScoringPtr->getBlackRegions())
		{
			for (const Position& pos : component->getElements())
				ci::gl::drawSolidCircle(getCoordinates(pos), (float)PIXELS_PER_SQUARE / 5);
		}

		ci::gl::color(1.0f, 1.0f, 1.0f);
		for (std::shared_ptr<Component> component : mScoringPtr->getWhiteRegions())
		{
			for (const Position& pos : component->getElements())
				ci::gl::drawSolidCircle(getCoordinates(pos), (float)PIXELS_PER_SQUARE / 5);
		}
	}
}

void Application::renderCurrentPosition()
{
	ci::gl::color(1.0f, 0.8f, 0.8f);
	ci::ivec2 currentPosition = getCoordinates(mPosition);
	ci::gl::drawStrokedRect(ci::Rectf(currentPosition[0] - HALF_SQUARE, currentPosition[1] - HALF_SQUARE,
			currentPosition[0] + HALF_SQUARE, currentPosition[1] + HALF_SQUARE), 1.0);
}

void Application::renderText()
{
	ci::gl::drawSolidRect(ci::Rectf(FIGURE_WIDTH, 0, FIGURE_WIDTH + TEXT_SIZE * 3, FIGURE_WIDTH));

	ci::ivec2 leftTopPosition{FIGURE_WIDTH / 4, FIGURE_WIDTH};
	ci::ivec2 leftBottomPosition{FIGURE_WIDTH / 4, FIGURE_WIDTH + TEXT_SIZE};
	ci::ivec2 rightTopPosition{FIGURE_WIDTH * 3 / 4, FIGURE_WIDTH};
	ci::ivec2 rightBottomPosition{FIGURE_WIDTH * 3 / 4, FIGURE_WIDTH + TEXT_SIZE};

	std::string strLeftTop, strLeftBottom, strRightTop, strRightBottom;
	ci::ColorA leftTopColor, leftBottomColor;
	if (!mScoringMode)
	{
		GoBasic::SIDE side = mCurrentGame.getCurrentPlayer();

		if (side == GoBasic::SIDE::BLACK)
		{
			leftTopColor = ci::Color::black();
			strLeftTop = "Black's turn.";
		}
		else
		{
			leftTopColor = ci::Color::white();
			strLeftTop = "White's turn.";
		}

		leftBottomColor = ci::Colorf(1.0f, 0.0f, 0.0f);
		if (mState == GoBasic::STATE::ILLEGAL)
			strLeftBottom = "Illegal move";
		else
			strLeftBottom = "";

		strRightTop = "Click on board to play.";
		strRightBottom = "p = pass; u = undo; s = calculate score";
	}
	else
	{
		leftTopColor = ci::Color::black();
		leftBottomColor = ci::Color::white();

		std::ostringstream ossB, ossW;
		ossB << "Black: " << mBlackScore;
		ossW << "White: " << mWhiteScore;
		strLeftTop = ossB.str();
		strLeftBottom = ossW.str();

		strRightTop = "Click to change region assignment.";
		strRightBottom = "x = return to game";
	}

	ci::gl::drawStringCentered(strLeftTop, leftTopPosition, leftTopColor, STANDARD_FONT);
	ci::gl::drawStringCentered(strLeftBottom, leftBottomPosition, leftBottomColor, STANDARD_FONT);
	ci::gl::drawStringCentered(strRightTop, rightTopPosition, ci::Color::black(), INSTRUCTION_FONT);
	ci::gl::drawStringCentered(strRightBottom, rightBottomPosition, ci::Color::black(), INSTRUCTION_FONT);
}


void Application::setup()
{
	draw();
}

void Application::draw()
{
	ci::gl::clear();
	renderBoard();
	renderMoves();
	renderCurrentPosition();
	renderText();
}

CINDER_APP(Application, ci::app::RendererGl(ci::app::RendererGl::Options().msaa(16)), &Application::prepareSettings)

