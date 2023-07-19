#include<iostream>
#include<thread>
#include<string>
#include<list>
#include<mutex>
using namespace std;
class DoSomething {
public:
	void wc() {

		for (int i=0; i < 100; i++) {

			//No.1 unique_lock加锁过程
			//unique_lock<mutex>m(mtx);
			//No.2 unique_lock其他参数
			//2.1 adopt_lock先进行lock操作，不适用，程序会调用abort函数终止程序
			//mtx.lock();
			//unique_lock<mutex>unique(mtx, adopt_lock);
			//2.2 defer_lock,需要自己手动创造lock，创键一个没有lock的锁
			//unique_lock<mutex>unique(mtx, defer_lock);//想到一个没有上锁的锁
			//unique.lock();unique.unlock()
			//2.3 try_to_lock
			unique_lock<mutex>unique(mtx, try_to_lock);
			cout << "上厕所" << endl;
			if (unique.owns_lock()) {
				num.push_back(i);
			}
			
			
		}
	}
	void batch() {
		for (int i = 0; i < 100; i++) {
			if (!num.empty()) {
				unique_lock<mutex>m(mtx);
				cout << "batch" << endl;
				num.pop_back();
			}
			else {
				cout << "正在做事" << endl;
			}
			

		}
		
	}

private:
	list<int> num;
	mutex mtx;


};
int main() {

	DoSomething man;
	thread t(&DoSomething::wc, &man);
	thread t1(&DoSomething::batch, &man);
	t.join();
	t1.join();




	return 0;
}