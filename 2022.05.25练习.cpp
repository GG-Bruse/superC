#include<iostream>
using namespace std;
class Person
{
public:
	Person(int a)
	{
		this->age = a;	
	}	
	void setage(int a)
	{
		this->age = a;
	}
	void show()
	{
		cout<<"age is "<<this->age<<endl;
	}
private:
	int age;	
};
class Student:private Person
{
public:	
	Student(int a,int b):Person(a)
	{
		this->cridit = b;	
	}
	void setage_cre(int a,int b)
	{
		Person::setage(a);
		this->cridit = b;	
	}
	void show()
	{
		Person::show();
		cout<<"cridit is "<<this->cridit<<endl;
	}
private:
	int cridit;	
};
int main()
{
	Student stu1(19,166);
	stu1.setage_cre(20,168);
	stu1.show();
	return 0;
}





#include<iostream>
using namespace std;
class B
{
public:
	B(int a)
	{
		i = a;
		cout<<"c base"<<endl;
	}
	void showI()
	{
		cout<<i<<endl;
	}
	~B(){cout<<"d base"<<endl;}
private:
	int i;	
};
class D:public B
{
public:
	D(int a,int b):B(b)
	{
		j = a;
		cout<<"c derived"<<endl; 
	}
	void showIJ()
	{
		B::showI();
		cout<<j<<endl; 
	}
	~D()
	{
		cout<<"d derived"<<endl; 
	}
private:	
	int j;
};
int main()
{
	D obj(50,60);
	obj.showIJ();
	return 0;
}








#include<iostream>
using namespace std;
class base1
{
public:
	base1()
	{
		cout<<"class base1"<<endl;
	}
};
class base2
{
public:
	base2()
	{
		cout<<"class base2"<<endl;
	}	
};
class level1:public base2,virtual public base1{
public:
	level1()
	{
		cout<<"class level1"<<endl;
	}	
};
class level2:public base2,virtual public base1{
public:
	level2()
	{
		cout<<"class level2"<<endl;
	}	
};
class toplevel:public level1,virtual public level2{
public:
	toplevel()
	{
		cout<<"class toplevel"<<endl;
	}
};
int main()
{
	toplevel obj;
	return 0;
}




