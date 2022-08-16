#include <iostream>
using namespace std;


void findCompletionTime(int process[] , int n , int bt[],int at[], int ct[], int timeQ)
{
	// sorting the processes according to thier arrival time.
	// to find out one with the lowest arrival time.
	// this process will execute first.
	int temp=0;
	for(int i =0;i<n;i++)
	{
		for( int j=0;j<(n-i-1);j++)
		{
			if(at[j]>at[j+1])
			{
				temp=process[j];
				process[j]=process[j+1];
				process[j+1]=temp;
				
				temp=at[j];
				at[j]=at[j+1];
				at[j+1]=temp;
				
				temp=bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=temp;					
			}
		}
	}
	// array for copying the burst times
	int rem_bt_time[n];
	for(int i=0;i<n;i++)
	{
		// copying all the burst time for all the process.
		// before execution intial remaining time of each ana evert process will equals to its burst lenght.

			rem_bt_time[i]=bt[i];
			
			// makign every program completion time 0 at the start.
			ct[i]=0;
		
	}
	int timeTaken=0;
	int check=1;
	int leaveTime[n];
	temp = timeQ;
	
	cout <<endl<< "Processes Execution Sequence : "<<endl;
	while(1)
	{	
		// true.
		check=1;	
		for( int i=0;i<n;i++)
		{	
			if(rem_bt_time[i]>0)
			{
				timeQ = temp;
				// there is a pending process.
				check =0;
				// if burst time is greater than time quantum.
				// then 
				// execute the process for time quantum.
				if(rem_bt_time[i]>=timeQ)
				{
					timeTaken= timeTaken+timeQ;
					leaveTime[i]=timeTaken;
					cout<<endl<<"Process   " << process[i]<<" Left at : "<<leaveTime[i];
					rem_bt_time[i]=rem_bt_time[i]-timeQ;
					ct[i]=timeTaken;	
				}
				else
				{
					timeQ=1;
					timeTaken=timeTaken+timeQ;
					leaveTime[i]=timeTaken;
					cout<<endl<<"Process   " << process[i]<<" Left at : "<<leaveTime[i];
					rem_bt_time[i]=0;
					ct[i]=timeTaken;
				}
			}	
		}
			if(check==1)
			{
				break;
			}
	}
}

void findturnAroundTime (int processes[], int n , int at[], int tat[],int ct[])
{
	for(int i=0; i<n ;i++)
	{
		tat[i]=ct[i]-at[i];
	}
}

void findWatingTime(int processes[], int n, int wt[],int tat[], int bt[])
{	
	for(int i=0;i<n;i++)
	{
		wt[i] =tat[i]-bt[i];
	}
}

void findAvgTime(int processes[],int n , int bt[], int at[], int timeQ)
{
	
	int wt[n], tat[n], ct[n],total_wt =0 , total_tat=0;
	findCompletionTime(processes,n,bt,at,ct,timeQ);
	findturnAroundTime(processes,n,at,tat,ct);
	findWatingTime(processes ,n , wt ,tat,bt);
	cout << "\n\nProcesses "<< " Arrival time "<<" Burst time " << " Completion time "<<" turn around time " <<" wating time\n ";
	for(int i=0; i<n;i++)
	{
		total_wt = total_wt + wt[i];
		total_tat =total_tat+tat[i];
		cout <<"  "<<i+1<<"\t\t"<<at[i] <<"\t   "<<bt[i]<<"\t\t " <<ct[i]<<"\t\t "<<tat[i]<<"\t\t   "<<wt[i]<< endl;	
	}
	
	cout<< "average waiting time : " << (float)total_wt / (float)n <<endl ;
	cout<< "average tat time : " << (float)total_tat / (float)n;
}
	
	int main ()
	{
		int processes[]= {1,2,3,4};
		int timeQuantum=2;
		int n=4;
		
		int arrivalTime[]={0,2,5,6};
		int burstTime[]={6,1,4,3};
		
		findAvgTime(processes,n,burstTime,arrivalTime,timeQuantum);
		return 0;
	}
