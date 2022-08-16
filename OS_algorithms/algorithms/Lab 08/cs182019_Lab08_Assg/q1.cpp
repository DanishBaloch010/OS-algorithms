#include <thread>
#include <iostream>
using namespace std;
// assg question 01
class ArithematicSeries
{
	private:
		int nth_term;
		int difference;
		int first_term;
		int series;
		
	public:
		ArithematicSeries(int n,int d,int a){
			nth_term=n;
			difference=d;
			first_term=a;
			series=0;
		}
				
		void operator()(){
			cout<<endl<<"Arithematic Squence " <<endl;
			for (int i=1;i<nth_term;i++){
				if(i==1){
					cout<<first_term<<endl;
				}
				else{
					series = first_term+(i*difference);
					cout<<series<<endl;		
				}
			}
		}
};
int main(){
	ArithematicSeries series(7,5,3);
	thread thread(ref(series));
	thread.join();
	return 0;
}

