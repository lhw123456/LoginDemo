#if 1
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
void test01()
{
	//�ڽ�ȡ������  
	negate<int>n;
	cout << n(10) << endl;

	//�ڽ��ӷ����� 
	plus<int>p;
	cout << p(10, 20) << endl;
}
//���ڷº�����lambda���ʽ  
void test02()
{
	vector<int>v{1, 2, 33, 22, 11, 10, 9, 20};
	sort(v.begin(), v.end(), greater<int>());
	for_each(v.begin(), v.end(), [](int val) {cout << val << endl; });
}
int main()
{
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
#endif