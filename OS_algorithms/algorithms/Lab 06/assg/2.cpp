#include <bits/stdc++.h>
using namespace std;

typedef struct
{
	int pid, at, wt, bt, ta, st;
	bool isComplete;
}process;

void processDetails(int i, process p[])
{
		cout << "Enter the Process ID of : " << i + 1 <<endl;
		cin  >> p[i].pid;
		cout << "Enter the Arrival Time of : " << i + 1 <<endl;
		cin  >> p[i].at;
		cout << "Enter the Burst Time of : " << i + 1 <<endl;
		cin  >> p[i].bt;

		p[i].isComplete = false;
}

void sort(process p[], int k, int start)
{
	process temp;

	for (int i = start; i < k; ++i)
	{
		for (int j = i + 1; j < k + 1; ++j)
		{
			if (p[i].bt < p[j].bt)
			{
				continue;
			}
			else
			{
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int n, i, k = 0, j = 0;
	float avgwt = 0.0, avgtat = 0.0;
	float tat = 0.0;
	float wt = 0.0;

	cout << "Enter the Number of Procrsses: " <<endl;
	cin  >> n;
	process p[n];

	for (int i = 0 ; i < n; i++)
	{
		cout << " <--------------Process Details " << i << "--------------->";
		cout << endl;
		processDetails(i, p);
	}
	
	for ( i = 0; i < n; i++)
	{
			
		if (p[i].isComplete == true)
		{
			continue;
		}
		else
		{
			k = i;
			while (p[i].at <= tat && i < n)
			i++;

			sort(p, i, k);
			i = k;
			if (p[i].at <= tat)
			{
				p[i].st = tat;
			}		
			else
			{
				p[i].st = p[i].at;
				p[i].st = tat;
				p[i].isComplete = true;
				tat += p[i].st - p[i].at;
				p[i].ta = p[i].bt + p[i].wt;
				avgwt += p[i].wt;
				avgtat += p[i].ta;
			
			}

		}
	}

	avgwt /= n;
	avgtat /= n;

	cout << "\n\tProcess ID\tArrival Time\tBurst Time\tWait Time\tTurnaround Time\n";

	for (int i = 0; i < n; i++)
	{
		cout << "\t" << p[i].pid << "\t\t" << p[i].at << "\t\t" << p[i].bt << "\t\t" << p[i].wt << "\t\t" << p[i].ta<<endl;
 
	}
	cout << "\n\nAverage Waitinhg Time: " << avgwt;
	cout << "\nAverage Turn Around Time: " << avgtat;
	return 0;
}
