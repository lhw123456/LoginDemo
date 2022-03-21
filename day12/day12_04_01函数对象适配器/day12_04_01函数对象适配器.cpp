#if 1
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<string>
using namespace std;
//��������������  
class myPlus:public binary_function<int ,int, void>
{
public:
	void operator()(int val1, int start) const 
	{
		cout << val1 + start << endl;
	}
};
void test01()
{
	vector<int>v{ 1,20,13,14,16,29 };
	int start = 0;
	cin >> start;
	for_each(v.begin(), v.end(), bind2nd(myPlus(), start));
}
//2.һԪȡ�������� 
class greaterThanFive:public unary_function<int ,bool>
{
public:
	bool operator()(int val) const 
	{
		return val > 5;
	}
};
void test02()
{
	vector<int>v{ 1,20,13,14,16,29 };
	//vector<int>::iterator pos = find_if(v.begin(), v.end(), not1(greaterThanFive()));
	//�ڶ��ַ������ҵ�С��5����
	vector<int>::iterator pos = find_if(v.begin(), v.end(), not1(bind2nd(greater<int>(), 5)));
	if (pos == v.end())
	{
		cout << "δ�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ��ĵ�һ�����ǣ�" << *pos << endl;
	}
	//  ��Ԫȡ�� 
	sort(v.begin(), v.end(), not2(less<int>()));
	for_each(v.begin(), v.end(), [](int val) {cout << val << endl; });
}
//3.����ָ��������
void myPrint(int val,int start)
{
	cout << val+start << endl;
}
void test03()
{
	vector<int>v{ 1,20,13,14,16,29 };
	int start = 0;
	cin >> start;
	for_each(v.begin(), v.end(), bind2nd(ptr_fun(myPrint),start));
}
//4.��Ա����������
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	void showPerson()
	{
		cout << "������" << this->m_Name << "  ���䣺" << this->m_Age << endl;
	}
	string m_Name;
	int m_Age;
};
//void printPerson(Person &p)
//{d
//	cout << "������" << p.m_Name << "  ���䣺" << p.m_Age << endl;
//}
void test04()
{
	Person p1("aaa", 20);
	Person p2("bbb", 21);
	Person p3("ccc", 24);
	Person p4("ddd", 25);
	vector<Person>v{ p1,p2,p3,p4 };

	for_each(v.begin(), v.end(), mem_fun_ref(&Person::showPerson));
}
int main()
{
	test04();
	system("pause");
	return EXIT_SUCCESS;
}
#endif