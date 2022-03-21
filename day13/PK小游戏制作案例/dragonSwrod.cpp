#define _CRT_SECURE_NO_WARNINGS
#include"fileManage.h"	
#include<iostream>
#include"dragonSword.h"
using namespace std;
//构造函数初始化内存中的内容   
dragonSwrod::dragonSwrod()
{
	fileManage fm;
	string path = "Weapons.csv";
	map<string, map<string, string>>mWeapon;
	fm.loadCVSFile(path, mWeapon);

	//获取小刀的id号
	string id = mWeapon["3"]["weaponId"];
	this->weaponName = mWeapon[id]["weaponName"];
	this->baseDamage = atoi(mWeapon[id]["weaponAtk"].c_str());
	this->critPlus = atoi(mWeapon[id]["weaponCritPlus"].c_str());
	this->critRate = atoi(mWeapon[id]["weaponCritRate"].c_str());
	this->suckPlus = atoi(mWeapon[id]["weaponSuckPlus"].c_str());
	this->suckRate = atoi(mWeapon[id]["weaponSuckRate"].c_str());
	this->frozenRate = atoi(mWeapon[id]["weaponFrozenRate"].c_str());
}
int dragonSwrod::getBaseDamage()
{
	return this->baseDamage;
}

int dragonSwrod::getCrit()
{
	if (isTrigger(critRate))
	{
		return this->baseDamage * this->critPlus;
	}
	else
	{
		return 0;
	}
}

int dragonSwrod::getSuckBlood()
{
	if (isTrigger(suckRate))
	{
		return this->baseDamage * this->suckPlus;
	}
	else
	{
		return 0;
	}
}

int dragonSwrod::getFrozen()
{
	if (isTrigger(frozenRate))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool dragonSwrod::isTrigger(int rate)
{
	int num = rand() % 100 + 1;
	if (num <= rate)
	{
		return true;
	}
	else
	{
		return false;
	}
}
