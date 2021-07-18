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

    for (size_t i = 0; i < population_size; ++i)
        cout << "fitness:" << population[i].fitness << endl;
}

float_t Genetic::get_rotation_angle(const int x_i, const int best_i, bool condition){
    const float_t pi = acosf(-1);
    if (x_i == 0 && best_i == 1 && condition == false)
        return 0.01f*pi;
    else if (x_i == 1 && best_i == 0 && condition == false)
        return -1*0.01f*pi;
    else
        return 0; 
}

void Genetic::quantum_gate(Individuo &initial, Individuo &best){
    const float_t pi = acosf(-1);
    bool condition = initial.fitness >= best.fitness;
    for (size_t i = 0; i < initial.size; ++i){
        float_t angle = get_rotation_angle(initial.cromo_bit[i], best.cromo_bit[i], condition);
        if((angle > 0 && angle < pi/2) || angle > pi && angle < (3/2)*pi){
            initial[i].alpha = initial[i].alpha*cos(angle) - initial[i].alpha*sin(angle);
            initial[i].beta = initial[i].beta*sin(angle) + initial[i].beta*cos(angle);
        }else{
            initial[i].alpha = initial[i].alpha*sin(angle) - initial[i].alpha*cos(angle);
            initial[i].beta = initial[i].beta*-1*sin(angle) - initial[i].beta*cos(angle);   
        }
    }
}

Genetic::Genetic(size_t popu_size, size_t cromo_size, size_t generations, const int max_capacity)
    : population_size{popu_size}, cromosoma_size{cromo_size}, generations{generations}, max_capacity{max_capacity} {}

Genetic::~Genetic(){
    population.clear();
}

void Genetic::exe(){
    initialize_Population();
    make();
    evaluate();
    Individuo best = population[0];
    for (size_t i = 1; i < generations; ++i){
        quantum_gate(population[i], best);        
    }
}
