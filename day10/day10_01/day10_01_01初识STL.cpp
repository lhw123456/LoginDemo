#if 1
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
void myFunc(int val)
{
	cout << val << endl;
}
void test01()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(11);
	v.push_back(12);
	v.push_back(13);
	vector<int>::iterator itBeg = v.begin();
	vector<int>::iterator itEnd = v.end();
	//while (itBeg != itEnd)
	//{
	//	cout << *itBeg << endl;
	//	itBeg++;
	//}

	/*for (auto& c : v)
	{
		cout << c << endl;
	}*/
	for_each(itBeg, itEnd, myFunc);
}
class Person
{
public:
	Person(string name,int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};
//自定义数据类型
void test02()
{
	Person p1("tom", 23);
	Person p2("jerry", 22);
	Person p3("bell", 21);

	vector<Person*>v;
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);

	for (auto p : v)
	{
		cout << "姓名：" << p->m_Name << "  年龄：" << p->m_Age << endl;
	}
}
//容器嵌套容器
void test03()
{
	vector<vector<int>>v;
	vector<int>v1;
	vector<int>v2;
	vector<int>v3;
	for (int i = 1; i < 5; ++i)
	{
		v1.push_back(i + 10);
		v2.push_back(i + 100);
		v3.push_back(i + 1000);
	}
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);

	//1.第一种输出写法
	//for (auto c : v)
	//{
	//	for (auto c1 : c)
	//	{
	//		cout << c1<<" ";
	//	}
	//	cout << endl;
	//}

	//2.第二种输出写法 
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); ++it)
	{
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
		{
			cout << *vit << " ";
		}
		cout << endl;
	}
}
int main()
{
	test03();
	system("pause");
	return EXIT_SUCCESS;
}
#endif