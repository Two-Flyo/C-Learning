#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>

using namespace std;
bool CheckLetter(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
		return true;
	else
		return false;
}
int main()
{
	
	char c1 = '0', c2 = 'P';
	if ((c1 == c2) || (CheckLetter(c1) && CheckLetter(c2) && abs(c1 - c2) == 32))
		cout << "==" << endl;
	//string s1("zbdxlrf~");
	//s1.push_back('A');
	//s1.append("abdcsa");
	//for (size_t i = 0; i < s1.length(); i++)
	//{
	//	cout<<s1[i];
	//}
	//for (int i = 0; i < s1.size(); i++)
	//{
	//	

	//	//cout << s1.operator[](i) << " ";
	//	//cout << s1[i]++ << " ";
	//}
	return 0;
}


//int main()
//{
//	string s1("hello lrf!\n");
//	string s2(6, 'c');
//	string s3();
//	string s4(s1);
//	return 0;
//}


//#include<iostream>
//#include<string>
//using namespace std;
//class Solution {
//public:
//	bool ChecKChar(char c)
//	{
//		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
//			return true;
//		else
//			return false;
//	}
//	bool IsEqual(char c1, char c2)
//	{
//		if ((c1 == c2) || (() && abs(c1 - c2) == 32))
//			return true;
//		else
//			return false;
//	}
//	bool isPalindrome(string s) {
//		int begin = 0, end = s.size() - 1;
//		while (begin < end)
//		{
//			while (begin < end && !ChecKChar(s[begin]))
//				begin++;
//
//			while (begin < end && !ChecKChar(s[end]))
//				end--;
//
//			if (IsEqual(s[begin], s[end]))
//				begin++, end--;
//			else
//				return false;
//		}
//		return true;
//	}
//};
//
//int main()
//{
//	string s = "0P";
//	Solution a;
//	a.isPalindrome(s);
//	return 0;
//}

//int main()
//{
//	string s1("12344321");
//	int s = stoi(s1);
//	cout << s << endl;
//	return 0;
//}
//
////int main()
//{
//	string s1;
//	int ret = 0;
//	while (cin >> s1)
//	{
//		ret = s1.size();
//	}
//	cout << ret << endl;
//	return 0;
//}
//void TestPushBack()
//{
//	string s;
//	size_t sz = s.capacity();
//	cout << "capacity init:" << sz << endl;
//	s.reserve(1010);
//	for (int i = 0; i <1000; i++)
//	{
//		s += 'c';
//		if (sz != s.capacity())
//		{
//			sz = s.capacity();
//			cout << "capacity changed:" << sz << endl;
//		}
//	}
//}

//void TestString()
//{
//	string s1;
//	s1.reserve(100);
//	string s2;
//	s2.resize(100);
//
//	string s3("hello world!");
//	s3.reserve(100);
//
//	string s4("hello world!");
//	s4.resize(5);
//	string file("test.txt");
//	
//}

//void TestString2()
//{
//	string s1("lrfnisgerfadsgfoubqaoie/sadsahddad//.asdadsadasdjasldasda");
//	size_t pos = s1.find('/');
//	if (pos != string::npos)
//	{
//		string suffix1 = s1.substr(pos,s1.size()-pos);
//		string suffix2 = s1.substr(pos);
//		cout << suffix1 << endl;
//		cout << suffix2 << endl;
//	}
//}

//void TestString()
//{
//	string s
//}
//
//int main()
//{
//	//TestPushBack();
//	//TestString2();
//	TestString3();
//	return 0;
//}

//void func(const string& s)
//{
//	string::const_reverse_iterator rit = s.rbegin();
//	while (rit != s.rend())
//	{
//		cout << *rit << ' ';
//		++rit;
//	}
//	cout << endl;
//}

//void Test_string()
//{
//	string s1("hello world!");
//	string::reverse_iterator rit = s1.rbegin();
//	while (rit != s1.rend())
//	{
//		cout << *rit << ' ';
//		++rit;
//	}
//
//	const string str("hello world");
//	func(str);
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
//}

//int main() 
//{	
//	Test_string();
//
//	return 0;
//}


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