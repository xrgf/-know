#include<iostream>
#include<thread>
using namespace std;
void threadFunc() {

	cout << "子线程的id:" << this_thread::get_id() << endl;
	cout << "id:" << this_thread::get_id() << endl;
}
void test1() {

	cout << "id:" << this_thread::get_id() << endl;
	thread t1(threadFunc);
	t1.join();
}
int main() {

	test1();
	cout << "id:" << this_thread::get_id() << endl;




	return 0;
}