#pragma once
template<typename T>
class Iter {
 public:
  virtual bool HasNext() const = 0;
  virtual T Next() = 0;
  virtual bool HasPred() const = 0;
  virtual T Prev() = 0;

};

template<typename T>
class ArrayIterator : public Iter {
 public:
  ArrayIterator(T* v, uint32_t size) : data_ptr_(v), cur_size_(size) {
  
  }


  virtual bool HasNext() {
  
  }
  virtual T Next() {}
  virtual bool HasPred() {}
  virtual T Prev() {}

 private:
  T* data_ptr_;
  uint32_t cur_size_;
  uint32_t cur_value_;
};
