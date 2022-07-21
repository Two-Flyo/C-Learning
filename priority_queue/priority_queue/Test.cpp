#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<functional>
#include"priority_queue.h"

using namespace std;

void test_priority_queue()
{
	priority_queue<int,vector<int>,greater<int>> pq;  //默认大堆
	pq.push(3);
	pq.push(3);
	pq.push(7);
	pq.push(1);
	pq.push(9);

	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}

	cout << endl;
}



int main()
{
	//Less->仿函数 less->函数对象
	//Less less;
	//cout << less(1, 2) << endl;

	//Greater greater;
	//cout << greater(1, 2) << endl;
	lrf::test_priority_queue();
	//Less<int> less;
	//cout << less(1, 2) << endl;
	//
	//cout << Less<int>()(1, 2) << endl;

	//cout << Less<double>()(1, 2) << endl;
	return 0;
}