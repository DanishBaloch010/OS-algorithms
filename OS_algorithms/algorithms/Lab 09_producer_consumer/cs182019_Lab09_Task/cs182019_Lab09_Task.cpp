#include <iostream>
#include <thread>
#include<conio.h>
using namespace std;
int flag[2];

// cs182019 Lab 09 Task
int turn;
const int MAX =100;
int ans=0;

void lock_init()
{
	flag[0] =flag[1]=0;
	turn =0;	
}

void lock (int self)
{
	flag[self] =1;
	turn = 1-self;
	
	while(flag[1-self]==1  && turn==1-self);
}

void unlock (int self)
{
	flag[self] =0;
}

void func(int s)
{
	int i =0;
	int self =s;
	cout<< "Thread Entered : " << self<<endl;
	
	lock(self);
	for(i=0; i<MAX;i++)
	{
		ans++;
	}
	unlock(self);
}

int main()

{
	lock_init();
	thread threadObj1(func,1);
	threadObj1.join();
	thread threadObj2(func,2);
	threadObj2.join();
	cout<<"Actual Count :  " <<ans<< " | Expected Count : "<<MAX*2<<endl;
	getch();
	return 0;
}
