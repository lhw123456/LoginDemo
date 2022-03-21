#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<map>
#include<ctime>
using namespace std;
enum name  { finance=0,research,sales };
class Person
{
public:
	Person(string name, int age, string tel, int salary)
	{
		this->m_Name = name;
		this->m_Age = age;
		this->m_Tel = tel;
		this->m_Salary = salary;
	}
	string m_Name;
	int m_Age;
	string m_Tel;
	int m_Salary;
};
void printSecInfo(multimap<int ,Person>::iterator &mit)
{
	cout << "姓名：" << (mit->second).m_Name << "  年龄：" << (mit->second).m_Age << "  电话" << (mit->second).m_Tel << "  工资：" << (mit->second).m_Salary << endl;
}
void setSectionInfo(multimap<int,Person> &m)
{
	for (multimap<int,Person>::iterator mit = m.begin();mit != m.end(); ++mit)
	{
		switch (mit->first)
		{
		case finance:   
			cout << "finance:" << endl;
			printSecInfo(mit);
			break;
		case research:
			cout << "research" << endl;
			printSecInfo(mit);
			break;
		case sales:
			cout << "sales" << endl;
			printSecInfo(mit);
			break;
		default:
			cout << "信息有误" << endl;
			break;
		}
	}
}
void test01()
{
	multimap<int,Person >m;
	//1.创建5个员工，并赋予他们基础信息  
	Person w1("w1", 20, "17564768907", 4000);
	Person w2("w2", 22, "13676549087", 6000);
	Person w3("w3", 29, "13876597860", 3000);
	Person w4("w4", 18, "13923657820", 2000);
	Person w5("w5", 17, "13828182868", 10000);

	//2.将人员的信息放在multimap容器中保存 
	Person arr[] = { w1,w2,w3,w4,w5 };
	int num = 0;
	for (int i = 0; i < 5; ++i)
	{
		num = rand() % 3;
		m.insert(pair<int ,Person>(num,arr[i]));
	}

	//3.部门信息打印 
setSectionInfo(m);
}
int main()
{
	srand((unsigned int)time(NULL));
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
#endif