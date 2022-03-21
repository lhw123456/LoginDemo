#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
using namespace std;
//º¯Êý¶ÔÏó 
class myPrint
{
public:
      void operator()(string text)
	{
		cout << text << endl;
		++m_Count;
	}
	int m_Count=0;
};
void test01()
{
	myPrint mp;
	//mp.m_Count = 0;
	mp("hello");
	mp("hello");
	mp("hello");
	mp("hello");
	mp("hello");
	cout << "mp.m_Count=" << mp.m_Count << endl;
}
void test02()
{
	myPrint()("hello");
}
int main()
{
	test02();
	system("pause");
	return EXIT_SUCCESS;
}