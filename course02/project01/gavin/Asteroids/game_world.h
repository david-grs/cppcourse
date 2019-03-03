#pragma once
#include "controller.h"
#include "utils.h"
#include "game_store.h"
#include "asteroid.h"
#include "ship.h"
#include "collidable.h"

class GameWorld {
public:
    explicit GameWorld(Controller& controller);

    void Update(FrameDelta frameDelta);
    void Draw();

    template<typename T, typename ...Args>
    ObjectId CreateGameObject(Args&&... args)
    {
        return SpawnObject<T>(args...);
    }

    void RegisterCallback(std::function<void()> f, std::chrono::microseconds time)
    {
        mCallbacks.emplace_back(f, std::chrono::steady_clock::now() + time);
    }

    ObjectId GetId()
    {
        return mIds++;
    }

    template<class Obj>
    Obj& GetObject(ObjectId id)
    {
        return mWorldContents.Get<Obj>(id);
    }
private:
    Controller& mController;
    using Callback = std::tuple<std::function<void()>, std::chrono::steady_clock::time_point>;

    GameStore<Ship, Laser, Asteroid> mWorldContents;
    std::deque<Callback> mCallbacks;
    ObjectId mIds = 0;
    void SpawnAsteroid();
    void UpdateCollisions();
    bool Call(Callback &callback);

    template<typename T, typename ...Args>
    ObjectId SpawnObject(Args&&... args)
    {
        return mWorldContents.Create<T>(this, args...);
    }

};