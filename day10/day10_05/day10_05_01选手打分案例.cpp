#if 1
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<ctime>
#include<algorithm>
using namespace std;
//实现选手打分案例  
//void creatPlayer(vector<string>& s)
//{
//	string str = "ABCDE";
//	string name = "Player:";
//	for (int i = 0; i < str.size(); ++i)
//	{
//		string final_Name = name + str[i];
//		s.push_back(final_Name);
//	}
//	return;
//}
//void test01()
//{
//	vector<string>s;
//	creatPlayer(s);
//	for (auto c : s)
//	  {
//		  cout << c << " " << endl;
//	  }
//}
class Person
{
public:
	Person(string name, int score)
	{
		this->m_Name = name;
		this->m_Score = score;
	}
	string m_Name;
	int m_Score;
};
void creatPlayer(vector<Person>& v)
{
	string str = "ABCDE";
  	string name = "Player:";
	for (int i = 0; i < str.size(); ++i)
	{
		string final_Name = name + str[i];
		Person p(final_Name, 0);
		v.push_back(p);
	}
}
int AverageScore(deque<int>& d)
{
	int sum = 0;
	for (auto c : d)
	{
		sum += c;
		//cout << "sum=" << sum << endl;
	}
	/*cout << d.size() << endl;
	cout << sum / d.size() << endl;*/
	return sum / d.size();
}
void printScore(const vector<Person>& d)
{
	for (vector<Person>::const_iterator it =d.begin();it!=d.end();++it)
	{
		cout << "姓名："<<(*it).m_Name<<"  平均分："<<(*it).m_Score << endl;
	}
}
void test02()
{
	vector<Person>v;
	creatPlayer(v);
	//for (auto c : v)
	//{
	//	cout << c.m_Name << " " << endl;
	//}
	for (auto &c : v)
	{
		deque<int>d;
		for (int i = 0; i < 10; ++i)
		{
			int score = rand() % 100 +50;
			//cout << "socre=" << score << endl;
			d.push_back(score);
		}
		sort(d.begin(), d.end());
		d.pop_back();
		d.pop_front();
		int score=AverageScore(d);
		//cout << "score=" << score << endl;
		c.m_Score = score;
	}
	printScore(v);

}
int main()
{
	srand((unsigned int)time(NULL));
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
#endif