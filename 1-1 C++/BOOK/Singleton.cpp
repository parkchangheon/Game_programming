/* 
�ƹ� �������� ���� �ý��� Ŭ���� �ν��Ͻ��� ���� �� �ִٸ�, �ٸ� �ν��Ͻ����� � �۾��� ������������ �� �� ����. 
�̱������� ����� �ȴٸ�, Ŭ������ �ν��Ͻ��� �ϳ��� �������� ������ �ܰ迡�� ������ �� �ִ�.
*/



#include<iostream>
using namespace std;

// ���� �������� ���� ==> ���� �ν��Ͻ��� ������ �� �����Ƿ�, �������� ������ �� �ִ� �޼��带 �����Ѵ�.
class FileSystem
{
private:
	FileSystem() {}
	static FileSystem* instance_; //�ش� ���� ��� ������ Ŭ���� �ν��Ͻ��� �����Ѵ�. private�̹Ƿ� �ܺο����� ������ �Ұ�.

public :
	static FileSystem instance(){			// ��𿡼��� ������ �����ϰ�, ������ �ʿ��� ������ �ν��Ͻ� �ʱ�ȭ�� �̷�� ���ҵ� ��.
		//lazy initialize
		if (instance_ == NULL) {
			instance_ = new FileSystem();
			return *instance_;
		}
	}
};

//�ֱ� ���� ��� 
class FileSystem2 {
private:
	FileSystem2() {}

public:
	static FileSystem2 Instance() {
		static FileSystem2* Instance_ = new FileSystem2;
		return *Instance_;
	}
};

//�ѹ��� ������� �ʾҴٸ�, �ƿ� �ν��Ͻ��� �������� �ʴ´�. => �޸�, CPU��뷮�� ���� �� �ִ�.
//ó�� ���ɶ�, �ʱ�ȭ�� �ǹǷ� ���ӳ����� ���� ������ �ʴ´ٸ�, �ʱ�ȭ ������ �ʴ´�.

// ��Ÿ�ӿ� �ʱ�ȭ�� �ȴ�.
 
 




// �̱����� ����� �� �ִ�.
class FileSystem3 {
public:
	static FileSystem3& instance();

	virtual ~FileSystem3() {};
	virtual char* readFile(char* path) = 0;
	virtual void writeFile(char* path, char* contents) = 0;

	//FileSystem Ŭ������ �̱������� �����.
protected:
	FileSystem3() {}
};

FileSystem3& FileSystem3::instance() {	// �ش� �Լ��� ���� �����ϱ� ������, �÷��� ���� �ڵ�� FileSystem ���ο� ���� ���� �� �ִ�.
#if PLATFORM == PS4
	static FileSystem3* instance = new PS4FileSystem;
#elif PLATFORM == NINTENDO
	static FileSystem3* instance = new NintendoFileSystem;
#endif
	return *instance;

}



class PS4FileSystem : public FileSystem3 {
public:
	virtual char* readFile(char* path) {
		//ps4 ���� IO API�� ����Ѵ�.
	}
	virtual void writeFile(char* path, char* contents) {
		//ps4 ���� IO API�� ����Ѵ�.
	}
};

class NintendoFileSystem : public FileSystem3 {
public:
	virtual char* readFile(char* path) {
		//ps4 ���� IO API�� ����Ѵ�.
	}
	virtual void writeFile(char* path, char* contents) {
		//ps4 ���� IO API�� ����Ѵ�.
	}
};

