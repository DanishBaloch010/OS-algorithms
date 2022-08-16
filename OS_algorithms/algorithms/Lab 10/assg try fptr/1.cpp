#include<iostream>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;
//global variable 
//void incrementFunc(int *x);
int increment=10000000;

int counter=0;

	mutex m;
	
	void incrementFunc(int value){
		m.lock();
		int range = value;
		for(int i=0; i<range; i++){
			counter++;
		}
		pthread_t ptid = pthread_self();
		cout<<"Thread ID --> " << ptid << " added 10000000 now Counter Is : " <<counter<<endl;
		m.unlock();
	}
	
	int getFinalValue(){
		return counter;
	}

void (*fptr)(int)=&incrementFunc;
int main()
{
	int numOfThreads=4;
		
	vector<thread> threads;
	
	cout<<"Counter was Initially : "<<counter<<endl;
	
	//here 4 threads will use same shared data
	for(int i=0;i<numOfThreads;++i)
	{
		threads.push_back(thread(*fptr)(1000));
	}
		
		
	// joining all the threads into main
	for(int i=numOfThreads-1; i>=0; i--){
		threads[i].join();
	}
	
	// final results
	cout<< "\nTotal --> "<<numOfThreads<<" Threads Added --> "<<increment<<endl;
	cout <<"The Final Incremented Values is --> "<<getFinalValue()<<endl;
	
}
