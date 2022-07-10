#define _CRT_SECURE_NO_WARNINGS
#include"vector.h"
#include<string>
using namespace std;
int main()
 {
	//test_vector();
	std::string ret = "1100";
	int sum = 0;
	for (int i = 0; i < ret.size(); i++)
	{
		sum = 10 * sum + stoi(""+ret[i]);
	}
	std::cout << sum;
	return 0;
}