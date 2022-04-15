#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

template<class T>
class basic_string
{
private:
	T* _str;
	//···
};

int main()
{
	string s1;
	cin >> s1;
	string s2("hello world!");
	string s3(s2);
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	string s4(s2, 1, 4);
	string s5("hello world!", 5);//针对的是字符数组，去字符数组的前n个字符
	cout << s4<<endl;
	cout << s5 << endl;
	return 0;
}


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