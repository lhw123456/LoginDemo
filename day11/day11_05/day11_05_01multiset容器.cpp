#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<set>
using namespace std;
class  myCompare
{
public:
	bool operator()(int val1, int val2) const 
	{
		return val1 > val2;
	}
};
void test01()
{
	multiset<int,myCompare>mult;
	mult.insert(10);
	mult.insert(10);
	mult.insert(20);
	mult.insert(30);
	mult.insert(40);
	for (auto c : mult)
	{
		cout << c << " ";
	}
	cout << endl;
}
int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
#endif