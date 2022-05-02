#include"string.h"

using namespace lrf;


int main()
{
	string s1("lrf233!");
	s1.push_back(' ');
	s1.push_back('$');
	s1.append("fighting!");
	string s2;
	s2 += 'x';
	s2 += "123 233";
	s2.insert(0,"lrff");
	s2.erase(2);
	//cout << s1 << endl;

	/*string s1("lrfhhh");
	string s2(s1);
	string s3;
	s3 = s2;*/

	//string::iterator it = s1.begin();
	//while (it != s1.end())
	//{
	//	*it += 1;
	//	++it;
	//}
	//it = s1.begin();
	//while (it != s1.end())
	//{
	//	cout << *it << ' ';
	//	++it;
	//}
	////编译时被替换为迭代器
	//for (auto x : s1)
	//{
	//	cout << x << ' ';
	//}


	//string s2(s1);
	//string s3("2333");
	//s3 = s1;
	//string s4;
	//cout << s1.c_str() << endl;
	//for (int i = 0; i < s1.size(); i++)
	//{
	//	cout << s1[i] << endl;
	//}
	return 0;
}