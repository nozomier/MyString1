#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>    //�����strlen��strcpy����ʵ����Ӧ�Ĺ���
using namespace std;

class MyString {
public:
	//���캯��+��������
	MyString();
	MyString(const char* const);
	MyString(const MyString&);
	MyString(const int str);
	~MyString();

	//ֱ�ӵ����ַ�����ָ�뷵�أ����ص�ָ�����ֱ��ʹ��cout<<���
	const char* getString() const;

	//���ַ����ĳ���(ֱ�ӷ������е�˽�г�Աlen��ֵ)
	//const���������޸������ݳ�Ա,������������ݵ�����
	int length()const;
	int size() const;

	//���ظ�ֵ�������ʹ�ÿ���ʹ�ö�����"xxxxxx"����ֵ
	MyString& operator = (const MyString&);
	MyString& operator = (const char*);
	//friend MyString operator+(const MyString& , const MyString& );
	MyString& operator += (double a);
	MyString& operator +  (const MyString&);
	//MyString& operator-=(int str);
	MyString& operator -= (const char* str);
	//�����±������
	char& operator [] (const int index);

	//������������
	friend ostream& operator << (ostream&, const MyString&);


	//���ַ������е���
	void Reverse();
	//���ش�m��ʼ�ĵ�n����ĸ
	MyString subString(int ,int );

	//��ѯĳ�ַ����Ƿ���ָ���ַ������Ӵ�,������λ��
	int find(const MyString& other);
	//��ѯĳ�ַ����Ƿ���ָ���ַ������Ӵ�(����ģʽ)
	bool Find(char* search_string);
	//ת��Ϊ����
	int toint();
	//ת��Ϊ������
	double tofloat(string str);
	double tofloat(const char* str);

private:
	char* str;    //ָ�������׵�ַ(��ʱΪҰָ��)
	int len;    //�ַ����ĳ���

};

