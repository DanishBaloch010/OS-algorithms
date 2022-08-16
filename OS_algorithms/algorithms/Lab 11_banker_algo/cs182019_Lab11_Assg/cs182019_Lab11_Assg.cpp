#include<stdio.h>
#include <iostream>
#include <queue>
#include <conio.h>
using namespace std;

// p[0],p[1],p[2] = allocation
// p[3],p[4],p[5] = max
// p[6],p[7],p[8] = need
// p[second_last] is for Process Number.
// p[last] is for identifying if process has done completion ?

int p1[]={0,1,0,	7,5,3,	0,0,0	,1	,0};
int p2[]={2,0,0,	3,2,2,	0,0,0	,2	,0};
int p3[]={3,0,2,	9,0,2,	0,0,0	,3	,0};
int p4[]={2,1,1,	2,2,2,	0,0,0	,4	,0};
int p5[]={0,0,2,	4,3,3,	0,0,0	,5	,0};

int availableResources[]={3,3,2};

queue<int> safeSequence;
	
void needCalculator(int array[]){
	int j = 3 ;
	int k = 0;
	// calculating need for all the processes
	for(int i=6;i<9;i++)
	{
		array[i]=array[j]-array[k];
		j++;
		k++;
	}
	
}
void printer()
{
	int *ptr;
	ptr=p1;
	int checker=9;
	int loopLocker=0; // lock open
	cout<<" Allocation            Max		Need		    Process Num.	Available"<<endl;
	cout <<"===================|================|=====================|===============|=================|"<<endl;
	int j=0;
		for(int i=0;i<5;i++)
		{				
			for(j=0;j<10;j++)
			{
				cout <<*(ptr + j )<< "      ";	
			}
		if(loopLocker==0)
		{
			for(int i=0;i<3;i++)
			{
				cout <<"      "<<availableResources[i];
			}
			loopLocker=1;
		}
		
		if(j = checker)
		{
			if(*(ptr + 9) == 1)
				ptr = p2;
			else if(*(ptr + 9) == 2)
				ptr = p3;
			else if(*(ptr + 9) == 3)
				ptr = p4;
			else if(*(ptr + 9) == 4)
				ptr = p5;
		}
		cout<<endl;
	}
	
}

int algoRunCounter=0;
void BankersAlgorithm()
{
	int numberOfProcessLeft=5;	
	int checker=9;
	int totalProcessCount=5;
	int ProcessExecutedCounter=1;
	bool printOriginalSequence = true;
	
	while(ProcessExecutedCounter <= totalProcessCount)
	{	
		bool SystemSafeCheck = false;
		int *ptr = p1;
		int trueCheck=3;
		for(int i=0;i<5;i++)
		{
			
			int a =0;
			int allocatorCheck=0; // false
			int j=6;
			
			// first checking if the process has done completion or not.
			// 0 means it has not done completion.
			if(*(ptr+10) == 0)
			{
					// check if current process need is less or equal to available resources.
					for(j=6;j<9;j++)
					{
						if(*(ptr + j) <= availableResources[a] )
							allocatorCheck++;
						
						else
							allocatorCheck--;
							
						a++;	
					}
					// if the current process is allocate-able than
					if(allocatorCheck == trueCheck && j == checker)
					{
						SystemSafeCheck = true;
						if(printOriginalSequence==true)
						{
							cout<<"\n--------- ORIGINAL  SEQUENCE AS PROCESSES ARE ARRANGED ------------"<<endl<<endl;
							printOriginalSequence=false;
						}
						printer();
						cout<<endl;
						cout<<"-----------------------------------------------------------------------------"<<endl;
						cout<<"\nProcess "<<*(ptr+9)<< " Got Executed and set its ALLOCATION FREE."<<endl;
						if(SystemSafeCheck==true)
							cout<<"\n ---> SYSTEM IN IS IN SAFE CONDITION. <-----"<<endl;
						
						// the process is allocated.
						// now its allocation is set free
						for(int i=0;i<3;i++)
							availableResources[i] =availableResources[i] + *(ptr + i);
						
						safeSequence.push(*(ptr+9));
						*(ptr + 10)=1; // process has exited(done processing)
						ProcessExecutedCounter++;
						numberOfProcessLeft--;						
						cout<<"\nNumber of Processes  Left -- > | "<<numberOfProcessLeft<<" | "<<endl<<endl;
						
						// after allocation move to next process
						if(*(ptr + 9) == 1)
							ptr = p2;
	
						else if(*(ptr + 9) == 2 )
							ptr = p3;
						
						else if(*(ptr + 9) == 3 )
							ptr = p4;
						
						else if(*(ptr + 9) == 4)
							ptr = p5;
						
					}
					// if the current process is not allocate-able than
					// than move to next process
					else if (allocatorCheck != trueCheck && j == checker)
					{
						if(*(ptr + 9) == 1)
							ptr = p2;
	
						else if(*(ptr + 9) == 2 )
							ptr = p3;
						
						else if(*(ptr + 9) == 3 )
							ptr = p4;
						
						else if(*(ptr + 9) == 4)
							ptr = p5;
					}
				}
			
				// if procees has done completion than move to the next process.
				else
				{
					if(*(ptr + 9) == 1)
						ptr = p2;
						
					else if(*(ptr + 9) == 2)
						ptr = p3;
						
					else if(*(ptr + 9) == 3)
						ptr = p4;
					
					else if(*(ptr + 9) == 4)
						ptr = p5;
				}				
		}
		
		// if no process is allocatable than exit. 
		if(SystemSafeCheck == false)
		{
			cout<<"\nSystem is in Deadlocked State."<<endl;
			cout<<"\nALGORITHM TERMINATED."<<endl;
			exit(0);
		}
		
		algoRunCounter++;
	}
	
}

int main()
{
	//calculating need for every process
	needCalculator(p1);
	needCalculator(p2);
	needCalculator(p3);
	needCalculator(p4);
	needCalculator(p5);
	
	BankersAlgorithm();
	
	cout <<endl<<"Safe Sequence Is : ";
	while(!safeSequence.empty())
	{
		cout << "\t --> " << safeSequence.front();
        safeSequence.pop();
	}
	cout <<endl;
	
	cout <<"\nNumber of Time's the Banker Algorithm has run : "<< algoRunCounter<<endl;
	
	cout<<"\nPress Any to Exit.."<<endl;
	getch();
	return 0;
}
