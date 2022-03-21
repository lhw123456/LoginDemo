#include"hero.h"
#include"fileManage.h"
#include"monster.h"
Hero::Hero(int heroId)
{
	fileManage fm;
	string path = "Hero.csv";
	map<string, map<string, string>>mHero;
	//��Ӣ�۵�����д�뵽mHero������  
	fm.loadCVSFile(path, mHero);

	//�������е�Ӣ�ۻ�����Ϣд�뵽���������   
	string tempId = to_string(heroId);//������ת����string����  
	string id = mHero[tempId]["heroId"];

	this->heroName = mHero[id]["heroName"];
	this->heroInfo = mHero[id]["heroInfo"];
	this->heroDef = atoi(mHero[id]["heroDef"].c_str());
	this->heroHp = atoi(mHero[id]["heroHp"].c_str());
	this->heroAtk= atoi(mHero[id]["heroAtk"].c_str());

	//������ָ��Ϊ�� 
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
		damage = this->heroDef;     //����Ϊ��  
	}
	else
	{
		//�����˺�  
		damage = this->heroAtk + this->pWeapon->getBaseDamage();
		//������Ѫ 
		addHp = this->pWeapon->getSuckBlood();
		//�Ƿ����  
		frozen = this->pWeapon->getFrozen();
		//�Ƿ񱩻�  
		crit = this->pWeapon->getCrit();
	}
	if (crit)
	{
		damage = damage + crit;
		cout << "Ӣ��������������,����<<" << monster->monsterName << ">>�ܵ������˺���" << endl;
	}
	if (frozen)
	{
		cout << "Ӣ��������������Ч��������<<" << monster->monsterName << ">>ֹͣ����һ�غϣ�" << endl;
	}
	if (addHp)
	{
		cout << "Ӣ������������Ѫ��Ӣ��Ѫ������" << addHp << "Ѫ!" << endl;
	}
	monster->isFrozen = frozen;
	int trueManage = (damage - monster->monsterDef) > 0 ? (damage - monster->monsterDef) : 1;
	monster->monsterHp -= trueManage;
	this->heroHp += addHp;
	cout << "Ӣ��<<" << this->heroName << ">>��������<<" << monster->monsterName << ">>���" << trueManage << "���˺���" << endl;
}

void Hero::EquipWeapon(Weapon* weapon)
{
	if (weapon == NULL)
	{
		return;
	 }
	this->pWeapon = weapon;
	cout << "Ӣ��<<" << this->heroName << ">>װ����<<" << weapon->weaponName << ">>!" << endl;
}
