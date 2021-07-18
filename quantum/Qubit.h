#pragma once 
#include <cmath>

// Unidad más pequeña de representación del QEA
class Qubit
{
    friend class Genetic;
    private:
        // Amplitud de la probabilidad
        double alpha;
        double beta;

    public:
        // Inicialización
        Qubit();
        int colapso() const; // el qubit colapsa
};

#include "Qubit.cpp"
