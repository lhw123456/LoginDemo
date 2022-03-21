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
	cout << "栈的大小为：" << s.size() << endl;
	while (!s.empty())
	{
		
		cout << "栈顶元素为：" <<s.top()<< endl;
		s.pop();
	}
	cout << "栈的大小为：" << s.size() << endl;
}
int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
#endif