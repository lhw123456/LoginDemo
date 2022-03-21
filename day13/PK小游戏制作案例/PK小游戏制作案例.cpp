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
	cout << "��ӭ�������µ�һ������" << endl;
	cout << "��ѡ������Ӣ�ۣ�" << endl;
	char buf[1024] = {0};
	fileManage fm;
	string path = "Hero.csv";
	map<string, map<string, string>>mHero;
	//��Ӣ�۵�����д�뵽mData������  
	fm.loadCVSFile(path, mHero);
	//sprintf������һЩ��ʽ�����
	sprintf(buf, "1��%s  <%s>", mHero["1"]["heroName"].c_str(), mHero["1"]["heroInfo"].c_str());
	cout << buf << endl;
	sprintf(buf, "2��%s  <%s>", mHero["2"]["heroName"].c_str(), mHero["2"]["heroInfo"].c_str());
	cout << buf << endl;
	sprintf(buf, "3��%s  <%s>", mHero["3"]["heroName"].c_str(), mHero["3"]["heroInfo"].c_str());
	cout << buf << endl;

	int select = 0;  //�����û�������ѡ�� 
	cin >> select;
	cin.get();//����enter�س�����  

	Hero hero(select);
	cout << "��ѡ���Ӣ���ǣ�" << hero.heroName<< endl;

	path = "Weapons.csv";
	map<string, map<string, string>>mWeapon;
	fm.loadCVSFile(path, mWeapon);
	memset(buf, 0, sizeof(buf));
	cout << "1�����ֿ�ȭ" << endl;
	sprintf(buf, "2��%s  ", mWeapon["1"]["weaponName"].c_str());
	cout << buf << endl;
	sprintf(buf, "3��%s  ", mWeapon["2"]["weaponName"].c_str());
	cout << buf << endl;
	sprintf(buf, "4��%s  ", mWeapon["3"]["weaponName"].c_str());
	cout << buf << endl;

	Weapon* weapon = NULL;
	cin >> select;
	cin.get();
	switch (select)
	{
	case 1:
		cout << "����NB,�����ɣ�" << endl;
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

	//��������  
	int mId = rand() % 5 + 1;
	Monster monster(mId);
	int round = 1;
	while (true)
	{
		cin.get();
		system("cls");
		cout << "-----------��ǰ��" << round << "�غ�-----------" << endl;
		if (hero.heroHp <= 0)
		{
			cout << "Ӣ��<<" << hero.heroName << ">>�ѹң���Ϸʧ�ܣ�" << endl;
			break;
		}
		hero.Attack(&monster);
		if (monster.monsterHp <= 0)
		{
			cout << "����<<" << monster.monsterName << ">>�ѹң���Ϸʤ����" << endl;
			break;
		}
		monster.Attack(&hero);
		cout << "Ӣ��<<" << hero.heroName << ">>��ǰѪ���ǣ�" << hero.heroHp <<"�㣡"<< endl;
		cout << "����<<" << monster.monsterName<< ">>��ǰѪ���ǣ�" << monster.monsterHp <<"�㣡"<< endl;
		if (hero.heroHp <= 0)
		{
			cout << "Ӣ��<<" << hero.heroName << ">>�ѹң���Ϸʧ�ܣ�" << endl;
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
	cout << "1��������������" << mData["1"]["weaponAtk"] << endl;
	cout << "2��������Ѫ�ʣ�" << mData["2"]["weaponSuckPlus"] << endl;*/
	//cout << "5�Ź���Ѫ����" << mData["5"]["monsterHp"] << endl;
	/*Weapon *weapon = NULL;
	weapon = new Knife;
	cout << "1���������ƣ�" << weapon->weaponName << endl;
	cout << "1��������������" << weapon->getBaseDamage() << endl;
	cout << "1��������Ѫ�ʣ�" << weapon->suckRate << endl;
	cout << "-----------------------------------------" << endl;
	delete weapon;

	weapon = new broadSwod;
	cout << "2���������ƣ�" << weapon->weaponName << endl;
	cout << "2��������������" << weapon->getBaseDamage() << endl;
	cout << "2��������Ѫ�ʣ�" << weapon->suckRate << endl;
	cout << "-----------------------------------------" << endl;
	delete weapon;
	
	weapon = new dragonSwrod;
	cout << "3���������ƣ�" << weapon->weaponName << endl;
	cout << "3��������������" << weapon->getBaseDamage() << endl;
	cout << "3��������Ѫ�ʣ�" << weapon->suckRate << endl;
	delete  weapon;*/
	srand((unsigned int)time(NULL));
	Fighting();
	system("pause");
	return EXIT_SUCCESS;
}