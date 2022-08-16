#include<iostream>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;
//mutex example
class Wallet{
	private:
		int money=0;
		mutex mutex;
		
	public:
		void addMoney(int amount){
			mutex.lock();
			for(int i=0; i<amount; i++){
				money++;
			}
			mutex.unlock();
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
