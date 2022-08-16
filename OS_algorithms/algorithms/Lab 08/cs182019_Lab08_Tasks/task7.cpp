#include<iostream>
#include<thread>
using namespace std;
class Summation{
	private:
		int sum;
		int limit;
	public:
		Summation(int lim){
			limit=lim;
			sum=0;
		}
		int getSum() const{
			return sum;
		}
		
		void operator ()(){
			for(int i=1;i<=limit;i++){
				sum =sum+i;
			}
		}
};
int main()
{
	Summation sumHelper(10);
	thread thread(ref(sumHelper));
	thread.detach();
	cout<<"Sum : "<<sumHelper.getSum()<<endl;
	return 0;
}
