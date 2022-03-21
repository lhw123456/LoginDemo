#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<set>//����ʽ����  
using namespace std;
//insert(elem);//�������в���Ԫ�ء�
//clear();//�������Ԫ��
//erase(pos);//ɾ��pos��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�������
//erase(beg, end);//ɾ������[beg,end)������Ԫ�� ��������һ��Ԫ�صĵ�������
//erase(elem);//ɾ��������ֵΪelem��Ԫ�ء�
//
//3.7.2.5 set���Ҳ���
//find(key);//���Ҽ�key�Ƿ����,�����ڣ����ظü���Ԫ�صĵ��������������ڣ�����set.end();
//count(key);//���Ҽ�key��Ԫ�ظ���
//lower_bound(keyElem);//���ص�һ��key>=keyElemԪ�صĵ�������
//upper_bound(keyElem);//���ص�һ��key>keyElemԪ�صĵ�������
//equal_range(keyElem);//����������key��keyElem��ȵ������޵�������������
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
		cout << "û�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ���" << endl;
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
		cout << "û�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ���Ԫ���ǣ�" << *(p.first) << endl;
	}
	if (p.second == s.end())
	{
		cout << "û�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ���Ԫ���ǣ�" << *(p.second) << endl;
	}
}
//2.pair����Ĵ��� 
void test02()
{
	//1.pair����ĵ�һ�ִ�������
	pair<string, int>p("tom", 20);
	cout << "p.first=" << p.first << endl;
	cout << "p.second=" << p.second << endl;

	cout << endl;

	//2.pair����ĵڶ��ִ������� 
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
		cout << "����10�ɹ���" << endl;
	}
	else
	{
		cout << "����ʧ�ܣ�" << endl;
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