#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


int main()
{
	//Ȩ�޷Ŵ�
	//const int a = 10;
	//int& b = a; //error
	//Ȩ�޲���
	const int c = 20;
	const int& d = c;
	//Ȩ����С
	int e = 30;
	const int& f = e;
	return 0;
}

//��ֵ����
//int Add(int x, int y)
//{
//	int z = x + y;
//	return z;
//}


//�����÷���
//int& Add(int x, int y)
//{
//	int z = x + y;
//	return z;
//}
//int& Count()
//{
//	static int n = 0;
//	n++;
//	//...
//	return n;
//}
//int main()
//{
//	int& ret = Add(2, 3);
//	cout << ret << endl;
//	//Add(3, 5);
//	printf("Test\n");
//	cout << ret << endl;
//	return 0;
//}



//void swap(int x, int y)//��ֵ(����ʵ�ֽ����Ĺ���)
//{
//	int tmp = x;
//	x = y;
//	y = tmp;
//}
//void swap(int* x, int* y)//����ַ
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//void swap(int& x, int& y)//������
//{
//	int tmp = x;
//	x = y;
//	y = tmp;
//}
////swap()�������أ�����swap(x,y)����ʱ��������
//int main()
//{
//	int x = 1, y = 2;
//	swap(&x, &y);
//	printf("x=%d y=%d\n", x, y);
//	//swap(x, y); swap(x,y)����ʱ��������
//	printf("x=%d y=%d\n", x, y);
//
//	return 0;
//}

//int main()
//{
//	int a = 233;
//	int& b = a;
//	printf("a=%d b=%d\n", a, b);
//
//	int& d = b;
//	int t = 123;
//	//int& c = t; error
//	int c = 111;
//	b = c;
//	printf("a=%d b=%d\n", a, c);
//	return 0;
//}

//int Add(int x, int y)
//{
//	return x + y;
//}
//double Add(double x, double y)
//{
//	return x + y;
//}
//
//int main()
//{
//	int a = Add(1, 2);
//	double b = Add(1.1212, 321.1);
//	printf("a = %d b = %lf ",a, b);
//	return 0;
//}

//void fun(int x = 23333)
//{ 
//	cout << x << endl;
//}
//void fun2(int a = 0, int b = 0, int c = 0)
//{
//	cout << a << b <<  c << endl;
//}
//void fun3(int a, int b, int c = 0)
//{
//	cout << a << b << c << endl;
//}
//void fun4(int a, int b = 0, int c = 0)
//{
//	cout << a << b << c << endl;
//}
//int main()
//{
//	//fun(233);
//	//fun();
//	//fun3(1,2);
//	//fun3(1,2,3);
//	fun4(1);
//	fun4(1, 2);
//	fun4(1, 2, 3);
//	return 0;
//}



//using namespace std;
////using std::cout;
////using std::endl;
//int main()
//{
//	cout << "hello world!" << endl;
//	printf("hello world!\n");
//	int a = 101;
//	double b = 1.1230;
//	char c = 97;
//	cout << a << b << c;
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//namespace lrf
//{
//	int rand = 233;//�����ռ���Զ������
//	int add(int x, int y)//�����ռ���Զ��庯��
//	{
//		return x + y;
//	}
//	struct s//�����ռ���Զ�������
//	{
//		int a;
//		double b;
//	};
//	namespace lrff //�����ռ�Ƕ��
//	{
//		int a = 123;
//	}
//}
//namespace lrf //ͬһ�����������������ͬ���Ƶ������ռ�
//{
//	int aa = 10;
//}
//using namespace lrf;
//using namespace lrf::lrff;
//int main()
//{
//	int rand = 3;
//	printf("%d ",rand);
//	printf("%d ",rand);
//	int ret=add(1, 3);
//	lrf::s t = { 1,12.1 };
//	printf("%d ", aa);
//	printf("%d ", rand);
//	printf("%d ", a);
//	return 0;
//}