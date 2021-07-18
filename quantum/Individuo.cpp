#include "Individuo.h"
using namespace std;

//initial data
vector<int> profit_vector = {12, 34, 23, 10, 12, 34, 8, 12, 54, 12};
vector<int> weight_vector = {11, 12, 34, 22, 11, 17, 10, 11, 32, 21};
const int sum_weight = 181;

Individuo::Individuo(size_t size)
    : size{size}, cromosoma{new Qubit[size]}, fitness{0.f}, profit{0}, cromo_bit{new int[size]} {}

bool Individuo::operator < (const Individuo& o) const {
	return (fitness > o.fitness);
}

Qubit& Individuo::operator[](int index){
    return cromosoma[index];
}

void Individuo::observate(){
    for (size_t i = 0; i < size; ++i)
        cout << cromosoma[i].colapso() << "  ";
    cout << endl;
}

void Individuo::evaluate_fitness(const int marx_capacity){
    int total_profit = 0;
    int total_weight = 0;
    for (size_t i = 0; i < size; ++i){
        int aux = cromosoma[i].colapso();
        cromo_bit[i] = aux;
        if (aux == 1){
            total_profit += profit_vector[i];
            total_weight += weight_vector[i];
        }else
            continue;
    }
    profit = total_profit;
    weight = total_weight;   
    fitness = profit - (sum_weight*abs(weight-marx_capacity));
}

Individuo::~Individuo(){
    delete[] cromosoma;
}



