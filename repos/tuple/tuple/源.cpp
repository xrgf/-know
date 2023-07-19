#include<list>
#include<iostream>
#include<functional>
using namespace std;
template <class _T>
void printflist(list<_T>data)
{
	for (auto v : data)
	{
		cout << v << "  ";
	}
}
class A
{
public:
	class B
	{
	public:
		void printff()
		{
			cout << "interor" << endl;
		}
	protected:
		int num;
	};
protected:
	int age;
};

int main()
{
	A::B b;
	b.printff();
	

	

	
	
	
	//while (!strname.empty())
	//{
	//	cout << endl;
	//	cout << strname.front();
	//	strname.pop_front();
	//	cout << endl;
	//	cout << strname.size();
	//}


	return 0;
}