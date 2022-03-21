#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iostream>
#include<vector>
#include<string>
#include<functional>
#include<algorithm>
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
class comparePreson:public binary_function<Person *,Person *,bool>
{
public:
	bool operator()( Person* p1, Person*p2) const
	{
		return p1->m_Name == p2->m_Name && p1->m_Age == p2->m_Age;
	}
};
void test01()
{
	Person p1("aaa", 20);
	Person p2("bbb", 30);
	Person p3("ccc", 40);
	Person p4("ddd", 50);
	vector<Person*>v{ &p1,&p2,&p3,&p4 };
	Person* p = new Person("bbb", 30);
	vector<Person*>::iterator pos = find_if(v.begin(), v.end(), bind2nd(comparePreson(), p));
	if (pos == v.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到了，姓名：" << (*pos)->m_Name << "  年龄：" << (*pos)->m_Age << endl;
	}
}
int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
#endif