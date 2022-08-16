#include <iostream>
#include <thread>
using namespace std;
class DisplayThread
{
	public:
		void operator()()
		{
			for(int i=0;i<5;i++)
			{
				cout<<"\nThread using fucntion object.";
			}
		}
};

int main()
{
	thread threadObj( ( DisplayThread() ) );
	for(int i=0;i<5;i++)
	{
		cout<<"Display from main thread."<<endl;
	}
	
	cout<<"Waiting for thread to complete."<<endl;
	threadObj.join();
	
	cout<<"Exiting from main thread"<<endl;
	return 0;
}
