#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>    //会借用strlen与strcpy函数实现相应的功能
using namespace std;

class MyString {
public:
	//构造函数+析构函数
	MyString();
	MyString(const char* const);
	MyString(const MyString&);
	MyString(const int str);
	~MyString();

	//直接调用字符串首指针返回，返回的指针可以直接使用cout<<输出
	const char* getString() const;

	//求字符串的长度(直接返回类中的私有成员len的值)
	//const函数不能修改其数据成员,仅仅起到输出数据的作用
	int length()const;
	int size() const;

	//重载赋值运算符，使得可以使用对象与"xxxxxx"来赋值
	MyString& operator = (const MyString&);
	MyString& operator = (const char*);
	//friend MyString operator+(const MyString& , const MyString& );
	MyString& operator += (double a);
	MyString& operator +  (const MyString&);
	//MyString& operator-=(int str);
	MyString& operator -= (const char* str);
	//重载下标运算符
	char& operator [] (const int index);

	//重载输出运算符
	friend ostream& operator << (ostream&, const MyString&);


	//对字符串进行倒置
	void Reverse();
	//返回从m开始的第n个字母
	MyString subString(int ,int );

	//查询某字符串是否是指定字符串的子串,返回其位置
	int find(const MyString& other);
	//查询某字符串是否是指定字符串的子串(暴力模式)
	bool Find(char* search_string);
	//转换为整型
	int toint();
	//转换为浮点型
	double tofloat(string str);
	double tofloat(const char* str);

private:
	char* str;    //指向数组首地址(此时为野指针)
	int len;    //字符串的长度

};

