#include<iostream> 

using namespace std; 

void findTurnAroundTime(int process[], int wt[], int no, int bt[], int tat[], int ct[], int arrival[])
{
  for(int i = 0; i < no ; i++)
  {
    tat[i] = ct[i] - arrival[i];
    wt[i] = tat[i] - bt[i];
  }
}
  
void findWaitingTime(int process[], int wt[], int no, int bt[], int quantum, int ct[], int arrival[])
{
  int rem_time[no];
 
  for(int i = 0; i < no; i++)
    rem_time[i] = bt[i];
 
  int t = 0;
  int at = 0;
  while(1)
  {
    bool done = true;
    for(int i = 0; i < no; i++)
    {
      if(rem_time[i] > 0)
      {
        done = false;
        if(rem_time[i] > quantum && arrival[i] <= at)
        {
          t += quantum;
          rem_time[i] -= quantum;
          at++;
        }
        else
        {
          if(arrival[i] <= at)
          {
            at++;
            t += rem_time[i];
            rem_time[i] = 0;
            ct[i] = t; 
          }
        }
      }
    }
    if(done==true) 
      break;
  } 
}
 
void FindavgTime(int process[], int no, int bt[], int quantum, int arrival[])
{
  int wt[no];
  int tat[no];
  int ct[no];
  int total_wt = 0, total_tat = 0;
  findWaitingTime(process, wt, no, bt, quantum, ct, arrival); 
  findTurnAroundTime(process, wt,  no, bt, tat, ct, arrival);
  cout << "PROCESS" << "\t  ARRIVAL TIME" << "\t  BURST TIME" << "\tCOMPLETION TIME" << "\tTURNAROUNDTIME" <<  "\tWAITING TIME\n";
 
  for (int i = 0; i < no; i++) 
  { 
    total_wt = total_wt + wt[i]; 
    total_tat = total_tat + tat[i]; 
    cout << i + 1 <<"\t\t "<< arrival[i] << "\t\t" <<  bt[i] << "\t" <<ct[i] <<"\t\t "<<  tat[i] << "\t\t\t "<< wt[i] << " \t" << endl; 
  } 
 
  cout << "\nAverage Waiting Time : " <<(float)total_wt / (float)no; 
  cout << "\nAverage Turn Around : " <<(float)total_tat / (float)no; 
}
  
int main() 
{ 
    std::cout<<" 1). ROUND ROBIN\n";
    std::cout<<" ---------------\n\n";

 int quantum = 2;
  int arrival_time[] = {0,2,5,6};
  int process[] = {1,2,3,4};
  int burst_time[] = {6,1,4,3};
  int n = sizeof process / sizeof process[0];
  FindavgTime(process, n, burst_time, quantum, arrival_time);
  return 0;
}
