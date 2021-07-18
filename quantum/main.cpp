#include <bits/stdc++.h>
#include "Genetic.h"

int main(int argc, char **argv)
{
    //Algorithm
    srand(static_cast<unsigned int>(time(nullptr)));
    Genetic a(5,10,1000,20);
    a.exe();

    //free memory
    a.~Genetic();
    return EXIT_SUCCESS;
}
