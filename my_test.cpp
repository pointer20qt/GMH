#include <iostream>
#include "cs.h"
#include "e.h"
#include "bash.h"
#include <iostream>
#include <climits>//������c���Ե�һЩ���εķ�Χ
#include <vector>
#pragma comment(lib,"libTest.lib") //�������
using namespace std;
#define DEBUG 1
#ifndef  DEBUG
# error test
#endif
#if  0
#error  1024
int a;
void run();
#elif 0
int a;
void run();
#endif
#define pr(...)  printf(__VA_ARGS__);
#define max(a,b) a>b?a:b
void t()
{
	throw out_of_range("����Խ����");
}
//std::exception	���쳣�����б�׼ C++ �쳣�ĸ��ࡣ
//std::bad_alloc	���쳣����ͨ�� new �׳���
int main()
{
	vector<int> arr{ 1, 2, 3, 4, 5, 6 };
	try{
		while (1)
		{
			system("pause");
			auto p=new(nothrow) int[1024 * 1024 * 100];
			cout << p << endl;
		}
	}
	catch (bad_alloc& e)
	{
		cout << e.what() << endl;
	}
	catch (out_of_range & e)
	{
		cout<<e.what() << "����Խ���쳣" << endl;
	}
	catch ( int test)
	{
		cout << "�������쳣���쳣����" << test << endl;
	}
	catch (...)//���������쳣
	{
		cout << "�������쳣" << endl;	
	}
	return 0;
} 