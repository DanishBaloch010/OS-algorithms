#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <queue>
using namespace std;
// with each block there is a validity bit to check if free...
// block[1] = 1 ; block[3]=2; 
// block[5] = 3 ; block[7]=4;
// block[9] = 5;
int block[] = {100,1,0, 500,2,0, 200,3,0, 300,4,0, 600,5,0};
int blockSize = 15;
// p[last] is a validity bit ...
// to check if process is allocated or not.
// 0 is not allocated.
// p[second_last] is process number.
int p1[]={212, 1, 0};
int p2[]={417, 2, 0 };
int p3[]={112, 3, 0 };
int p4[]={426, 4, 0};

queue<int> blockAllocation;

firstFit()
{
	int *ptr;
	
	int totalProcess= 4;
	int processAllocationCounter=1;
	
	while(processAllocationCounter <= totalProcess)
	{
		ptr = p1;
		for(int i=0;i<blockSize;i++)
		{
			cout << "i value : "  <<i << endl;
			int blockLocationCheck = i % 3;
		
			if( blockLocationCheck == 0)
			{
				int blockAllocationCheck = i + 2;
				int check = block[blockAllocationCheck];
				if(block[blockAllocationCheck] == 0)
				{
					// if process is not allocated previously
					if(*(ptr + 2 ) == 0)
					{
						if(*(ptr+0) <= block[i])
						{
							//process allocated.
							*(ptr+2) = 1;
							// block is allocated
							block[blockAllocationCheck]=1;
							
							// save the name of process
							blockAllocation.push(*(ptr+1));
							// save the respected allocated block.
							blockAllocation.push(block[i+1]);
							
							processAllocationCounter++;
							
							if(*(ptr+1) == 1)
							{
								ptr = p2;
							}
							else if(*(ptr+1) == 2)
							{
								ptr = p3;
							}
							else if(*(ptr+1) == 3)
							{
								ptr = p4;
							}
						}
					}
					
					else
					{
						if(*(ptr+1) == 1)
						{
							ptr = p2;
						}
						else if(*(ptr+1) == 2)
						{
							ptr = p3;
						}
						else if(*(ptr+1) == 3)
						{
							ptr = p4;
						}
					}
				}
				// if not allocatable.
				else
				{
					// block is already allocated to another process
					// do nothing
					// loop back and move to next block
				}
				
			}
			
			else
			{
				// it is not position of block in array
				// do nothing
				// loop back and increment.
				// until block index is reached.
			}
		} 
	}
	
}

void bestFit()
{

}
void worstFit()
{
	
}
int main()
{
	
	firstFit();
//	int choice = 0;
//	char carryOn = 'y';
//	
//	while( (carryOn == 'y') || (carryOn == 'Y') )
//	{
//		cout <<"Choose 1 for First Fit :	"<<endl;
//		cout <<"Choose 2 for Best  Fit :	"<<endl;
//		cout <<"Choose 3 for Worst Fit : 	";
//		cin >>  choice;
//		switch(choice)
//		{
//			case 1:
//				firstFit();
//			case 2:
//				bestFit();
//			case 3:
//				worstFit();
//			default:
//				cout<<"Invalid Choice...."<<endl;	
//		}
//		
//		cout<<"Do you wish to Continue y/n ?... "<<endl;
//		cin >> carryOn;
//	}
//		
//	cout <<"Program Terminated.... " <<endl;	

	cout<<"Press Any Key To Exit......"<<endl;
	getch();
	return 0;

}
