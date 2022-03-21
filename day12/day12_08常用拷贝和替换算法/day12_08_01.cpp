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
	vector<int>v{ 2,3,4,5,6,7,8,90,12,22 };
	replace_if(v.begin(), v.end(), bind2nd(greater<int>(), 3), 200);
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}
int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
#endif