#if 1
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
using namespace std;
//1.string构造函数 
//string();//创建一个空的字符串 例如: string str;      
//string(const string& str);//使用一个string对象初始化另一个string对象
//string(const char* s);//使用字符串s初始化
//string(int n, char c);//使用n个字符c初始化 
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
//2.string 赋值函数
//string& operator=(const char* s);//char*类型字符串 赋值给当前的字符串
//string& operator=(const string& s);//把字符串s赋给当前的字符串
//string& operator=(char c);//字符赋值给当前的字符串
//string& assign(const char* s);//把字符串s赋给当前的字符串
//string& assign(const char* s, int n);//把字符串s的前n个字符赋给当前的字符串
//string& assign(const string& s);//把字符串s赋给当前字符串
//string& assign(int n, char c);//用n个字符c赋给当前字符串
//string& assign(const string& s, int start, int n);//将s从start开始n个字符赋值给字符串
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
//3.at 和[]访问（at访问会抛出异常）
//char& operator[](int n);//通过[]方式取字符
//char& at(int n);//通过at方法获取字符
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
		cout << "异常捕获" << endl;
	}
}
//4.字符串拼接 
//string& operator+=(const string& str);//重载+=操作符
//string& operator+=(const char* str);//重载+=操作符
//string& operator+=(const char c);//重载+=操作符
//string& append(const char* s);//把字符串s连接到当前字符串结尾
//string& append(const char* s, int n);//把字符串s的前n个字符连接到当前字符串结尾
//string& append(const string& s);//同operator+=()
//string& append(const string& s, int pos, int n);//把字符串s中从pos开始的n个字符连接到当前字符串结尾
//string& append(int n, char c);//在当前字符串结尾添加n个字符c
void test04()
{
	string str1("我");
	str1 += "爱北京";
	cout << "str1=" << str1 << endl;
	str1.append("天安门");
	cout << "str1=" << str1 << endl;
}
//5.string查找 
//int find(const string& str, int pos = 0) const; //查找str第一次出现位置,从pos开始查找
//int find(const char* s, int pos = 0) const;  //查找s第一次出现位置,从pos开始查找
//int find(const char* s, int pos, int n) const;  //从pos位置查找s的前n个字符第一次位置
//int find(const char c, int pos = 0) const;  //查找字符c第一次出现位置
//int rfind(const string& str, int pos = npos) const;//查找str最后一次位置,从pos开始查找
//int rfind(const char* s, int pos = npos) const;//查找s最后一次出现位置,从pos开始查找
//int rfind(const char* s, int pos, int n) const;//从pos查找s的前n个字符最后一次位置
//int rfind(const char c, int pos = 0) const; //查找字符c最后一次出现位置
//string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
//string& replace(int pos, int n, const char* s); //替换从pos开始的n个字符为字符串s
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
//6.字符串比较
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
//7.截取子串 
void test07()
{
	string str = "abcdef";
	string subString = str.substr(0, 3);
	cout << "subString=" << subString << endl;
}
//8.案例1  zhangtao@sina.com.cn   截取@前年的字符（无论@前面的字符是几位）
void test08()
{
	string str = "zhangtao111@sina.com.cn";
	int pos = str.find("@");  //pos=8
	string subStr = str.substr(0,pos);
	cout << "subStr=" << subStr << endl;
}
//9.案例2   截取非.的字符存储在vector<string>容器中   eg: www.itcast.com.cn    www itcast com cn 
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
//10.字符串插入和删除
//string& insert(int pos, const char* s); //插入字符串
//string& insert(int pos, const string& str); //插入字符串
//string& insert(int pos, int n, char c);//在指定位置插入n个字符c
//string& erase(int pos, int n = npos);//删除从Pos开始的n个字符 
void test10()
{
	string str = "helloworld";
	string str1 = str.insert(1, "1111");
	cout << "str1=" << str1 << endl;
	
	str.erase(1, 4);
	cout << "str=" << str << endl;
}
//11.string和c风格字符串转换  
//string 转 char*
//string str = "itcast";
//const char* cstr = str.c_str();
////char* 转 string 
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
//12. 为了修改string字符串的内容，下标操作符[]和at都会返回字符的引用。但当字符串的内存被重新分配之后，可能发生错误.
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
//13.大小写字母之间的转换  
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