#if 1
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//vector中找到大于5的数，并返回迭代器 
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
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到了大于5的数字" << endl;
	}
}
//2.二元谓词 
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
	//for (auto c : v)   //从大到小的顺序  
	//{
	//	cout << c << endl;
	//}
	//遍历容器 
	for_each(v.begin(), v.end(), printNum);
}
int main()
{
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
#endif