#include "game_world.h"
#include "asteroid.h"
#include "ship.h"
#include <glm/gtc/random.hpp>

using namespace std::chrono_literals;

GameWorld::GameWorld(Controller &controller) :
        GameObject(),
        mController(controller){
    CreateGameObject<Ship>(ci::app::getWindowCenter(), glm::vec2{0.0, 1.0}, mController);
    RegisterCallback([this](){
        SpawnAsteroid();
    }, 5s);
}

void GameWorld::Update(const float frameDelta)
{
    UpdateCollisions();
    GameObject::Update(frameDelta);
}

void GameWorld::Draw()
{
    GameObject::Draw();
}

void GameWorld::SpawnAsteroid()
{
    auto direction = glm::sphericalRand(1.0);
    CreateGameObject<Asteroid>(glm::vec2{1.0, 1.0}, glm::normalize(direction), 20, 30);
    RegisterCallback([this](){
        SpawnAsteroid();
    }, 10s);
}

void GameWorld::AddCollider(Collidable* collidable)
{
    mColliders.push_back(collidable);
}

void GameWorld::UpdateCollisions() {
    //FIXME: collection of references without ownership?
    for(auto a : mColliders)
        for(auto b : mColliders)
            if(a != b and a->Overlaps(*b))
                a->Collide(*b);
}

void GameWorld::RemoveCollider(Collidable *collidable) {
    mColliders.erase(std::remove_if(mColliders.begin(), mColliders.end(), [collidable](Collidable* collider){return collider == collidable;}), mColliders.end());
}
