#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>


using namespace std;

//void test_map()
//{
//	map<string, string> dict; 
//	pair<string, string> kv1("lrf","�����");
//	dict.insert(kv1);
//	dict.insert(pair<string, string>("lh", "�"));
//	//make_pair�Զ��Ƶ�����
//	dict.insert(make_pair("test", "����"));
//
//
//	auto it = dict.begin();
//	while (it!=dict.end())
//	{
//		cout << (*it).first << ":" << (*it).second << endl;
//		cout << it->first << ":" << it->second << endl;
//		++it;
//	}
//
//
//
//	for (auto& kv : dict)
//	{
//		cout << kv.first << ":" << kv.second << endl;
//	}
//		
//}

//void test_map2()
//{
//	string arr[] = { "ƻ��","�㽶","ƻ��","�㽶","ƻ��","����","����","����" };
//	map<string, int> countMap;
//
//	for (auto& str : arr)
//	{
//		countMap[str]++;
//	}
	//for (auto& str : arr)
	//{
	//	auto ret = countMap.find(str);
	//	if (ret == countMap.end())
	//	{
	//		countMap.insert(make_pair(str, 1));
	//	}
	//	else
	//	{
	//		ret->second++;
	//	}
	//}
	//for (auto& str : arr)
	//{
	//	//insert�ķ���ֵ���
	//	auto kv = countMap.insert(make_pair(str, 1));
	//	if (kv.second == false)
	//	{
	//		kv.first->second++;
	//	}
	//}

//	for (auto& kv : countMap)
//	{
//		cout << kv.first << ":" << kv.second << endl;
//	}
//}


//void test_map3()
//{
//	map<string, string> dict;
//	dict.insert(make_pair("sort", "����"));
//	dict.insert(make_pair("left", "���"));
//	dict.insert(make_pair("left", "ʣ��"));
//	dict["left"] = "ʣ��";
//	dict["test"]="����";
//	cout << dict["sort"] << endl;
//	cout << dict["left"] << endl;
//	cout << dict["test"] << endl;
//}



void test_multimap()
{
	multimap<string, string> dict;
	dict.insert(make_pair("sort", "����"));
	dict.insert(make_pair("test", "����"));

	for (auto& kv : dict)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
}

struct CountVal
{
	bool operator()(const pair<string, int>& x, const pair<string, int>& y)
	{
		return x.second < y.second;
	}
};
struct CountIteratorVal
{
	bool operator()(const map<string, int>::iterator& x, const map<string, int>::iterator& y)
	{
		return x->second < y->second;
	}
};


//ͳ����ϲ����ǰK��ˮ��
void GetFavoriteFruit(const vector<string>& fruits, size_t k)
{

	map<string, int> countMap;
	for (auto& str : fruits)
	{
		countMap[str]++;
	}
	//multimap<int, string,greater<int>> sortMap;
	//for (auto& kv : countMap)
	//{
	//	sortMap.insert(make_pair(kv.second, kv.first));
	//}
	//for (auto e : sortMap)
	//{
	//	cout << e.second << ":" << e.first << endl;
	//}

	priority_queue<map<string, int>::iterator, vector<map<string, int>::iterator>, CountIteratorVal> pq;
	auto it = countMap.begin();
	while (it!=countMap.end())
	{
		pq.push(it);
		++it;
	}
	while (k--)
	{
		cout<< pq.top()->first << ":" << pq.top()->second << endl;
		pq.pop();
	}


	//priority_queue<pair<string, int>, vector<pair<string, int>>, CountVal> pq;
	//for (auto& kv : countMap)
	//{
	//	pq.push(kv);
	//}

	//while (k--)
	//{
	//	cout << pq.top().first << ":" << pq.top().second << endl;
	//	pq.pop();
	//}

	//����������  :����
	//sort
	//multimap
	//vector<pair<string, int>> sortV;
	//for (auto& kv : countMap)
	//{
	//	sortV.push_back(kv);
	//}
	
	//vector<map<string, int>::iterator> sortV;
	//auto it = countMap.begin();
	//while (it!=countMap.end())
	//{
	//	sortV.push_back(it);
	//	++it;
	//}

	////ʵ��һ���º���
	//sort(sortV.begin(), sortV.end(),CountIteratorVal() );
	//for (int i = 0; i < k; i++)
	//{
	//	cout << sortV[i]->first << ":" << sortV[i]->second << endl;
	//}

}

int main()
{
	vector<string> arr = { "ƻ��","�㽶","ƻ��","�㽶","ƻ��","����","����","����" };
	GetFavoriteFruit(arr,4);
}

//void test_set1()
//{
//	set<int> s;//����+ȥ��
//	s.insert(3);
//	s.insert(1);
//	s.insert(5);
//	s.insert(2);
//	s.insert(8);
//	s.insert(1);
//	s.insert(8);
//
//	//set<int>::iterator it = s.begin();
//	auto it = s.begin();
//	while (it!=s.end())
//	{
//		cout << *it << endl;
//		++it;
//	}
//
//	set<int>::iterator pos = s.find(3);
//	if (pos != s.end())
//	{
//		s.erase(pos);//pos��������Чλ�õĵ�����
//	}
//	s.erase(30);//30��
//	for (auto e : s)
//	{
//		cout << e << endl;
//	}
//}
//
//void test_multiset()
//{
//	multiset<int> s; //����
//	s.insert(3);
//	s.insert(1);
//	s.insert(5);
//	s.insert(2);
//	s.insert(8);
//	s.insert(1);
//	s.insert(8);
//
//	//set<int>::iterator it = s.begin();
//	auto it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << endl;
//		++it;
//	}
//
//	auto pos = s.find(3);
//	if (pos != s.end())
//	{
//		s.erase(pos);//pos��������Чλ�õĵ�����
//	}
//	for (auto e : s)
//	{
//		cout << e << endl;
//	}
//}
//
//int main()
//{
//	//test_set1();
//	test_multiset();
//
//	return 0;
//}