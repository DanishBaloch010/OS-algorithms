#include<iostream>
using namespace std;
int bufferSize = 5;
int buffer[5];

// production in slot's is 1
int produced = 1; 
// consumption from slot's is 0
int consumed = 0;

int emptyspace=0;
int productionCount=0;
int consumptionCount=0;
 
void bufferCheck()
{
	cout<<"<--- BUFFER SLOTS ----> "<<endl;
	for(int i =0; i<bufferSize; i++)
	{
		if(buffer[i]==1)
			cout<<"SLOT " << i << " IS FILLED "<< buffer[i]<<endl;
			
		else if(buffer[i]==0)
			cout<<"SLOT " << i << " IS EMPTY "<< buffer[i]<<endl;
	}
	cout<<endl;
}
void producer()
{
	int notFull=1; // 1 is true
	
	// checking if buffer is NOT FULL
	for(int i =0 ;i<bufferSize;i++)
	{
		//if the slot is filled
		if(buffer[i]==1)
			notFull=0;
		
		// else if slot is empty
		else
		{
			notFull=1;
			emptyspace=i;
			break;
		}
	}
	// data production
	if(notFull==1)
	{
		buffer[emptyspace] = produced;
		productionCount++;
	}
	// if every slot is filled.
	if(notFull==0)
		cout << "Cant Produce Buffer is Full .\n" << endl;
	
	bufferCheck();
}

void consumer ()
{
	// 1 is true
	int notEmpty=1;
	// checking if Buffer is NOT EMPTY
	for(int i =0 ;i<bufferSize;i++)
	{
		//if slot is empty
		if(buffer[i]==0)
			notEmpty=0;
			
		// if slot is not empty
		else
		{
			notEmpty=1;
			buffer[i]=consumed;
			consumptionCount++;
			break;
		}
	}
	if(notEmpty==0)
		cout<<"Cant Consume Buffer is Empty .\n"<<endl;
	
	bufferCheck();
}

void emptyBuffer()
{
	for(int i =0;i<bufferSize;i++)
		buffer[i]=0;
}

int main()
{
	// creating an empty buffer filled with only zeros
	emptyBuffer();
	// 0 indicates slot is empty for production
	bufferCheck();
	int request;
	
	while(1)
	{
		cout <<"-->> Press 1 for Consumption .\n";
		cout <<"-->> Press 2 for Production .\n";
		cin >> request;
		cout << endl;
		
		if(request==1)
			consumer();
			
		else if(request==2)
			producer();
		
		else
		{
			cout<<"Invalid Choice, Terminated.\n"<<endl;
			break;			
		}
	}
	
	cout<<"Productions : "<<productionCount<<endl;
	cout <<"Consumptions : "<<consumptionCount<<endl;
	
	return 0;
}


