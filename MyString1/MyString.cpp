#include "MyString.h"
using namespace std;

MyString::MyString()    //������ַ���temp
{
	str = new char[1];
	str[0] = '\0';
	len = 0;
}

MyString::MyString(const char* const P)    //���ն�ָ̬����������Ӧ���ַ���temp(567)
{
	if (P)
	{
		len = strlen(P);    //ȡ����
		str = new char[len + 1];    //���ռ�
		strcpy(str, P);    //����ֵ
	}
	else
	{
		MyString();    //���������ַ���Ϊ�գ�ֱ�ӵ���/0���캯��
	}
}

MyString::MyString(const MyString& AnotherMyString)  //�������캯����������β�ʹ����const�����β����е����к�����Ҫʹ��const������
{
	len = AnotherMyString.length();
	str = new char[len + 1];
	strcpy(str, AnotherMyString.str);
}

MyString::MyString(const int str)
{
	int digitofnum = floor(log10(str)) + 1;
	char* a = new char[digitofnum];;
	sprintf(a, "%d", str);
	int len1 = strlen(a);
	this->len = len1;
	this->str = new char[len1 + 1];
	strcpy(this->str, a);

}

int MyString::length() const   //�󳤶ȳ�Ա����
{
	return len;
}

int MyString::size() const
{
	return len;
}

const char* MyString::getString()const
{
	return str;
}

MyString& MyString::operator=(const MyString& AnotherMyString)
{
	if (&AnotherMyString == this)
	{
		return *this;
	}
	//delete[] str;
	len = AnotherMyString.length();
	str = new char[len + 1];
	strcpy(str, AnotherMyString.str);
	return *this;
	// TODO: �ڴ˴����� return ���
}

MyString& MyString::operator=(const char* P)
{
	//delete[] str;
	len = strlen(P);
	str = new char[len + 1];
	strcpy(str, P);
	return *this;

}


MyString& MyString::operator+(const MyString& other)
{
	
	int len = strlen(str) + strlen(other.str) + 1;
	char* tmp = new char[len];
	memset(tmp, 0, len);
	strcpy(tmp, str);
	strcat(tmp, other.str);
	MyString str1(tmp);
	delete[] str;

	str = tmp;
	return *this;
	
}

MyString& MyString::operator+=(double str)
{
	char* a = new char[10000];
	sprintf(a, "%.1f", str);
	len = strlen(a);
	MyString b(a);
	*this = *this + b;
	return *this;
}


MyString& MyString::operator-=(const char* str)
{
	MyString temp1,temp2;
	char* a = new char[10];//a="23"
	int len1 = strlen(str);
	int len2 = strlen(this->str);
	char* c_str = this->str;
	int skr=find(str);
	int i,j = 0;
	//cout << skr;//��c_str[skr]��ʼ��ɾ��len1��
	//cout << len1<<len2 << endl;
	if (skr != -1) {
		for (i = 0; i < skr;i++) {
				a[j] = c_str[i];
				//cout << a[j] << endl;
				j++;
			}
		for (i = skr+len1; i < len2; i++) {
			a[j] = c_str[i];
			j++;
		}
		a[j + 1] = '\0';
	}
	//cout << a << endl;
	this->str = a;
	return *this;
}


char& MyString::operator[](const int index)
{
	if (index > len)    //�������Խ�磬������һ���ַ�
	{
		cout << "Warning!!!" << endl;
		cout << "Out of boundary! The last char is: ";
		return str[len - 1];
	}
	else
	{
		return str[index - 1];
	}
	// TODO: �ڴ˴����� return ���
}

void MyString::Reverse()
{
	int length = this->len;
	char* c_str = this->str;
	char temp_data;
	for (int i = 0; i < length / 2; i++)
	{
		temp_data = c_str[i];
		c_str[i] = c_str[length - 1 - i];
		c_str[length - 1 - i] = temp_data;
	}
}

MyString MyString::subString(int m, int n) {

	MyString temp;
	char* c_str = this->str;
	char* str2 = new char[n + 2];
	int i = 0;
	for (i = 0; i < n; i++) {
		str2[i] = c_str[m + i];
	}
	str2[i + 1] = '\0';
	cout << str2 << endl;
	return *this;
}


int MyString::find(const MyString& other)
{

	int len1, len2;
	int i = 0;
	len1 = this->len;
	char* c_str = this->str;
	len2 = strlen(other.str);
	bool judge = false;
	//ȷ��iÿ�ο��������ƶ�һλ
	int location=0;
	char* loc = strstr(this->str, other.str);
	char* str2 = new char[100];
	str2 = loc;
	int k = 0;
	for (int i = 0; c_str[i] != '\0'; i++) {
		if (k == 0 && c_str[i] == other.str[k]) {
			k++;
			continue;
		}
		if (k > 0 && c_str[i] == other.str[k]) {
			k++;
			if (k == strlen(other.str)) {
				location = i - k + 1;
				//cout << location << endl;
				return location;//����Ŀ���ַ������Ӵ�ĩβ-�Ӵ�����+1
			}
			continue;
		}
		k = 0;
	}
	return -1;//û�ҵ�����
}

int MyString::toint() {
	MyString temp;
	int len1;
	int i=0,flag=0,j = 0;
	len1 = this->len;
	int nozomi=0;
	char* c_str = this->str;
	//cout << c_str[0];
	for (j = 0; j < (int)strlen(c_str); j++)
	{
		nozomi = nozomi * 10 + (c_str[j] - '0');//ASCLL����48Ϊ����0)
		//cout <<1111<< nozomi << endl;
	}
	for (i = 0; i < len1; i++) {
		if (c_str[i] > '9' || c_str[i] < '1')
		{
			nozomi = -2;
			return nozomi;
			//return -2;
		}
	}
	return nozomi;


}

double MyString::tofloat(string str) {
	float f = atof(str.c_str());
	//cout << f;
	return f;
}

double MyString::tofloat(const char* str) {
	int i = 0, j = 0;
	bool flag = 1;
	float sum = 0;
	int len1 = strlen(str);
	while (str[i] != '\0') {
		if (str[i] == '.')flag = 0;
		if (flag == 1) {
			if (i == 0)sum += ((int)str[i] - 48);
			else sum = sum * 10 + ((int)str[i] - 48);
		}
		if (flag == 0 && str[i] != '.') {
			if (j == 0)sum = sum + ((int)str[i] - 48) / 10.0;
			if (j == 1)sum = sum + ((int)str[i] - 48) / 100.0;
			if (j == 2)sum = sum + ((int)str[i] - 48) / 1000.0;
			if (j == 3)sum = sum + ((int)str[i] - 48) / 10000.0;
			if (j == 4)sum = sum + ((int)str[i] - 48) / 100000.0;
			j++;
		}
		i++;
	}
	return sum;
}

bool MyString::Find(char* search_string)
{
	int length = this->len;
	char* c_str = this->str;
	bool judge = false;
	//ȷ��iÿ�ο��������ƶ�һλ
	int temp_data = 0;

	for (int i = 0, j = 0; j < strlen(search_string) && i < length; )
	{
		if (c_str[i] == search_string[j])
		{
			//cout << c_str[i] << "==" << search_string[j] << endl;
			//cout << i << "::" << j << endl;
			judge = true;
			i++;
			j++;
		}
		else
		{
			judge = false;
			temp_data++;
			i = temp_data;
			j = 0;
		}
	}
	return judge;
}


MyString::~MyString()    //�ͷ�����ռ�
{
	delete[] str;
	len = 0;
}

ostream& operator << (ostream& output, const MyString& str)    //������������
{
	output << str.getString();
	return output;
	// TODO: �ڴ˴����� return ���
}

