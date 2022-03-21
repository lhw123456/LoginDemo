#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<string>
using namespace std;
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};
void test01()
{
	Person p1("aaa", 20);
	Person p2("bbb", 30);
	Person p3 ("ccc", 40);
	Person p4("ddd", 50);

	queue<Person>d;
	d.push(p1);
	d.push(p2);
	d.push(p3);
	d.push(p4);
	cout << "deque大小为：" << d.size() << endl;
	while (!d.empty())
	{
		cout << "队头元素：" << d.front().m_Name << "  " << d.front().m_Age << endl;
		cout << "队尾元素：" << d.back().m_Name << "  " << d.back().m_Age << endl;
		d.pop();
	}
	cout << "deque大小为：" << d.size() << endl;
}
int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
#endif