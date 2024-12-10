#include <atomic>
#include <functional>
using namespace std;

class Foo {
 public:
  atomic<int> cnt = 0;
  void first(function<void()> printFirst) {
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    cnt++;
  }

  void second(function<void()> printSecond) {
    while (cnt != 1);
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    cnt++;
  }

  void third(function<void()> printThird) {
    while (cnt != 2);
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
  }
};
