#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<set>//关联式容器  
using namespace std;
//insert(elem);//在容器中插入元素。
//clear();//清除所有元素
//erase(pos);//删除pos迭代器所指的元素，返回下一个元素的迭代器。
//erase(beg, end);//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
//erase(elem);//删除容器中值为elem的元素。
//
//3.7.2.5 set查找操作
//find(key);//查找键key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
//count(key);//查找键key的元素个数
//lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
//upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
//equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
void printSet(set<int>& s)
{
	for (auto c : s)
	{
		cout << c << " " ;
	}
	cout << endl;
}
void test01()
{
	set<int>s;
	s.insert(10);
	s.insert(20);
	s.insert(30);
	s.insert(40);
	s.insert(10);
	printSet(s);

	//s.erase(10);
	printSet(s);

	if (s.find(20) == s.end())
	{
		cout << "没找到" << endl;
	}
	else
	{
		cout << "找到了" << endl;
	}
	int num = s.count(30);
	cout << "num=" << num << endl;

	set<int>::iterator pos = s.lower_bound(30);
	cout << "*pos=" << *pos << endl;

	pos = s.upper_bound(30);
	cout << "*pos=" << *pos << endl;

	pair<set<int>::iterator, set<int>::iterator>p = s.equal_range(30);
	if (p.first == s.end())
	{
		cout << "没找到" << endl;
	}
	else
	{
		cout << "找到的元素是：" << *(p.first) << endl;
	}
	if (p.second == s.end())
	{
		cout << "没找到" << endl;
	}
	else
	{
		cout << "找到的元素是：" << *(p.second) << endl;
	}
}
//2.pair对组的创建 
void test02()
{
	//1.pair对组的第一种创建方法
	pair<string, int>p("tom", 20);
	cout << "p.first=" << p.first << endl;
	cout << "p.second=" << p.second << endl;

	cout << endl;

	//2.pair对组的第二种创建方法 
	pair<string, int>p1 = make_pair("tom", 20);
	cout << "p1.first=" << p1.first << endl;
	cout << "p1.second=" << p1.second << endl;
}
void test03()
{
	set<int>s;
	s.insert(10);
	s.insert(20);
	s.insert(30);
	s.insert(40);
	s.insert(10);
	pair<set<int>::iterator, bool>p = s.insert(10);
	if (p.second)
	{
		cout << "插入10成功！" << endl;
	}
	else
	{
		cout << "插入失败！" << endl;
	}
	printSet(s);
}
int main()
{
	test03();
	system("pause");
	return EXIT_SUCCESS;
}
#endif