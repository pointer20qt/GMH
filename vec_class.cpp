#include <iostream>
#include <string>
#include <initializer_list>//ר��������ʼ����
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
	string schoolName;
	string address;
	string schoolTYpe;
public:
	school(string schoolName, string schoolTYpe, string address){
		this->schoolName = schoolName;
		this->schoolTYpe = schoolTYpe;
		this->address = address;
		cout << schoolName << "���˹��캯��" << endl;
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
			//cout<<"��"<<i+1<<"��"<< *(arr.begin()+i)<< endl;
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