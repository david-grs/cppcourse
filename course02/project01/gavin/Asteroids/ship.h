#pragma once
#include <cinder/app/RendererGl.h>
#include <cinder/gl/gl.h>
#include "controller.h"
#include "laser.h"
#include "collidable.h"


class Ship : public Collidable {
public:
    Ship(GameObject& parent, const glm::vec2 &center, const glm::vec2& heading, Controller& controller);
    void Update(float frameDelta) override;
    void Draw() override;
    void Accelerate(float force);
    void Rotate(float degreesClockwise);
    void Fire();
    void Collide(Collidable& other) override;

private:
    glm::vec2 mHeading;
    Controller& mController;
    glm::vec2 mSpeed{0,0};
    std::vector<std::shared_ptr<Laser>> mLasers;

    std::chrono::steady_clock::time_point mLastFireTime = std::chrono::steady_clock::now();
    bool ReadyToFire();
    void Crash();
};


