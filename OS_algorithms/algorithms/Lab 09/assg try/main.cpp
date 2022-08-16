#include <iostream>
//#include "spscQueue.h"
#include <thread>
#include <queue>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
  (void)argc, (void)argv;

  using namespace std;

  queue<int> q;
  auto t = std::thread([&] 
  {
    while (!q.front())
      ;
    std::cout << q.front() << std::endl;
    q.pop();
  });
  q.push(1);
  t.join();

  return 0;
}
