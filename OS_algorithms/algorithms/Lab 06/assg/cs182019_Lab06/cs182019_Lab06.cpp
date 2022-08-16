#include <iostream>
using namespace std;

// but SJF implementation.
void swap(int *xp , int *yp)
{
	int temp = *xp;
	*xp=*yp;
	*yp=temp;
}

void findCompletionTime(int process[], int n, int at[],int bt[], int ct[])
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if((at[j]>at[j+1])&&(bt[j]>bt[j+1]))
			{
				swap(&at[j],&at[j+1]);
				swap(&bt[j],&bt[j+1]);
			}
		}
	}
	
	ct[0]=bt[0];
	
	for(int i=0 ;i<n ;i++)
	{
		ct[i]=ct[i-1]+bt[i];
	}
}

void findTurnAroundTime( int processes[],int n , int at[], int tat[],int ct[])
{
	for(int i=0;i<n;i++)
	{
		tat[i]=ct[i]-at[i];
	}
}

void findWaitingTime(int processes[], int n , int wt[], int tat[], int bt[])
{
	wt[0]=0;
	
	for(int i=1;i<n;i++)
	{
		wt[i]=tat[i]-bt[i];
	}
}

void findAvgTime(int processes[], int n , int bt[], int at[])
{
	int wt[n], tat[n] , ct[n],total_wt=0 , total_tat=0;
	
	findCompletionTime(processes,n,at,bt,ct);
	
	findTurnAroundTime(processes,n,at,tat,ct);
	
	findWaitingTime(processes,n,wt,tat,bt);
	
	cout<<"Processes  "<<" Arrival Time  "<<" Burst Time  "<<" Completion Time  "<<" Turn Around Time  "<<" Waiting Time\n";
	
	
	for(int i=0 ;i<n;i++)
	{
		total_wt =total_wt +wt[i];
		total_tat =total_tat +tat[i];
		cout << "   "<< i+1<<"\t\t"<<at[i]<<"\t    "<<bt[i]<<"\t\t "<<ct[i]<<"          \t\t "<<tat[i]<<"\t\t   "<<wt[i]<<endl;
		
	}
	
	cout << "Avergae waiting Time : " << (float)total_wt/(float)n<<endl;
	cout << "Avergae Turn Around Time : " << (float)total_tat/(float)n<<endl;
}

int main()
{
	int processes[]={1,2,3};
	int n=3;
	
	int burst_time[]={8,2,3};
	int arrival_time[]={0,1,4};
	
	findAvgTime(processes,n,burst_time,arrival_time);
	return 0;
	
}

