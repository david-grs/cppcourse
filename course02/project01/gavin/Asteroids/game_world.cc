#include "game_world.h"
#include "asteroid.h"
#include "ship.h"
#include <glm/gtc/random.hpp>

using namespace std::chrono_literals;

GameWorld::GameWorld(Controller &controller) :
        mController(controller)
{
    SpawnObject<Ship>(ci::app::getWindowCenter(), glm::vec2{0.0, 1.0}, &mController);
    RegisterCallback([this](){
        SpawnAsteroid();
    }, 5s);
}

void GameWorld::Update(FrameDelta frameDelta)
{
    UpdateCollisions();
    mCallbacks.erase(std::remove_if(mCallbacks.begin(), mCallbacks.end(), [this](auto &callback){return Call(callback);}), mCallbacks.end());
    mWorldContents.RemoveIf([](auto&& child){return child.GetDestroyed();});
    mWorldContents.ForAll([frameDelta](auto&& child){child.Update(frameDelta);});
}

void GameWorld::Draw()
{
    mWorldContents.ForAll([](auto&& child){child.Draw();});
}

bool GameWorld::Call(Callback &callback)
{
    auto now = std::chrono::steady_clock::now();
    if(now > std::get<1>(callback))
    {
        std::get<0>(callback)();
        return true;
    }
    return false;
}

void GameWorld::SpawnAsteroid()
{
    auto direction = glm::sphericalRand(1.0);
    CreateGameObject<Asteroid>(glm::vec2{1.0, 1.0}, glm::normalize(direction), 20, 30);
    RegisterCallback([this](){
        SpawnAsteroid();
    }, 10s);
}

void GameWorld::UpdateCollisions() {
    mWorldContents.ForAllOf<Collidable>([&](auto&& a){
        mWorldContents.ForAllOf<Collidable>([&](auto&& b){
            if(a.GetId() != b.GetId() and a.Overlaps(b))
                a.Collide(b);
        });
    });

}