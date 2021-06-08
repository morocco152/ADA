#include <bits/stdc++.h>

//ClassIndividual
template <typename T>
class Individual{
private:
    std::vector<T> array;
    std::vector<T> copy_array;
    std::vector<bool> estado; 
    int fit_;
public:
    Individual(std::vector<T> &);
    std::vector<T> getArray();
    bool operator < (Individual&) const;
    void set_array(std::vector<T> &);
    void suffle(); 
    int get_len();
    void set_fitness(int);
    int get_fitness();
    void fitness();
    void print();
    void mutar(int);
    void l_suffle();
    void exe();
};

//class Gen_Poblacion

template <typename T>
class Gen_Poblacion{
private:
    std::vector<T> array;
    int num_ind;
public:
    Gen_Poblacion(std::vector<T> &,int);
    int get_num();
    std::vector<Individual<T>> Generar();
};

//Class Genetic algorithm

template <typename T>
class Genetic{
private:
    std::vector<Individual<T>> population;
    std::vector<T> for_sort;
    std::vector<T> target;
    float mutation_chance;
    int num_individuos;
    int cant_cruce;
public:
    Genetic(std::vector<T> &, float, int, int);
    std::vector<Individual<T>> sorted();
    std::vector<Individual<T>> selection();
    std::vector<Individual<T>> reproduction();
    std::vector<Individual<T>> mutation();
    std::vector<T> cruzar(std::vector<T> &, std::vector<T> &, std::vector<T> &);
    int random_pos(int);
    int key_bett();
    bool is_sorted_();
    void print_pop();
    void iniciar();
};
