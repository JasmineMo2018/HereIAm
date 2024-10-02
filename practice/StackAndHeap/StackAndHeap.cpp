// StackAndHeap.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

// int global_var = 0;

    // 汇编

// 冯诺依曼
/*
  1. CPU
  2. 内存 硬盘
  3. I/0


  内部负责存储计算的 比内存更快的 集成到cpu中的存储设备，：寄存器

  通用寄存器：保存、传递、计算并存结果
    数据寄存器： EAX EBX ECX EDX       EAX通常用来记录返回值 ECX 通常用来保存this
    变址寄存器： ESI EDI
    指针寄存器： ESP EBP               EBP 保存函数的栈底(extended base pointer) ESP 目前的栈顶的位置(extended stack
  pointer) 栈顶的地址要比栈底小

  段寄存器： CS DS ES SS GS       保存数据、变量的信息

  指令寄存器： EIP                指向当前程序运行到哪

  标志寄存器： CF PF AF ZF SF OF  当前程序是否有进位、溢出、结果是奇数偶数等信息




  常见基本语句：
  1. 基本运算： INC，ADD    +
                DEC，SUB    -
                mul         *
                div         /
  2. 循环跳转： loop
                call
                jmp
                ret
  3. 数据移动： mov
                lea
  4. 栈操作：   PUSH
                POP
  5. 逻辑运算： AND
                OR
                XOR
                NOT
  6. 比较运算： cmp
                test


  内中断、int指令、端口、外中断


*/

// RAII 资源管理 初始化的时候做资源分配
/*
  栈上不太容易产生内存碎片

  为啥用栈： 1. 对象比较大 栈空间有限
             2. 有些对象编译时期不知道大小


  // 对象创建自动申请资源 对象销毁自动释放资源
  new ： operator new 堆申请一块空间
         placement new 对象的构造函数做一下调用

  delete ： 调用析构函数
            释放资源

  析构函数： virtual 继承体系
            子类和父类内部的成员不一样，子类可能有自己堆的私有成员
            父类指针调用的时候，调不到子类的析构函数 虚表重写那个地址

*/



enum number_type {
  INTGER,
  RATIONAL,
  COMPLEX
};

class Number {
 public:
  Number() { std::cout << "Number" << std::endl; }
  virtual ~Number() { std::cout << "~Number" << std::endl; }
};

class Intger : public Number {
 public:
  Intger() { std::cout << "Intger" << std::endl; }
  ~Intger() { std::cout << "~Intger" << std::endl; }
};

class Rational : public Number {
 public:
  Rational() { std::cout << "Rational" << std::endl; }
  ~Rational() { std::cout << "~Rational" << std::endl; }
};

class Complex : public Number {
 public:
  Complex() { std::cout << "Complex" << std::endl; }
  ~Complex() { std::cout << "~Complex" << std::endl; }
};

Number* CreateNumber(number_type type) {
  switch (type) {
    case INTGER: {
      return new Intger();
    }
    case RATIONAL: {
      return new Rational();
    }
    case COMPLEX: {
      return new Complex();
    }
    default: {
      return new Number();
    }
  }
}

class Number_Wrapper {
 public:
  explicit Number_Wrapper(Number* ptr = nullptr) : ptr_(ptr){}


  ~Number_Wrapper() { delete ptr_; }

 private:
  Number* ptr_;
};

int main()
{

  Number_Wrapper(CreateNumber(INTGER));








  return 0;
  //int stack_var = 1;
  //int* heap_var = new int(2);
  //static int static_var = 3;
  //const char* str_constant = "hello";

  //
  //std::cout << global_var << " ," << &global_var << std::endl;
  //std::cout << stack_var << " ," << &stack_var << std::endl;
  //std::cout << *heap_var << " ," << heap_var << std::endl;
  //std::cout << static_var << " ," << &static_var << std::endl;
  //std::cout << str_constant << " ," << &str_constant << std::endl;

  //delete heap_var; 
  //  std::cout << "Hello World!\n";




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
