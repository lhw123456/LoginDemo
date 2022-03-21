#pragma once 
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"weapon.h"
#include"fileManage.h"
#include"knife.h"
using namespace std;
class Knife :public Weapon
{
public: 
	Knife();
	//获取基础伤害  
	virtual int getBaseDamage();
	//暴击效果 返回值大于0 出发暴击  
	virtual int getCrit() ;
	//获取吸血  返回值大于0  出发吸血 
	virtual int getSuckBlood() ;
	//冰冻效果  返回值大于0  代表冰冻 
	virtual int getFrozen() ;

	//出发概率  
	virtual bool isTrigger(int rate) ;
};