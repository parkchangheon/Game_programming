#include<vector>
#include<iostream>
#include<chrono>
#include<thread>
#include<memory>
#include<mutex>
using namespace std;

const int MaxCount = 15000;
const int ThreadCount = 4;

// �켱 �̱� ������ ������� ó���غ�
// Single Thread First

bool IsPrimeNumber(int num)
{
	if (num == 1)
		return false;

	else if (num == 2 || num == 3)
		return true;

	for (int i = 2; i < num-1; i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}


void PrintPrimeNumber(const vector<int>& numbers)
{
	for (auto i : numbers)
		cout << i << " ";
}

//�̱۽�����(SingleTHread)
//int main()
//{
//	vector<int> primes;
//	auto t0 = chrono::system_clock::now(); // �Լ��� ���� ���� �ð� ����
//
//	for (int i = 0; i <= MaxCount; i++)
//	{
//		if (IsPrimeNumber(i))
//		{
//			primes.push_back(i);
//		}
//	}
//
//	auto t1 = chrono::system_clock::now();
//	auto duration = chrono::duration_cast<chrono::milliseconds>(t1 - t0).count();
//	cout << "Took" << duration << " miliseconds" << endl;
//	PrintPrimeNumber(primes);
//}



//Use Multi Thread ==>error has pop up

void MutexEx0()
{
	int num = 1;
	vector<int> primes;

	auto t0 = chrono::system_clock::now();
	vector<shared_ptr<thread>>threads;

	for (int i = 0; i < ThreadCount; i++)
	{
		shared_ptr<thread> thread(new thread([&]() {

			//�� �������� ���� �Լ�
			//���� ������ �� ������ ������ ����.

			while (true)
			{
				int n;
				n = num;
				num++;

				if (n >= MaxCount) break;

				if (IsPrimeNumber(n))
				{
					primes.push_back(n);
				}

			}
		}));
		//������ ��ü�� �ϴ� ���´�.
		threads.push_back(thread);
	}

	for (auto thread : threads)
		thread->join();


	auto t1 = chrono::system_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(t1 - t0).count();
	cout << "Took" << duration << " miliseconds" << endl;
	PrintPrimeNumber(primes);

}


//�׷��� race condition ������ ������ �� �ִ�.
/*
���� ������/���μ����� ���� �ڿ��� ���ÿ� �����Ϸ� �Ҷ� �Ͼ�� �����Ȳ
�׷���, ���ý�Ʈ ����Ī�� �����ϰ� �Ͼ�� �ʴ´�.
�׷��� ��� ���� �޶��� �� �ִ�.
*/


//�̰��� �ذ��ϱ� ���� ����� �Ӱ迵�� - ���ý��̴�.
/*
1. x,y�� ��ȣ�ϴ� ���ؽ� MX�� ����
2. ������� x,y�� �ǵ帮�� ���� MX�� ������ ��û
3. ������� x,y�� �׼��� �Ѵ�.
4. �׼����� ������ MX�� ������ ���°��� ��û
*/

void MutexEx()
{
	std::mutex mx;
	mx.lock();  //���⼭ ������ ȹ���ϸ� ���� �ܰ�� �Ѿ��.

	//read(x); ==> ���� ���⼭ throw�� �ϸ� �Ʒ� �κ��� ������ �Ұ����ϴ�, try-catch�� ���⵵�ϴµ�, �ʹ� ������. ==>���� ���� �ı���, �ڵ� unlock���ְ� �غ���
	//write(y);
	//sum(x); ==> ��� �ܰ�

	mx.unlock(); // ������ �����ش�.
}



void MutexEx2()
{
	std::recursive_mutex mx;
	lock_guard<recursive_mutex> lock(mx); //lock ��ü�� ������� �ڵ����� unlock�� ����ȴ�.
	//read(x);
	//write(x);
	//sum(x);

}



// mutex�� Ȱ���� multithreading code

int main() {
	int num = 1;
	recursive_mutex num_mutex; //�Ϲ� mutex���� ������� �������� ����.

	vector<int>primes;
	recursive_mutex primes_mutex;

	auto t0 = chrono::system_clock::now();

	vector<shared_ptr<thread>> threads;
	
	for (int i = 0; i < ThreadCount; i++)
	{
		shared_ptr<thread> thread(new thread([&]() {
			while (true)
			{
				int n;
				{
					lock_guard<recursive_mutex> num_lock(num_mutex);
					n = num;
					num++;
				}

				if (n >= MaxCount) break;

				if (IsPrimeNumber(n))
				{
					lock_guard<recursive_mutex> primes_lock(primes_mutex);
					primes.push_back(n);
				}
			}
		}));

		threads.push_back(thread);
	}

	for (auto thread : threads)
	{
		thread->join();
	}

	auto t1 = chrono::system_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(t1 - t0).count();
	cout << "Took" << duration << " miliseconds" << endl;
	PrintPrimeNumber(primes);

}


// ������ �ϳ��ϋ��� ������ 4���϶��� �ҿ� �Ǵ� �ð��� 4�� �پ������ ����
// cpu�� ������������, �ᱹ cpu�� �޸𸮿� �����ϰԵȴ�.
// �׷��ٸ� ���ؽ��� �߰� ������ ���� ���� �ʳ� �����ٵ� 
// ������ ���α׷� ������ ��������. => �׼��� ������ ���̱⶧��.
// ���� ���α׷��� �ſ� ����������. (�������� ���� �߻� ����)



