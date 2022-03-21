#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"fileManage.h"
#include"knife.h"
#include"broadSwod.h"
#include"dragonSword.h"
#include"hero.h"
#include"monster.h"
#include"ctime"
using namespace std;
void Fighting()
{
	cout << "欢迎来到天下第一武道大会" << endl;
	cout << "请选择您的英雄：" << endl;
	char buf[1024] = {0};
	fileManage fm;
	string path = "Hero.csv";
	map<string, map<string, string>>mHero;
	//将英雄的数据写入到mData容器中  
	fm.loadCVSFile(path, mHero);
	//sprintf可以做一些格式化输出
	sprintf(buf, "1、%s  <%s>", mHero["1"]["heroName"].c_str(), mHero["1"]["heroInfo"].c_str());
	cout << buf << endl;
	sprintf(buf, "2、%s  <%s>", mHero["2"]["heroName"].c_str(), mHero["2"]["heroInfo"].c_str());
	cout << buf << endl;
	sprintf(buf, "3、%s  <%s>", mHero["3"]["heroName"].c_str(), mHero["3"]["heroInfo"].c_str());
	cout << buf << endl;

	int select = 0;  //接受用户的输入选择 
	cin >> select;
	cin.get();//读走enter回车符号  

	Hero hero(select);
	cout << "您选择的英雄是：" << hero.heroName<< endl;

	path = "Weapons.csv";
	map<string, map<string, string>>mWeapon;
	fm.loadCVSFile(path, mWeapon);
	memset(buf, 0, sizeof(buf));
	cout << "1、赤手空拳" << endl;
	sprintf(buf, "2、%s  ", mWeapon["1"]["weaponName"].c_str());
	cout << buf << endl;
	sprintf(buf, "3、%s  ", mWeapon["2"]["weaponName"].c_str());
	cout << buf << endl;
	sprintf(buf, "4、%s  ", mWeapon["3"]["weaponName"].c_str());
	cout << buf << endl;

	Weapon* weapon = NULL;
	cin >> select;
	cin.get();
	switch (select)
	{
	case 1:
		cout << "你真NB,等死吧！" << endl;
		break;
	case 2:
		weapon = new Knife;
		break;
	case 3:
		weapon = new broadSwod;
		break;
	case 4:
		weapon = new dragonSwrod;
		break;
	default:
		break;
	}
	hero.EquipWeapon(weapon);

	//创建怪物  
	int mId = rand() % 5 + 1;
	Monster monster(mId);
	int round = 1;
	while (true)
	{
		cin.get();
		system("cls");
		cout << "-----------当前第" << round << "回合-----------" << endl;
		if (hero.heroHp <= 0)
		{
			cout << "英雄<<" << hero.heroName << ">>已挂，游戏失败！" << endl;
			break;
		}
		hero.Attack(&monster);
		if (monster.monsterHp <= 0)
		{
			cout << "怪兽<<" << monster.monsterName << ">>已挂，游戏胜利！" << endl;
			break;
		}
		monster.Attack(&hero);
		cout << "英雄<<" << hero.heroName << ">>当前血量是：" << hero.heroHp <<"点！"<< endl;
		cout << "怪兽<<" << monster.monsterName<< ">>当前血量是：" << monster.monsterHp <<"点！"<< endl;
		if (hero.heroHp <= 0)
		{
			cout << "英雄<<" << hero.heroName << ">>已挂，游戏失败！" << endl;
			break;
		}
		round++;
	}
}
int main()
{
	/*fileManage fm;
	string path = "Weapons.csv";
	map<string, map<string, string>>mData;
	fm.loadCVSFile(path,mData);
	cout << "1号武器攻击力：" << mData["1"]["weaponAtk"] << endl;
	cout << "2号武器吸血率：" << mData["2"]["weaponSuckPlus"] << endl;*/
	//cout << "5号怪兽血量：" << mData["5"]["monsterHp"] << endl;
	/*Weapon *weapon = NULL;
	weapon = new Knife;
	cout << "1号武器名称：" << weapon->weaponName << endl;
	cout << "1号武器攻击力：" << weapon->getBaseDamage() << endl;
	cout << "1号武器吸血率：" << weapon->suckRate << endl;
	cout << "-----------------------------------------" << endl;
	delete weapon;

	weapon = new broadSwod;
	cout << "2号武器名称：" << weapon->weaponName << endl;
	cout << "2号武器攻击力：" << weapon->getBaseDamage() << endl;
	cout << "2号武器吸血率：" << weapon->suckRate << endl;
	cout << "-----------------------------------------" << endl;
	delete weapon;
	
	weapon = new dragonSwrod;
	cout << "3号武器名称：" << weapon->weaponName << endl;
	cout << "3号武器攻击力：" << weapon->getBaseDamage() << endl;
	cout << "3号武器吸血率：" << weapon->suckRate << endl;
	delete  weapon;*/
	srand((unsigned int)time(NULL));
	Fighting();
	system("pause");
	return EXIT_SUCCESS;
}