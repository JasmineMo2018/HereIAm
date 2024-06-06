#include <iostream>
#include <functional>
// ��װ���̳С���̬ �����ü̳к��麯����
// ��װ�������߲������ڲ�ʵ��
// �̳У����ô��룬�����ظ�������
// ��̬����д�������Ϊ������������ʹ���麯��


// ����дһ�����ܱ����������̳е��ࣿ==========================================
//class FinalClass {
// public:
//  FinalClass() {
//    std::cout << "FinalClass()" << std::endl;
//  }
//  virtual ~FinalClass() { std::cout << "~FinalClass()" << std::endl; }
//
//};

// 1. ���԰Ѹ���Ĺ���д��private�����ǻᵼ�¸���û�취ʹ��
// 2. �������Կ��Ǹ�ɵ�����Ҳ������


class FinalClass final{
 public:
  FinalClass() { std::cout << "FinalClass()" << std::endl; }
  virtual ~FinalClass() { std::cout << "~FinalClass()" << std::endl; }
};

// 3. C++11 ������ final ��֤��ǰ���಻�ܱ��̳У����Ǳ�������Ӱ��

 class InheritC /*: public FinalClass*/ {
  public:
   InheritC() {
     std::cout << "InheritC()" << std::endl;
   }
   virtual ~InheritC() { std::cout << "~InheritC()" << std::endl; }

 };

//  * �ӿڼ̳� 
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

 // �����麯��ʵ�ֶ�̬ ָ��Ĵ���
 // �麯���Ƕ�̬��̬��ģ���Ǿ�̬��̬

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

// ���ؼ̳�
// ��̳�
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