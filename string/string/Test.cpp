#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

using namespace std;

template<class T>
class basic_string
{
private:
	T* _str;
	//···
};

//编码 -- 值 --符号建立映射关系 -- 编码表
// ASCII编码 -- 表示英文
// 
//
//typedef basic_string<char> string

int main()
{
	char str1[] = "hello";
	cout << str1 << endl;
	char str2[] = "加油";
	cout << str2 << endl;
	return 0;
}