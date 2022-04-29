#include "MyString.h"
using namespace std;

int main()
{
	MyString a;
	cout << "【调用缺省构造函数实现初始化】" << endl;
	cout << "string a = " << a << endl;
	cout << "Length = " << a.length()  << endl;

	MyString b("567");
	cout << "【调用普通构造函数实现初始化】" << endl;
	cout << "string b = " << b << endl;
	cout << "Length = " << b.length()  << endl;

	MyString c(b);
	cout << "【调用拷贝构造函数实现初始化】" << endl;
	cout << "string c = " << c << endl;
	cout << "Length = " << c.length()  << endl;

	MyString c1(567);
	cout << "【调用整型构造函数实现初始化】" << endl;
	cout << "string c1 = " << c1 << endl;
	cout << "Length = " << c1.length()  << endl;

	MyString d = b;    //这里不会再次调用缺省构造函数进行初始化
	cout << "【调用 =(对象) 实现赋值】" << endl;
	cout << "string d = " << d << endl;
	cout << "Length = " << d.length()  << endl;

	MyString e1 = "00000000";
	MyString e;
	e = e1 + b;
	cout << "【调用 +】" << endl;//=(动态指针) 实现赋值
	cout << "string d = " << e << endl;
	//cout << "Length = " << e.length() << endl << endl;

	MyString f1 = "12345";
	MyString f =( f1 += 23.0);
	cout << "【调用 +=】" << endl;
	cout << "string f = " << f << endl;
	//cout << "Length = " << f.length() << endl << endl;

	//删除子串
	cout << "【调用 -=】" << endl;
	MyString g1 = "12345";
	MyString g = (g1 -= "34");
	cout << "string g = " << g << endl;
	//整型删除子串
	cout << "【调用整型 -=】" << endl;
	MyString h1(12345);
	MyString h = (h1 -= "34");
	cout << "string g = " << g << endl;

	
	MyString A1 = "123456789";
	MyString B1 = "4321";
	MyString C1 = "abcdefgh";
	//返回从m到n
	cout << "【调用 substring】" << endl;
	cout << "第2-4位是：";
	C1.subString(1,3);
	
	//寻找子串位置
	cout << "【调用 find】" << endl;
	int testfind=A1.find("34");
	int testfind2 = A1.find("99");
	cout << "子串第一次出现的下标是" << testfind << endl;
	cout << "错误子串：" << testfind2 << endl;

	//转化为整数
	cout << "【调用 toint】" << endl;
	MyString D1="114514";
	MyString D2 = "abcd";
	int testd1=D1.toint();
	int testd2 = D2.toint();
	cout << testd1 << endl;
	cout << "【toint错误】" << endl;
	cout << testd2 << endl;

	//转化为浮点数
	cout << "【调用 tofloat】" << endl;
	MyString E1;
	float frihata = E1.tofloat("114.514");
	cout << frihata << endl;

}
