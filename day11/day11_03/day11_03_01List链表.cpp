#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<list>
using namespace std;

void printList(list<int>& L)
{
	for (auto c : L)
	{
		cout << c << " ";
	}
	cout << endl;
}
void test01()
{
	list<int>L;
	list<int>L2(10, 100);
	list<int>L3(L2);
	printList(L);
	printList(L2);
	printList(L3);
}
//reverse();//反转链表，比如lst包含1,3,5元素，运行此方法后，lst就包含5,3,1元素。
//sort(); //list排序
void test02()
{
	list<int>L;
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	L.push_back(40);
	L.push_front(50);
	L.push_front(60);
	//60 50 10 20 30 40 50 
	printList(L);

	//50 40 30 20 10 50 60 
	L.reverse();
	printList(L);
	//
	L.insert(++L.begin(), 70);
	printList(L);
}
//3. 排序 
int myCompare(int val1, int val2)
{
	return val1 > val2;
}
void test03()
{
	list<int>L;
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	L.push_back(40);
	L.push_back(40);
	L.push_back(40);
	printList(L);
	L.remove(40);
	printList(L);
	L.push_front(70);
	L.push_front(80);
	printList(L);

	L.sort(myCompare);
	printList(L);
}
//4.对于自定义类型的数据进行排序  
class Person
{
public:
	Person(string name, int age,int height)
	{
		this->m_Name = name;
		this->m_Age = age;
		this->m_Height = height;
	}
	bool operator ==(const Person& p) const
	{
		return this->m_Name == p.m_Name && this->m_Height == p.m_Height && this->m_Age == p.m_Age;
	}
	string m_Name;
	int m_Age;
	int m_Height;
};
void printListPerson(list<Person>const &L)
{
	for (auto c : L)
	{
		cout << "姓名：" << c.m_Name << "  年龄：" << c.m_Age << " 身高："<<c.m_Height<<endl;
	}
	return;
}
bool myComparePerson(Person& p1, Person& p2)
{
	if (p1.m_Age == p2.m_Age)
	{
		return p1.m_Height > p2.m_Height;
	}
	return p1.m_Age >p2.m_Age;
}
void test04()
{
	Person p1("张飞", 20,170);
	Person p2("赵云", 22,180);
	Person p3("貂蝉", 21,165);
	Person p4("吕布", 19,189);
	Person p5("黄忠", 19,193);
	Person p6("关羽", 19,192);
	list<Person>L;
	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);
	cout << "排序前：" << endl;
	printListPerson(L);

	cout << "排序后：" << endl;
	L.sort(myComparePerson);
	printListPerson(L);

	//删除第一个元素操作  
	cout << "删除操作后：" << endl;
	L.remove(p1);
	printListPerson(L);
}
int main()
{
	test04();
	system("pause");
	return EXIT_SUCCESS;
}
#endif