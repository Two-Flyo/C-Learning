#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

using namespace std;

//����ģ��

template<class T>

T Add(const T& x1, const T& x2)
{
	return x1 + x2;
}

int main()
{
	int a = 2;
	double b = 2.333;
	//cout<<Add(a, b)<<endl; error
	cout << Add((double)a, b) << endl;

	cout << Add<int>(a, b) << endl;//ָ��Tʹ��int
	cout << Add<double>(a, b) << endl;//ָ��Tʹ��double
	return 0;
}

//template<class T>                //template<typename T> //ģ������б� --- ��������
//void Swap(T& x1, T& x2)           //���������б�  -- ��������
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
