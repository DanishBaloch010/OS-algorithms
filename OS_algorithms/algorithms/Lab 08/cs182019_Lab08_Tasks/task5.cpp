#include <iostream>
#include <thread>
using namespace std;

void thread_function()
{
	cout<<endl<<"Inside Thread :: ID = "<<this_thread::get_id()<<endl;
}

int main()
{
	thread threadObj1(thread_function);
	thread threadObj2(thread_function);
	if(threadObj1.get_id()!= threadObj2.get_id())
	{
		cout<<endl<<"Both threads have different IDs"<<endl;
	}	
	cout<<"From main thread :: ID of thread 1 = "<<threadObj1.get_id()<<endl;
	cout<<"From main thread :: ID of thread 2 = "<<threadObj2.get_id()<<endl;
	threadObj1.join();
	threadObj2.join();
	return 0;

}
