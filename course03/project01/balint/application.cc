#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;

// We'll create a new Cinder Application by deriving from the App class.
class BasicApp : public App
{
 public:
  // Cinder will call 'mouseDrag' when the user moves the mouse while holding one of its buttons.
  // See also: mouseMove, mouseDown, mouseUp and mouseWheel.
  void mouseDrag(MouseEvent event) override;

  // Cinder will call 'keyDown' when the user presses a key on the keyboard.
  // See also: keyUp.
  void keyDown(KeyEvent event) override;

  // Cinder will call 'draw' each time the contents of the window need to be redrawn.
  void draw() override;
  void update() override;
  void setup() override;

 private:
  // This will maintain a list of points which we will draw line segments between
  std::vector<vec2> mPoints;
  float mBarrierWidth = 5;
  float mLeftBatPos;
  float mRightBatPos;
  vec2 mBallPos;
  vec2 mBallVel;
  float batLength = 200;
  float mBallRadius = 13;
  float height = 600;
  float width = 800;

  void drawSurroundings();
  void drawBall();
  void drawLeftBat();
  void drawRightBat();
  void moveBall();

  bool ballCollidesDown_p() { return (mBallPos + mBallVel).x >= (getWindowHeight() - mBarrierWidth - mBallRadius) ? true : false; }
  bool ballCollidesUp_p() { return (mBallPos + mBallVel).x <= ( mBarrierWidth + mBallRadius ) ? true : false; }
  bool ballCollidesLeft_p() { return (mBallPos + mBallVel).y <= ( mBarrierWidth   + mBallRadius) ? true : false; }
  bool ballCollidesRight_p() { return (mBallPos + mBallVel).y >= (getWindowWidth() - mBarrierWidth - mBallRadius) ? true : false; }
};

void prepareSettings(BasicApp::Settings* settings) {
  settings->setMultiTouchEnabled(false);
}

void BasicApp::update()
{
  static const double timestep = 1.0 / 60.0;

  // Keep track of time.
  static double time = getElapsedSeconds();
  static double accumulator = 0.0;

  // Calculate elapsed time since last frame.
  double elapsed = getElapsedSeconds() - time;
  time += elapsed;
  accumulator += math<double>::min(elapsed, 0.1);  // prevents 'spiral of death'
  while (accumulator >= timestep)
    {
      accumulator -= timestep;
      moveBall();
    }
}
void BasicApp::moveBall()
{
  if (ballCollidesDown_p())
    {
      mBallVel.x *= -1;
    }
  else if (ballCollidesUp_p())
    {
      mBallVel.x *= -1;
    }
  else if (ballCollidesLeft_p())
    {
      mBallVel.y *= -1;
    }
  else if (ballCollidesRight_p())
    {
      mBallVel.y *= -1;
    }
  mBallPos += mBallVel;
}

void BasicApp::setup(){
  
  float halfHeight = getWindowHeight()/2;
  float halfWidth = getWindowWidth()/2;
  mLeftBatPos = halfHeight;
  mRightBatPos = halfHeight;
  mBallPos = vec2(halfWidth, halfHeight);
  mBallVel = vec2(1,1);
}
void BasicApp::mouseDrag(MouseEvent event)
{
  // Store the current mouse position in the list.
  mPoints.push_back(event.getPos());
}

void BasicApp::keyDown(KeyEvent event)
{
  if (event.getChar() == 'f')
    {  // Toggle full screen when the user presses the 'f' key.
      setFullScreen(!isFullScreen());
    }
  else if (event.getCode() == KeyEvent::KEY_SPACE)
    {
      // Clear the list of points when the user presses the space bar.
      mPoints.clear();
    }
  else if (event.getCode() == KeyEvent::KEY_ESCAPE)
    {
      // Exit full screen, or quit the application, when the user presses the ESC key.
      if (isFullScreen())
	setFullScreen(false);
      else
	quit();
    }
}
void BasicApp::drawSurroundings()
{
  gl::color(Color::white());
  gl::drawSolidRect(Rectf(0, 0, mBarrierWidth, getWindowHeight()));
  gl::drawSolidRect(Rectf(0, 0, getWindowWidth(), mBarrierWidth));
  gl::drawSolidRect(Rectf(0, getWindowHeight() - mBarrierWidth, getWindowWidth(), getWindowHeight()));
  gl::drawSolidRect(Rectf(getWindowWidth() - mBarrierWidth, 0, getWindowWidth(), getWindowHeight()));
}
void BasicApp::drawBall()
{
  gl::color(Color::white());
  gl::drawSolidCircle(mBallPos, mBallRadius);
}

void BasicApp::drawLeftBat()
{
  float xposmin = mLeftBatPos - 0.5 * batLength;
  float xposmax = mLeftBatPos + 0.5 * batLength;
  gl::drawSolidRect(Rectf(mBarrierWidth, xposmin, 2*mBarrierWidth, xposmax));
};

void BasicApp::drawRightBat()
{
  float xposmin = mRightBatPos - 0.5 * batLength;
  float xposmax = mRightBatPos + 0.5 * batLength;
  float width = getWindowWidth();
  gl::drawSolidRect(Rectf(width - 2*mBarrierWidth, xposmin, width - mBarrierWidth, xposmax));
};

void BasicApp::draw()
{
  // Clear the contents of the window. This call will clear
  // both the color and depth buffers.
  gl::clear(Color::gray(0.1f));

  int height = getWindowHeight();
  int width = getWindowWidth();
  // gl::drawSolidCircle( vec2( 15.0f, 25.0f ), 50.0f );
  float x = cos(getElapsedSeconds() * 1 / 7) * 200 + getWindowWidth() / 2;
  float y = sin(getElapsedSeconds() * 2) * 200 + getWindowHeight() / 2;

  drawSurroundings();
  // mBallPos = vec2(x, y);
  drawBall();
  drawLeftBat();
  drawRightBat();

  // Set the current draw color to orange by setting values for
  // red, green and blue directly. Values range from 0 to 1.
  // See also: gl::ScopedColor
  gl::color(1.0f, 0.5f, 0.25f);

  // We're going to draw a line through all the points in the list
  // using a few convenience functions: 'begin' will tell OpenGL to
  // start constructing a line strip, 'vertex' will add a point to the
  // line strip and 'end' will execute the draw calls on the GPU.
  gl::begin(GL_LINE_STRIP);
  for (const vec2& point : mPoints)
    {
      gl::vertex(point);
    }
  gl::end();
}

// This line tells Cinder to actually create and run the application.
CINDER_APP(BasicApp, RendererGl, prepareSettings)
