#include "asteroid.h"
#include "utils.h"
#include <cinder/gl/gl.h>
#include <cinder/app/App.h>
#include <glm/gtc/random.hpp>

Asteroid::Asteroid(GameObject& parent, glm::vec2 direction, glm::vec2 position, float size, float speed) :
                Collidable(parent, Tag::Asteroid, position, size),
                mDirection(direction),
                mSpeed(speed) {
}

void Asteroid::Update(float frameDelta)
{
    auto dist = mDirection * mSpeed * frameDelta;
    mPosition += dist;
    auto bounds = ci::app::getWindowBounds();
    if(!bounds.contains(mPosition))
        ReturnToPlayArea(bounds, mPosition);
    GameObject::Update(frameDelta);
}

void Asteroid::Draw()
{
    ci::gl::drawStrokedCircle(mPosition, mSize);
    GameObject::Draw();
}

void Asteroid::Collide(Collidable &other)
{
    if(other.GetTag() == Tag::Laser)
    {
        Destroy();
        if(mSize > 5)
            Break();
    }
}

void Asteroid::Break()
{
    for(int i = 0; i < 2; i++)
    {
        auto direction = glm::sphericalRand(1.0);
        CreateFreeGameObject<Asteroid>(glm::normalize(direction), mPosition, mSize/2, mSpeed*2);
    }
}
