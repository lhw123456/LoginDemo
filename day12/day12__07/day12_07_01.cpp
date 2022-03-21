#if 1
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<ctime>
using namespace std;
void test01()
{
	vector<int>v1{ 0,1,2,3,4,5,6,7 };
	vector<int>v2{ 8,9,10,11,12,13,14 };
	vector<int>vNew;
	vNew.resize(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vNew.begin());
	for_each(vNew.begin(), vNew.end(), [ ](int val) {cout << val << " "; });
	cout << endl;
}
void test02()
{
	srand((unsigned int)time(NULL));
	vector<int>v{ 0,1,2,3,4,5,6,7 };
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
	cout << endl;
}
void test03()
{
	vector<int>v{ 0,1,2,3,4,5,6,7 };
	reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
	cout << endl;
}
int main()
{
	test03();
	system("pause");
	return EXIT_SUCCESS;
}
#endif