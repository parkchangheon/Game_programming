#include "maniacs.h"
#include <iostream>


CReverseDirectMan::CReverseDirectMan() : speed(5.0f), flag(false),
X(0.f),Y(0.f),
get_Item(false)
{
	cout << "constructor." << endl;
}

bool CReverseDirectMan::Move(const CInputState* is)
{
	speed = 0.1f;
	
	if (flag)
		speed = -speed;

	if (is->Left()) X -= speed;
	if (is->Right()) X += speed;
	if (is->Up()) Y += speed;
	if (is->Down()) Y -= speed;
	
	// 
	if (X < 0) X = 0;
	if (X > MAX_X - 1) X = MAX_X - 1;
	//
	if (Y < 0) Y = 0;
	if (Y > MAX_Y - 1) Y = MAX_Y - 1;

	//������ ȹ�� ���� ����
	//��� �����ۿ� ���Ͽ� �˻� + ������ ȹ�� �� �̵� ������ �ٲ�
	for (CTaskIter i = Game->MoverList; i.HasNext(); )
	{
		CMover* mover = (CMover*)i.Next();

		//�������� ���� �Ÿ� �ȿ� �������� ������ ȹ�� ����
		if (mover->Type == 1 && abs(mover->X - X) < 1 && abs(mover->Y - Y) < 1)
		{
			//�̵������� ���� ��Ų��
			flag = !flag;
			i.Remove();

			get_Item = true;
		}
	}
	// -> �ٵ� ����Ʈ 


	// ������ �����ߴٸ�, ���ο� �������� �������ش�.
	if (get_Item)
		new CReverseDirectMan();

	Angle = flag ? 0.5f : 0;
	return true;

}
