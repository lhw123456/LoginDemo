#if 1
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
using namespace std;
//1.string���캯�� 
//string();//����һ���յ��ַ��� ����: string str;      
//string(const string& str);//ʹ��һ��string�����ʼ����һ��string����
//string(const char* s);//ʹ���ַ���s��ʼ��
//string(int n, char c);//ʹ��n���ַ�c��ʼ�� 
void test01()
{
	string str1;
	string str2 = str1;
	string str3("hello world");
	string str4(3, 'a');
	cout << "str1=" << str1 << endl;
	cout << "str2=" << str2 << endl;
	cout << "str3=" << str3 << endl;
	cout << "str4=" << str4 << endl;
}
//2.string ��ֵ����
//string& operator=(const char* s);//char*�����ַ��� ��ֵ����ǰ���ַ���
//string& operator=(const string& s);//���ַ���s������ǰ���ַ���
//string& operator=(char c);//�ַ���ֵ����ǰ���ַ���
//string& assign(const char* s);//���ַ���s������ǰ���ַ���
//string& assign(const char* s, int n);//���ַ���s��ǰn���ַ�������ǰ���ַ���
//string& assign(const string& s);//���ַ���s������ǰ�ַ���
//string& assign(int n, char c);//��n���ַ�c������ǰ�ַ���
//string& assign(const string& s, int start, int n);//��s��start��ʼn���ַ���ֵ���ַ���
void test02()
{
	string str;
	str.assign("hello");
	string str2;
	str2.assign("hello", 2);
	cout << "str=" << str << endl;
	cout << "str2=" << str2 << endl;
	string str3;
	str3.assign(str, 2, 2);
	cout << "str3=" << str3 << endl;
}
//3.at ��[]���ʣ�at���ʻ��׳��쳣��
//char& operator[](int n);//ͨ��[]��ʽȡ�ַ�
//char& at(int n);//ͨ��at������ȡ�ַ�
void test03()
{
	string str("hello world");
	try 
	{
		cout << str.at(100) << endl;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	catch (...)
	{
		cout << "�쳣����" << endl;
	}
}
//4.�ַ���ƴ�� 
//string& operator+=(const string& str);//����+=������
//string& operator+=(const char* str);//����+=������
//string& operator+=(const char c);//����+=������
//string& append(const char* s);//���ַ���s���ӵ���ǰ�ַ�����β
//string& append(const char* s, int n);//���ַ���s��ǰn���ַ����ӵ���ǰ�ַ�����β
//string& append(const string& s);//ͬoperator+=()
//string& append(const string& s, int pos, int n);//���ַ���s�д�pos��ʼ��n���ַ����ӵ���ǰ�ַ�����β
//string& append(int n, char c);//�ڵ�ǰ�ַ�����β���n���ַ�c
void test04()
{
	string str1("��");
	str1 += "������";
	cout << "str1=" << str1 << endl;
	str1.append("�찲��");
	cout << "str1=" << str1 << endl;
}
//5.string���� 
//int find(const string& str, int pos = 0) const; //����str��һ�γ���λ��,��pos��ʼ����
//int find(const char* s, int pos = 0) const;  //����s��һ�γ���λ��,��pos��ʼ����
//int find(const char* s, int pos, int n) const;  //��posλ�ò���s��ǰn���ַ���һ��λ��
//int find(const char c, int pos = 0) const;  //�����ַ�c��һ�γ���λ��
//int rfind(const string& str, int pos = npos) const;//����str���һ��λ��,��pos��ʼ����
//int rfind(const char* s, int pos = npos) const;//����s���һ�γ���λ��,��pos��ʼ����
//int rfind(const char* s, int pos, int n) const;//��pos����s��ǰn���ַ����һ��λ��
//int rfind(const char c, int pos = 0) const; //�����ַ�c���һ�γ���λ��
//string& replace(int pos, int n, const string& str); //�滻��pos��ʼn���ַ�Ϊ�ַ���str
//string& replace(int pos, int n, const char* s); //�滻��pos��ʼ��n���ַ�Ϊ�ַ���s
void test05()
{
	string str("helloworllod");
	int pos=str.find("llo", 0);
	cout << "pos=" << pos << endl;

	int pos1 = str.rfind('o');
	cout << "pos1=" << pos1 << endl;
	str.replace(1, 3, "oooooo");
	cout << "str=" << str << endl;
}
//6.�ַ����Ƚ�
void test06()
{
	string str1 = "hello";
	string str2("hello");
	if (str1.compare(str2) == 0)
	{
		cout << "str1=str2" << endl;
	}
	else if (str1.compare(str2) > 0)
	{
		cout << "str1>str2" << endl;
	}
	else
	{
		cout << "str1<str2" << endl;
	}
}
//7.��ȡ�Ӵ� 
void test07()
{
	string str = "abcdef";
	string subString = str.substr(0, 3);
	cout << "subString=" << subString << endl;
}
//8.����1  zhangtao@sina.com.cn   ��ȡ@ǰ����ַ�������@ǰ����ַ��Ǽ�λ��
void test08()
{
	string str = "zhangtao111@sina.com.cn";
	int pos = str.find("@");  //pos=8
	string subStr = str.substr(0,pos);
	cout << "subStr=" << subStr << endl;
}
//9.����2   ��ȡ��.���ַ��洢��vector<string>������   eg: www.itcast.com.cn    www itcast com cn 
void test09()
{
	string str = "www.itcast.com.cn";
	//int pos = str.find(".");  //pos=3
	//cout << "pos=" <<pos<<endl;

	//int pos1 = str.find(".",pos+1);  //pos=10
	//cout << "pos1=" << pos1 << endl;
	vector<string>v;
	int pos = 0;
	int start = 0;
	while (true)
	{
		pos = str.find(".",start);
		if (pos == -1)
		{
			string temp = str.substr(start, str.size() - start);
			v.push_back(temp);
			break;
		}
		string temp = str.substr(start, pos - start);
		start = pos + 1;
		v.push_back(temp);
	}
	for (auto &c : v)
	{
		cout << c << endl;
	}
}
//10.�ַ��������ɾ��
//string& insert(int pos, const char* s); //�����ַ���
//string& insert(int pos, const string& str); //�����ַ���
//string& insert(int pos, int n, char c);//��ָ��λ�ò���n���ַ�c
//string& erase(int pos, int n = npos);//ɾ����Pos��ʼ��n���ַ� 
void test10()
{
	string str = "helloworld";
	string str1 = str.insert(1, "1111");
	cout << "str1=" << str1 << endl;
	
	str.erase(1, 4);
	cout << "str=" << str << endl;
}
//11.string��c����ַ���ת��  
//string ת char*
//string str = "itcast";
//const char* cstr = str.c_str();
////char* ת string 
//char* s = "itcast";
//string str(s);
void test11()
{
	const char* str = "hello";
	string str1(str);
	cout << "str1=" << str1 << endl;
	const char* str2 = str1.c_str();
	cout << "str2=" << str2 << endl;
}
//12. Ϊ���޸�string�ַ��������ݣ��±������[]��at���᷵���ַ������á������ַ������ڴ汻���·���֮�󣬿��ܷ�������.
void test12()
{
	string s = "hello";
	char& a = s[1];
	char& b = s[2];
	cout << "a=" << a << "  b=" << b << endl;

	/*s = "pppppppppppppppppppppppppppppppppppppp";
	a = '1';
	b = '1';
	cout << "s=" << s << endl;*/
}
//13.��Сд��ĸ֮���ת��  
void test13()
{
	string s = "HELLOworld";
	for (int i = 0; i < s.size(); ++i)
	{
		s[i] = tolower(s[i]);
	}
	cout << "s=" << s << endl;
}
int main()
{
	test13();
	system("pause");
	return EXIT_SUCCESS;
}
#endif