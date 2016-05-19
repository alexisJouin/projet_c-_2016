#ifndef ARRAYOFNUMBER_HPP
#define ARRAYOFNUMBER_HPP
#include "Number.hpp"
#include <vector>

class ArrayOfNumber{
 private:
  std::vector<Number> _numbers;
public:
  void generateNumber();
  
};
#endif
