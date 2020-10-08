//
// Created by rodion on 10/8/20.
//

#include "GraphicsCard.h"

GraphicsCard::GraphicsCard(const std::string &name,
                           const std::string &distributor,
                           const unsigned int &price,
                           const unsigned int &mem_frequency,
                           const unsigned int &core_frequency,
                           const unsigned int &mem_size)
                           :
                           name_(name),
                           distributor_(distributor),
                           price_(price),
                           memory_frequency_(mem_frequency),
                           core_frequency_(core_frequency),
                           memory_size_(mem_size) {}

std::optional<GraphicsCard> GraphicsCard::create(const std::string &name,
                                                 const std::string &distributor,
                                                 const unsigned int &price,
                                                 const unsigned int &mem_frequency,
                                                 const unsigned int &core_frequency,
                                                 const unsigned int &mem_size) {
  if(name == "" || distributor == "" || mem_frequency == 0 || core_frequency == 0 || mem_size == 0) return std::nullopt;
  return GraphicsCard{name, distributor, price, mem_frequency, core_frequency, mem_size};
}

std::string GraphicsCard::getName() const { return this->name_; }

std::string GraphicsCard::getDistributor() const { return this->distributor_; }

unsigned int GraphicsCard::getPrice() const { return this->price_; }

unsigned int GraphicsCard::getMemoryFrequency() const { return this->memory_frequency_; }

unsigned int GraphicsCard::getCoreFrequency() const { return this->core_frequency_; }

unsigned int GraphicsCard::getMemorySize() const { return this->memory_size_; }