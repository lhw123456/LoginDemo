#pragma once 
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<functional>
#include<map>
#include<string>
using namespace std;
class fileManage
{
public:
	//将单行的数据解析到指定的容器中
	void parseLineDataToVector(string line,vector<string>&v);
	void loadCVSFile(string path, map<string, map<string, string>>& mData);
};