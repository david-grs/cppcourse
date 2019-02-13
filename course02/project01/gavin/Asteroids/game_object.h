#pragma once

#include <vector>
#include <memory>
#include <functional>
#include <deque>
#include <chrono>
#include <algorithm>
#include <glm/vec2.hpp>
#include "utils.h"

class GameObject {

public:
    GameObject(GameObject& parent, Tag tag, glm::vec2 position, float size) : mRoot(parent.GetRoot()), mParent(parent), mTag(tag), mPosition(position), mSize(size){};
    GameObject() : mRoot(*this), mParent(*this), mTag(Tag::None), mPosition(0,0), mSize(0) {};
    virtual void Update(float frameDelta);
    virtual void Draw();

    GameObject& GetParent() { return mParent;}
    GameObject& GetRoot() { return mRoot;}

    Tag GetTag() { return mTag;}
    bool GetDestroyed() { return mDestroyed;}

protected:
    GameObject& mRoot;
    bool mDestroyed = false;
    GameObject& mParent;
    Tag mTag;
    glm::vec2 mPosition;
    float mSize;



    void Create(const std::shared_ptr<GameObject> &object)
    {
        mChildren.push_back(object);
    }

    template<typename T, typename ...Args>
    std::shared_ptr<T> CreateGameObject(Args&&... args)
    {
        auto newObject = std::make_shared<T>(*this, args...);
        mChildren.push_back(newObject);
        return newObject;
    }

    template<typename T, typename ...Args>
    std::shared_ptr<T> CreateFreeGameObject(Args&&... args)
    {
        return mRoot.CreateGameObject<T>(args...);
    }

    void DestroyGameObject(std::shared_ptr<GameObject> ptr)
    {
        mChildren.erase(std::remove_if(mChildren.begin(), mChildren.end(), [ptr](auto c){return c == ptr;}),mChildren.end());
    }

    void RegisterCallback(std::function<void()> f, std::chrono::microseconds time)
    {
        mCallbacks.emplace_back(f, std::chrono::steady_clock::now() + time);
    }

    virtual void Destroy()
    {
        mDestroyed = true;
    }

private:
    using Callback = std::tuple<std::function<void()>, std::chrono::steady_clock::time_point>;

    std::vector<std::shared_ptr<GameObject>> mChildren;
    std::deque<Callback> mCallbacks;

    bool Call(Callback &callback);

};


