#pragma once
class GameWorld;

#include "game_world.h"
#include "utils.h"
#include <glm/vec2.hpp>
#include <vector>
#include <memory>
#include <functional>
#include <deque>
#include <chrono>
#include <algorithm>

class GameObject {
public:
    GameObject(GameWorld* root, ObjectId id, glm::vec2 position, float size) : mRoot(root), mId(id), mPosition(position), mSize(size){};
    virtual void Update(FrameDelta frameDelta) = 0;
    virtual void Draw() = 0;

    bool GetDestroyed() { return mDestroyed;}

    virtual void Destroy()
    {
        mDestroyed = true;
    }

    ObjectId GetId()
    {
        return mId;
    }

protected:
    GameWorld* mRoot;
    ObjectId mId;
    bool mDestroyed = false;
    glm::vec2 mPosition;
    float mSize;

};


