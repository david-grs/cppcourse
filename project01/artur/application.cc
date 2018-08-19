#include "application.h"
#include <cinder/gl/gl.h>
#include <random>

static const cinder::ivec2 WindowSize{640, 480};
static const double SIZE = 20;
static const double HALF_SIZE = SIZE/2;

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
  if(!running)
    {
      return;
    }
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
  ci::gl::drawSolidRect( ci::Rectf(0, 0, SIZE*corner.GetX(), HALF_SIZE ));
  ci::gl::drawSolidRect( ci::Rectf(0, SIZE*corner.GetY()-HALF_SIZE, SIZE*corner.GetX(), SIZE*corner.GetY() ));
  ci::gl::drawSolidRect( ci::Rectf(0, 0, HALF_SIZE, SIZE*corner.GetY() ));
  ci::gl::drawSolidRect( ci::Rectf(SIZE*corner.GetX()-HALF_SIZE, 0, SIZE*corner.GetX(), SIZE*corner.GetY() ));

  for(int i = 0; i < snake.Length()-1; ++i)
    {
      Point p = snake.Body().at(i);
      ci::gl::drawSolidCircle( ci::vec2(SIZE*p.GetX(), SIZE*p.GetY()), HALF_SIZE);
    }
  ci::gl::color( ci::Color( 1, 0, 0 ) );
  ci::gl::drawSolidCircle( ci::vec2(SIZE*snake.Body().back().GetX(),
				    SIZE*snake.Body().back().GetY()), HALF_SIZE);
  ci::gl::color( ci::Color( 0, 1, 0 ) );
  ci::gl::drawSolidCircle( ci::vec2(SIZE*fruit.GetX(), SIZE*fruit.GetY()), HALF_SIZE);
}

void Application::update()
{
  if(!running)
    {
      return;
    }
  if(!snake.IsAlive(corner))
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
	  fruit = Point(std::rand()%(corner.GetX()-1)+1,
			std::rand()%(corner.GetY()-1)+1);
	  for(int rand_i = 0; rand_i < 10; ++rand_i)
	    {
	      // Didn't manage to make it work with std::find
	      for(int i = 0; i < snake.Length(); ++i)
		{
		  if(snake.Body()[i] == fruit)
		    {
		      fruit = Point(std::rand()%(corner.GetX()-1)+1,
				    std::rand()%(corner.GetY()-1)+1);
		      i=0;
		    }
		}
	    }
	}
      counter++;
      if(counter%35==0)
	{
	  counter=0;
	  snake.Move(snake.Dir());
	}
    }
}

CINDER_APP(Application, ci::app::RendererGl(ci::app::RendererGl::Options().msaa(16)), &Application::prepareSettings)

