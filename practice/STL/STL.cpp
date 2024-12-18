// STL.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include<list>
#include <set>
#include <map>
#include<bitset>

#include <algorithm>
#include <numeric>


class MyTestClass {
 public:
  MyTestClass() { std::cout << "MyTestClass" << std::endl;
  }

  ~MyTestClass() { std::cout << "~MyTestClass" << std::endl; }

};

/* 容器： 
    序列性 线性：vector、list、deque 排列和插入顺序有关
          1. vector 自动扩容 size、capacity
                    扩容，深拷贝。每次扩容为前面的1.5倍 (old + old / 2),有的是两倍
          2. list 双向链表 插入删除容易 但是不支持随机访问
          3. stack queue(deque)
            adapter ： 默认的是个deque
            deque是一系列连续的内存块组成的数组，每个内存块存储一定量的元素
            deque是vector和list的一个择中方案，可以支持随机访问，效率没有vector高，头尾插入删除效率高
            stack和queue是有限制的deque
    关联性 非线性： map、set、multimap、multiset unorderedxxx 排列和自身特点有关 红黑树
          1. set 
          key-value都是键值 一起排序 不能通过set的迭代器改变set的元素值 排好了，不许改
          2. map 
          key和value是分开的，排序key，所以key不能改，value可以改
          3. multiset、multimap
          key不是唯一的 底层实现是一种特殊的平衡二叉搜索树
*/

/*
  算法：
    1.可变序列和非可变序列
    2.排序、搜索、数值算法、其他
*/

struct Compare{
  bool operator()(const int a, const int b) const { return a > b;
  }
};

void PrintSquare(int a) { std::cout << a * a << std::endl; }
bool JSCount(int a) { return a % 2 == 0; }
int SetSquare(int a) { return a * a ; }

static const unsigned int MAX_NUM = 10000;
void BitmapSort(int arr[], unsigned int size) {
  std::bitset<MAX_NUM> bit_set;
  for (unsigned int i = 0; i < size; i++) {
    bit_set.set(arr[i]);
  }

  for (unsigned int i = 0, j = 0; i < MAX_NUM; i ++) {
    if (bit_set.test(i)) {
      arr[j++] = i;
    }

  }
}

int main()
{
  std::vector<int> v = {5,6,7,8,9,10};
  // for_each
  std::cout << "for_each!\n";
  std::for_each(v.begin(), v.end(), PrintSquare);


  // count if
  std::cout << "count if!\n";
 int event_count = std::count_if(v.begin(), v.end(), JSCount);
  std::cout << event_count << std::endl;

  // transform
  std::transform(v.begin(), v.end(), v.begin(), [](int x) { return x * x; });

  // fill
  std::vector<int> v2(5);
  std::fill(v2.begin(), v2.end(), 6);

  // 排序 sort ： 里面不只是快排 会根据情况去选择堆排 插入排序等 综合
  std::sort(v.begin(), v.end()); // 不稳定 快排 堆排
  std::stable_sort(v.begin(), v.end()); // 稳定 归并 插入
  std::partial_sort(v.begin(),v.begin() + 5, v.end());
  // bitmap
  int arr[] = {2,4,4,8956,41,21,3,97,257,55};
  BitmapSort(arr, sizeof(arr) / sizeof(arr[0]));

  // 搜索 find ： 一般用二分 和一些特殊条件的
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
