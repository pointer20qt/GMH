#include <iostream>
#include <string>
#include <initializer_list>//专门用来初始化的
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
	string schoolName;
	string address;
	string schoolTYpe;
public:
	school(string schoolName, string schoolTYpe, string address){
		this->schoolName = schoolName;
		this->schoolTYpe = schoolTYpe;
		this->address = address;
		cout << schoolName << "走了构造函数" << endl;
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
class vec
{
	int* arg;
public:
	vec(std::initializer_list<int> arr)
	{
		arg = new int[sizeof(arr)];
	/*	for (auto i = arr.begin(); i !=arr.end() ; i++)
		{
			cout << *i << endl;
		}*/
		for (int i = 0; i < arr.size(); i++)
		{
			//cout<<"第"<<i+1<<"个"<< *(arr.begin()+i)<< endl;
			arg[i] = *(arr.begin() + i);
		}
	}
	int& operator[](unsigned int index)	{
		return arg[index];
	}
};
int main()
{
	vec v({ 1, 2, 3, 4, 5, 6 });
	cout << v[2] << endl;
	v[2] = 8;
	cout << v[2] << endl;
	vec v1{ 1, 2, 3, 4, 5, 6 };
	system("pause");
}
/*class complex
{
	int real;
	int vir;
public:
	complex(int real,int vir):real(real),vir(vir){
}
	complex operator+(complex & x)
	{
		real += x.real;
		vir += x.vir;
		return complex(real,vir);
	}
	std::string toString()
	{
		char buff[50];
		sprintf(buff,"(%d+%di)",real,vir);
		return string(buff);
	}
};   */  