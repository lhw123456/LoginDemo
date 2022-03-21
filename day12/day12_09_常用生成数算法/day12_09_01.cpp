#if 1
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<numeric>
#include<vector>
using namespace std;
void test01()
{
	vector<int>v;
	for (int i = 0; i <= 100; ++i)
	{
		v.push_back(i);
	}
	int num = accumulate(v.begin(), v.end(),0);
	cout << "num=" << num << endl;
}
void test02()
{
	vector<int>v;
	v.resize(10);
	fill(v.begin(), v.end(), 20);
	for(auto c:v)
	{
		cout << c << " ";
	}
	cout << endl;
}
int main()
{
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
#endif