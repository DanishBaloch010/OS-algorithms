#include <string>
#include <queue>
#include <iostream>
using namespace std;

//1. Write a C++ program to implement the mechanism of a long term scheduler. Your long
//term scheduler should carefully select the I/O bound and CPU bound processes, keeping
//the ratio as 70 % CPU bound processes and 30% I/O bound processes.

// lab 05 kay class task me FCFS hai. 
int cpuRatio=0;
int ioRatio=0;
int fullRatio = cpuRatio +ioRatio;
string process;
int readyQueueProcessNumber=1;

void LTS(queue<string> readyQ)
{
	cout <<"Ready Queue size: "<<readyQ.size()<<endl;
	cout <<"Ready Queue is 100% empty.\n"; 
	cout << "-----------X Proceses Are ----------X "<<endl;
 
 	refresh:
	while(!readyQ.empty()) 
	{		
		string process = readyQ.front().c_str();
		if(process=="CPU process" && cpuRatio == 70)
	 	{
	 		readyQ.pop();
	 		goto refresh;	
		}
		else if(process=="IO process" && ioRatio == 30)
	 	{
	 		readyQ.pop();
	 		goto refresh;
		}
		else if(cpuRatio==70 && ioRatio==30)
		{
			cout << "Ready Queue is full there is no room for more processes.\n";
			// when the ready queue is full the function will terminate.
			break;
		}
		
		else if ( process=="IO process" && ioRatio < 30)
	 	{
	 				cout << process <<"\n";
	 				cout <<"Process Number : " <<readyQueueProcessNumber<<"\n";
 					ioRatio=ioRatio+10;	
 					readyQueueProcessNumber++;
					cout<<"There is "<<30-ioRatio<<"% " << "space left for IO process.\n\n";
					readyQ.pop();
	 	}

		else if (process=="CPU process" && cpuRatio < 70)
 		{
 				cout << process <<"\n";
 				cout <<"Process Number : " <<readyQueueProcessNumber<<"\n";
	 			cpuRatio=cpuRatio+10;
	 			readyQueueProcessNumber++;
				cout<<"There is "<<70-cpuRatio<<"% " << "space left for CPU process.\n\n";
				readyQ.pop();		
				
		}
			
		else
		{
			readyQ.pop();
		}
		
	}
}
int main()
{
 	queue<string> JobQueue;
 	
 	//Inserting into JobQueue.
 	// There are 23 processes in job queue.
 	// LTS will schedule only 10 processes in ratio of 70% for cpu and 30% for IO.
 	// LTS will schedule processes in FCFS mannner....
 		//... but when the respective process(io or cpu) limit is reached it will queue the another type of processes.
 	// there will be always 10 process , 7 cpu bound and 3 io bound. irrespective of processesa arranged in job queue.
 	JobQueue.push("CPU process");
 	JobQueue.push("IO process");
 	JobQueue.push("CPU process");
 	JobQueue.push("IO process");
 	JobQueue.push("CPU process");
 	JobQueue.push("IO process");
 	JobQueue.push("CPU process");
 	JobQueue.push("IO process");
 	JobQueue.push("CPU process");
 	JobQueue.push("IO process");
 	JobQueue.push("CPU process");
 	JobQueue.push("IO process");
 	JobQueue.push("CPU process");
 	JobQueue.push("IO process");
	JobQueue.push("IO process");
 	JobQueue.push("CPU process");
 	JobQueue.push("IO process");
 	JobQueue.push("CPU process");
 	JobQueue.push("IO process");
 	JobQueue.push("CPU process");
 	JobQueue.push("IO process");
 	JobQueue.push("CPU process");
 	JobQueue.push("IO process");
 	
	//sending job queue in LTS.
 	LTS(JobQueue);
 	

	return 0;
}
