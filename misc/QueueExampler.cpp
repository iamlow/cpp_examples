#include <iostream>

template <typename T>
class Queue {
public:
  Queue (const int size = 5) {
    size_ = size;
    t_ = new T[size];
  }

  ~Queue () {
    delete [] t_;
  }

  bool isEmpty() {
    return front_ == rear_;
  }

  bool isFull() {
    return front_ == (rear_ + 1) % size_;
  }

  void push(const T &t) {
    if(isFull()) {
      std::cout << "Q is FULL!\n";
      return;
    }
    rear_ = (rear_ + 1) % size_;
    std::cout << "push rear: " << rear_ << std::endl;
    t_[rear_] = t;
  }

  T pop() {
    if (isEmpty()) {
      std::cout << "Q is Empty!\n";
      // throw std::exception();
      return -1;
    }
    front_ = (front_ + 1) % size_;
    std::cout << "pop front: " << front_ << std::endl;
    return t_[front_];
  }

private:
  int front_ = 0;
  int rear_ = 0;
  T *t_ = nullptr;
  int size_ = 0;
};

int main(void)
{
  Queue<int> q;
  q.push(10);
  q.push(20);
  q.push(30);
  q.push(40);
  q.push(50);
  q.push(60);

  std::cout << q.pop() << std::endl;
  std::cout << q.pop() << std::endl;
  std::cout << q.pop() << std::endl;
  std::cout << q.pop() << std::endl;
  std::cout << q.pop() << std::endl;
  std::cout << q.pop() << std::endl;

  q.push(10);
  q.push(20);
  q.push(30);
  q.push(40);
  q.push(50);
  q.push(60);

  std::cout << q.pop() << std::endl;
  std::cout << q.pop() << std::endl;
  std::cout << q.pop() << std::endl;
  std::cout << q.pop() << std::endl;
  std::cout << q.pop() << std::endl;
  std::cout << q.pop() << std::endl;

  return 0;
}
