#include<iostream>
using namespace std;
template<typename _T>
class A
{
public:
	//A(_T date):date(date){}
void printf();
protected:
	_T date;
};
template<class _>
void A<_>::printf()
{
	cout << this->date;
}
template <class _T>
class B :public A<_T>
{
public:
	//B(_T date):A<_T>(date){}
	void printff();
protected:
	int age;
};
template <class _T>
void B<_T>::printff()
{
	cout << "kk" << endl;
}
class C
{
public:
	template <class _t>
	void printfk();
	template<class _t>
	void printfkk(_t date);
protected:
};
template <class _t>
void C::printfk()
{
	cout << "LLL" << endl;
}
template<class _t>
void C::printfkk(_t date)
{
	cout << date << endl;
}
template <class _T1, class _T2>

struct mypair
{
	_T1 first;
	_T2 secend;
	mypair(_T1 first,_T2 secend):first(first),secend(secend){}
	void printf();
};
template<class a,class b>
void mypair<a, b>::printf()
{
	cout << first << "\t" << secend << endl;
}
int main()
{/*
	A<int> a(15);
	a.printf();
	A<string>* a1 = new A<string>("kkk");
	a1->printf();*/
	
	//B<string> b;
	//b.printff();
	C c;
	c.printfk<int>();//无参一定要显示调用
	c.printfkk(12);//代参数的时候可以隐式调用
	c.printfkk("kk");   
	mypair<int, string > mm(15, "mama");
	mm.printf();
	pair <int, string> tt = make_pair<int, string>(1, "mm");
	pair<int, int> ll = make_pair<int, int>(1, 1 );
	
	cout << tt.second;




	return 0;
}