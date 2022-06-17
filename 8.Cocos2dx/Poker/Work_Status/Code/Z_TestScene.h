/********************************************************************
	file name:	LogoScene.h

	purpose:	�ΰ� ��� ���
*********************************************************************/
#pragma once

class Z_TestScene : public Scene, public CCTargetedTouchDelegate
{
	enum LogoSceneState {
		ONE_STORE,	//�������
		NUMIX,		//���ͽ�
		GAME_MODE,	//���� ���
		END,		//��
	};

	typedef deque<LogoSceneState> StateContainer;

public:
	Z_TestScene();
	virtual ~Z_TestScene();

	virtual void onLoad();
	virtual void onUnload();

	virtual void onStart();
	virtual void onEnd();
	virtual void onUpdate(float dt);

	virtual bool handling(STCMD& stCmd);

public: // CCTargetedTouchDelegate
	virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);

public:
	LogoSceneState mState;
	Layer* mBackground;
	Panel* mPublisher;
	bool mSkip;
	bool mAuth;

private:
	StateContainer mStateContainer;
	SkelObject* mBg;
	float mStateDelay;
	void setState();
	float mDelay;
	bool mIsFadeOuting;
};
