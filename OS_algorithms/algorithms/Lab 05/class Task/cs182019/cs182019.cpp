#include <iostream>

// lab 05 class task
// FCFS implementation
using namespace std;

void findCompletionTime(int process[] , int n , int bt[],int ct[])
{
	
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

void findAvgTime(int processes[],int n , int bt[], int at[])
{
	
	int wt[n], tat[n], ct[n],total_wt =0 , total_tat=0;
	findCompletionTime(processes,n,bt,ct);
	findturnAroundTime(processes,n,at,tat,ct);
	findWatingTime(processes ,n , wt ,tat,bt);
	
	cout << "Processes "<< " Arrival time "<<" Burst time " << " Completion time "<<" turn around time " <<" wating time\n ";
	
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
		cout << "----FCFS----"<<endl;
		int processes[]= {1,2,3,4};
		int n=4;
		int burstTime[]={6,1,4,3};
		int arrivalTime[]={0,2,5,6};
		
		findAvgTime(processes,n,burstTime,arrivalTime);
		return 0;
	}
