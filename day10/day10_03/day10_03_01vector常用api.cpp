#if 1
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<list>
using namespace std;

//1.构造函数类使用
//vector<T> v; //采用模板实现类实现，默认构造函数
//vector(v.begin(), v.end());//将v[begin(), end())区间中的元素拷贝给本身。
//vector(n, elem);//构造函数将n个elem拷贝给本身。
//vector(const vector& vec);//拷贝构造函数。
//
////例子 使用第二个构造函数 我们可以...
//int arr[] = { 2,3,4,1,9 };
//vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));
void printVector(vector<int>& v)
{
	for (auto c : v)
	{
		cout << c << " ";
	}
	cout << endl;
}
void test01()
{
	vector<int>v(10, 100);
	printVector(v);

	vector<int>v2(v);
	printVector(v2);

	int arr[] = { 1,2,4,5,5,6,7 };
	vector<int>v3(arr, arr + sizeof(arr) / sizeof(arr[0]));
	printVector(v3);

	vector<int>v4(v3.begin(), v3.end());
	printVector(v4);
}
//2.常用赋值操作
//assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
//assign(n, elem);//将n个elem拷贝赋值给本身。
//vector& operator=(const vector& vec);//重载等号操作符
//swap(vec);// 将vec与本身的元素互换。

void test02()
{
	vector<int >v{ 1,2,4,5,6,6 };
	vector<int >v2(v);
	printVector(v2);
	vector<int>v3;
	v3.assign(v.begin(), v.end());
	printVector(v3);
	cout << "....................................................." << endl;
	vector<int>v4(10, 2);
	v4.swap(v);
	printVector(v);
	printVector(v4);
}
void test03()
{
	vector<int>v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
		cout << "v.capacity=" << v.capacity() << endl;
	}
}
//4.vector容器插入和删除
//insert(const_iterator pos, int count, ele);//迭代器指向位置pos插入count个元素ele.
//push_back(ele); //尾部插入元素ele
//pop_back();//删除最后一个元素
//erase(const_iterator start, const_iterator end);//删除迭代器从start到end之间的元素
//erase(const_iterator pos);//删除迭代器指向的元素
//clear();//删除容器中所有元素
void test04()
{
	vector<int >v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.insert(++v.begin(), 3, 20);
	//10 20 20 20 20 30 40 
	printVector(v);
	/*v.erase(v.begin(), v.end());
	printVector(v);*/
	v.pop_back();
	printVector(v);
}
//5.逆序打印数据
void test05()
{
	vector<int >v{ 10,20,30,40,50 };
	printVector(v);
	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}
//6.巧用swap收缩内存 
void test06()
{
	vector<int>v;
	for (int i = 0; i < 100000; ++i)
	{
		v.push_back(i);
	}
	cout << "容量为：" << v.capacity() << endl;
	cout << "大小为：" << v.size() << endl;
	v.resize(3);
	cout << "容量为：" << v.capacity() << endl;
	cout << "大小为：" << v.size() << endl;

	vector<int>(v).swap(v);
	cout << "容量为：" << v.capacity() << endl;
	cout << "大小为：" << v.size() << endl;
}
//7.案例2  计算分配内存的大小
void test07()
{
	int* p = NULL;
	vector<int>v;
	v.reserve(100000);
	int num = 0;
	for (int i = 0; i < 100000; ++i)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			p = &v[0];
			++num;
		}
	}
	cout << "num=" << num << endl;
}
void test08()
{
	vector<int>v{ 1,2,4,5,5,6 };
	vector<int>::iterator it = v.begin();
	it++;
	it--;
	it += 1;

	list<int>L{ 1,3,5,6 };
	list<int>::iterator lit = L.begin();
	lit++;
	//lit = lit + 1;
}
void test09()
{
	for (int i = 0; i != 10; i++)
	{
		int j;
		j = i;
		cout << j << endl;
		cout << &j << endl;
	}
}
int main()
{
	test09();
	system("pause");
	return EXIT_SUCCESS;
}
#endif