#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<list>
#include"list.h"
using namespace std;

int main()
{
	lrf::test_list1();
	return 0;
}

//int main()
//{
//	list<int> lt;
//	lt.push_back(3);
//	lt.push_back(4);
//	lt.push_back(1);
//	lt.push_back(2);
//	lt.push_back(3);
//	lt.push_back(4);
//	lt.sort();
//	lt.unique();//去重之前应该先排序
//
//	list<int>::iterator it = lt.begin();
//	while (it != lt.end())
//	{
//		cout << *it << ' ';
//		++it;
//	}
//	cout << endl;
//
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	list<int>::reverse_iterator rit = lt.rbegin();
//	while (rit != lt.rend())
//	{
//		cout << *rit << ' ';
//		++rit;
//	}
//	cout << endl;
//
//	return 0;
//}