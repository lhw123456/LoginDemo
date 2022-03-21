#pragma once 
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"weapon.h"
class Monster;
using namespace std;
class Hero
{
public:
	Hero(int heroId);

	void Attack(Monster* monster);
	void EquipWeapon(Weapon* weapon);
public:
	int heroHp;
	int heroAtk;
	int heroDef;
	string heroName;
	string heroInfo;
	Weapon* pWeapon;
};
