//
// Created by rodion on 10/8/20.
//

#ifndef COMPUTERSHOP_GOODS_COMPONENT_GRAPHICSCARD_H_
#define COMPUTERSHOP_GOODS_COMPONENT_GRAPHICSCARD_H_

#include <optional>
#include "Component.h"

class GraphicsCard : public Component {
 public:
  static std::optional<GraphicsCard>   create(const std::string& name, const std::string& distributor,
                               const unsigned int& price, const unsigned int& mem_frequency,
                               const unsigned int& core_frequency, const unsigned int& mem_size);

 public:
  std::string getName() const override;
  std::string getDistributor() const override;
  unsigned int getPrice() const override;
  unsigned int getMemoryFrequency() const;
  unsigned int getCoreFrequency() const;
  unsigned int getMemorySize() const;

 private:
  GraphicsCard(const std::string& name, const std::string& distributor,
               const unsigned int& price, const unsigned int& mem_frequency,
               const unsigned int& core_frequency, const unsigned int& mem_size);

 private:
  std::string name_;
  std::string distributor_;
  unsigned int price_;
  unsigned int memory_frequency_;
  unsigned int core_frequency_;
  unsigned int memory_size_;
};

#endif //COMPUTERSHOP_GOODS_COMPONENT_GRAPHICSCARD_H_
