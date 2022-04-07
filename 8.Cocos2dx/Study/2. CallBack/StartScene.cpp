#include "StartScene.h"
#include "CharacterScene.h"

USING_NS_CC;   //using namespace cocos2d

Scene *StartScene::createScene() {
	auto scene = Scene::create();  //scene�� autorelease ��ü�̴�. �� �޸� ������ �����൵ �ڵ����� ��
	auto layer = StartScene::create(); //layer ���� "

	scene->addChild(layer);  //layer 
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
	auto back = Sprite::create("INU.png"); //resource ������ �ִ�..

	back->setPosition(Point(winSize.width / 2, winSize.height / 2));
	this->addChild(back);


	//title�� �ش� ����Ʈ�� ��ġ��ŵ�ϴ�. ȭ���� ���� �߾ӿ� ��ġ�ϵ��� �ߴ�.
	auto title = Sprite::create("Title.png");
	title->setAnchorPoint(Point(0.5f, 0.5f)); //��Ŀ����Ʈ ����
	title->setPosition(Point(winSize.width / 2, winSize.height - 70));
	this->addChild(title);

	auto character = Sprite::create("mugosa.png");
	character->setPosition(Point(winSize.width / 2, winSize.height / 2));
	this->addChild(character);

	//�׸��� ȭ�鿡 ������ GL verts: GL calls�� ���ؽ� ������ openGL�� ȣ��� Ƚ����
	//FPS�� �ʴ� ȭ���� ���ŵǴ� Ƚ��. -> 60.1�̶� 60FPS


	/*****menuitemImage�� menu Ŭ������ ���*****/


	//��ư�߰�
	//��ư�� �޴� Ŭ������ ��ƾ߸� ȭ�鿡 ���� �� �ִ�. 
	//�Ʒ���ư�� ù��° ���ڰ� �̹����� ���̰� �ι�° ���ڰ� Ŭ���� ���δ�.
	auto button1 = MenuItemImage::create("button_ch1.png", "button_ch1_on.png", "button_ch1_dis.png", [&](Ref *sender) 
	{
		log("OnClicked1111"); 
	//auto Scene = CharacterScene::createScene(); ���� ����
	auto Scene = TransitionCrossFade::create(0.5f, CharacterScene::createScene());
	Director::getInstance()->pushScene(Scene);
	});
	//[&](Ref *sender){} �� �ݹ� �޼����̴�. �� �� ��ư�� �������� �ڵ����� ����Ǵ� �޼����� �����
	//->�̸����� �޼��带 �Ｎ���� ����ʰ� ��� -> ���� ���
	//button1->setEnabled(true); //�ش� �޼���� ��ư�� ���� �� �ְ����� ���� ���� ������. true�� ������ ����
	button1->setPosition(Point(winSize.width / 2, 100));
	
	//menuItemImage�� create���� normalImage�� selectImage�ܿ��� disabledImage�� �Ű������� �߰��� �� �ִ�.
	//disabledImage�� ��ư�� ��밡������ ������(���� �� ������) ǥ�õ� �̹����� ����.

	//menuitem���� menuitemsprite ���� ���� Ŭ������ �ְ�, �� �Ʒ� MenuItemImage�� ����
	//MenuItemImage�� ���ϸ��� �޾� MenuItem�� �����ϰ� (MenuItem�� Menu�� �߰��Ǿ� ����)
	//MenuItemSprite�� Sprite�� �޾� MenuItem�� �����Ѵ�.
	
	//menuitem >> menuitemsprite >> menuitemimage
	//�׷��Ƿ� menuitem�� ������ ���Ŀ��� Menu�� �����ϰ�, �տ��� ������ menuitem�� menu�� �߰��Ѵ�

	//�α������ ������� �־ CharacterScene�� ȣ���Ѵ�.
	//getInstance()->pushScene�� �ش� Scene�� �߰��ϴ� �޼����Դϴ�.
	//replace�� �ᵵ �Ǵµ�, push�� ������ ������ ���� �߰��ϴ� ���, replace�� ���ְ� �߰��ϴ� ���

	auto button2 = MenuItemImage::create("button_ch2.png", "button_ch1_on.png",CC_CALLBACK_1(StartScene::OnClickButton,this));
	button2->setPosition(Point(winSize.width / 2, 40));
	button2->setEnabled(true);

	//������ ��ư�� �޴��� �߰��Ѵ�.
	auto menu = Menu::create(button1, button2, NULL); //������ �׸񿡴� NULL�� �Է��ϴ� ������ ������
	menu->setPosition(Point::ZERO);  //��ư ��ġ ����
	//menu�� ���϶��� setPoint(Point::Zero)�� �����ش�.==>��ġ��ǥ�� ��Ȯ�ϰ� ����
	//Point::ZERO�� point(0,0)�� ���� �ǹ�

	this->addChild(menu);
	// ��ư ������ �޴��� �ٿ��߸� �����ش�.

	//Ÿ��Ʋ ��������Ʈ�� �ִϸ��̼� �߰�
	auto to = title->getPosition();
	auto from = Point(to.x, to.y + 100);

	//title ��������Ʈ�� ���� ��ġ�� ����
	title->setPosition(from);

	//MoveTo�� ������ ��带 �ش� ��ġ�� �����̴� �׼��� �����.
	//auto action = MoveTo::create(0.5f, to);   //�׼��� ���� ���� action ���� -> �ð��� �̵��� ��ġ ����
	auto action = Sequence::create(MoveTo::create(0.5f, to), RotateTo::create(0.5f, 720), NULL);
	//���� �ڵ�� �����̰� ���ƶ�. �Ű������� ������ ���� �� �ִ� �ż���� NULL�� �� �߰����ٰ�.
	//sequence�� ���������� ����̵ǰ�, spawn�� �ִϸ��̼��� ���ÿ� ����ȴ�.


	title->runAction(action);   //title ��������Ʈ�� �׼� ����


	//Ÿ��Ʋ�� ��ġ�� �����ͼ�  to ��� ����Ʈ�� �߰����ְ�, from�� �ִϸ��̼��� ������ ��ġ
	

	return true;

}


//�ݹ� �޼����̴�. -> ��� ��ư�� ����ұ�? ->menuItemImage�� ������ �� �߰� �Ű������� �ִ´�.
void StartScene::OnClickButton(Ref *object) {
	log("OnClickButton!!!");
}






