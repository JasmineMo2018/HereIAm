// template.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

// 编译期已经完成了 没有运行时的计算损耗

// 5！ =  5 * 4 * 3 * 2 * 1
template<unsigned int N>
struct Factorial {
  static const unsigned int value = Factorial<N - 1>::value * Factorial<N - 2>::value;

};

// 偏特化
template<>
struct Factorial<unsigned int(1)> {
  static const unsigned int value = 1;
};
template <>
struct Factorial<unsigned int(2)> {
  static const unsigned int value = 2;
};


// 类型泛型
template<typename T>
T MyMax(T a, T b) {
  return (a > b) ? a : b;
}
// 偏特化
template <typename T>
T MyMax(short a, T b) {
  return (a > b) ? a : b;
}

// 类
template<typename T>
class MyVector {
 private:
  T* m_data;

};

int fb(int n) {
  if (n == 1) {
    return 1;
  } 
  if (n == 2) {
    return 2;
  }
  return fb(n - 1) + fb(n - 2);
}


// 模板判断处理
template<bool Condition, typename T, typename F>
struct Conditional {
  using type = T;
};
  // 偏特化
template <typename T, typename F>
struct Conditional<false, T, F> {
  using type = F;
};

#include <type_traits>

// type traits
template <typename T>
void CheckType() {
  if (std::is_pointer<T>::value) {
    std::cout << "the type is a pointer." << std::endl;
  } else if (std::is_const<T>::value) {
    std::cout << "the type is a const." << std::endl;
  } else {
    std::cout << "the type is other." << std::endl;
  }

}

// Value traits

// Function traits
template<typename T>
void CheckFunc() {
  if (std::is_function<T>::value) {

  } else {
  }
}

// 可变参数模板
// 1. 递归模式展开
template<typename T>
T sum(T value) {
  return value;
}

template <typename T, typename...Args>
T sum(T first, Args...agrs) {
  return first + sum(agrs...);
}

template <typename... Args>
auto sum2(Args... agrs) {
  return (agrs+...);
}

// 参数包作为函数参数
template <typename... Args>
void myprint(Args... agrs) {
  (std::cout << ... << agrs);
}




// 简化容器声明
template<typename T>
using MyVector2 = std::vector<T>;

// 函数指针别名
bool CompareInt(const int& a, const int& b) { return a < b; }

template<typename T>
using CompareFunc = bool (*)(const T&, const T&);

// 模板变量
template<typename T>
T my_t_pi = T(3.14159);

// 嵌套
template<typename T>
using MyPair = std::pair<T, T>;

template<typename T>
using MyPairVector = std::vector<MyPair<T>>;

// constexpr
constexpr int const_expre_a = 5;
constexpr double const_expre_b = const_expre_a * 3.14;

constexpr int square(int x) { return x * x; }

// 静态断言
template<typename T>
void CheckSize() {
  static_assert(sizeof(T) >= 4, "type size must be at least 4");
}

constexpr int expre_arr_size = 10;
int expre_arr[expre_arr_size];



template<unsigned int N>
struct MyFB{
  static const unsigned int value_1 = MyFB<N-1>::value_1 * MyFB<N-2>::value_1;
};

template <>
struct MyFB<unsigned int(1)> {

  static const unsigned int value_1 = 1;
};

template <>
struct MyFB<unsigned int(2)> {
  static const unsigned int value_1 = 2;
};

int main()
{

    int b = 10;
  int& a = b;
    std::cout << a << std::endl;
  std::cout << "const_expre_a" << const_expre_a << std::endl;
  std::cout << "const_expre_b" << const_expre_b << std::endl;

  std::cout << "square" << square(5) << std::endl;

  CheckSize<int>();
  // CheckSize<short>();
  int* a = nullptr;

  static const unsigned int number = 5;


    std::cout << "Factorial of " << number << " is " << Factorial<number>::value << std::endl;

    std::cout << "fb of " << number << " is " << fb(number) << std::endl;


    using resultType = Conditional<true, double, int>::type ;
    std::cout << typeid(resultType).name() << std::endl; // 运行时刻类型识别

    // Traits
    CheckType<const int>();

    std::cout << sum<int>(1,2,3,4,5) << std::endl;
    myprint(1, 2, 3, 4, 5, "sss", "ttt" );

    CompareFunc<int> func = CompareInt;
    func(1, 3);

    double pi_value = my_t_pi<double>;
    int pi_value2 = my_t_pi<int>;
    std::cout << pi_value << " " << pi_value2 << std::endl;
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
