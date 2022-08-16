#include <iostream>
//#include "spscQueue.h"
#include <thread>
#include <queue>

queue<int> q;
auto t = std::thread([&] {
  while (!q.front());
  std::cout << *q.front() << std::endl;
  q.pop();
});
q.push(1);
t.join();
