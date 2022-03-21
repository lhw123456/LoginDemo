#define _CRT_SECURE_NO_WARNINGS
#include"monster.h"
#include<iostream>
using namespace std;

Monster::Monster(int monsterId)
{
	fileManage fm;
	string path = "Monsters.csv";
	map<string, map<string, string>>mMonster;
	//将英雄的数据写入到mData容器中  
	fm.loadCVSFile(path, mMonster);

	//将容器中的英雄基础信息写入到类的属性中   
	string tempId= to_string(monsterId);//将整型转换成string类型  
	string id = mMonster[tempId]["monsterId"];

	this->monsterName = mMonster[id]["monsterName"];
	this->monsterDef = atoi(mMonster[id]["monsterDef"].c_str());
	this->monsterHp= atoi(mMonster[id]["monsterHp"].c_str());
	this->monsterAtk = atoi(mMonster[id]["monsterAtk"].c_str());

	//刚开始状态是没有被冰冻  
	this->isFrozen = false;
}

void Monster::Attack(Hero* hero)
{
	if (this->isFrozen)
	{
		cout << "怪物<<" << this->monsterName << ">>被冰冻，本回合无法进行攻击！" << endl;
		return;
	}
	int damage = this->monsterAtk - hero->heroDef > 0 ? this->monsterAtk - hero->heroDef:1;
	hero->heroHp -= damage;
	cout << "怪物<<" << this->monsterName << ">>发动了攻击，造成了英雄：<<" << hero->heroName<<">>" <<damage << "点伤害!" << endl;
}
