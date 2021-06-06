#include <bits/stdc++.h> 
#include "library.cpp"

int main(int argc, char const *argv[]){

    srand(time(NULL));
    std::vector<int> array = {9, 1, 0, 6, 2,-6,23};
    Genetic<int> test = Genetic<int>(array,0.3,6,2);
    test.iniciar();
  
    return EXIT_SUCCESS;
}
