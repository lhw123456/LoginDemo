#if 1
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<functional>
#include<algorithm>
#include<iterator>
#include<string>
#include<vector>
using namespace std;
void test01()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; ++i)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	vector<int>vTarget;
	int c = v1.size() < v2.size() ? v1.size() : v2.size();
	vTarget.resize(c);
	vector<int>::iterator itEnd=set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());//返回值是指向最后一个元素的指针
	for_each(vTarget.begin(), itEnd, [](int val) {cout << val << " "; });
	cout << endl;
}
int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
#endif