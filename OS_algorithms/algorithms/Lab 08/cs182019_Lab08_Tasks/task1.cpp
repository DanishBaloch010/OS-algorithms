#include <iostream>
#include <thread>

using namespace std;


void threadFunction()
{
	for(int i=0;i<5;i++)
	{
		cout<< "Thread using function pointer." <<endl;
	}
}

int main()
{
	thread threadObj(threadFunction);
	cout<<"Display from main thead."<<endl;
	threadObj.join();
	
	cout<<"\nExit of main function."<<endl;
	return 0;
}
