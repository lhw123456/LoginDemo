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
//ѧУ�ݽ���������  24����     ���α�������ǰ���� 
class Speaker
{
public:
	string m_Name;
	int m_Score[3];
};
//1.����ѡ����Ϣ  
void creatSpeaker(vector<int>&v,map<int, Speaker>& m)
{
	string nameSid = "ABCDEFGHIJKLMNOPQRSTUVWX ";
	for (int i = 0; i < 24; ++i)
	{
		Speaker st;
		string name = "ѡ��";
		st.m_Name = name + nameSid[i];
		for (int j = 0; j < 3; ++j)
		{
			st.m_Score[j] = 0;
		}
		//���ѡ�ֱ�ŵ����� 
		v.push_back(100 + i);
		m.insert(make_pair(i + 100, st));
	}
}

//2.��ǩ 
void drawLabel(vector<int>& v)
{
	random_shuffle(v.begin(), v.end());
}
//3.��ʼ���� 
void speechContest(int index,vector<int>&v,map<int ,Speaker>&m,vector<int>&v2)//vector<int>&v2���ڴ�ŵ�һ�ֽ��� ����Ա��Ϣ
{
	multimap<int, int, greater<int>>mGroup;  //��ʱ��������Ž���ѡ�ֵķ����ͱ�ţ�int :����		int:���
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
	cout << "��"<<index<<"�ֽ�����Ա��ź͸�����Ϣ���£�" << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << *it << " ";
		cout << m[*it].m_Name << "   " << m[*it].m_Score[index-1] << endl;
	}
	cout << endl;
}
void test01()
{
	 //�����еĹ��ܷ�ģ���д  �������Լ��ٳ���ĳ����ʣ�Ҳ������Գ���
	
	 //1.�������24��ѡ�ֱ�š�������Ϣ������
	vector<int>v1;
	map<int, Speaker>m;  //int��Ӧ����ѡ�ֵı�ţ�Speaker�б���ѡ�ֵ������͵÷���Ϣ
	creatSpeaker(v1, m);
   //2.��һ�ֱ��� 
	drawLabel(v1);
	vector<int>v2;  //��ŵ�һ�ֽ���ѡ�ֵı�š�
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