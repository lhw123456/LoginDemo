#if 1
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;
void test01()
{
	vector<int>v{ 3,2,4,5,6,7,4,4,4,9 };
	vector<int>::iterator pos = adjacent_find(v.begin(), v.end());
	if (pos == v.end())
	{
		cout << "δ�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ��ˣ�Ԫ��Ϊ��" << *pos << endl;
	}
}
void test02()
{
	vector<int>v{ 3,2,4,5,6,7,4,4,4,9 };
	sort(v.begin(), v.end(), less<int>());
	bool ret = binary_search(v.begin(), v.end(), 3);
	if (ret == true)
	{
		cout << "�ҵ���" << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}
}
void test03()
{
	vector<int>v{ 3,2,4,5,6,7,4,4,4,9 };
	int num = count(v.begin(), v.end(), 4);
	cout << "num=" << num << endl;
}
int main()
{
	test03();
	system("pause");
	return EXIT_SUCCESS;
}
#endif