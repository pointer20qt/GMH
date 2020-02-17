#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>//专门用来初始化的
#define  DEBUG//加入这个宏断言失效
#include <assert.h>//断言的头文件
#include "tool.h"
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
	int val;
	tool(){
		cout << "tool构造了" << endl;
	}
	tool(int t){
		cout << "单参数构造了,参数是t" << t << endl;
	}
	tool(const tool&){
		cout << "tool拷贝构造了" << endl;
	}
	tool(tool&&){
		cout << "tool移动构造了" << endl;
	}
	~tool(){
		cout << "tool析构了" << endl;
	}
	tool& operator = (tool&&){
		cout << "tool移动赋值了" << endl;
		return *this;
	}
	tool& operator = (const tool&){
		cout << "tool拷贝赋值了" << endl;
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
	tool *p;
	A(int v)
	{ 
		cout << "A构造函数" << endl;
		p = new tool;
		val = v;
	}
	//重载类型,需要时将A转化成其他类型
	operator int(){
		cout << "A转化了int" << endl;
		return val;
	}//使用委托构造函数时不允许别的成员初始化
	A(const A& other)
	{
		cout << "A拷贝构造函数" << endl;
		p = new tool;
	}
	A(A&& other)
	{
		p = other.p;
		other.p = nullptr;
		val = other.val;
		cout << "A移动构造" << endl;
	}
	//复制赋值运算符
	A& operator=(const A& other)
	{
		delete p;//先把原来的空间删除
		p = new tool;
		cout << "A拷贝赋值" << endl;
		return *this;	 
		
	}//移动赋值运算符
	A& operator=(A&& other)
	{
		delete p;
		p = other.p;
		other.p = nullptr;
		val = other.val;
		cout << "A移动赋值" << endl;
		return *this;
	}
	~A()
	{
		cout << "A析构函数" << endl;
		delete p;
	}
};



//栈 先入后出， Push pop,size,empty模板类可以和模板函数一样定义多个类型，也可以定义默认的，但要指明类型
template<class T> class L_stack
{
	vector<T> arr;
public: 
	void push(T&& a)
	{
		arr.push_back(a);
	}
	void pop()
	{
		arr.pop_back();
	}
	T& top()
	{
		return arr.back();
	
	}
	size_t size()

	{
		return arr.size();
	}
};
//模板参数包 拆包
void lprint(){
	cout << "输出空参" << endl;
}//递归推到出返现必须有一个参数，无无参的print所以我们手写一个供它调用
//void lprint(const char *d3)
//{
//	cout << d3 << endl;
//	lprint();
//}
//void lprint(int d2, const char *d3)
//{
//	cout << d2 << endl;
//	lprint( d3);
//}
//void lprint( double a, int d2, const char *d3)
//{
//	cout << a << endl;
//	lprint(d2, d3);
//}
//void lprint(int a,double d1,int d2,const char *d3)
//{
//	cout << a << endl;
//	lprint(d1,d2,d3);
//}
//递归拆包，用第一个变量接收arg中的第一个参数类型，没有推导出上面的函数
template<class f,class... arg> void lprint(f a,arg... d1)
{
	cout << a << endl;
	lprint(d1...);
}

template<class T> void Lswap(T& a, T& b){
	T tem = std::move(a);
	a = std::move(b);
	b = std::move(tem);
}
void swap1(A& a, A & b)
{
	//temp里是自己的p  a是a的p b是 b的p
	A tem = std::move(a);
	//a是b的p  b是b的p
	a = std::move(b);
	//b是temp的p  如果不重写=号，系统默认是浅拷贝，对temp空间二次释放了
	b = std::move(tem);
}
void run()
{//智能指针自动析构对象,也可以手动析构
	auto_ptr<tool> t;
	tool *p = new tool;
	L_autoptr<tool> ptr(p);
	L_autoptr<tool> ptr2(ptr);
	L_autoptr<tool> ptr3;
	ptr3 = ptr2;
	//ptr.reset(p);//释放之前指针,指向新指针
	//ptr.release();//将内部存的指针返回
	//delete ptr.release();//手动释放
	ptr3->val = 5;//可以想指针一样使用
	cout << "run结束了" << endl;
}

int main()
{//智能指针，管理一个对象，能够管理一个对象释放。
	run();
	return 0;
}


