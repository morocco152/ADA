// "- Crear Github
//     - Hacer el bogosort - Encapsular el arreglo en una clase individuo - Class Fitness para verificar qué tan ordenado está - Crear una pieza de arte(Framework) "
// C++ implementation of Bogo Sort
#include <bits/stdc++.h>
using namespace std;

// Comprobar si el arreglo esta ordenado o no
bool is_sorted(const vector<int> &vec)
{

  for (int i = 1, n = vec.size(); i < n; i++)
  {
    if (vec[i - 1] > vec[i])
      return false;
    // returns false if an element is smaller than one to its left
  }

  return true;
}
// Genera permutación de la matriz
void shuffle(vector<int> &vec)
{
  int i, n, tmp, rand_idx;

  for (i = 0, n = vec.size(); i < n; i++)
  {

    tmp = vec[i]; // store temporarily

    rand_idx = rand() % n; // pick a random index in the vector/array

    // swap each element in vector/array with another one that is chosen randomly
    vec[i] = vec[rand_idx];
    vec[rand_idx] = tmp;
  }
}

void bogosort(vector<int> &vec)
{
  while (!is_sorted(vec))
    shuffle(vec);
}

// prints the array
void print(vector<int> &array)
{
  for (auto it = array.begin(); it != array.end(); it++)
    std::cout << *it << " ";
  std::cout << "\n";
}

// Driver code
int main()
{
  vector<int> a = {3, 2, 5, 1, 0, 4};
  print(a);
  bogosort(a);
  print(a);
  return 0;
}
