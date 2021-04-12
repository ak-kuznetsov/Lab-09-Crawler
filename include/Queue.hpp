// Copyright 2021 ak-kuznetsov <a.kuznetsov2701@mail.ru>

#ifndef TEMPLATE_QUEUE_HPP
#define TEMPLATE_QUEUE_HPP

#include <iostream>
#include <mutex>
#include <queue>
#include <string>

template <typename T>
class Queue {
 public:
  Queue() : _counter(0) {}
  void push(T&& obj) {
    std::lock_guard<std::mutex> lock(_mut);
    _queue.push(obj);
    ++_counter;
  }

  T front() {
    std::lock_guard<std::mutex> lock(_mut);
    T _tmp = _queue.front();
    _queue.pop();
    return _tmp;
  }

  void pop() {
    std::lock_guard<std::mutex> lock(_mut);
    --_counter;
  }

  bool empty() {
    std::lock_guard<std::mutex> lock(_mut);
    return _queue.empty();
  }

  int _counter;

 private:
  std::mutex _mut;
  std::queue<T> _queue;
};

#endif  // TEMPLATE_QUEUE_HPP
