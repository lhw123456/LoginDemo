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
	//��ȡ�����˺�  
	virtual int getBaseDamage();
	//����Ч�� ����ֵ����0 ��������  
	virtual int getCrit() ;
	//��ȡ��Ѫ  ����ֵ����0  ������Ѫ 
	virtual int getSuckBlood() ;
	//����Ч��  ����ֵ����0  ������� 
	virtual int getFrozen() ;

	//��������  
	virtual bool isTrigger(int rate) ;
};