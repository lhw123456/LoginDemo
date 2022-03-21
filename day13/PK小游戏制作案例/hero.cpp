#include"hero.h"
#include"fileManage.h"
#include"monster.h"
Hero::Hero(int heroId)
{
	fileManage fm;
	string path = "Hero.csv";
	map<string, map<string, string>>mHero;
	//将英雄的数据写入到mHero容器中  
	fm.loadCVSFile(path, mHero);

	//将容器中的英雄基础信息写入到类的属性中   
	string tempId = to_string(heroId);//将整型转换成string类型  
	string id = mHero[tempId]["heroId"];

	this->heroName = mHero[id]["heroName"];
	this->heroInfo = mHero[id]["heroInfo"];
	this->heroDef = atoi(mHero[id]["heroDef"].c_str());
	this->heroHp = atoi(mHero[id]["heroHp"].c_str());
	this->heroAtk= atoi(mHero[id]["heroAtk"].c_str());

	//武器类指针为空 
	this->pWeapon = NULL;
}

void Hero::Attack(Monster* monster)
{
	int crit = 0;
	int damage = 0;
	int addHp = 0;
	int frozen = 0;

	if (this->pWeapon == NULL)
	{
		damage = this->heroDef;     //武器为空  
	}
	else
	{
		//基础伤害  
		damage = this->heroAtk + this->pWeapon->getBaseDamage();
		//计算吸血 
		addHp = this->pWeapon->getSuckBlood();
		//是否冰冻  
		frozen = this->pWeapon->getFrozen();
		//是否暴击  
		crit = this->pWeapon->getCrit();
	}
	if (crit)
	{
		damage = damage + crit;
		cout << "英雄武器触发暴击,怪物<<" << monster->monsterName << ">>受到暴击伤害！" << endl;
	}
	if (frozen)
	{
		cout << "英雄武器触发冰冻效果，怪物<<" << monster->monsterName << ">>停止攻击一回合！" << endl;
	}
	if (addHp)
	{
		cout << "英雄武器触发吸血，英雄血量增加" << addHp << "血!" << endl;
	}
	monster->isFrozen = frozen;
	int trueManage = (damage - monster->monsterDef) > 0 ? (damage - monster->monsterDef) : 1;
	monster->monsterHp -= trueManage;
	this->heroHp += addHp;
	cout << "英雄<<" << this->heroName << ">>攻击怪物<<" << monster->monsterName << ">>造成" << trueManage << "点伤害！" << endl;
}

void Hero::EquipWeapon(Weapon* weapon)
{
	if (weapon == NULL)
	{
		return;
	 }
	this->pWeapon = weapon;
	cout << "英雄<<" << this->heroName << ">>装备了<<" << weapon->weaponName << ">>!" << endl;
}
