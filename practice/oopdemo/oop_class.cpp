#include <iostream>
#include <functional>
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

 class InheritC /*: public FinalClass*/ {
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

 void default_walk() { std::cout << "default_walk." << std::endl; }

 // 不用虚函数实现多态 指针的传递
 // 虚函数是动态多态、模板是静态多态

 class BirdA {
  public:
   // typedef void (*MyWalkFunc)();
   typedef std::function<void()> MyWalkFunc;
   BirdA(MyWalkFunc func) : func_(func) {}

  private:
   MyWalkFunc func_;

  public:
   void WalkF() { func_(); }
 };

 class SparrowA : public BirdA {
  public:
   typedef void (*MyWalkFunc)();
   SparrowA(MyWalkFunc func = default_walk) : BirdA(func) {}
 };

 void SparrowWalk() { std::cout << "SparrowWalk." << std::endl; }

 class TNA : public BirdA {
  public:
   typedef void (*MyWalkFunc)();
   TNA(MyWalkFunc func = default_walk) : BirdA(func) {}
 };

 void TNWalk() { std::cout << "TNWalk." << std::endl; }

 class Sparrow : public Bird, public CanFlyable {
  public:
   virtual ~Sparrow() {}

  public:
   virtual void Fly() {}
 };




void DefaultWalk() { std::cout << "B Default walk" << std::endl; }

class BirdB {
  public:
   typedef std::function<void()> MyBirdBWalk;
   BirdB(MyBirdBWalk func = DefaultWalk) { func_ = func;
   }

   void Walk() { func_();
   }
  private:
   MyBirdBWalk func_;
};

void AAAWalk() { std::cout << "AAAWalk" << std::endl; }

class AAA : public BirdB {
  public:
   AAA(MyBirdBWalk func) : BirdB(func){}

};
void BBBWalk() { std::cout << "BBBWalk" << std::endl; }

class BBB : public BirdB {
  public:
   BBB(MyBirdBWalk func) : BirdB(func) {}

};

// 多重继承
// 虚继承
class Shape_Basic {
  public:
   Shape_Basic(int id) : id_(id) {}

  public:
   int id_;
};

class Shape_WithColor : virtual public Shape_Basic {
  public:
   Shape_WithColor(int id) : Shape_Basic(id) {}
   void set_id(int id) { id_ = id; }
};

class Shape_WithShape : virtual public Shape_Basic {
  public:
   Shape_WithShape(int id) : Shape_Basic(id) {}
   int get_id() const { return id_;
   }
};

class MyShape : public Shape_WithColor, public Shape_WithShape {

  public:
   MyShape(int id) : Shape_WithColor(id), Shape_WithShape(id), Shape_Basic(id) {}
};

int main() {
  MyShape s(1);
   s.set_id(2);
  std::cout << s.get_id() << std::endl;
}