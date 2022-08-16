#include <bits/stdc++.h>

using namespace std;

void waiting(int &wait)
{
	if (wait>0)
	{
		wait --;
	}
}

void working(int &work)
{
	work ++;
}

int main()
{
	int array[5];
	int empty=5, full=0, mutex=1;
	int choice;

	while(1)
	{
		cout<< "===================================";
		cout<< endl;
		cout<< endl;
		cout<< "Empty ==> " << empty << "\tFull ==> " << full << "\tMutex ==> " << mutex;
		cout<< endl;
		cout<< endl;
		cout<< "===================================";
		cout<< endl;
		cout<< endl;
		cout<< "Select one:" <<endl << endl << "1- Producer  2- Consumer";
		cout<< endl;
		cout  << endl;
		cin >>choice;
		cout  << endl;
		
			
		if (choice == 1)
		{
			if(empty !=0 && mutex ==1)
			{
				cout << "Enter value: " << endl;
				cout  << endl;
				waiting(empty);
				waiting(mutex);
				cin>>array[full];
				working(mutex);
				working(full);
			}
			else
			{
				cout << "Buffer is full"<<endl;
			}
		}
		else if (choice == 2)
		{
			if(full >0 && mutex==1)
			{
				waiting(full);
				waiting(mutex);
				cout  << endl;
				cout << "Data: " << array[full] << endl ;
				cout  << endl;
				working(mutex);
				working(empty);
				
			}
			else
			{
				cout << "Buffer is empty"<<endl;
			}
		}
		else break;
	}
	return 0;
}
