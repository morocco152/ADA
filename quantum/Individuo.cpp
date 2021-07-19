#include "Individuo.h"
using namespace std;

//initial data
    vector<int> profit_vector = {15 , 13 , 21 , 22 , 18 , 12 , 16 , 23 , 16 , 14 , 27 , 14 , 28 , 10 , 24 , 14 , 20 , 17 , 14 , 18 , 13 , 15 , 18 , 26 , 15 , 24 , 12 , 11 , 26 , 15 , 24 , 26 , 23 , 24 , 17 , 12 , 28 , 26 , 21 , 11 , 25 , 22 , 24 , 21 , 23 , 10 , 11 , 29 , 15 , 14};
    vector<int> weight_vector = {16 , 8 , 12 , 10 , 7 , 15 , 12 , 17 , 5 , 9 , 15 , 6 , 8 , 13 , 10 , 13 , 16 , 5 , 6 , 12 , 10 , 14 , 13 , 17 , 19 , 9 , 11 , 7 , 12 , 11 , 18 , 14 , 10 , 9 , 16 , 8 , 14 , 17 , 9 , 17 , 17 , 7 , 16 , 15 , 14 , 16 , 13 , 11 , 7 , 5};
    const int sum_weight = 591;

Individuo::Individuo(size_t size)
    : size{size}, cromosoma{new Qubit[size]}, fitness{0.f}, profit{0}, cromosome_colapsed{new int[size]} {}

bool Individuo::operator < (const Individuo& o) const {
	return (fitness > o.fitness);
}

Qubit& Individuo::operator[](int index){
    return cromosoma[index];
}

const int& Individuo::operator[](int index) const{
    return cromosome_colapsed[index];
}

void Individuo::observate(const int marx_capacity){
    int total_profit = 0;
    int total_weight = 0;
    for (size_t i = 0; i < size; ++i){
        int aux = cromosoma[i].colapso();
        cromosome_colapsed[i] = aux;
        if (aux == 1){
            total_profit += profit_vector[i];
            total_weight += weight_vector[i];
        }else
            continue;
    }
    profit = total_profit;
    weight = total_weight; 
}

void Individuo::evaluate_fitness(const int type_fitness, const int max_capacity){
    if (type_fitness == 1)
        fitness = profit - (sum_weight*abs(weight-max_capacity));
    else if ( type_fitness == 2)
        fitness = profit;
    else 
        EXIT_FAILURE;
}

void Individuo::show_binary(){
    for (size_t i = 0; i < size; ++i)
        cout << cromosome_colapsed[i] << " " ; 
    cout << endl;
}

void Individuo::repair(const int max_capacity){

    bool overfilled = false;

    if(get_t_weight() > max_capacity)
        overfilled = true;

    srand(time(0));
    int i_th;
    while(overfilled){
	    i_th = rand()%size;
        cromosome_colapsed[i_th] = 0;
        
        if(get_t_weight() <= max_capacity)
            overfilled = false;
    }

    srand(time(0));
    int j_th;
    while (!overfilled){
	    j_th = rand()%size;
        cromosome_colapsed[j_th] = 1;

        if(get_t_weight() > max_capacity)
            overfilled = true;
    }

    cromosome_colapsed[j_th] = 0;


    int total_profit = 0;
    int total_weight = 0;
    for (size_t i = 0; i < size; ++i){
        if (cromosome_colapsed[i] == 1){
            total_profit += profit_vector[i];
        }else
            continue;
    }
    profit = total_profit;
    fitness = profit;
    weight = get_t_weight();
}

int Individuo::get_t_weight(){
    int temp_weight = 0;
    for(int i = 0; i < size; i++){
        if (cromosome_colapsed[i] == 1){
            temp_weight += weight_vector[i];
        }else
            continue;
    }

    return temp_weight;
}
