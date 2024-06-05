// oopdemo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

// 仨灯仨开关的问题

#include <iostream>

class Button {
 public:
  Button() {
    is_open_ = false;
    hot_rate_ = 0;
  }

  Button(bool is_open) {
    if (is_open) {
      hot_rate_ = 10;
    } else {
      hot_rate_ = 0;
    }
    is_open_ = is_open;
  }
  ~Button() {}

 public:
  bool get_open_state() { return is_open_; }
  uint32_t get_hot_rate() { return hot_rate_; }
  void set_open_state(bool is_open) {
    if (!is_open) {
      hot_rate_ -= 5;
    }
    is_open_ = is_open;
  }

 private:
  uint32_t hot_rate_ = 0;
  bool is_open_ = false;
};


//int main() {
//  Button but_1(true);
//  Button but_2(true);
//  Button but_3(false);
//
//  std::cout << "button 1 state : " << but_1.get_open_state() << ", hot rate : " << but_1.get_hot_rate() << std::endl;
//  std::cout << "button 2 state : " << but_2.get_open_state() << ", hot rate : " << but_2.get_hot_rate() << std::endl;
//  std::cout << "button 3 state : " << but_3.get_open_state() << ", hot rate : " << but_3.get_hot_rate() << std::endl;
//
//  but_2.set_open_state(false);
//  std::cout << "button 1 state : " << but_1.get_open_state() << ", hot rate : " << but_1.get_hot_rate() << std::endl;
//  std::cout << "button 2 state : " << but_2.get_open_state() << ", hot rate : " << but_2.get_hot_rate() << std::endl;
//  std::cout << "button 3 state : " << but_3.get_open_state() << ", hot rate : " << but_3.get_hot_rate() << std::endl;
//  getchar();
//  return 0;
//}

// 面向过程：C ===========================================================
// 结构化程序设计 程序 = 算法 + 数据结构
// 顺序、条件、goto
// 函数和数据没有做一个很好的关联
// 重算法实现细节


// 面向对象：C++ ==========================================================
// 早期 C + class
// 函数可以复用
// 数据和函数是有关联的且有边界的。扩展性比较好。
// 更关注设计和实现思路
// 重设计、实现思路



