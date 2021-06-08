#include <bits/stdc++.h> 
#include "library.cpp"

int main(int argc, char const *argv[]){

    srand(time(NULL));
    std::vector<int> array = {6,5,1,2,4,3};
    Genetic<int> test = Genetic<int>(array,0.3,5,3);
    test.iniciar();
  
    return EXIT_SUCCESS;
}
