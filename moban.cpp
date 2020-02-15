#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>//专门用来初始化的
#define  DEBUG//加入这个宏断言失效
#include <assert.h>//断言的头文件
using  namespace std;
using  I = int;
typedef void(*F) (int, const std::string &);
using F = void(*)(int, const std::string &);

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
//实现多态实现虚析构实现隐藏
class school
{
protected:
	string schoolName="默认学校名";
	string address="大学";
	string schoolTYpe="学校";
public:
	school(string schoolName, string schoolTYpe, string address){
		this->schoolName = schoolName;
		this->schoolTYpe = schoolTYpe;
		this->address = address;
		cout << schoolName << "走了构造函数" << endl;
	}
	school(string schoolName):school(schoolName,"指针","培训"){
	

	}
	school()
	{
		cout << "父类学校无参构造函数" << endl;
	}
	virtual void schoolOpen()
	{
		cout<< this->schoolName<< "父类学校开学了" << endl;
	}
	//递归调用成员对象的拷贝构造方法，如果不是对象，就复制
	school(const school &p) :schoolName(p.schoolName), schoolTYpe(p.schoolTYpe), address(p.address)
	{
		//this->a = p.a;
		cout <<schoolName<< "父类调用了拷贝构造函数" << endl;
	}
	//类的默认移动构造和拷贝构造功能相同
	school(school&& p) :schoolName(p.schoolName), schoolTYpe(p.schoolTYpe), address(p.address)
	{
		cout << schoolName << "父类调用了移动构造函数" << endl;
	}
	virtual ~school()
	{
		cout << this->schoolName << "学校父类析构函数" << endl;		
	}
};
class student{
public:
	virtual void learn() = 0;
};
class college : public school,public student
{
	int b;
public:
	principal *v_p=new principal("朱老师");
	college() {
		cout << "春天花花幼儿园开学了" << endl;
	}
	//纯虚类的方法
	void learn()
	{
		cout << "大学生在学习" << endl;
	}
	void schoolOpen()
	{
		cout << "子类春田花花幼稚园开学了" << endl;
	}

	~college()
	{
		delete v_p;
		cout << "大学子类被析构了" << endl;
	}
};
class tool{
public:
	tool()
	{
		cout << "无参数的构造函数" << endl;
	}
	tool(int t)
	{
		cout<<"参数"<<t<< "的构造函数" << endl;
	}
	~tool()
	{
		cout << "析构函数" << endl;
	}
	tool(const tool & t)
	{
		cout << "拷贝构造函数" << endl;
	} 
	tool(tool && t)
	{
		cout << "移动构造函数" << endl;
	}
	tool& operator=(const tool& t)
	{
		cout << "拷贝赋值了" << endl;
		return *this;
	}
	tool& operator=( tool&& t)
	{
		cout << "移动赋值了" << endl;
		return *this;
	}
};
//静态断言不成立输出后面的话
static_assert (sizeof(int) != 32, "not windows");
class vec{
public:
	vector<int>  arr;
	vec(initializer_list<int> list) :arr(list){
	}
	int& operator[](int dex){
		assert(2);
		//assert(dex >= 0 && dex < arr.size());//在程序运行期间判断程序是否出问题，不满足条件引发断言，可以写多个断言,断言实际就是传个int是0就报错是1就不会报错
		//assert(dex >= 0);
		return arr[dex];
	}
};
//函数模板,模板在预处理展开不同的函数，根据类型自己在内存中推导出函数
//可以定义常量，定义常量d时,必须在模板推倒时给常量赋值
//可以在定义给类型一个默认定义值如T3，在模板推到时，T3的位置默认就是int值
template<int d, class T, class T2, class T3 = int> T Lmax(T a, T2 b)
{
	cout << d << endl;
	int arr[d];
	return a > b ? a : b;
}
class A{
public:
	int val;
	char *p;
	A(int v)
	{ 
		cout << "构造函数" << endl;
		p = new char[100];
		val = v;
	}
	//重载类型,需要时将A转化成其他类型
	operator int(){
		cout << "A转化了int" << endl;
		return val;
	}//使用委托构造函数时不允许别的成员初始化
	A(const A& other)
	{
		cout << "拷贝构造函数" << endl;
		p = new char[100];
	}
	A& operator=(const A& other)
	{
		delete p;//先把原来的空间删除
		p = new char[100];
		return *this;	 
	}
	~A()
	{
		cout << "析构函数" << endl;
		delete p;
	}
};
template<class T> void swap1(T& a, T& b)
{
	//temp里是自己的p  a是a的p b是 b的p
	A tem(a);
	a = b;
	b = tem;		
}

int main()
{
	int x = 5,	x1 = 6;
	double d = 2.3, d1 = 3.6;
	A a1(25), a2(31);
	swap1(a1, a2);
	//编译器发现A类型可以转化成int类型就将他转化所以不会报错
	cout << a1 << "交换" << a2 << endl;
	return 0;
}
//隐式推导，如果有默认的函数和模板函数类似，在隐式推到时候将优先调用写好的函数。
//cout << Lmax<2>(x, d1) << endl;
//显示推导
//cout << Lmax<2, int, double>(x, x1) << endl;
//显示指定模板 必须使用模板推导的函数，不能使用非模板的函数
//cout << Lmax<2>(d, x) << endl;

//cout << a << " " << b << endl;
