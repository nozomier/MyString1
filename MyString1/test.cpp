#include "MyString.h"
using namespace std;

int main()
{
	MyString a;
	cout << "������ȱʡ���캯��ʵ�ֳ�ʼ����" << endl;
	cout << "string a = " << a << endl;
	cout << "Length = " << a.length()  << endl;

	MyString b("567");
	cout << "��������ͨ���캯��ʵ�ֳ�ʼ����" << endl;
	cout << "string b = " << b << endl;
	cout << "Length = " << b.length()  << endl;

	MyString c(b);
	cout << "�����ÿ������캯��ʵ�ֳ�ʼ����" << endl;
	cout << "string c = " << c << endl;
	cout << "Length = " << c.length()  << endl;

	MyString c1(567);
	cout << "���������͹��캯��ʵ�ֳ�ʼ����" << endl;
	cout << "string c1 = " << c1 << endl;
	cout << "Length = " << c1.length()  << endl;

	MyString d = b;    //���ﲻ���ٴε���ȱʡ���캯�����г�ʼ��
	cout << "������ =(����) ʵ�ָ�ֵ��" << endl;
	cout << "string d = " << d << endl;
	cout << "Length = " << d.length()  << endl;

	MyString e1 = "00000000";
	MyString e;
	e = e1 + b;
	cout << "������ +��" << endl;//=(��ָ̬��) ʵ�ָ�ֵ
	cout << "string d = " << e << endl;
	//cout << "Length = " << e.length() << endl << endl;

	MyString f1 = "12345";
	MyString f =( f1 += 23.0);
	cout << "������ +=��" << endl;
	cout << "string f = " << f << endl;
	//cout << "Length = " << f.length() << endl << endl;

	//ɾ���Ӵ�
	cout << "������ -=��" << endl;
	MyString g1 = "12345";
	MyString g = (g1 -= "34");
	cout << "string g = " << g << endl;
	//����ɾ���Ӵ�
	cout << "���������� -=��" << endl;
	MyString h1(12345);
	MyString h = (h1 -= "34");
	cout << "string g = " << g << endl;

	
	MyString A1 = "123456789";
	MyString B1 = "4321";
	MyString C1 = "abcdefgh";
	//���ش�m��n
	cout << "������ substring��" << endl;
	cout << "��2-4λ�ǣ�";
	C1.subString(1,3);
	
	//Ѱ���Ӵ�λ��
	cout << "������ find��" << endl;
	int testfind=A1.find("34");
	int testfind2 = A1.find("99");
	cout << "�Ӵ���һ�γ��ֵ��±���" << testfind << endl;
	cout << "�����Ӵ���" << testfind2 << endl;

	//ת��Ϊ����
	cout << "������ toint��" << endl;
	MyString D1="114514";
	MyString D2 = "abcd";
	int testd1=D1.toint();
	int testd2 = D2.toint();
	cout << testd1 << endl;
	cout << "��toint����" << endl;
	cout << testd2 << endl;

	//ת��Ϊ������
	cout << "������ tofloat��" << endl;
	MyString E1;
	float frihata = E1.tofloat("114.514");
	cout << frihata << endl;

}
