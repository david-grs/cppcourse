#pragma once
#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>

class Application : public ci::app::App
{
public:
	Application();

	void keyDown(ci::app::KeyEvent) override;
	void setup() override;
	void draw() override;
	void update() override;
    void move();
    bool intesecton(ci::Rectf block);
    void createApple();


	static void prepareSettings(Settings*);
private:
    bool mBreach;
    std::size_t mPoints;
    std::size_t mTimer;
    std::size_t mBlockSize;
    std::string mDirect;// value = {"Up", "Down", "Left", "Right"}
    std::vector<ci::Rectf> mBody;
    ci::vec2 mWSize;
    ci::Rectf mApple;

};
