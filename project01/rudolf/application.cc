#include "application.h"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include <cstdlib>
#include <random>




static const cinder::ivec2 WindowSize{640, 480};
static const std::size_t BlockSize(10);

std::random_device rd;     // only used once to initialise (seed) engine
std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
std::uniform_int_distribution<int> uni_x(0,(WindowSize.x - BlockSize) / BlockSize); // guaranteed unbiased
std::uniform_int_distribution<int> uni_y(0,(WindowSize.y - BlockSize) / BlockSize); // guaranteed unbiased

using namespace ci;
using namespace ci::app;

Application::Application():
    mTimer(0),
    mBlockSize(BlockSize),
    mWSize(WindowSize)
{

}

void Application::prepareSettings(Settings* settings)
{
	settings->setWindowSize(WindowSize);
	settings->setFrameRate(35.0f);
	settings->setResizable(false);
	settings->setFullScreen(false);
}

void Application::keyDown(ci::app::KeyEvent key)
{
    if ( key.KEY_DOWN == key.getCode() ) { if(mDirect != "Up"){mDirect = "Down";}}
    else if ( key.KEY_UP == key.getCode() ) { if(mDirect != "Down") mDirect = "Up"; }
    else if ( key.KEY_LEFT == key.getCode() ) { if(mDirect != "Right") mDirect = "Left"; }
    else if ( key.KEY_RIGHT == key.getCode() ) { if(mDirect != "Left") mDirect = "Right";}
    else if ( key.KEY_r == key.getCode() ){ setup(); }// reset game
}
void Application::setup()
{
    mBreach = false;
    mDirect = "Left";
    mPoints = 1;
    mBody = std::vector<ci::Rectf>(3);
    for (std::size_t it=0; it < mBody.size(); ++it)
    {
        mBody[it].set(mWSize.x / 2 + mBlockSize * it,
                     mWSize.y / 2,
                     mWSize.x / 2 + mBlockSize * ( it + 1)-1,
                     mWSize.y / 2 + mBlockSize-1);
    }
    mApple.set(260,240,269,240,249);
}
void Application::createApple()
{
    //
    do{
        auto ran_x = uni_x(rng) * mBlockSize;
        auto ran_y = uni_y(rng) * mBlockSize;
        mApple.set(ran_x, ran_y, ran_x + mBlockSize - 1,ran_y + mBlockSize - 1);
    }
    while(intesecton(mApple));
}

void Application::move()
{
    mTimer++;
    if (mTimer >= 35)
    {
        mTimer=mPoints;
        ci::Rectf tNose = mBody[0];
        if (mDirect=="Right")
        {
            tNose.set(tNose.x1 + mBlockSize ,
                         tNose.y1 ,
                         tNose.x2 + mBlockSize ,
                         tNose.y2);
        }
        else if (mDirect=="Up")
        {
            tNose.set(tNose.x1 ,
                         tNose.y1 - mBlockSize,
                         tNose.x2 ,
                         tNose.y2 - mBlockSize);
        }
        else if (mDirect=="Down")
        {
            tNose.set(tNose.x1 ,
                         tNose.y1 + mBlockSize,
                         tNose.x2 ,
                         tNose.y2 + mBlockSize);
        }
        else
        {
            tNose.set(tNose.x1 - mBlockSize ,
                         tNose.y1 ,
                         tNose.x2 - mBlockSize ,
                         tNose.y2);
        }

        ci::Rectf tTail = mBody[mBody.size()-1];
        for (std::size_t it = mBody.size()-1;it >0; --it)
        {
            mBody[it]=mBody[it-1];
        }
        if(intesecton(mApple))
        {
            mPoints++;
            mBody.push_back(tTail);
            createApple();
        }
        if( tNose.x1 >= mWSize.x || tNose.y1 >= mWSize.y || tNose.x1<0 || tNose.y1 < 0 || intesecton(tNose))
        {
            mBreach=true;
        }else{
            mBody[0]=tNose;
        }
    }
}

bool Application::intesecton(ci::Rectf block)
{
    for (std::size_t it = 0; it < mBody.size(); ++it)
    {
        if (block.intersects(mBody[it]))
        {
            return true;
        }
    }
    return false;
}

void Application::draw()
{
    if (mBreach)
    {}
    else{
        move();
        {
            ci::gl::clear();
            for (std::size_t it=0;it < mBody.size(); ++it)
            {
                ci::gl::drawSolidRect(mBody[it]);
            }
            ci::gl::drawSolidRect(mApple);
        }
    }
}

void Application::update()
{

}

CINDER_APP(Application, ci::app::RendererGl(ci::app::RendererGl::Options().msaa(16)), &Application::prepareSettings)

