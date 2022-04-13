#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

using namespace std;

template<class T>
class A
{
public:
	A(T a,T b)
	:_a(a),
	_b(b)
	{

	}

private:
	T _a;
	T _b; 
};

int main()
{
	A<int> a1(1, 3);
	A<double> a2(1, 3);
	return 0;
}


////函数模板
//template<class T>
//T Add(const T& x1, const T& x2)
//{
//	return x1 + x2;
//}
//
//int main()
//{
//	int a = 2;
//	double b = 2.333;
//	//cout<<Add(a, b)<<endl; error
//	cout << Add((double)a, b) << endl;
//	
//	//显式实例化
//	cout << Add<int>(a, b) << endl;//指定T使用int
//	cout << Add<double>(a, b) << endl;//指定T使用double
//	return 0;
//}

//template<class T>                //template<typename T> //模板参数列表 --- 参数类型
//void Swap(T& x1, T& x2)           //函数参数列表  -- 参数类型
//{
//	T x = x1;
//	x1 = x2;
//	x2 = x;
//}
//int main()
//{
//	int a = 2, b = 3;
//	double c = 2.3, d = 3.2;
//	Swap(a, b);
//	Swap(c, d);
//	return 0;
//}
