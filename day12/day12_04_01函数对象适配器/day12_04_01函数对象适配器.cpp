#if 1
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<string>
using namespace std;
//函数对象适配器  
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
//2.一元取反适配器 
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
	//第二种方法，找到小于5的数
	vector<int>::iterator pos = find_if(v.begin(), v.end(), not1(bind2nd(greater<int>(), 5)));
	if (pos == v.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到的第一个数是：" << *pos << endl;
	}
	//  二元取反 
	sort(v.begin(), v.end(), not2(less<int>()));
	for_each(v.begin(), v.end(), [](int val) {cout << val << endl; });
}
//3.函数指针适配器
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
//4.成员函数适配器
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
		cout << "姓名：" << this->m_Name << "  年龄：" << this->m_Age << endl;
	}
	string m_Name;
	int m_Age;
};
//void printPerson(Person &p)
//{d
//	cout << "姓名：" << p.m_Name << "  年龄：" << p.m_Age << endl;
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