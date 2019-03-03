#include <cinder/gl/gl.h>
#include <cinder/app/App.h>
#include <glm/gtc/random.hpp>
#include "game_world.h"
#include "utils.h"

using namespace std::chrono_literals;


Asteroid::Asteroid(GameWorld* root, glm::vec2 direction, glm::vec2 position, float size, float speed) :
                Collidable(root, root->GetId(), position, size),
                mDirection(direction),
                mSpeed(speed) {
}

void Asteroid::Update(FrameDelta frameDelta)
{
    auto dist = mDirection * mSpeed * frameDelta.count();
    mPosition += dist;
    auto bounds = ci::app::getWindowBounds();
    if(!bounds.contains(mPosition))
        ReturnToPlayArea(bounds, mPosition);
}

void Asteroid::Draw()
{
    ci::gl::drawStrokedCircle(mPosition, mSize);
}

void Asteroid::Collide(Laser&)
{
    Destroy();
    if(mSize > 5)
        Break();
}

void Asteroid::Break()
{
    for(int i = 0; i < 2; i++)
    {
        auto direction = glm::sphericalRand(1.0);
        mRoot->CreateGameObject<Asteroid>(glm::normalize(direction), mPosition, mSize/2, mSpeed*2);
    }
}
