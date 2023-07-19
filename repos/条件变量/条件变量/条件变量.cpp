#include<condition_variable>
#include<iostream>
#include<thread>
#include<chrono>
#include<mutex>
using namespace std;
/*
	condition_variable类
	1.调用waid函数 阻塞线程
	2.unique_lock 加锁线程
	3.notify_one notify_all 唤醒线程
*/
condition_variable cv;
mutex cv_m;
int i = 0;// 描述唤醒条件
bool done = false;//充当开关
void wait_one() {
	unique_lock<mutex>lk(cv_m);
	cout << "等待中......" << endl;
	cv.wait(lk, [] {return i == 1; });
	this_thread::sleep_for(1s);
	cout << "运行结束....." << endl;
	done = true;
}
void signal_one() {
	this_thread::sleep_for(1s);
	
	cout << "不做条件变量唤醒操作....." << endl;
	cv.notify_one();//不做唤醒

	unique_lock<mutex>lkc(cv_m);
	i = 1;
	 while(!done){
		cout << "条件变量的唤醒操作" << endl;
		//lkc.unlock();
		cv.notify_one();//唤醒线程中的一个线程
		this_thread::sleep_for(1s);
		//lkc.lock();
	}
}
void TestNotifyOne() {
	thread t1(wait_one), t2(signal_one);
	t1.join();
	t2.join();
}
int main() {


	TestNotifyOne();

	return 0;

}