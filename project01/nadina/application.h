#pragma once

#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>
#include <cinder/gl/gl.h>
#include <vector>

class Application : public ci::app::App
{
public:
	Application();

	void keyDown(ci::app::KeyEvent) override;
	void setup() override;
	void draw() override;
	void update() override;

	static void prepareSettings(Settings*);

    bool collisionDetected();
    void updateFoodPos();
    void increaseSnake();
    void resetBoundaries(glm::vec2& pos);

private:
    std::vector<glm::vec2> mSnake;
    glm::vec2 mFood;

    int mHorizontalDirection = 1;
    int mVerticalDirection = 0;
    float mSpeed = 5.0f;
    int mSnakeSize = 40;
    int mFoodSize = 40;

};
