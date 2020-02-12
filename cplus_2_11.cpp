#include <iostream>
#include <string>
using  namespace std;
struct node
{
	int a;
	int b;
};
class principal
{
	string name;
public:
	principal(string sname)
	{
		this->name = sname;
	}
	~principal()
	{
		cout << "杨老师被析构了" << endl;
	}
};
class school
{

	string schoolName;
	string address;
	string schoolTYpe;
public:
	principal *master;
	school(string schoolName, string schoolTYpe, string address){
		this->schoolName = schoolName;
		this->schoolTYpe = schoolTYpe;
		this->address = address;
		cout << "走了构造函数" << endl;
		master = new principal("杨老师");
	}
	void schoolOpen()
	{
		cout<< this->schoolName<< "学校开学了" << endl;
	}
	//递归调用成员对象的拷贝构造方法，如果不是对象，就复制
	school(const school &p)
	{
		this->master = new principal(p.master);
		cout <<this->schoolName<< "调用了copy构造函数" << endl;
	}
	~school()
	{
		delete master;
		
	}
};
//函数会创造出新的变量，内容和传入的参数一样
void swap(school a,school b)
{
	school tem = a;
	/*a = b;
	b = tem;*/

}

void swap(int a,int b)
{
	int tem = a;
	a = b;
	b = tem;
}
void run()
{
	school s("八一农垦大学", "大学", "大庆");
	school s1("东北石油大学", "大学", "大庆");
	swap(s,s1);
}
int main()
{
	run();
	return 0;
}     