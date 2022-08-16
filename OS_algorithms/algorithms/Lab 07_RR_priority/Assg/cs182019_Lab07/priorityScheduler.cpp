#include <iostream>
using namespace std;

// cs182019 
// LAB 07
void findCompletionTime(int process[] , int n ,int at[], int bt[],int ct[] , int p[])
{
	int temp=0;
	
	// arranging every process acording to least arrival times
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
				
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;				
			}
		}
	}
	// now we know which process has lowest arrival time and it will execute first.

	// now we have to check which process has the highest priority.	
	// for this, leaving the first process 
	// and arranging the remaining processes accoring to highest priority.
	for(int i =1;i<n;i++)
	{
		for( int j=1;j<(n-i);j++)
		{
			if(p[j]>p[j+1])
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
				
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;				
			}
		}
	}
	
	// executing every process
	ct[0]=bt[0];
	for(int i =1;i<n ;i++)
	{
		ct[i]=ct[i-1]+bt[i];
	}
}

void findturnAroundTime (int processes[], int n , int at[], int tat[], int ct[])
{
	for(int i=0; i<n ;i++)
	{
		tat[i]=ct[i]-at[i];
	}
}

void findWatingTime(int processes[], int n, int wt[], int tat[], int bt[])
{
	wt[0]=0;
	
	for(int i=1;i<n;i++)
	{
		wt[i] =tat[i]-bt[i];
	}
}

void findAvgTime(int processes[],int n , int bt[], int at[], int p[])
{
	int wt[n], tat[n], ct[n],total_wt =0 , total_tat=0;
	findCompletionTime(processes,n,at,bt,ct,p);
	findturnAroundTime(processes,n,at,tat,ct);
	findWatingTime(processes ,n , wt ,tat,bt);
	cout << "\nOrder at which all the processes executed : ";
	for(int i=0;i<n;i++)
	{
		cout << processes[i] <<" " ;
	}
	cout<<"\n\n";
	cout << "Processes |"<< " Arrival time |"<<" Burst time |" << " Priority |" << "Completion time |"<<" turn around time |" <<" wating time\n ";
	for(int i=0; i<n;i++)
	{
		total_wt = total_wt + wt[i];
		total_tat =total_tat+tat[i];
		
		cout <<" "<<processes[i]<<"\t\t"<<at[i]<<"\t    "<<bt[i]<<"\t\t "<<p[i]<<"\t\t "<<ct[i]<<"\t\t "<<tat[i]<<"\t\t   "<<wt[i]<< endl;
	}
	cout<< "average waiting time : " << (float)total_wt / (float)n <<endl ;
	cout<< "average tat time : " << (float)total_tat / (float)n;
}
	
	int main ()
	{
		int processes[]= {1,2,3,4,5};
		int n=5;
		
//		int burstTime[]={6,1,4,3};
//		int arrivalTime[]={0,2,5,6};
//		int priority[]={2,4,1,3};
		
		int burstTime[]={11,28,2,10,16};
		int arrivalTime[]={0,5,12,2,9};
		int priority[]={2,0,3,1,4};
		
		findAvgTime(processes,n,burstTime,arrivalTime, priority);
		return 0;
	}
