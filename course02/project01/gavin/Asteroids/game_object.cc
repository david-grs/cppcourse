//
// Created by gavinparker on 10-2-19.
//

#include <algorithm>

#include "game_object.h"

void GameObject::Update(float frameDelta)
{
    mCallbacks.erase(std::remove_if(mCallbacks.begin(), mCallbacks.end(), [this](auto &callback){return Call(callback);}), mCallbacks.end());
    mChildren.erase(std::remove_if(mChildren.begin(), mChildren.end(), [](auto &child){return child->GetDestroyed();}), mChildren.end());
    std::for_each(mChildren.begin(), mChildren.end(), [frameDelta](auto child){child->Update(frameDelta);});
}

bool GameObject::Call(Callback &callback)
{
    auto now = std::chrono::steady_clock::now();
    if(now > std::get<1>(callback))
    {
        std::get<0>(callback)();
        return true;
    }
    return false;
}

void GameObject::Draw() {
    std::for_each(mChildren.begin(), mChildren.end(), [](auto child){child->Draw();});
}
