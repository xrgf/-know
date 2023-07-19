#include<iostream>
#include<string>
using namespace std;
class father
{
public:
	father() { cout << "父类无参构造函数" << endl; }
	father(string name, int age) :name(name), age(age) { cout << "父类有参构造函数" << endl; }
	void printf()
	{
		cout << name << "\t" << age << endl;
	}
	friend ostream& operator<<(ostream& out, father f)
	{
		out << f.age << "\t" << f.name << endl;
		return out;
	}
	friend istream& operator>>(istream& in, father& f)
	{
		cin >>f.name >> f.age;
		return in;
	}
protected:
	string name;
	int age;
};
class son : public father
{
public:
	son():father() { cout << "子类无参构造函数" << endl; }
	son(string name, int age,int num) :father(name, age),num(num ){ cout << "子类有参构造函数" << endl; }
	son(int num) :father("mm", 100), num(num) { cout << "父类固定化" << endl; }
	void printff()
	{
		cout << name << "\t" << age <<"\t" << num << endl;
		
	}

protected:
	int num;
};
class A
{
public:
	A(int a) :a(a) { cout << "A" << endl; }
protected:
	int a;
};
class B :public virtual A
{
public:
	B(int a, int b) :A(a), b(b) { cout << "B" << endl; }
protected:
	int b;
};
class C :public virtual A
{
public:
	C(int a, int c) :A(a), c(c) { cout << "C" << endl; }
protected:
	int c;
};
class D :public B, public C
{
public:
	D(int a, int b, int c, int d) :B(a, b), C(a, c), A(a), d(d) { cout << "D" << endl; }
	void printf()
	{
		cout << a << "\t" << b << "\t" << "\t" << c << "\t" << d << endl;
	}
protected:
	int d;
};
int i = 50;
int main()
{
	/*son s;
	son s1("张三", 18,50);
	s1.printff();*/
	father f("baba", 50);
	/*cout << f;
	operator<<(cout, f);
	cin >> f;
	/*cout << f;*/
	/*son s3(50);
	s3.printff();
	son s4(10);
	s4.printff(); */
	/*	D d(1, 2, 3, 4);
		d.printf();
		D* d1 = &d;
		d1->printf();*/
	int i = 10;
	cout << i << endl;
	cout << ::i << endl;

	return 0;
}