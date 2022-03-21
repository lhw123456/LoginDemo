#if 1
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;
#include<vector>
class myPrint
{
public:
	int  operator()(int val)
	{
		return val;
	}
};
void test01()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; ++i)
	{
		v1.push_back(i);
	}
	v2.resize(v1.size());
	transform(v1.begin(), v1.end(), v2.begin(), myPrint());
	for_each(v2.begin(), v2.end(), [](int val) {cout << val << endl; });
}
int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
#endif