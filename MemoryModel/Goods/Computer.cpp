//
// Created by rodion on 10/8/20.
//

#include "Computer.h"

std::optional<Computer> Computer::create(const std::string &name,
                                         const std::vector<std::shared_ptr<Component>> &components) {
  if(name == "") return std::nullopt;
  return Computer{name, components};
}

Computer::Computer(const std::string &name, const std::vector<std::shared_ptr<Component>> &components) {
  this->name_ = name;
  this->components_ = components;
}

