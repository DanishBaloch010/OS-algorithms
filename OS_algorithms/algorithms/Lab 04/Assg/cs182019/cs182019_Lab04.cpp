#include<iostream>
#include <iomanip>  
#include <stdlib.h> 
#include <unistd.h> 
#include<queue>
//Create a Scheduler class. It should enqueue the PCB objects i nto a Queue based on the arrival
//time and dequeue a PCB object whenever the CPU i s free. Calculate whether CPU i s free
//based on the allocation time + burst time of the previous PCB object. Assume CPU i s free for
//the initial case.
// lab 04 assignment 
using namespace std;

struct Block 
{
	string processState;
	int processNum;
	string schedulingInfo;
	string IOstatusInfo;
	int arrivalTime;
	int burstLength;
	int allocationTime;
	Block *programCounter;
	Block *next;

	Block(string ps, int pn, string si, string io,int at, int bt, int allt)
	{
		this->processState = ps;
		this->processNum = pn;
		this->schedulingInfo = si;
		this->IOstatusInfo = io;
		this->arrivalTime = at;
		this->burstLength = bt;
		this->allocationTime = allt;
		this->next = NULL;
	}
	~Block(){}
};

struct headNode
{
	int count;
	Block *front;
	Block *rear;
	headNode():front(NULL), rear(NULL){}
};

class Queue
{
private:
	headNode *head = NULL;
	int c;
	
public:
	void Enqueue(string ps, int pn, string si, string io,int at, int bt, int allt);
	void Dequeue();
	void Scheduler(int at , int bt, int allt);
	void Display();
};
int termination = 0;
int prog_counter = 98;
Queue q;
void Queue::Scheduler (int at,int bt ,int allt)
{
	if(at==0)
	{
		termination = allt+bt;
		prog_counter=prog_counter+2;
		q.Enqueue("Executing",prog_counter, "priority : 1", "printer", at, bt, allt);
		cout << endl;
		cout << "wait for 1st process execution in : " << bt  << " seconds ." <<endl;
		sleep(bt);
		cout << "Process " << prog_counter<< " Terminated at " << termination << endl;
		cout<< "Allocation Time : " << allt <<endl;
		cout << "Burst length : " <<bt <<endl;
		cout << "Total execution Time : " << termination << endl;
		cout << "Process " <<prog_counter << " Exited."<<endl;
		cout << endl;

	}
	if(at == termination)
	{
		termination = termination+bt;
		prog_counter=prog_counter+2;
		q.Enqueue("Executing",prog_counter, "priority=2", "monitor",  at, bt ,  allt);
		cout << endl;
		cout << "wait for more : " << bt  << " seconds ."<<endl;
		sleep (bt);
		cout << "Process " << prog_counter<< " Terminated at " << termination << endl;
		cout<< "Allocation Time : " << allt <<endl;
		cout << "Burst length : " <<bt <<endl;
		cout << "Total execution Time : " << termination << endl;
		cout << "Process " <<prog_counter << " Exited."<<endl;		
		cout << endl;
	}
	
}

void Queue::Enqueue (string ps, int pn, string si, string io,int at, int bt, int allt)
{
	Block *temp = new Block(ps,pn,si,io,at,bt,allt);
	
	if(head == NULL)
	{
			headNode *htemp = new headNode();
			htemp->front = temp;
			htemp->rear = temp;
			htemp->count = c++;
			head = htemp;
	}
	
	else
	{
		head->count = c++;
		head->rear->next = temp;
		head->rear = temp;
	}
}
void Queue::Dequeue()
{
	Block *temp = NULL;
	temp = head->front;
	Block *savePrev;

	 if(head->front == NULL)
	{
		cout <<"Queue underflow";
	}
	else
	{
		head->count = c--;
		head->front = head->front->next;
		savePrev = temp;
		delete temp;
	}		
}

void Queue::Display()
{
	int i=0;
	Block *temp=NULL;
	if(head == NULL)
	{
		cout << "No block in list";
	}
	else
	{
		temp = head->front;
		while(temp !=NULL)
		{
			cout<<endl;
			cout << "------ Block " <<i<< "--------"<< endl;
			cout << "Process State: " << temp->processState<< endl;
			cout << "Process Number: " << temp->processNum<< endl;
			cout << "Scheduling Information: " << temp->schedulingInfo<< endl;
			cout << "IO Information: " << temp->IOstatusInfo<< endl;
			cout << "Arrival Time: " << temp->arrivalTime<<endl;
			cout << "Burst Length: " << temp->burstLength<<endl;
			cout << "Allocation Time: " << temp->allocationTime << endl;
			temp = temp->next;
			i++;			
		}
	}
}

int main()
{
	// considering a non primitive FCFS scheduler. all process will wait until the termination of previous process.
	q.Scheduler(0,3,0);
	q.Scheduler(3,4,3);
	q.Scheduler(7,5,7);
	q.Scheduler(12,3,12);
	
	cout << "Total execution time of all process combined : " << termination << endl;
	cout << endl <<"------All PROCESS INFORMATION----" << endl;
	q.Display();
	
	q.Dequeue();
	q.Dequeue();
	q.Dequeue();
	q.Dequeue();
		
	return 0;
}

	
	
	
