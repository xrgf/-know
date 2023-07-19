#include<iostream>
#include<thread>
#include<vector>
#include<list>
#include<mutex>
using namespace  std;
void printData(int i) {

	cout <<"线程序号::"<< i << endl;
}
void TestCreateThread() {

	vector<thread*>test;
	for (int i = 0; i < 10; i++) {
		test.push_back(new thread(printData, i));
	}
	for (auto v : test) {
		v->join();
		//v->detach();
	}
	cout << "主线程" << endl;
}
//数据共享问题分析
//只读操作：稳定安全，不需要特殊处理，直接读就可以
vector<int> g_data={ 1,2,3 };
void printVector(int i) {
	cout << "子线程id::" << i << endl;
	for (auto v : g_data) {
		cout << v << "  ";
	}
	cout << endl;
}
void TestThread() {

	vector<thread*>test;
	for (int i = 0; i < 10; i++){

		test.push_back(new thread(printVector, i));
	}
	for (auto v:test) {
		v->join();
	}
}
//有读有写的时候：需要特殊处理，让程序只对共享数据的单一操作。
class Seaking {
public:
	void makeFriend() {
		for (int i = 0; i < 100; i++) {

			lock_guard<mutex>m_mutex();
			//加锁
			// 
			//m_mutex.lock();
			cout << "增加一个女朋友" << endl;
			mm.push_back(i);
			//m_mutex.unlock();
		}
	}
	void breakup() {
		for (int i = 0; i < 100; i++) {
			if (!mm.empty()) {
				lock_guard<mutex>m_mutex();//带（）是构造函数;
				//m_mutex.lock();
				cout << "减少一个女朋友" << endl;
				mm.pop_back();
				//m_mutex.unlock();
			}
			else {
				cout << "单身狗一个" << endl;
			}
		}
	}

private:
	list<int>mm;
	mutex m_mutex;//构建互斥量对象


};
/*	mutex类(互斥量)创建互斥量类的对象
* No.one
* 1.1通过调用lock函数进行加锁
* 1.2通过调用unlock函数进行解锁
* 注意点lock和unlock成对出现
* No.two
* lock_guard 对象实现加锁
*	lock_guard类的构造函数中调用lock函数
*	lock_guard类的析构函数调用了unlock函数
* 

*/
int main() {


	//TestCreateThread();
	//TestThread();
	Seaking ss;
	thread t1(&Seaking::makeFriend, &ss);
	thread t(&Seaking::breakup, &ss);
	t.join();
	t1.join();


	return 0;
}