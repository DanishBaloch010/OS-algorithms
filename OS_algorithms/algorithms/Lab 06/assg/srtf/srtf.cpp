#include <bits/stdc++.h> 
using namespace std; 

struct process{ 
	int id;
	int at;
	int bt;
}; 

void findWT(process p[], int n, float wt[]) 
{ 
	int burstCopy[n]; 
	
	for (int i = 0; i < n; i++) 
		burstCopy[i] = p[i].bt; 

	int complete = 0, t = 0, min = INT_MAX; 
	int shortest = 0, finish; 
	bool check = false; 

	while (complete != n) { 

		for (int j = 0; j < n; j++) { 
			if ((p[j].at <= t) && 
			(burstCopy[j] < min) && burstCopy[j] > 0) { 
				min = burstCopy[j]; 
				shortest = j; 
				check = true; 
			} 
		} 

		if (check == false) { 
			t++; 
			continue; 
		} 

		burstCopy[shortest]--; 

		min = burstCopy[shortest]; 
		if (min == 0) 
			min = INT_MAX; 
			
		if (burstCopy[shortest] == 0)
		{ 
			complete++; 
			check = false; 
			finish = t + 1; 
			wt[shortest] = finish - p[shortest].bt - p[shortest].at; 
			
			if (wt[shortest] < 0)
				wt[shortest] = 0;
		}
		t++; 
	} 
} 

void findTAT(process p[], int n, float wt[], float tat[]) 
{ 
	for (int i = 0; i < n; i++) 
		tat[i] = p[i].bt + wt[i];
} 


void findAvgTime(process p[], int n) 
{ 
	float wt[n], tat[n];
	float total_wt = 0;
	float total_tat = 0; 

	findWT(p, n, wt); 

	findTAT(p, n, wt, tat); 

	cout << "|Process| " << "\t|AT|" << "\t\t|BT| " << "\t\t|WT| "<< "\t\t|TAT|\n\n"; 

	for (int i = 0; i < n; i++) 
	{ 
		total_wt = total_wt + wt[i]; 
		total_tat = total_tat + tat[i]; 
		cout << " " << p[i].id << "\t\t" << p[i].at << "\t\t" << p[i].bt << "\t\t " << wt[i] << "\t\t " << tat[i] << endl; 
	} 

	cout << "\nAverage. WT = " << total_wt/(n); 
	cout << "\nAverage TATt = " << total_tat/(n); 
} 

int main() 
{ 
	process p[] = { {1,0,8}, {2,1,4}, {3,2,2}, {4,3,1}, {5,4,3}, {6,5,2} }; 
	int n = sizeof(p) / sizeof(p[0]); 

	findAvgTime(p, n); 
	return 0; 
} 

