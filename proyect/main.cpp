// // "- Crear Github
// //     - Hacer el bogosort - Encapsular el arreglo en una clase individuo - Class Fitness para verificar qué tan ordenado está - Crear una pieza de arte(Framework) "
// // C++ implementation of Bogo Sort
#include <iostream>
#include <vector>
#include "./classes/Individual.cpp"

int main(int argc, char const *argv[])
{
  std::vector<int> array = {9,4,1,0,3};
  std::vector<int> arrayt = {0,1,3,4,9};
  Individual<int> id_01(array,arrayt);
  
  id_01.bogo_sort();
  return 0;
}