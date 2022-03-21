#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
#include<string>
using namespace std;
void test01()
{
	map<int, int >m;
	//第一种插入方式
	m.insert(pair<int, int>(4, 40));
	//第二种插入方式
	m.insert(make_pair(2, 20));
	//第三种插入方式  
	m.insert(map<int, int>::value_type(3, 30));
	//第四种插入方式  
	m[1] = 10;
	m.insert(pair<int, int>(4, 40));
	for (auto c : m)
	{
		cout << "key:" << c.first << "   value:" << c.second << endl;
	}
}
//2.map容器实现自定义数据类型的排序  
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
class myCompare
{
public:
	bool operator()(const Person &p1, const Person &p2) const 
	{
		return p1.m_Age>p2.m_Age;
	}
};
//bool operator==(const Person& p1, const Person& p2)
//{
//	return (p1.m_Age > p2.m_Age);
//}
void test02()
{
	map<Person, int,myCompare>m;
	Person p1("tom", 23);
	Person p2("jerry", 22);
	Person p3("bell", 21);
	Person p4("hill", 25);
	m.insert(pair<Person,int>(p1,10));
	m.insert(pair<Person,int>(p2,20));
	m.insert(pair<Person,int>(p3,30));
	m.insert(pair<Person,int>(p4,40));
	for (auto c : m)
	{
		cout << "姓名：" << c.first.m_Name << "  年龄：" << c.first.m_Age << "  序号：" << c.second << endl;
	}
}
int main()
{
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
#endif