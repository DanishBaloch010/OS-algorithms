#include<iostream>
#include <thread>
#include <vector>

using namespace std;
// race condition example
class Wallet{
	private:
		int money=0;
		
	public:
		void addMoney(int amount){
			for(int i=0; i<amount; i++){
				money++;
			}
		}
		int getMoney(){
			return money;
		}
};

int main(){
	Wallet walletObj;
	vector<thread> threads;
	for(int i=0;i<5;++i)
		threads.push_back(thread(Wallet::addMoney,&walletObj,10000));
	
	for(int i=4; i>=0; i--){
		threads[i].join();
		cout<< walletObj.getMoney()<<endl;
	}
	
}
