#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
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
	bool operator==(const Person& p)const
	{
		return p.m_Name == this->m_Name && p.m_Age == this->m_Age;
	}
	string m_Name;
	int m_Age;
};
void test01()
{
	Person p1("aaa", 20);
	Person p2("bbb", 30);
	Person p3("ccc", 40);
	Person p4("ddd", 50);
	vector<Person>v{ p1,p2,p3,p4 };
	vector<Person>::iterator pos = find(v.begin(), v.end(), p2);
	if (pos == v.end())
	{
		cout << "δ�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ��ˣ������ǣ�" << (*pos).m_Name << "  ���䣺" << (*pos).m_Age << endl;
	}
	
}
int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
#endif