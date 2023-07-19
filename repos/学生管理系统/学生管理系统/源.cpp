#include<iostream>
#include<list>
#include<string>
#include<set>
#include<map>
using namespace std;
struct node
{
	node(int data,string name):data(data),name(name){}
	node(){}
	int data;
	string name;
};
class compareByname
{
public:
	bool operator()(node std1, node std2)
	{
		return std1.data < std2.data;
	}
};
bool compareByName(node std1, node std2)
{
	return std1.data < std2.data;
}
class system
{
public:
	
	system() {};
	void meau()
	{
		cout << "***************************" << endl;
		cout << "按0\t  退出" << endl;
		cout << "按1\t  录用信息" << endl;
		cout << "按2\t  删除信息" << endl;
		cout << "按3\t  查找信息" << endl;
	}
	void keyDown()
	{
		cout << "请输入相应的按键" << endl;
		char key;
		cin >> key;
		switch (key - 48)
		{
			case 0:
				exit(0);
				break;
			case 1:
			{

				cout << "输入学生的姓名\t年龄" << endl;
				node stu;
				cin >> stu.name >> stu.data;
				this->student.push_back(stu);
				break;
			}
			case2:
			{
				cout << "输入学生的姓名\t年龄" << endl;
				 

			}
		}
	}
	void push_back(node stu)
	{
		this->student.push_back(stu);
	}
	void push_front(node stu)
	{
		this->push_front(stu);
	}
	void pop_back()
	{
		this->student.pop_back();
	}
	void pop_front()
	{
		this->student.pop_front();
	}
	void search_node(node stu)
	{
		list<node>::iterator iter;
		for (iter = student.begin(); iter->name != stu.name; iter++)
		{
			
		}
		if (iter != student.end())
		{
			cout << iter->data << "   " << iter->name << endl;
		}
		else
		{
			cout << "没有知道相应的姓名" << endl;
		}
		
	}
	void delete_node(node stu)
	{
		list<node>::iterator iter;
		for (iter = student.begin(); iter->name != stu.name; iter++)
		{

		}
		if (iter != student.end())
		{
			this->student.erase(iter);
		}
		else
		{
			cout << "没有找到要delete的姓名" << endl;
		}
	}
	bool empty()
	{
		return student.empty();
	}
	int size()
	{
		return student.size();
	}
	void printflist()
	{
		for (auto v : this->student)
		{
			cout << v.name << "  " << v.data << endl;
		}
	}
	void sort_node()
	{
		student.sort(compareByName);
	}
	 friend bool operator>(node std1,node std2) 
	{
		return std1.data < std2.data;
	}
protected:
	list<node> student;
};
void testset()
{
	set<int> s{ 1,2,35,6,7,8,9,1 };
	for (auto v : s)
	{
		cout << v << "  ";
	}
}
void testmap()
{
	map<int ,string>mapset;
	mapset[1] = "kkkk";
	mapset[2] = "5555";
	mapset[-1] = "lll";
	for (auto v : mapset)
	{
		cout << v.first<<"  "<<v.second << endl;
	}

}
int main()
{
	class system Sys_student;
	Sys_student.push_back({ 17,"张三" });
	Sys_student.push_back(node(18, "李四"));
	Sys_student.printflist();

	testset();
	cout << endl;
	testmap();


	return 0;
}