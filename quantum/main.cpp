#include <bits/stdc++.h>
#include "Genetic.h"

int main(int argc, char **argv)
{
    //Algorithm
    // fitness penality 1 
    // fitness repair 2 

    puts("fitness : Penalty!");    
    srand(static_cast<unsigned int>(time(nullptr)));
    Genetic a(20,50,1000,300,1);
    a.exe();
    //free memory
    a.~Genetic();

    puts("fitness : Repair");
    srand(static_cast<unsigned int>(time(nullptr)));
    Genetic b(20,50,1000,300,2);
    b.exe();
    //free memory
    b.~Genetic();

    return EXIT_SUCCESS;
}

