#pragma once
#include "Qubit.h"

class Individuo
{
    friend class Genetic;
    private:
        Qubit* cromosoma;
        int* cromosome_colapsed;
        float fitness;
        size_t size;
        int profit;
        int weight;

    public:
        Individuo(size_t size);
        bool operator < (const Individuo& o) const;
        void evaluate_fitness(const int);
        Qubit& operator[](int index); 
        const int& operator[] (int index) const;
        void observate();
};

#include "Individuo.cpp"
