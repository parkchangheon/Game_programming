#include "StartScene.h"


USING_NS_CC;   //using namespace cocos2d

Scene *StartScene::createScene() {
	auto scene = Scene::create();
	auto layer = StartScene::create();

	scene->addChild(layer);
	return scene;
}


bool StartScene::init()
{
	if (!Layer::init())
		return false;

	/*****����̽��� ũ�⸦ �����ɴϴ�.*****/

	//director�� �����ɴϴ�.
	auto director = Director::getInstance();

	//OpenGLView�� �����ɴϴ�.
	auto glview = director->getOpenGLView();

	//OpenGL���� DesingResolutionSize�� �����ɴϴ�.
	auto winSize = glview->getDesignResolutionSize();



	/*****��� �̹��� back�� �ֽ��ϴ�.****/
	//Sprite �����Ͽ� �̹��� ����
	auto back = Sprite::create("INU.png");

	back->setPosition(Point(winSize.width / 2, winSize.height / 2));
	this->addChild(back);


	return true;

}





