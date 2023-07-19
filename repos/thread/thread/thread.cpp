#include<iostream>
#include<thread>
using namespace std;
void print() {
	cout << "线程处理函数启动........" << endl;
}
void test1() {
	thread t1(print);
	t1.join();

}
void printData(int num) {
	cout << "id  " << num << endl;
}
void test3() {
	int num = 1;
	thread t1(printData, num);
	t1.join();
}
void test2() {

	thread t1([]() {cout << "lambda表达式" << endl; });
	t1.join();
}
void printReference(int& num) {
	num = 1001;
	cout << "子线程：" << num << endl;
}
void test4() {
	int num = 0;
	thread t1(printReference,ref(num));
	t1.join();
	cout << "主线程：" << num << endl;
}
class MM {

public:
	void print(int& id) {
		cout << "id :" << id << endl;
	}
};
void test6() {
	MM mm;
	int id = 0;
	thread t1(&MM::print, mm, ref(id));
	t1.join();

}
int main() {


	test1();
	test2();
	test3();
	test4();
	test6();

	return 0;
}