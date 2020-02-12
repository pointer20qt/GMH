#include <iostream>
#include "cs.h"
#include "e.h"
#include "bash.h"
#include <iostream>
#include <climits>//定义了c语言的一些整形的范围
#include <vector>
#pragma comment(lib,"libTest.lib") //链接语句
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
	throw out_of_range("数据越界了");
}
//std::exception	该异常是所有标准 C++ 异常的父类。
//std::bad_alloc	该异常可以通过 new 抛出。
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
		cout<<e.what() << "数组越界异常" << endl;
	}
	catch ( int test)
	{
		cout << "发生了异常，异常对象" << test << endl;
	}
	catch (...)//捕获所有异常
	{
		cout << "发生了异常" << endl;	
	}
	return 0;
} 