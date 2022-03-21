#if 1
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<list>
using namespace std;

//1.���캯����ʹ��
//vector<T> v; //����ģ��ʵ����ʵ�֣�Ĭ�Ϲ��캯��
//vector(v.begin(), v.end());//��v[begin(), end())�����е�Ԫ�ؿ���������
//vector(n, elem);//���캯����n��elem����������
//vector(const vector& vec);//�������캯����
//
////���� ʹ�õڶ������캯�� ���ǿ���...
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
//2.���ø�ֵ����
//assign(beg, end);//��[beg, end)�����е����ݿ�����ֵ������
//assign(n, elem);//��n��elem������ֵ������
//vector& operator=(const vector& vec);//���صȺŲ�����
//swap(vec);// ��vec�뱾���Ԫ�ػ�����

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
//4.vector���������ɾ��
//insert(const_iterator pos, int count, ele);//������ָ��λ��pos����count��Ԫ��ele.
//push_back(ele); //β������Ԫ��ele
//pop_back();//ɾ�����һ��Ԫ��
//erase(const_iterator start, const_iterator end);//ɾ����������start��end֮���Ԫ��
//erase(const_iterator pos);//ɾ��������ָ���Ԫ��
//clear();//ɾ������������Ԫ��
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
//5.�����ӡ����
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
//6.����swap�����ڴ� 
void test06()
{
	vector<int>v;
	for (int i = 0; i < 100000; ++i)
	{
		v.push_back(i);
	}
	cout << "����Ϊ��" << v.capacity() << endl;
	cout << "��СΪ��" << v.size() << endl;
	v.resize(3);
	cout << "����Ϊ��" << v.capacity() << endl;
	cout << "��СΪ��" << v.size() << endl;

	vector<int>(v).swap(v);
	cout << "����Ϊ��" << v.capacity() << endl;
	cout << "��СΪ��" << v.size() << endl;
}
//7.����2  ��������ڴ�Ĵ�С
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