#define _CRT_SECURE_NO_WARNINGS
#include"monster.h"
#include<iostream>
using namespace std;

Monster::Monster(int monsterId)
{
	fileManage fm;
	string path = "Monsters.csv";
	map<string, map<string, string>>mMonster;
	//��Ӣ�۵�����д�뵽mData������  
	fm.loadCVSFile(path, mMonster);

	//�������е�Ӣ�ۻ�����Ϣд�뵽���������   
	string tempId= to_string(monsterId);//������ת����string����  
	string id = mMonster[tempId]["monsterId"];

	this->monsterName = mMonster[id]["monsterName"];
	this->monsterDef = atoi(mMonster[id]["monsterDef"].c_str());
	this->monsterHp= atoi(mMonster[id]["monsterHp"].c_str());
	this->monsterAtk = atoi(mMonster[id]["monsterAtk"].c_str());

	//�տ�ʼ״̬��û�б�����  
	this->isFrozen = false;
}

void Monster::Attack(Hero* hero)
{
	if (this->isFrozen)
	{
		cout << "����<<" << this->monsterName << ">>�����������غ��޷����й�����" << endl;
		return;
	}
	int damage = this->monsterAtk - hero->heroDef > 0 ? this->monsterAtk - hero->heroDef:1;
	hero->heroHp -= damage;
	cout << "����<<" << this->monsterName << ">>�����˹����������Ӣ�ۣ�<<" << hero->heroName<<">>" <<damage << "���˺�!" << endl;
}
