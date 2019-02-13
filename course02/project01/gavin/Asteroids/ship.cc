#include "ship.h"
#include "utils.h"
#include "asteroid.h"
#include <glm/gtc/random.hpp>
#include <math.h>

using namespace std::chrono_literals;

Ship::Ship(GameObject& parent, const glm::vec2& center, const glm::vec2& heading, Controller& controller) : Collidable(parent, Tag::Player, center, 10),
        mHeading(heading),
        mController(controller){
}


void Ship::Update(float frameDelta)
{
    if(mController.held('w'))
        Accelerate(frameDelta);
    if(mController.held('a'))
        Rotate(frameDelta*60.0f);
    if(mController.held('d'))
        Rotate(-frameDelta*60.0f);
    if(mController.held('e') and ReadyToFire())
        Fire();
    mPosition += mSpeed;
    auto bounds = ci::app::getWindowBounds();

    if(!bounds.contains(mPosition))
        ReturnToPlayArea(bounds, mPosition);

    GameObject::Update(frameDelta);
}

void Ship::Draw()
{

    const auto front = mHeading*mSize;
    const auto left = glm::vec2(mHeading.y*(mSize/3.0), -mHeading.x*(mSize/3.0));
    ci::gl::drawSolidTriangle(mPosition + front, mPosition + left, mPosition - left);
    GameObject::Draw();
}

void Ship::Accelerate(float force)
{
    mSpeed += mHeading * force;
}

void Ship::Rotate(float degreesClockwise)
{
    const auto rads = degreesClockwise * M_PI / 180.0;
    glm::mat2x2 rotation(glm::vec2(cos(rads), sin(rads)), glm::vec2(-sin(rads), cos(rads)));
    auto new_heading = mHeading * rotation;
    mHeading = new_heading;

}

void Ship::Fire()
{
    auto laser = CreateGameObject<Laser>(normalize(mHeading), mPosition);
    RegisterCallback([this, laser](){DestroyGameObject(laser);}, 2s);
    mLastFireTime = std::chrono::steady_clock::now();
}

bool Ship::ReadyToFire()
{
    return std::chrono::steady_clock::now() - mLastFireTime > 200ms;
}

void Ship::Collide(Collidable &other)
{
    if(other.GetTag() == Tag::Asteroid)
        Crash();
}

void Ship::Crash()
{
    for(int i=0; i < 5; i ++)
    {
        auto direction = glm::sphericalRand(1.0);
        auto laser = CreateFreeGameObject<Laser>(direction, mPosition);
    }
    std::cout << "you crashed!" << std::endl;
    RegisterCallback([this](){Destroy();}, 20ms);
}
