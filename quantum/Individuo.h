#pragma once
#include "Qubit.h"

class Individuo
{
    friend class Genetic;
    private:
        Qubit* cromosoma;
        int* cromo_bit;
        float fitness;
        size_t size;
        int profit;
        int weight;

    public:
        bool operator < (const Individuo& o) const;
        void evaluate_fitness(const int);
        Qubit& operator [] (int index);
        Individuo(size_t size);
        void observate();
        ~Individuo();
};

#include "Individuo.cpp"