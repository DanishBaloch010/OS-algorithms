/*
* copy one queue to another c++ program
* 
*/

#include <string>
#include <queue>
#include <iostream>
using namespace std;

/*
*Copy original queue to temp queue and process
Elements of the Temp queue will printed and
popped.

Finally temp queue will be empty and it will 
not affect original queue and data in original
queue will be found.

*/

void copyQueue(queue<string> tempQ)
{
	cout<<"Temp Queue size: "<<tempQ.size()<<endl;
 //iterate the queue, print elements and 
 //pop the element - on pop element will be removed \
 //from queue
 cout << "Fruits are: "<<endl;
 while(!tempQ.empty()) 
	{ 
 		string data = tempQ.front().c_str();
 		std::cout << data <<"\n";
		tempQ.pop();

	} 
}
int main()
{
 //Create a queue
 queue<string> fruitsQueue;

/*
 *Insert elements in to the queue
 */
 cout << "Inserting elements into Queue\n";
 fruitsQueue.push("Apple");
 fruitsQueue.push("Mango");
 fruitsQueue.push("Banana");
 fruitsQueue.push("Kiwi");
 fruitsQueue.push("Berry");

cout<< "Original queue size: "<<fruitsQueue.size()<<endl;

//copy queue to another queue
 copyQueue(fruitsQueue);

/*
 *Check if original queue contains and elements
 and not popped by temp queue
 */ 
 cout<< "Original queue size: "<<fruitsQueue.size()<<endl;;

//Process orinial queue
 cout << "Fruits are: "<<endl;
 while(!fruitsQueue.empty()) {

//front() function returns firsts element
 //but does not delete it from queue
 cout <<fruitsQueue.front() << "\n";

//To delete front element from the queue.
 fruitsQueue.pop();
 }

cout << endl;

return 0;
}
