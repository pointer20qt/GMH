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
		cout << "����ʦ��������" << endl;
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
		cout << "���˹��캯��" << endl;
		master = new principal("����ʦ");
	}
	void schoolOpen()
	{
		cout<< this->schoolName<< "ѧУ��ѧ��" << endl;
	}
	//�ݹ���ó�Ա����Ŀ������췽����������Ƕ��󣬾͸���
	school(const school &p)
	{
		this->master = new principal(p.master);
		cout <<this->schoolName<< "������copy���캯��" << endl;
	}
	~school()
	{
		delete master;
		
	}
};
//�����ᴴ����µı��������ݺʹ���Ĳ���һ��
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
	school s("��һũ�Ѵ�ѧ", "��ѧ", "����");
	school s1("����ʯ�ʹ�ѧ", "��ѧ", "����");
	swap(s,s1);
}
int main()
{
	run();
	return 0;
}     