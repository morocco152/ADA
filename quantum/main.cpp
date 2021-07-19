#include <bits/stdc++.h>
#include "Genetic.h"

int main(int argc, char **argv)
{
    srand(static_cast<unsigned int>(time(nullptr)));
    
    //Algorithm
    // fitness penality 1 
    // fitness repair 2 

    puts("fitness : Penalty!");    
    Genetic a(30,50,1000,300,1);
    a.exe();

    puts("fitness : Repair");
    Genetic b(20,50,1000,300,2);
    b.exe();


    //free memory
    a.~Genetic();
    b.~Genetic();

    return EXIT_SUCCESS;
}

