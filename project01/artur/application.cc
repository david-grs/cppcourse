#include "application.h"
#include <cinder/gl/gl.h>

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
      break;
    case ci::app::KeyEvent::KEY_UP:
      snake.ChangeDirection(Point(Direction::up));
      break;
    case ci::app::KeyEvent::KEY_LEFT:
      snake.ChangeDirection(Point(Direction::left));
      break;
    case ci::app::KeyEvent::KEY_RIGHT:
      snake.ChangeDirection(Point(Direction::right));
      break;
    default:
      break;
    }
}

void Application::setup()
{
  counter = 0;
  snake = Snake();
}

void Application::draw()
{
  ci::gl::clear();

  for(int i = 0; i < snake.Length(); ++i)
    {
      Point p = snake.Body().at(i);
      ci::gl::drawSolidCircle( ci::vec2(10*p.GetX(), 10*p.GetY()), 5);
    }
}

void Application::update()
{
  if(!snake.IsAlive())
    {
      /*
      std::cout<<"You died!"<<std::endl;
      std::cout<<"Score"<<std::endl;
      std::cout<<snake.Length()<<std::endl;
      */
    }
  else
    {
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

