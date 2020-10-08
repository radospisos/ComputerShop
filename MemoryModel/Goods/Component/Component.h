//
// Created by rodion on 10/8/20.
//

#ifndef COMPUTERSHOP_GOODS_COMPONENT_H_
#define COMPUTERSHOP_GOODS_COMPONENT_H_

#include <string>

class Component {
 public:
  virtual std::string getName() const = 0;
  virtual std::string getDistributor() const = 0;
  virtual unsigned int getPrice() const = 0;
};

#endif //COMPUTERSHOP_GOODS_COMPONENT_H_
