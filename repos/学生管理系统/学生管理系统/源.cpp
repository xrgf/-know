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
		cout << "��0\t  �˳�" << endl;
		cout << "��1\t  ¼����Ϣ" << endl;
		cout << "��2\t  ɾ����Ϣ" << endl;
		cout << "��3\t  ������Ϣ" << endl;
	}
	void keyDown()
	{
		cout << "��������Ӧ�İ���" << endl;
		char key;
		cin >> key;
		switch (key - 48)
		{
			case 0:
				exit(0);
				break;
			case 1:
			{

				cout << "����ѧ��������\t����" << endl;
				node stu;
				cin >> stu.name >> stu.data;
				this->student.push_back(stu);
				break;
			}
			case2:
			{
				cout << "����ѧ��������\t����" << endl;
				 

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
			cout << "û��֪����Ӧ������" << endl;
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
			cout << "û���ҵ�Ҫdelete������" << endl;
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
	Sys_student.push_back({ 17,"����" });
	Sys_student.push_back(node(18, "����"));
	Sys_student.printflist();

	testset();
	cout << endl;
	testmap();


	return 0;
}