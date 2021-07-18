#include "Genetic.h"
using namespace std;

void Genetic::initialize_Population(){
    for (size_t i = 0; i < population_size; ++i)
        population.push_back(Individuo(cromosoma_size));
}

void Genetic::make(){
    for (size_t i = 0; i < population_size; ++i)
        population[i].observate();
}

void Genetic::repair(){
    /* bustamante */
}

void Genetic::evaluate(){
    for (size_t i = 0; i < population_size; ++i)
        population[i].evaluate_fitness(max_capacity);
    sort(population.begin(), population.end());
}

float Genetic::get_rotation_angle(const int xi,const int bi, bool condition){
    const float pi = acosf(-1);
    if (xi == 0 && bi == 1 && condition == false)
        return 0.01f*pi;
    else if (xi == 1 && bi == 0 && condition == false)
        return -1*0.01f*pi;
    else
        return 0; 
}

void Genetic::quantum_gate(Individuo &initial, Individuo &best){
    const float pi = acosf(-1);
    bool condition = initial.fitness >= best.fitness;
    for (size_t i = 0; i < initial.size; ++i){
        float angle = get_rotation_angle(initial.cromosome_colapsed[i], best.cromosome_colapsed[i], condition);
        if((angle >= 0 && angle <= pi/2) || angle >= pi && angle <= (3/2)*pi){
            initial[i].alpha = initial[i].alpha*cos(angle) - initial[i].alpha*sin(angle);
            initial[i].beta = initial[i].beta*sin(angle) + initial[i].beta*cos(angle);
        }else{
            initial[i].alpha = initial[i].alpha*sin(angle) - initial[i].alpha*cos(angle);
            initial[i].beta = initial[i].beta*-1*sin(angle) - initial[i].beta*cos(angle);   
        }
    }
}

Genetic::Genetic(size_t popu_size, size_t cromo_size, size_t generations, const int max_capacity)
    : population_size{popu_size}, cromosoma_size{cromo_size}, generations{generations}, max_capacity{max_capacity} { 
        population.reserve(population_size);
    }

void Genetic::exe(){
    initialize_Population();
    evaluate();
    Individuo best = population[0];
    for (int i = 0; i < generations; ++i){
        evaluate();
        for (int j = 0; j < population_size; ++j)
            quantum_gate(population[j],best);
        evaluate();
        if (population[0].fitness > best.fitness)
             best = population[0];
        cout << "Generation: " << i << "  fitness: " << best.fitness << "  >>" << endl;
    }
    cout << "Best Solution:" << endl;
    best.observate();
    cout << "Final weight: " << best.fitness << endl;
    EXIT_SUCCESS;
}

Genetic::~Genetic(){
    population.clear();
}
