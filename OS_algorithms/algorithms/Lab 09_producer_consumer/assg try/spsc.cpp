#include <iostream>
#include <spscQueue.h>
#include <thread>

int main(int argc, char *argv[]) {
  (void)argc, (void)argv;

  using namespace rigtorp;

  SPSCQueue<int> q(2);
  auto t = std::thread([&] {
    while (!q.front())
      ;
    std::cout << *q.front() << std::endl;
    q.pop();
  });
  q.push(1);
  t.join();

  return 0;
}
