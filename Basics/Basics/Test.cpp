#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

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
//	int rand = 233;//命名空间可以定义变量
//	int add(int x, int y)//命名空间可以定义函数
//	{
//		return x + y;
//	}
//	struct s//命名空间可以定义类型
//	{
//		int a;
//		double b;
//	};
//	namespace lrff //命名空间嵌套
//	{
//		int a = 123;
//	}
//}
//namespace lrf //同一个工程中允许存在相同名称的命名空间
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