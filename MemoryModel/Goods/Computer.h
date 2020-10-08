//
// Created by rodion on 10/8/20.
//

#ifndef COMPUTERSHOP_GOODS_COMPUTER_H_
#define COMPUTERSHOP_GOODS_COMPUTER_H_

#include <string>
#include <vector>
#include <memory>
#include "Component/GraphicsCard.h"

class Computer {
 public:
  static std::optional<Computer> create(const std::string& name, const std::vector<std::shared_ptr<Component>>& components);

 private:
  Computer(const std::string& name_, const std::vector<std::shared_ptr<Component>>& components);

 private:
  std::string name_;
  std::vector<std::shared_ptr<Component>> components_;
};

#endif //COMPUTERSHOP_GOODS_COMPUTER_H_
