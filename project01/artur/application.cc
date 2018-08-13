#include "application.h"
#include <cinder/gl/gl.h>
#include <random>

static const cinder::ivec2 WindowSize{640, 480};

Application::Application()
{}

void Application::prepareSettings(Settings* settings)
{
  settings->setWindowSize(WindowSize);
  settings->setFrameRate(35.0f);
  settings->setResizable(false);
  settings->setFullScreen(false);
}

void Application::keyDown(ci::app::KeyEvent event)
{
  switch(event.getCode())
    {
    case ci::app::KeyEvent::KEY_DOWN:
      snake.ChangeDirection(Point(Direction::down));
      counter = 0;
      break;
    case ci::app::KeyEvent::KEY_UP:
      snake.ChangeDirection(Point(Direction::up));
      counter = 0;
      break;
    case ci::app::KeyEvent::KEY_LEFT:
      snake.ChangeDirection(Point(Direction::left));
      counter = 0;
      break;
    case ci::app::KeyEvent::KEY_RIGHT:
      snake.ChangeDirection(Point(Direction::right));
      counter = 0;
      break;
    default:
      break;
    }
}

void Application::setup()
{
  running = true;
  counter = 0;
  snake = Snake();
  fruit = Point(10,10);
  corner = Point(16,16);
}

void Application::draw()
{
  ci::gl::clear();
  ci::gl::color( ci::Color( 1, 1, 1 ) );
  ci::gl::drawSolidRect( ci::Rectf(0, 0, 10*corner.GetX(), 5 ));
  ci::gl::drawSolidRect( ci::Rectf(0, 10*corner.GetY()-5, 10*corner.GetX(), 10*corner.GetY() ));
  ci::gl::drawSolidRect( ci::Rectf(0, 0, 5, 10*corner.GetY() ));
  ci::gl::drawSolidRect( ci::Rectf(10*corner.GetX()-5, 0, 10*corner.GetX(), 10*corner.GetY() ));

  for(int i = 0; i < snake.Length()-1; ++i)
    {
      Point p = snake.Body().at(i);
      ci::gl::drawSolidCircle( ci::vec2(10*p.GetX(), 10*p.GetY()), 5);
    }
  ci::gl::color( ci::Color( 1, 0, 0 ) );
  ci::gl::drawSolidCircle( ci::vec2(10*snake.Body().back().GetX(), 10*snake.Body().back().GetY()), 5);
  ci::gl::color( ci::Color( 0, 1, 0 ) );
  ci::gl::drawSolidCircle( ci::vec2(10*fruit.GetX(), 10*fruit.GetY()), 5);

}

void Application::update()
{
  if(!running)
    {
      return;
    }
  if(!snake.IsAlive())
    {
      running = false;

      std::cout<<"You died!"<<std::endl;
      std::cout<<"Score: "<<snake.Length()-5<<std::endl;
    }
  else
    {
      if(snake.Body().back() == fruit)
	{
	  snake.Grow();
	  fruit = Point(std::rand()%16,std::rand()%16);
	}
      counter++;
      if(counter%35==0)
	{
	  draw();
	  counter=0;
	  snake.Move(snake.Dir());
	}
    }
}

CINDER_APP(Application, ci::app::RendererGl(ci::app::RendererGl::Options().msaa(16)), &Application::prepareSettings)

