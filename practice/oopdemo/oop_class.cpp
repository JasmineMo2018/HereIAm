#include <iostream>
#include <functional>
// ��װ���̳С���̬ �����ü̳к��麯����
// ��װ�������߲������ڲ�ʵ��
// �̳У����ô��룬�����ظ�������
// ��̬����д�������Ϊ������������ʹ���麯��


// ����дһ�����ܱ����������̳е��ࣿ==========================================

// 1. ���԰Ѹ���Ĺ���д��private�����ǻᵼ�¸���û�취ʹ��
// �������Կ��Ǹ�ɵ�����Ҳ������
class FinalClassTest {
 private:
  FinalClassTest() { std::cout << "FinalClass()" << std::endl; }
  virtual ~FinalClassTest() { std::cout << "~FinalClass()" << std::endl; }
};

// 2. C++11 ������ final ��֤��ǰ���಻�ܱ��̳У����Ǳ�������Ӱ��

class FinalClassTest1 final {
 private:
  FinalClassTest1() { std::cout << "FinalClassTest1()" << std::endl; }
  virtual ~FinalClassTest1() { std::cout << "~FinalClassTest1()" << std::endl; }
};

//  * �ӿڼ̳� 
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

// �����麯��
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

 // �����麯��ʵ�ֶ�̬ ָ��Ĵ���
 // �麯���Ƕ�̬��̬��ģ���Ǿ�̬��̬

// ���μ̳�
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

// ���ؼ̳�
// ��̳�


int main() { 
  Shape shape_1(1);
  shape_1.SetId(2);
  std::cout << "id = " << shape_1.GetID();
  

  return 0;
}