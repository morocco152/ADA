#pragma once 
#include "Individuo.h"
using namespace std;

class Genetic
{
    protected:
        size_t generations;
        size_t cromosoma_size;
        size_t population_size;
        const int max_capacity;
        vector<Individuo> population;

    private:
        void make();
        void repair();
        void evaluate();
        void initialize_Population();
        void quantum_gate(Individuo&, Individuo&);
        float_t get_rotation_angle(const int, const int, bool);
        void appling_rotating_gate(Individuo &, Individuo &);
    public:
        Genetic(size_t, size_t, size_t, const int);
        ~Genetic();
        void exe();
};

#include "Genetic.cpp"