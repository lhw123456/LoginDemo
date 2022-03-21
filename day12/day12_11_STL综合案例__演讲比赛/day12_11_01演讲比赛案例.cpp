#if 1
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<map>
#include<numeric>
#include<algorithm>
#include<ctime>
using namespace std;
//学校演讲比赛案例  24个人     三次比赛决出前三名 
class Speaker
{
public:
	string m_Name;
	int m_Score[3];
};
//1.创建选手信息  
void creatSpeaker(vector<int>&v,map<int, Speaker>& m)
{
	string nameSid = "ABCDEFGHIJKLMNOPQRSTUVWX ";
	for (int i = 0; i < 24; ++i)
	{
		Speaker st;
		string name = "选手";
		st.m_Name = name + nameSid[i];
		for (int j = 0; j < 3; ++j)
		{
			st.m_Score[j] = 0;
		}
		//存放选手编号的容器 
		v.push_back(100 + i);
		m.insert(make_pair(i + 100, st));
	}
}

//2.抽签 
void drawLabel(vector<int>& v)
{
	random_shuffle(v.begin(), v.end());
}
//3.开始比赛 
void speechContest(int index,vector<int>&v,map<int ,Speaker>&m,vector<int>&v2)//vector<int>&v2用于存放第一轮晋级 的人员信息
{
	multimap<int, int, greater<int>>mGroup;  //临时容器，存放晋级选手的分数和编号，int :分数		int:编号
	int num = 0;
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		++num;
		deque<int>d;
		for (int i = 0; i < 10; ++i)
		{
			int score = rand() % 100 + 60;
			d.push_back(score);
		}
		sort(d.begin(), d.end());
		d.pop_back();
		d.pop_front();
		int avg = accumulate(d.begin(), d.end(), 0) / d.size();
		m[*it].m_Score[index-1] = avg;

		mGroup.insert(make_pair(avg, *it));
		if (num % 6 == 0)
		{
			int count = 0;
			for (multimap<int, int, greater<int>>::iterator mit = mGroup.begin(); mit != mGroup.end()&&count<3; ++mit,++count)
			{
				v2.push_back(mit->second);
			}
			mGroup.clear();
		}
   }
}
void showWinner(vector<int>&v,map<int,Speaker>&m,int index)
{
	cout << "第"<<index<<"轮晋级人员编号和个人信息如下：" << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << *it << " ";
		cout << m[*it].m_Name << "   " << m[*it].m_Score[index-1] << endl;
	}
	cout << endl;
}
void test01()
{
	 //将所有的功能分模块编写  这样可以减少程序的出错率，也方便调试程序
	
	 //1.建立存放24名选手编号、个人信息的容器
	vector<int>v1;
	map<int, Speaker>m;  //int对应的是选手的编号，Speaker中保存选手的姓名和得分信息
	creatSpeaker(v1, m);
   //2.第一轮比赛 
	drawLabel(v1);
	vector<int>v2;  //存放第一轮晋级选手的编号。
	speechContest(1, v1, m,v2);
	showWinner(v2,m,1);

	drawLabel(v2);
	vector<int>v3;
	speechContest(2, v2, m, v3);
	showWinner(v3, m, 2);

	drawLabel(v3);
	vector<int>v4;
	speechContest(3, v3, m, v4);
	showWinner(v4, m, 3);
}
int main()
{
	srand((unsigned int)time(NULL));
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
#endif