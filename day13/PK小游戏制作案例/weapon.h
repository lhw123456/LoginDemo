#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#pragma once
using namespace std;
#include"fileManage.h"
//��������  
class Weapon
{
public:
	//��ȡ�����˺�  
	virtual int getBaseDamage() = 0;
	//����Ч�� ����ֵ����0 ��������  
	virtual int getCrit() = 0;
	//��ȡ��Ѫ  ����ֵ����0  ������Ѫ 
	virtual int getSuckBlood() = 0;
	//����Ч��  ����ֵ����0  ������� 
	virtual int getFrozen() = 0;

	//��������  
	virtual bool isTrigger(int rate) = 0;
	
public:
	int baseDamage; //��������
	string weaponName;//��������
	int critPlus;   //����ϵ�� 
	int critRate;//������
	int suckPlus;//��Ѫϵ��  
	int suckRate;//��Ѫ��  
	int frozenRate;  //������  
};