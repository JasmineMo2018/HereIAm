#pragma once
#include <iostream>

class MyTestString final {
 public:
  MyTestString();
  // 三个构造
  MyTestString(const char* ptr);
  MyTestString(const MyTestString& ob);
  MyTestString(MyTestString&& ob);

  explicit MyTestString(int size); // 防止隐性转换

  // 两个赋值
  MyTestString& operator=(const MyTestString& ob);
  MyTestString& operator=(MyTestString&& ob);

  // 一个析构
  virtual ~MyTestString();

  const MyTestString& GetString() const {
    ++ref_count_;
    return *this;
  }

  void PrintStringInfo() { 
    ++ref_count_;
    std::cout << data_ptr_ << std::endl;
  }

  size_t GetLen() const {
    ++ref_count_;
    return data_len_;
  }

 private:
  char* data_ptr_ = nullptr;
  int data_len_ = 0;
  int data_alloc_ = 0;
  mutable int ref_count_ = 0; // 可以在一个const函数里面改变它
};
