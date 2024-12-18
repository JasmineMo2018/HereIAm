#pragma once
#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Computer {
 public:
  void SetCpu(const string& cpu) { 
    std::cout << cpu << std::endl;
    cpu_ = cpu;
  }

  void SetMemory(const string& memory) {
    std::cout << memory << std::endl;
    memory_ = memory;
  }

  void SetStorage(const string& storage) {
    std::cout << storage << std::endl;
    storage_ = storage;
  }

  void Show() const {
    std::cout << "computer show cpu " << cpu_ << " memory " << memory_ << " storage " << storage_ << std::endl;
    return;
  }

 private:
  string cpu_;
  string memory_;
  string storage_;

};

// 给外面暴露 抽象builder类
class ComputerBuilder {
 public:
  virtual void BuildCpu() = 0;
  virtual void BuildMempry() = 0;
  virtual void BuildStorage() = 0;

  virtual Computer CreateComputer() = 0;

};
