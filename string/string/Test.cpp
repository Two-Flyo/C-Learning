#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

void func(const string& s)
{
	string::const_reverse_iterator rit = s.rbegin();
	while (rit != s.rend())
	{
		cout << *rit << ' ';
		++rit;
	}
	cout << endl;
}

void Test_string()
{
	string s1("hello world!");
	string::reverse_iterator rit = s1.rbegin();
	while (rit != s1.rend())
	{
		cout << *rit << ' ';
		++rit;
	}

	const string str("hello world");
	func(str);
	//遍历+修改
	//(1)下标+[]
	//for (size_t i = 0; i < s1.size(); i++)
	//{
	//	s1[i] += 1;
	//}
	//for (size_t i=0;i<s1.size();i++)
	//{
	//	cout << s1[i] << " ";
	//}
	//(2)迭代器
	//string::iterator it = s1.begin();
	//while (it != s1.end())
	//{
	//	cout << *it << " ";
	//	++it;
	//}
	//cout << endl;
	//(3)范围for
	//for (auto& e : s1)
	//{
	//	e++;
	//	cout << e << ' ';
	//}
	//cout << endl;
	//for (auto e : s1)
	//{
	//	cout << e << ' ';
	//}
}

int main() 
{	
	Test_string();

	return 0;
}


//int main()
//{
//	string s1;
//	s1.push_back('a');
//	s1.append("bcdef");
//	cout << s1 << endl;
//	s1 += ' ';
//	s1 += "hijklmn";
//	cout << s1 << endl;
//	return 0;
//}

//int main()
//{
//	string s1("hello~world!");
//	for (size_t i = 0; i < s1.size(); i++)
//	{
//		cout << s1.operator[](i);
//		cout << s1[i];
//	}
//	for (size_t i = 0; i < s1.size(); i++)
//	{
//		s1[i] += 1;
//	}
//	cout << s1 << endl;
//
//	for (size_t i = 0; i < s1.size(); i++)
//	{
//		s1.at(i) -= 1;
//	}
//	cout << s1 << endl;
//	return 0;
//}

//int main()
//{
//	string s1;
//	cin >> s1;
//	cout << s1.size() << endl;
//	cout << s1.length() << endl;
//	cout << s1.capacity() << endl;
//	return 0;
//}

//template<class T>
//class basic_string
//{
//private:
//	T* _str;
//	//···
//};
//
//int main()
//{
//	string s1;
//	cin >> s1;
//	string s2("hello world!");
//	string s3(s2);
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << s3 << endl;
//	string s4(s2, 1, 4);
//	string s5("hello world!", 5);//针对的是字符数组，去字符数组的前n个字符
//	cout << s4<<endl;
//	cout << s5 << endl;
//	return 0;
//}


//编码 -- 值 --符号建立映射关系 -- 编码表
// ASCII编码 -- 表示英文
// 
//
//typedef basic_string<char> string

//int main()
//{
//	char str1[] = "hello";
//	cout << str1 << endl;
//	char str2[] = "加油";
//	cout << str2 << endl;
//	return 0;
//}