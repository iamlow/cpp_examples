#include <iostream>

template <typename T>
class Stack {
public:
  Stack(const int size = 10) {
    size_ = size;
    t_ = new T[size_];
  }

  ~Stack() {
    delete [] t_;
  }

  void push(const T &t) {
    if (size_ == index_ + 1) {
      std::cout << "Q is FULL!\n";
      return;
    }
    t_[++index_] = t;
  }

  T pop() {
    if (-1 == index_) {
      std::cout << "Q is empty!\n";
      return -1;
    }
    return t_[index_--];
  }

private:
  T *t_ = nullptr;
  int index_ = -1;
  int size_ = 0;
};

int main(void)
{
  Stack<int> stack;
  stack.push(10);
  stack.push(20);
  stack.push(30);
  stack.push(10);
  stack.push(20);
  stack.push(30);
  stack.push(10);
  stack.push(20);
  stack.push(30);
  stack.push(10);
  stack.push(20);
  stack.push(30);

  std::cout << stack.pop() << std::endl;
  std::cout << stack.pop() << std::endl;
  std::cout << stack.pop() << std::endl;
  std::cout << stack.pop() << std::endl;
  std::cout << stack.pop() << std::endl;
  std::cout << stack.pop() << std::endl;
  std::cout << stack.pop() << std::endl;
  std::cout << stack.pop() << std::endl;
  std::cout << stack.pop() << std::endl;
  std::cout << stack.pop() << std::endl;
  std::cout << stack.pop() << std::endl;
  std::cout << stack.pop() << std::endl;

  return 0;
}
