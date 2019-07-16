#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>
#include <cinder/gl/gl.h>
#include "go_basic.h"
#include "scoring.h"

class Application : public ci::app::App
{
public:
	Application();

	void keyDown(ci::app::KeyEvent) override;
	void mouseDown(ci::app::MouseEvent) override;
	void setup() override;
	void draw() override;

	static void prepareSettings(Settings*);

private:
	Position mPosition;
	GoBasic mCurrentGame;
	GoBasic::STATE mState;
	bool mScoringMode;
	std::unique_ptr<Scoring> mScoringPtr;
	float mBlackScore;
	float mWhiteScore;

	ci::ivec2 getCoordinates(int x, int y);
	ci::ivec2 getCoordinates(const Position& pos);

	void renderBoard();
	void renderMoves();
	void renderCurrentPosition();
	void renderText();
	void renderPassButton();
};
