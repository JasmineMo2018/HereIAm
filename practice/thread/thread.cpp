// thread.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <deque>
#include <atomic>
#include <Windows.h>
using namespace std;

std::mutex g_mu;
std::condition_variable g_cv;  
std::deque<int> g_buffers;
static const uint32_t BUFFER_MAX_SIZE = 10;
atomic<bool> g_is_done = false; 

void Producer(int value) {
  while (value) {
    unique_lock<mutex> locker(g_mu);
    g_cv.wait(locker, []() { return g_buffers.size() < BUFFER_MAX_SIZE; });
    g_buffers.push_back(value);
    cout << "produce value :" << value << endl;
    value--;
    locker.unlock();
    g_cv.notify_one();
  }
  g_is_done = true;
  g_cv.notify_all();
}



void Consumer() { 
  while (!g_is_done || !g_buffers.empty()) {
    unique_lock<mutex> locker(g_mu);
    g_cv.wait(locker, []() { return g_is_done || !g_buffers.empty(); });
    int value = g_buffers.front();
    g_buffers.pop_front();
    cout << "consumer value :" << value << endl;
    locker.unlock();
    g_cv.notify_one();
  }
}

std::condition_variable cur_cv;
std::deque<int> produce_buffer;
static const uint32_t MAX_BUFFER_SIZE = 10;
std::atomic<bool> is_done = false;
std::mutex pc_mutex;


void MyConsumer() {
  while (!is_done || !produce_buffer.empty()) {
    std::unique_lock<mutex> locker(pc_mutex);
    cur_cv.wait(locker, []() { return is_done || !produce_buffer.empty(); });
    if (produce_buffer.size() > 0) {
      int value = produce_buffer.front();
      produce_buffer.pop_front();
      cout << "consumer value :" << value << endl;
    }



    locker.unlock();
    g_cv.notify_one();
  }
}

void MyProducer(int32_t count) {
  while (count > 0) {
    std::unique_lock<std::mutex> locker(pc_mutex);
    cur_cv.wait(locker, []() { return produce_buffer.size() < MAX_BUFFER_SIZE; });
    produce_buffer.push_back(count);
    cout << "produce value :" << count << endl;
    count--;
    
    locker.unlock();
    cur_cv.notify_one();
    Sleep(20);
  }
  is_done = true;
  cur_cv.notify_all();
}

int main() {
  thread producer_th(MyProducer, 20);
  thread consumer_th(MyConsumer);

  int* test_ptr = new int(1);

  producer_th.join();

  consumer_th.join();
  std::cout << "Hello World!\n";
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
