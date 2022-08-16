#include <iostream>
#include <string>
#include <thread>
using namespace std;
class DisplayThread
{
	public:
		void operator()(int x,string str){
			cout<<"Passed Number = "<<x<<endl;
			cout<<"Passed String = "<<str<<endl;
		}
};

void threadFunction(int x,string str){
			cout<<"Passed Number = "<<x<<endl;
			cout<<"Passed String = "<<str<<endl;
}

int main(){
	int x=10;
	string str ="SAMPLE STRING.";
	thread threadObj1(threadFunction,x,str);
	thread threadObj2((DisplayThread()),x,str);
	thread threadObj3([](int x,string str){
		cout<<"Passed Number = "<<x<<endl;
		cout<<"Passed String = "<<str<<endl;
	},x,str);
	
	threadObj1.join();
	threadObj2.join();
	threadObj3.join();
}
