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
        int get_t_weight();

    public:
        Individuo(size_t size);
        bool operator < (const Individuo& o) const;
        void evaluate_fitness(const int, const int);
        Qubit& operator[](int); 
        const int& operator[] (int) const;
        void observate(const int);
        void repair(const int);
        void show_binary();
};

#include "Individuo.cpp"
