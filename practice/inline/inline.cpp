// inline.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

inline int maxValue(int a, int b) {
  return (a > b) ? a : b;
}

int main()
{
  const char* my_str = "my\0str";
  std::cout << sizeof(my_str) << std::endl; // 4 指针的长度
  std::cout << strlen(my_str) << std::endl;  // 2 不算\0

  char arr[10] = "mys\0tr";
  std::cout << sizeof(arr) << std::endl; // 10
  std::cout << strlen(arr) << std::endl; // 3 不算\0

  char* arr_ptr = new char[10];
  std::cout << strlen(arr_ptr) << std::endl;  // 不一定
  std::cout << sizeof(arr_ptr) << std::endl;  // 4
  std::cout << sizeof(*arr_ptr) << std::endl; // 1


  int b = 0b11001;
  bool is_equal_zero = b & (1 << 3); // 1
  

  std::cout << is_equal_zero << std::endl;
  // inline 空间换时间 代码段直接插入到调用的地方
  // 但是是否真的inline 取决于编译器是否采用
  // vs2022 还是call了
  int x = 3, y = 4;
  maxValue(x, y);

  // mutable -> const  // 可以在一个const函数里面改变它

  // volatile 拒绝编译器的优化缓存 每次都去取实际的值
  const volatile int min_len = 10;
  int* ptr = (int*)(& min_len) ;
  *ptr = 11;
  std::cout << min_len << std::endl; // 10
  std::cout << *ptr << std::endl; // 11
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
