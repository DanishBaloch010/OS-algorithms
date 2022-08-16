#include<iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <conio.h>
using namespace std;
//global variable 
int counter=0;

class Increment{
	private:
		mutex m;
		
	public:
		void incrementFunc(int value){
			m.lock();
			for(int i=0; i<value; i++){
				counter++;
			}
			pthread_t ptid = pthread_self();
			cout<<"Thread ID --> " << ptid << " added 10000000 now Counter Is : " <<counter<<endl;
			m.unlock();
		}
		int getFinalValue(){
			return counter;
		}
};

int main()
{
	int numOfThreads=4;
	int incrementValue=10000000;
	Increment incObj;
	vector<thread> threads;
	cout<<"Counter was Initially : "<<counter<<endl;
	
	//here 4 threads will use same shared data
	for(int i=0;i<numOfThreads;++i)
		threads.push_back(thread(Increment::incrementFunc,&incObj,incrementValue));
		
	// joining all the threads into main
	for(int i=numOfThreads-1; i>=0; i--){
		threads[i].join();
	}
	
	// final results
	cout<< "\nTotal --> "<<numOfThreads<<" Threads Added --> "<<incrementValue<<endl;
	cout <<"The Final Incremented Values is --> "<<incObj.getFinalValue()<<endl;
	
	getch();
	
}
