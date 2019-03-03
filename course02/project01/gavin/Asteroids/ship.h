#pragma once
#include "controller.h"
#include "laser.h"
#include <cinder/app/RendererGl.h>
#include <cinder/gl/gl.h>

class Ship : public Collidable {
public:
    Ship(GameWorld* root, glm::vec2 &center, glm::vec2& heading, Controller* controller);
    void Update(FrameDelta frameDelta) override;
    void Draw() override;
    void Accelerate(float force);
    void Rotate(float degreesClockwise);
    void Fire();

    void Collide(Asteroid &asteroid);

    template<typename T>
    void Collide(T&){}

private:
    glm::vec2 mHeading;
    Controller* mController;
    glm::vec2 mSpeed{0,0};

    std::chrono::steady_clock::time_point mLastFireTime = std::chrono::steady_clock::now();
    bool ReadyToFire();
    void Crash();
};


