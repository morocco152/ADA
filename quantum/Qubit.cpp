#include <bits/stdc++.h>
#include "Qubit.h"

Qubit::Qubit()
    : alpha{1/std::sqrt(2)}, beta{1/std::sqrt(2)} {} 

int Qubit::colapso() const{
    double probability = (double)rand() / (double)RAND_MAX;
    if (probability < beta * beta)
        return 1; 
    return 0;
}

