#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

using namespace std;

template<class T>
class basic_string
{
private:
	T* _str;
	//������
};

//���� -- ֵ --���Ž���ӳ���ϵ -- �����
// ASCII���� -- ��ʾӢ��
// 
//
//typedef basic_string<char> string

int main()
{
	char str1[] = "hello";
	cout << str1 << endl;
	char str2[] = "����";
	cout << str2 << endl;
	return 0;
}