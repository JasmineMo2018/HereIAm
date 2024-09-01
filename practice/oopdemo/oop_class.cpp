#include <iostream>
#include <functional>
// 封装、继承、多态 （少用继承和虚函数）
// 封装：调用者不关心内部实现
// 继承：服用代码，避免重复造轮子
// 多态：改写对象的行为，但不仅仅是使用虚函数


// 怎样写一个不能被其他类所继承的类？==========================================

// 1. 可以把父类的构造写成private，但是会导致父类没办法使用
// 不过可以考虑搞成单例，也可以用
class FinalClassTest {
 private:
  FinalClassTest() { std::cout << "FinalClass()" << std::endl; }
  virtual ~FinalClassTest() { std::cout << "~FinalClass()" << std::endl; }
};

// 2. C++11 新特性 final 保证当前的类不能被继承，但是本身不会受影响

class FinalClassTest1 final {
 private:
  FinalClassTest1() { std::cout << "FinalClassTest1()" << std::endl; }
  virtual ~FinalClassTest1() { std::cout << "~FinalClassTest1()" << std::endl; }
};

//  * 接口继承 
class CanFlyable {
 public:
  virtual void Fly() = 0;

};

class Bird {
 public:
  virtual void Walk() { std::cout << "Bird Walk." << std::endl; }

  double GetLength() { return length_; }
 private:
  double length_ = 0;

};

class Sprrow : public Bird, public CanFlyable {
 public:
  virtual void Fly() override { std::cout << "Sprrow Fly." << std::endl;
  }

  virtual void Walk() override { std::cout << "Sprrow Walk." << std::endl; }
  };

class Ostrich : public Bird {
 public:
  virtual void Walk() override { std::cout << "Ostrich Walk." << std::endl; }
};

class Bat : public CanFlyable {
 public:
  virtual void Fly() override { std::cout << "Bat Fly." << std::endl; };
};

// 不用虚函数
void default_walk() { std::cout << "default_walk." << std::endl; }
class BirdA {
 public:
  typedef std::function<void()> MyWalkFunc;
  BirdA(MyWalkFunc func = default_walk) : func_(func) {}

  void WalkF() const { func_();
  }
 private:
  MyWalkFunc func_;
};

void SprrowWalk() { std::cout << "SprrowWalk." << std::endl; }
void BatWalk() { std::cout << "BatWalk." << std::endl; }

class SprrowA : public BirdA{
 public:
  typedef std::function<void()> MyWalkFunc;
  SprrowA(MyWalkFunc f) : BirdA(f) {}

};

class BatA : public BirdA {
 public:
  typedef std::function<void()> MyWalkFunc;
  typedef void(*MyWalkFunc2)();
  BatA(MyWalkFunc f) : BirdA(f) {}
};

 // 不用虚函数实现多态 指针的传递
 // 虚函数是动态多态、模板是静态多态

// 菱形继承
class Shape_Basic {
 public:
  Shape_Basic(int id) { std::cout << "Shape_Basic()" << std::endl; }
 protected:
  int id_ = 0;


};

class Shape_WithColor : virtual public Shape_Basic {
 public:
  Shape_WithColor(int id) : Shape_Basic(id){
  }

  void SetId(int id) { id_ = id;
  }
};

class Shape_WithShape : virtual public Shape_Basic {
 public:
  Shape_WithShape(int id) : Shape_Basic(id) { id_ = id; }

  int GetID() { return id_;
  }

};

class Shape : public Shape_WithColor, public Shape_WithShape {
 public:
  Shape(int id) : Shape_WithColor(id), Shape_WithShape(id), Shape_Basic(id) {}
};

// 多重继承
// 虚继承


int main() { 
  Shape shape_1(1);
  shape_1.SetId(2);
  std::cout << "id = " << shape_1.GetID();
  

  return 0;
}