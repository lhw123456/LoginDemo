#if 1
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//vector���ҵ�����5�����������ص����� 
class myCompare
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};
void test01()
{
	vector<int>v{ 1,22,31,45,5 };
	vector<int>::iterator pos=find_if(v.begin(), v.end(), myCompare());
	if (pos== v.end())
	{
		cout << "δ�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ��˴���5������" << endl;
	}
}
//2.��Ԫν�� 
class compareTwoNum
{
public:
	bool operator()(int val1, int val2)
	{
		return val1 > val2;
	}
};
void printNum(int val)
{
	cout << val << endl;
}
void test02()
{
	vector<int>v{ 20,30,10,19,28,18,12 };
	sort(v.begin(), v.end(), compareTwoNum());
	//for (auto c : v)   //�Ӵ�С��˳��  
	//{
	//	cout << c << endl;
	//}
	//�������� 
	for_each(v.begin(), v.end(), printNum);
}
int main()
{
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
#endif