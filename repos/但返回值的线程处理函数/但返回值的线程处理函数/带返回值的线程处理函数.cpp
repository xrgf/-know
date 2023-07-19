#include<iostream>
#include<thread>
#include<future>
#include<chrono>
using namespace std;

int TestReturnone() {
	return 1001;
}
class MM {
public:
	int mmThread(int num) {
		cout << "MMThread_id  " << this_thread::get_id() << endl;
		num = num * 2;
		chrono::microseconds duration(500000);
		this_thread::sleep_for(duration);
		
		return num;
	}
};
void TestAsync() {
	future<int> result = async(TestReturnone);
	cout << result.get() << endl;
	MM mm; 
	auto resultone = async(&MM::mmThread, &mm, 1999);
	cout << resultone.get() << endl;;

	auto TestoneAsync = async(launch::deferred, &MM::mmThread, &mm, 800);
	cout << TestoneAsync.get() << endl;
	auto TesttwoAsync = async(launch::async, &MM::mmThread, &mm, 100);
}
void print() {

	cout << "被对比的线程id :" << this_thread::get_id() << endl;
}
void TestPackaged_task() {
	packaged_task<int(void)> taskOne(TestReturnone);
	thread t(ref(taskOne));
	t.join();
	cout << taskOne.get_future().get() << endl;

}
//线程的资源竞争问题

void printFor(int i) {
	cout << i << endl;
}
void printFortest() {

	for (int i = 0; i < 4; i++) {

		thread t(printFor, i);
		t.detach();

	}
	getchar();
}
int main() {
    /*print();
	cout << "主线程id  : " << this_thread::get_id() << endl;
	TestAsync();
	cout << "...................." << endl;
	TestPackaged_task();*/
	printFortest();

	return 0;
}