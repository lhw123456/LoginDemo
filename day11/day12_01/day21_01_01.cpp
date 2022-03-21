#if 1
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Person
{
public:
	Person(int a, int b) :m_A(a), m_B(b)
	{}
	int m_A;
	int m_B;
};
Person operator+(Person& p1, Person& p2)
{
	Person temp(0, 0);
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;
}
void test01()
{
	Person p1(10, 10);
	Person p2(20, 20);
	Person p3 = p1 + p2;
	cout << "p3.m_A=" << p3.m_A << "  p3.m_B=" << p3.m_B << endl;
}
int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
#endif