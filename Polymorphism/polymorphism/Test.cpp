#include <iostream>

using namespace std;


//�����������麯��,�Ƿ񹹳���д? -- ����!!!
class Person
{
public:
	virtual ~Person() { cout << "~Person()" << endl; }
};

class Student :public Person
{
public:
	virtual ~Student() { cout << "~Student()" << endl; }
};

//class Person
//{
//public:
//	//Э��
//	virtual Person* BuyTicket() { cout << "����Ʊ" << endl;  return nullptr; }
//};
//
//class Student :public Person
//{
//public:
//	//����������ͬ(������ ���� ����ֵ)���麯��
//	//Э��
//	virtual Student* BuyTicket() { cout << "ѧ��Ʊ" << endl; return nullptr; }
//};
//
//void fun(Person& s)
//{
//	s.BuyTicket();
//}
//
//int main()
//{
//	//��̬��̬:��������,������ͬһ�������в�ͬ����Ϊ
//	// ��̬:����ʱ
//	//��̬��̬:һ����������û���ָ��ȥ����ͬһ������,���ݲ�ͬ�Ķ���,����ò�ͬ�ĺ���
//	//��̬:����ʱ
//	Person p;
//	Student s;
//	fun(p);
//	fun(s);
//	//p.BuyTicket();
//	//s.BuyTicket();
//	return 0;
//}