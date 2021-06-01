#ifndef INDIVIDUAL_HPP
#define INDIVIDUAL_HPP
#include <iostream>
#include <vector>
#include "Fitness.hpp"

template <typename T>
class Individual : public Fitness
{
private:
  std::vector<T> array;
  std::vector<T> arrayt;
  // Shuffle añadido temporalmente
  void shuffle();

public:
  Individual(std::vector<T> &, std::vector<T> &);
  bool is_sorted();
  void bogo_sort();
  bool calfitness();
  void print_();
};

#endif