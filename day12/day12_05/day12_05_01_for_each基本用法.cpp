#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	for_each(param beg,param end,para _callback)
	遍历算法 遍历容器元素
	@param beg 开始迭代器
	@param end 结束迭代器
	@param _callback  函数回调或者函数对象
	@return 函数对象
*/

//1.for_each有返回值 
class myPrint
{
public:
	void operator()(int val)
	{
		cout << val << endl;
		this->m_Count++;
	}
	int m_Count = 0;
};
void test01()
{
	vector<int>v{1, 5, 2, 3, 7, 8, 9, 4};
	myPrint mp=for_each(v.begin(), v.end(), myPrint());
	cout << "mp.m_Count=" << mp.m_Count << endl;
}
//2.for_each基本用法
void printData(int val)
{
	cout << val << endl;
}
void test02()
{
	vector<int>v{ 1, 5, 2, 3, 7, 8, 9, 4 };
	 for_each(v.begin(), v.end(), printData);
}
int main()
{
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
#endif