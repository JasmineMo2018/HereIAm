#include <iostream>
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

 class InheritC : public FinalClass {
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




