#pragma once
class MyString {
 public:
  // 三个构造：构造、拷贝构造、转移构造
  MyString(); // 注意 可能会导致成员变量没有初始化，要衡量

  MyString(const MyString& ob);
  MyString(const char* ch);
  explicit MyString(size_t len); // 防止隐式转换
  MyString(MyString&& ob);

  // 两个赋值： 赋值函数、转移赋值
  MyString& operator=(const MyString& ob);
  MyString& operator=(MyString&& ob); // 右值不能加const

  // 一个析构： 析构函数
  virtual ~MyString(); // 如果你的类被继承 那么子类和父类的某些成员变量结构可能不一致。
                       // 析构写成虚的，可以实现多态，那么调用时就可以各自释放自己的资源。

  private:
   char* m_ch = nullptr;
   size_t m_len = 0;
   size_t m_alloc = 0;
};

// RVO
/*
  早期函数返回值：
    1. 值传递
    2. 引用传递 内部对参数处理

  返回临时对象的处理：
    

  编译器对返回值的优化：
  1. move语义
  2. RVO 和 NRVO 无名和有名 全局区开辟一块空间存地址，然后传递给外面的栈



*/

class MyStringTest {
  public:
   // 五个构造
   MyStringTest();

   MyStringTest(const char* str_ptr);

   explicit MyStringTest(int size);

   MyStringTest(const MyStringTest& ob);
   MyStringTest(MyStringTest&& ob);

   // 两个赋值
   MyStringTest& operator=(const MyStringTest& ob);
   MyStringTest& operator=(MyStringTest&& ob);


   // 一个析构
   virtual ~MyStringTest();

 private:
   char* my_string_ptr_ = nullptr;
   int string_len = 0;
   int malloc_len = 0;
};