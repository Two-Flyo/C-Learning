#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

class A
{
private:
	int _a;
};

class B:public A
{
private:
	int _b;
};

class C
{

};

int main()
{

	return 0;
}

//class Person
//{
//public:
//	Person(const char* name="lrf")
//	{
//		_name = name;
//		_count++;
//	}
//	void Print()
//	{}
//	static int _count;
//
//public:
//	string _name;
//};
//
//int Person::_count = 0;
//
//class Student : virtual public Person
//{
//public:
//	Student(const char* name="lrf", int num=18)
//		:Person(name),_num(num)
//	{}
//
//	//s2(s1)
//	Student(const Student& s)
//		:Person(s),_num(s._num)
//	{}
//
//
//	Student& operator=(const Student& s)
//	{
//		if (this != &s)
//		{
//			Person::operator=(s);
//			_num = s._num;
//		}
//		return *this;
//	}
//
//	~Student()
//	{
//		Person::~Person();
//
//
//	}
//public:
//	int _num;
//};
//
//class Teacher :virtual public Person
//{
//public:
//	int _id;
//};
//
//
//
//class Graduate :public Student
//{
// protected:
//	string _SeminarCourse;
//};
//
//
//class Assistant :public Student, public Teacher
//{
//protected:
//	string _majorCourse;
//};
//
//class A
//{
//public:
//	int _a;
//};
//// class B : public A
//class B :virtual public A
//{
//public:
//	int _b;
//};
//// class C : public A
//class C :virtual public A
//{
//public:
//	int _c;
//};
//class D : public B, public C
//{
//public:
//	int _d;
//};
//int main()
//{
//	D d;
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//	cout<<sizeof(d);
//	return 0;
//}


//int main()
//{
//	Assistant a;
//	a._id = 1;
//	a._num = 1;
//
//	//a._name = "lrf";//erroe ������
//	a.Student::_name = "lrf";
//	a.Teacher::_name = "Mr.F";
//
//	a._name = "liuruifei";
//	return 0;
//}

//int main()
//{
//	Person p;
//	Student s;
//	Graduate g;
//
//	cout << Person::_count << endl;
//	cout << Student::_count << endl;
//	cout << Graduate::_count << endl;
//	return 0;
//}

//��������ĸ�Ĭ�ϳ�Ա�������ǲ�д��������Ĭ�����ɵĻ��Щʲô�����أ�
//�������ȥд��Ӧ����ôд?
//int main()
//{
//	Student s1("zhangsan");
//	Student s2(s1);
//	Student s3;
//	s3 = s2;
//		
//	return 0;
//}

//int main()
//{
//	Person p;
//	Student s;
//
//	//����=����  ��ֵ����-> �и� ��Ƭ
//	//����������ת�����﷨��Ȼ֧�ֵ���Ϊ
//	p = s;
//	Person* ptr = &s;
//	Person& ref = s;

	//���಻�ܸ�����
	//s = (Student)p;//error
	//Student* pptr = (Student*)&p;
	//Student& rref = (Student&)p;
	//��Σ�գ�����Խ�����
//	
//	return 0;
//}