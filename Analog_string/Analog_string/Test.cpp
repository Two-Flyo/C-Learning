#include"string.h"

using namespace lrf;
using std::cout;
using std::endl;

int main()
{
	string s1("lrfhhh");

	string::iterator it = s1.begin();
	while (it != s1.end())
	{
		*it += 1;
		++it;
	}
	it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << ' ';
		++it;
	}
	//编译时被替换为迭代器
	for (auto x : s1)
	{
		cout << x << ' ';
	}



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