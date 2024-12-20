﻿// FuncObjectLambda.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdlib.h>
#include <functional>

#include <vector>
#include <algorithm>

#include <thread>
#include <mutex>

int compare(const void* a, const void* b) {
  if (a == nullptr || b == nullptr) {
    return 0;
  }
  double numA = *(double*)a;
  double numB = *(double*)b;

  if (numA - numB > 0) {
    return 1;
  } else if (numA - numB < 0) {
    return -1;
  } else {
    return 0;
  }
}

class CompareFuncObject {
 public:
  bool operator()(double x, double y) const {
    return x < y;
  }

};

class ToUpper {
 public:
  char operator()(char c) const {
    if (c >= 'a' && c <= 'z') {
      return static_cast<char>(c - 'a' + 'A');
    }
    return c;
  }
};

class TestMemfn {
 public:
  void DisplayNoPara() { std::cout << "TestMemfn::DisplayNoPara" << std::endl;
  }

 void DisplayWithNumber(int i) { std::cout << "TestMemfn::DisplayWithNumber" << i << std::endl; }

  int data_ = 10;

};

int fibonacci(int n) {
  // 1\1\2\3\5\8
  if (n <= 2) {
    return 1;
  } else {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}

inline int MaxValue(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

int main() {
  // C的排序
  double numbers[] = {3.3, 4, 2.5, 1, 7.6, 6, 8, 9,10,10};
  int size = sizeof(numbers) / sizeof(numbers[0]);
  qsort(numbers, size, sizeof(double), compare);
  for (auto item : numbers) {
    std::cout << item << " ";
  }
  std::cout << std::endl;

  // 函数对象
  std::vector<double> numbers2 = {3.3, 4, 2.5, 1, 7.6, 6, 8, 9, 10, 10};
  std::sort(numbers2.begin(), numbers2.end(), CompareFuncObject());
  for (auto item2 : numbers2) {
    std::cout << item2 << " ";
  }
  std::cout << std::endl;

  // 函数内部定义一个函数 => lambda
  std::vector<double> numbers3 = {3.3, 4, 2.5, 1, 7.6, 6, 8, 9, 10, 10};
  std::sort(numbers3.begin(), numbers3.end(), [](double x, double y)->bool { return x < y; });
  for (auto item3 : numbers3) {
    std::cout << item3 << " ";
  }
  std::cout << std::endl;

  // [] (int x, int y) -> bool {return x < y;};

  auto hi = []() -> void { std::cout << "hello world1" << std::endl; };
  hi();

  for_each(numbers3.begin(), numbers3.end(), [](double d) { std::cout << d<< " " ; });

  // []
  int a = 10;
  int b = 20;
  auto test = [&](int x) mutable -> int {   // mutable opt可选参数 改变值传递的变量在{}内部的副本的值
    a = 1;
    return a * x + b;
  };

  std::cout << test(3) << std::endl;

  struct Point {
    double x_;
    double y_;

    Point(double x, double y) : x_(x), y_(y) {}

  };

  Point p0(0.0, 0.0);
  Point p1(2.5, 3.0);
  Point p2(12.5, 3.5);
  double distance = 10;

  auto is_first_quadrant = [](const Point& p) { return p.x_ >= 0.0 && p.y_ >= 0.0; };

  auto is_distance_less_to_zero = [&p0, distance](const Point& p) {
    double value = sqrt((p.x_ - p0.x_) * (p.x_ - p0.x_) + (p.y_ - p0.y_) * (p.y_ - p0.y_));
    return value <= distance;
  };

  // std::bind 将函数对象的参数绑定至特定的值
  auto f1 = std::bind([](int i, int b) noexcept -> int { return i + b; }, std::placeholders::_1, 2);
  std::cout << f1(1) << std::endl;


  // 一个字符串是否为另一个字符串的子串
  ToUpper upper;
  std::cout << upper('a') << std::endl;


  auto equal = std::equal_to<char>();

  std::string str1 = "helloworld";
  std::string str2 = "llow";
  auto func3_res = std::search(str1.begin(), str1.end(), str2.begin(), str2.end(),
                               std::bind(std::equal_to<char>{},
                                         std::bind(upper, std::placeholders::_1),
                                         std::bind(upper, std::placeholders::_2)));
  std::cout << (func3_res != str1.end()) << std::endl;

  auto func4 = std::search(str1.begin(), str1.end(), str2.begin(), str2.end(),
                           std::bind(std::equal_to<char>{}, 
                                     std::bind(upper, std::placeholders::_1),
                                     std::bind(upper, std::placeholders::_2)));


  char c1 = 'a';
  char c2 = 'b';
  auto equal = std::equal_to<char>{};
  equal(c1, c2);

  // std::memfn 类对象的成员函数转换成普通函数
  TestMemfn testM;
  std::mem_fn (&TestMemfn::DisplayNoPara)(testM);
  std::mem_fn (&TestMemfn::DisplayWithNumber)(testM, 10);
  std::mem_fn (&TestMemfn::data_)(testM);

  // lambda 表达式 多线程 斐波那契数列
  int n = 10;
  std::mutex mutex;
  auto call_fib = [&mutex](int n) { 

    std::cout << "fib (" << n << ") = " << fibonacci(n) << std::endl; };

  std::thread t1(call_fib, n);
  std::thread t2(call_fib, n - 1);
  std::thread t3(call_fib, n - 2);

  t1.join();
  t2.join();
  t3.join();

  // inline 空间换时间 代码段直接插入到调用的地方
  // 但是是否真的inline 取决于编译器是否采用
  int inA = 3, inB = 4;
  int res = MaxValue(inA, inB);
  std::cout << res << std::endl;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
