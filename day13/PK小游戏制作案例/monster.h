#pragma once 
#define _CRT_SECURE_NO_WARNINGS
#include"fileManage.h"
#include"hero.h"
#include<iostream>
using namespace std;
class Monster
{
public:
	Monster(int monsterId);
	void Attack(Hero* hero);
public:
	string monsterName;
	int monsterHp;
	int monsterAtk;
	int monsterDef;
	bool isFrozen;
};