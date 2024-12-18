#pragma once
#include <iostream>

#include "computerbuilder.h"

class lenevocomputerbuilder : public ComputerBuilder {
 public:
  lenevocomputerbuilder() {
    comp_ = make_shared<Computer>();
  }
  virtual void BuildCpu() { 
    comp_->SetCpu("lenevo cpu");
    cout << "lenevo BuildCpu." << endl;
  }

  virtual void BuildMempry() {
    comp_->SetMemory("lenevo memory");
    cout << "lenevo BuildMempry." << endl;
  }

  virtual void BuildStorage() {
    comp_->SetStorage("lenevo storage");
    cout << "lenevo BuildStorage." << endl;
  }

  virtual Computer CreateComputer() {
    cout << "lenevo CreateComputer." << endl;
    return *comp_;
  }

 private:
  std::shared_ptr<Computer> comp_;
};
