#pragma once 
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"weapon.h"
#include"fileManage.h"
using namespace std;
class broadSwod :public Weapon
{
public:
	broadSwod();
	//��ȡ�����˺�  
	virtual int getBaseDamage();
	//����Ч�� ����ֵ����0 ��������  
	virtual int getCrit();
	//��ȡ��Ѫ  ����ֵ����0  ������Ѫ 
	virtual int getSuckBlood();
	//����Ч��  ����ֵ����0  ������� 
	virtual int getFrozen();

	//��������  
	virtual bool isTrigger(int rate);
};