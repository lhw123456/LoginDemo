#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	for_each(param beg,param end,para _callback)
	�����㷨 ��������Ԫ��
	@param beg ��ʼ������
	@param end ����������
	@param _callback  �����ص����ߺ�������
	@return ��������
*/

//1.for_each�з���ֵ 
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
//2.for_each�����÷�
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