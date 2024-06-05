#include <iostream>
// 封装、继承、多态 （少用继承和虚函数）
// 封装：调用者不关心内部实现
// 继承：服用代码，避免重复造轮子
// 多态：改写对象的行为，但不仅仅是使用虚函数


// 怎样写一个不能被其他类所继承的类？==========================================
//class FinalClass {
// public:
//  FinalClass() {
//    std::cout << "FinalClass()" << std::endl;
//  }
//  virtual ~FinalClass() { std::cout << "~FinalClass()" << std::endl; }
//
//};

// 1. 可以把父类的构造写成private，但是会导致父类没办法使用
// 2. 不过可以考虑搞成单例，也可以用


class FinalClass final{
 public:
  FinalClass() { std::cout << "FinalClass()" << std::endl; }
  virtual ~FinalClass() { std::cout << "~FinalClass()" << std::endl; }
};

// 3. C++11 新特性 final 保证当前的类不能被继承，但是本身不会受影响

 class InheritC : public FinalClass {
  public:
   InheritC() {
     std::cout << "InheritC()" << std::endl;
   }
   virtual ~InheritC() { std::cout << "~InheritC()" << std::endl; }

 };

//  * 接口继承 
 class CanFlyable {
  public:
   virtual void Fly() = 0;
 };


 class Bird {
  public:
   virtual ~Bird() {}

  public:
   virtual void Walk() {}
   virtual void get_length() {}

  private:
   uint32_t length() {}
 };

 class Sparrow : public Bird, public CanFlyable {
  public:
   virtual ~Sparrow() {}

  public:
   virtual void Fly() {}
 };

int main() { 
  { FinalClass fc;
  }
  { InheritC ic;
  }

}




