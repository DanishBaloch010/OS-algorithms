#include <iostream>
#include <thread>
using namespace std;
// assg question 02
class SumANDMultiply{
	private:
		int n;
		int sum;
		int mul;

	public:
		SumANDMultiply(int number){
			n=number;
			sum=0;
			mul=1;
		}
		int getSum() const{
			return sum;
		}
		int getMul() const{
			return mul;
		}
		void operator()(){
			for(int i=1;i<=n;i++){
				mul=mul*i;
				sum=sum+i;
			}
		}
};
int main(){
	SumANDMultiply SumANDMultiplyObj1(10);
	SumANDMultiply SumANDMultiplyObj2(10);
	thread threadObj1( ref(SumANDMultiplyObj1) );
	threadObj1.join();
	cout<<"Sum : "<<SumANDMultiplyObj1.getSum()<<endl;
	
	thread threadObj2( ref(SumANDMultiplyObj2) );
	threadObj2.join();
	cout<<"Mul : "<<SumANDMultiplyObj2.getMul()<<endl;
	return 0;
}
