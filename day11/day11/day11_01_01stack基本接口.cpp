#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>
using namespace std;
void test01()
{
	stack<int>s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	cout << "ջ�Ĵ�СΪ��" << s.size() << endl;
	while (!s.empty())
	{
		
		cout << "ջ��Ԫ��Ϊ��" <<s.top()<< endl;
		s.pop();
	}
	cout << "ջ�Ĵ�СΪ��" << s.size() << endl;
}
int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
#endif