#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>//ר��������ʼ����
#define  DEBUG//������������ʧЧ
#include <assert.h>//���Ե�ͷ�ļ�
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
		cout << "����ʦ��������" << endl;
	}
};
//ʵ�ֶ�̬ʵ��������ʵ������
class school
{
protected:
	string schoolName="Ĭ��ѧУ��";
	string address="��ѧ";
	string schoolTYpe="ѧУ";
public:
	school(string schoolName, string schoolTYpe, string address){
		this->schoolName = schoolName;
		this->schoolTYpe = schoolTYpe;
		this->address = address;
		cout << schoolName << "���˹��캯��" << endl;
	}
	school(string schoolName):school(schoolName,"ָ��","��ѵ"){
	

	}
	school()
	{
		cout << "����ѧУ�޲ι��캯��" << endl;
	}
	virtual void schoolOpen()
	{
		cout<< this->schoolName<< "����ѧУ��ѧ��" << endl;
	}
	//�ݹ���ó�Ա����Ŀ������췽����������Ƕ��󣬾͸���
	school(const school &p) :schoolName(p.schoolName), schoolTYpe(p.schoolTYpe), address(p.address)
	{
		//this->a = p.a;
		cout <<schoolName<< "��������˿������캯��" << endl;
	}
	//���Ĭ���ƶ�����Ϳ������칦����ͬ
	school(school&& p) :schoolName(p.schoolName), schoolTYpe(p.schoolTYpe), address(p.address)
	{
		cout << schoolName << "����������ƶ����캯��" << endl;
	}
	virtual ~school()
	{
		cout << this->schoolName << "ѧУ������������" << endl;		
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
	principal *v_p=new principal("����ʦ");
	college() {
		cout << "���컨���׶�԰��ѧ��" << endl;
	}
	//������ķ���
	void learn()
	{
		cout << "��ѧ����ѧϰ" << endl;
	}
	void schoolOpen()
	{
		cout << "���ഺ�ﻨ������԰��ѧ��" << endl;
	}

	~college()
	{
		delete v_p;
		cout << "��ѧ���౻������" << endl;
	}
};
class tool{
public:
	tool()
	{
		cout << "�޲����Ĺ��캯��" << endl;
	}
	tool(int t)
	{
		cout<<"����"<<t<< "�Ĺ��캯��" << endl;
	}
	~tool()
	{
		cout << "��������" << endl;
	}
	tool(const tool & t)
	{
		cout << "�������캯��" << endl;
	} 
	tool(tool && t)
	{
		cout << "�ƶ����캯��" << endl;
	}
	tool& operator=(const tool& t)
	{
		cout << "������ֵ��" << endl;
		return *this;
	}
	tool& operator=( tool&& t)
	{
		cout << "�ƶ���ֵ��" << endl;
		return *this;
	}
};
//��̬���Բ������������Ļ�
static_assert (sizeof(int) != 32, "not windows");
class vec{
public:
	vector<int>  arr;
	vec(initializer_list<int> list) :arr(list){
	}
	int& operator[](int dex){
		assert(2);
		//assert(dex >= 0 && dex < arr.size());//�ڳ��������ڼ��жϳ����Ƿ�����⣬�����������������ԣ�����д�������,����ʵ�ʾ��Ǵ���int��0�ͱ�����1�Ͳ��ᱨ��
		//assert(dex >= 0);
		return arr[dex];
	}
};
//����ģ��,ģ����Ԥ����չ����ͬ�ĺ��������������Լ����ڴ����Ƶ�������
//���Զ��峣�������峣��dʱ,������ģ���Ƶ�ʱ��������ֵ
//�����ڶ��������һ��Ĭ�϶���ֵ��T3����ģ���Ƶ�ʱ��T3��λ��Ĭ�Ͼ���intֵ
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
		cout << "���캯��" << endl;
		p = new char[100];
		val = v;
	}
	//��������,��Ҫʱ��Aת������������
	operator int(){
		cout << "Aת����int" << endl;
		return val;
	}//ʹ��ί�й��캯��ʱ�������ĳ�Ա��ʼ��
	A(const A& other)
	{
		cout << "�������캯��" << endl;
		p = new char[100];
	}
	A& operator=(const A& other)
	{
		delete p;//�Ȱ�ԭ���Ŀռ�ɾ��
		p = new char[100];
		return *this;	 
	}
	~A()
	{
		cout << "��������" << endl;
		delete p;
	}
};
template<class T> void swap1(T& a, T& b)
{
	//temp�����Լ���p  a��a��p b�� b��p
	A tem(a);
	//a��b��p  b��b��p
	a = b;
	//b��temp��p  �������д=�ţ�ϵͳĬ����ǳ��������temp�ռ�����ͷ���
	b = tem;		
}

//ջ �������� Push pop,size,emptyģ������Ժ�ģ�庯��һ�����������ͣ�Ҳ���Զ���Ĭ�ϵģ���Ҫָ������
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
//ģ������� ���
void lprint(){
	cout << "����ղ�" << endl;
}//�ݹ��Ƶ������ֱ�����һ�����������޲ε�print����������дһ����������
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
//�ݹ������õ�һ����������arg�еĵ�һ���������ͣ�û���Ƶ�������ĺ���
template<class f,class... arg> void lprint(f a,arg... d1)
{
	cout << a << endl;
	lprint(d1...);
}
int main()
{
	//��Ϊ�������int����T����int����
	/*L_stack<int> l;
	l.push(5);
	l.push(6);
	l.push(7);
	cout << l.top() << endl;
	l.pop();
	cout << l.top() << endl;
	cout << l.size() << endl;*/
	lprint(1,2.0,3,"123");
	return 0;
}



