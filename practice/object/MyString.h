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
