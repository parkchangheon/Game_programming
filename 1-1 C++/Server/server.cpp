//DWORD threadID;
//ThreadParam threadParam;
//threadParam.value = 123;
//CreateThread(
//	ThreadProc, &threadParam, &threadId
//);



//InGame MultiThreading
//#include<iostream>
//using namespace std;
//
//void Render() { ; }
//void LoadModel1() { ; }
//void LoadTexture() { ; }
//void LoadAnimation() { ; }
//void LoadSound() { ; }
//void FrameMove() { ; }
//
//void LoadScene()
//{
//	Render();
//	LoadScene();
//	Render();
//	LoadModel1();
//	Render();
//	LoadTexture();
//	Render();
//	LoadAnimation();
//	Render();
//	LoadSound();
//} //���� �ε��ϴ� ���� �ʴ� ��� --> ��Ƽ�������� ���� �ʾ��� ��
//
//
//// �ݸ� ��Ƽ �������� �ִ��� Ȱ���ϴ� ��� 
//int main()
//{
//	bool isStillLoading;
//
//	{ //Thread1
//		isStillLoading = true;
//		while (isStillLoading){ //�ε� ��Ȳ �ϋ� 
//			FrameMove();
//			Render();
//		}
//	}
//
//
//	{ //Thread2  --> ���ӿ��� �ʿ��� �����͸� ��ũ���� �ε��Ѵ�.
//		// �ε� ���� �� Ư�� ������ �����Ѵ�.
//		LoadScene();
//		LoadModel1();
//		LoadTexture();
//		LoadAnimation();
//		LoadSound();
//
//	}
//}



// �÷��̾� ������ �аų� ������ ��ũ�� �׼��� �ϴ� ���, 
// ��ũ�� �׼����ϴ� ������� ��ũ�� ó�� ����� ���� �� ���� ��ٷ��� �Ѵ�. ==> �̶� CPU�� ��µ�, �� ��� �ð��� �ٸ� �÷��̾�� �й�
