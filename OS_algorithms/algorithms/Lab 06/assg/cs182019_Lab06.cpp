#include<stdio.h>

	void swap(int *xp , int *yp)
{
	int temp = *xp;
	*xp=*yp;
	*yp=temp;
}

int main()
{
	int at[]={0,1,4};
	int bt[]={8,2,3};
	int n=3;
	int ct[n];
	int tat[n];
	int wt[n];
	
	
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
	
	int smallestAT=at[0];
	int smallestBT=bt[0];
	
	
	if(smallestBT!=at[1] && smallestBT!=at[2])
	{
		ct[0]=bt[0];
	}	
	else if(smallestBT==at[1] || smallestBT==at[2])
	{
		if(smallest)
	}
	
	
	

	
	
	
}
