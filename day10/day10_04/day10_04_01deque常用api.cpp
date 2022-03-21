#if 1
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;
bool myCompare(int val1, int val2)
{
	return val1 > val2;
}
void printDeque(deque<int>& d)
{
	for (auto& c : d)
	{
		cout << c << " ";
	}
	cout << endl;
}
void test01()
{
	deque<int>d{ 10,20,30,50,60 };
	sort(d.begin(), d.end(), myCompare);
	printDeque(d);

	d.pop_back();
	d.pop_front();
	printDeque(d);

	deque<int>d2{ 2,4,5,6,6,88};
	deque<int>::iterator it1 = d2.begin();
	it1 += 2;
	deque<int>::iterator it2 = d2.begin();
	it2 += 4;
	d.insert(d.begin(), it1, it2);

	//5 6 50 30 20 
	printDeque(d);
}
int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
#endif