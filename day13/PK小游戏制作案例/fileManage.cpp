#include "fileManage.h"
void fileManage::parseLineDataToVector(string line, vector<string>& v)
{
	//�����ݽ�����vector������
	int pos = 0;
	int start = 0;
	while (true)
	{
		pos = line.find(",", start);
		if (pos == -1)
		{
			string temp = line.substr(start, line.size() - start);
			v.push_back(temp);
			break;
		}
		string temp = line.substr(start, pos - start);
		v.push_back(temp);
		start = pos + 1;
	}
}
void fileManage::loadCVSFile(string path,map<string,map<string,string>>&mData)
{
	ifstream ifs(path, ios::out);
	if (!ifs.is_open())
	{
		cout << "���ļ�ʧ�ܣ�" << endl;
		return;
	}
	string FirstLine;
	ifs >> FirstLine;
	//cout << FirstLine << endl;
	vector <string>vFirst;
	parseLineDataToVector(FirstLine, vFirst);
	//for_each(v1.begin(), v1.end(), [](string val) {cout << val << endl; });

	//�����ڶ������� 
	//string SecondLine;
	//ifs >> SecondLine;
	//cout << SecondLine << endl;
	//vector<string>v2;
	//parseLineDataToVector(SecondLine, v2);
	//for_each(v2.begin(), v2.end(), [](string val) {cout << val << endl; });

	//׼�����������С���� 
	//map<string, map<string, string>>mData;
     //С����
	string otherLine;
	while (ifs >> otherLine)
	{
		vector<string>vOther;
		parseLineDataToVector(otherLine, vOther);
		map<string, string>m;
		for (int i = 0; i < vOther.size(); ++i)
		{
			m.insert(make_pair(vFirst[i], vOther[i]));
		}
		mData.insert(make_pair(vOther[0], m));
	}
	/*cout << "2��Ӣ�۹�������" << mData["2"]["heroAtk"] << endl;
	cout << "3��Ӣ�۷�������" << mData["3"]["heroDef"] << endl;*/
}
