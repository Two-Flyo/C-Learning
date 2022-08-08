#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<set>

using namespace std;

void test_set1()
{
	set<int> s;//����+ȥ��
	s.insert(3);
	s.insert(1);
	s.insert(5);
	s.insert(2);
	s.insert(8);
	s.insert(1);
	s.insert(8);

	//set<int>::iterator it = s.begin();
	auto it = s.begin();
	while (it!=s.end())
	{
		cout << *it << endl;
		++it;
	}

	set<int>::iterator pos = s.find(3);
	if (pos != s.end())
	{
		s.erase(pos);//pos��������Чλ�õĵ�����
	}
	s.erase(30);//30��
	for (auto e : s)
	{
		cout << e << endl;
	}
}

void test_multiset()
{
	multiset<int> s; //����
	s.insert(3);
	s.insert(1);
	s.insert(5);
	s.insert(2);
	s.insert(8);
	s.insert(1);
	s.insert(8);

	//set<int>::iterator it = s.begin();
	auto it = s.begin();
	while (it != s.end())
	{
		cout << *it << endl;
		++it;
	}

	auto pos = s.find(3);
	if (pos != s.end())
	{
		s.erase(pos);//pos��������Чλ�õĵ�����
	}
	for (auto e : s)
	{
		cout << e << endl;
	}
}

int main()
{
	//test_set1();
	test_multiset();

	return 0;
}