#pragma once
#include "cocos2d.h"
class StartScene : public cocos2d::Layer
{
public:
	//cpp ���� id ������ ���� => class instance pointer�� ��ȯ
	static cocos2d::Scene* createScene();
	virtual bool init();

	void menuCloseCallback(cocos2d::Ref* pSender);

	CREATE_FUNC(StartScene);
};




