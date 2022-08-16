#include <iostream>
#include <thread>

using namespace std;
int main()
{
	int x =9;
	thread threadObj([]{
		for(int i=0;i<5;i++)
		{
			cout <<"thread using lambda fucntion."<<endl;
		}
	});
	
	for(int i=0;i<5;i++)
	{
		cout<<"Display from main thread."<<endl;
	}
	threadObj.join();
	cout<<"Exiting from main thread."<<endl;
	return 0;
}
