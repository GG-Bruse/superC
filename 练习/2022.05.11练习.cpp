//#include<iostream>
//#include<iomanip>
//using namespace std;
//int main()
//{
//	double num;
//	cin >> num;
//	double ret = 5 * (num - 32) / 9;
//	cout.setf(ios::fixed);
//	cout << setprecision(2) << ret << endl;
//	return 0;
//}



//#include<iostream>
//using namespace std;
//class Base
//{
//public:
//	void setx(int n)
//	{
//		this->x = n;
//	}
//	void showx()
//	{
//		cout << this->x << endl;
//	}
//private:
//	int x;
//};
//class Derived : private Base
//{
//public:
//	void setxy(int n, int m)
//	{
//		setx(n);
//		this->y = m;
//	}
//	void showxy()
//	{
//		this->showx();
//		//cout << x << endl;
//	    cout<< this->y << endl;
//	}
//private:
//	int y;
//};
//int main()
//{
//	Derived obj;
//	//obj.setx(10);
//	//obj.showx();
//	obj.setxy(20, 30);
//	obj.showxy();
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class Base
//{
//public:
//	void seta(int sa)
//	{
//		this->a = sa;
//	}
//	void showa()
//	{
//		cout << "a = " << a << endl;
//	}
//protected:
//	int a;
//};
//class Derived1 :private Base
//{
//public:
//	void setab(int sa, int sb)
//	{
//		this->a = sa;
//		this->b = sb;
//	}
//	void showab()
//	{
//		cout << "a = " << a << endl;
//		cout << "b = " << b << endl;
//	}
//protected:
//	int b;
//};
//class Derived2 :private Derived1
//{
//public:
//	void setabc(int sa, int sb, int sc)
//	{
//		setab(sa, sb);
//		this->c = sc;
//	}
//	void showabc()
//	{
//		showab();
//		cout << "c = "<<this->c << endl;
//	}
//private:
//	int c;
//};
//int main()
//{
//	Base op1;
//	op1.seta(1);
//	op1.showa();
//	Derived1 op2;
//	op2.setab(2, 3);
//	op2.showab();
//	Derived2 op3;
//	op3.setabc(4, 5, 6);
//	op3.showabc();
//	return 0;
//}






#include<iostream>
using namespace std;
class Base
{
public:
	void setxy(int m, int n)
	{
		this->x = m;
		this->y = n;
	}
	void showxy()
	{
		cout << "x = " << this->x << endl;
		cout << "y = " << this->y << endl;
	}
private:
	int x;
protected:
	int y;
};
class Derived :public Base
{
public:
	void setxyz(int m, int n, int l)
	{
		setxy(m, n);
		z = l;
	}
	void showxyz()
	{
		this->showxy();
		cout << "x = " << z << endl;
	}
private:
	int z;
};
int main()
{
	Derived obj;
	obj.setxyz(30, 40, 50);
	obj.showxy();
	obj.showxyz();
	return 0;
}










