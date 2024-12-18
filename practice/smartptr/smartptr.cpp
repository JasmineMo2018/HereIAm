// smartptr.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>
#include "Retional.h"
#include "SmartPointer.h"



//class FileIO {
// public:
//  FileIO(const std::string& file_path) : file_path_(file_path), file_handle_(nullptr) {
//  
//  }
//
//  ~FileIO() {
//  
//  }
//   
//  bool OpenFile() { file_handle_ = std::make_unique<std::fstream>(file_path_);
//    if (file_handle_ == nullptr || !file_handle_->is_open()) {
//      return false;
//    }
//    return true;
//  }
//  bool CloseFile() {
//    if (file_handle_ != nullptr || file_handle_->is_open()) {
//      file_handle_->close();
//    }
//  
//  }
//
// private:
//  std::string file_path_;
//  std::unique_ptr<std::fstream> file_handle_;
//
//};
//
//class A {};
//class A0 {
// public:
//  A0() { ; };
//  ~A0() { ; };
//
//};
//class A1 {
// public:
//  A1() : a_(0) { ; }
//
//        private : 
//          
//          int a_;
//};
//
//class A11 {
//         public:
//          A11() : a_(0) { ; }
//
//         private:
//          int a_;
//          static const int b_ = 0;
//};
//
//class A2 {
//         public:
//          A2() { ; }
//          virtual ~A2() { ; };
//
//          void Test() { ; };
//          static void TestS() { ; };
//
//};
//class A22 {
//         public:
//          A22() { ; }
//          virtual ~A22() { ; };
//
//          virtual void TestV() { std::cout << "A22 TestV" << std::endl; };
//
//          void Test() { ; };
//          static void TestS() { ; };
//};
//


class Base1 {
 public:
  virtual void func_1() { ; }


};

class Shape {
 public:
  virtual void Draw() = 0;

};

class Circle : public Shape {
 public:
  virtual void Draw() override { std::cout << "Circle Draw." << std::endl;
  }

};

class Rectangle : public Shape {
 public:
  virtual void Draw() override { std::cout << "Rectangle Draw." << std::endl; }
};


template<typename T>
class ShapeT {
 public:
  void Draw() { (static_cast<T*>(this))->DrawImpl();
  }
};

class CircleT : public ShapeT<CircleT> {
 public:
  void DrawImpl() { std::cout << "CircleT DrawImpl" << std::endl; }

};

class RetangleT : public ShapeT<RetangleT> {
 public:
  void DrawImpl() { std::cout << "RetangleT DrawImpl" << std::endl; }
};

int main() {
  // 虚函数 动态多态
  Shape* ptr = new Circle();
  if (ptr!= nullptr) {
    ptr->Draw();
    delete ptr;
    ptr = nullptr;
  }

  Shape* ptr2 = new Rectangle();
  if (ptr2 != nullptr) {
    ptr2->Draw();
    delete ptr2;
    ptr2 = nullptr;
  }

  // 模板 静态多态
  CircleT pt;
  pt.Draw();
  RetangleT pt2;
  pt2.Draw();

  return 0;
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
