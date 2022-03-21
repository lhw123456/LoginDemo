#if 1
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
void test01()
{
	//内建取反函数  
	negate<int>n;
	cout << n(10) << endl;

	//内建加法函数 
	plus<int>p;
	cout << p(10, 20) << endl;
}
//大于仿函数和lambda表达式  
void test02()
{
	vector<int>v{1, 2, 33, 22, 11, 10, 9, 20};
	sort(v.begin(), v.end(), greater<int>());
	for_each(v.begin(), v.end(), [](int val) {cout << val << endl; });
}
int main()
{
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
#endif