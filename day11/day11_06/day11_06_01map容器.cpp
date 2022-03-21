#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
#include<string>
using namespace std;
void test01()
{
	map<int, int >m;
	//��һ�ֲ��뷽ʽ
	m.insert(pair<int, int>(4, 40));
	//�ڶ��ֲ��뷽ʽ
	m.insert(make_pair(2, 20));
	//�����ֲ��뷽ʽ  
	m.insert(map<int, int>::value_type(3, 30));
	//�����ֲ��뷽ʽ  
	m[1] = 10;
	m.insert(pair<int, int>(4, 40));
	for (auto c : m)
	{
		cout << "key:" << c.first << "   value:" << c.second << endl;
	}
}
//2.map����ʵ���Զ����������͵�����  
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
		cout << "������" << c.first.m_Name << "  ���䣺" << c.first.m_Age << "  ��ţ�" << c.second << endl;
	}
}
int main()
{
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
#endif