#include "libre.hpp"

template <typename T>
Individual<T>::Individual(std::vector<T> & _array){
    array = _array;
    copy_array = _array;
    std::sort(copy_array.begin(), copy_array.end());
    fit_ = 0;
}

template <typename T>
std::vector<T> Individual<T>::getArray(){
    return array;
}

template <typename T>
bool Individual<T>::operator<(Individual<T> &_a) const {
    return (fit_ < _a.fit_);
}

template <typename T>
int Individual<T>::get_len(){
    return array.size();
}

template <typename T>
void Individual<T>::set_fitness(int _s_fit){
    fit_ = _s_fit;
}

template <typename T>
int Individual<T>::get_fitness(){
    return fit_;
}

template <typename T>
void Individual<T>::fitness(){
    suffle();
    int fit = 0;
    for (int i = 0; i < get_len(); ++i){
        if(array[i] == copy_array[i])
            ++fit;
    }
    set_fitness(fit);
}

template <typename T>
void Individual<T>::suffle(){
    int tmp, rand_idx;
    for (int i = 0; i < get_len(); ++i){
        tmp = array[i];
        rand_idx = rand() % get_len();

        array[i] = array[rand_idx];
        array[rand_idx] = tmp;
    }
}

template <typename T>
void Individual<T>::print(){
    for (auto i : array)
        std::cout << i << " ";
    std::cout << "fit:" << get_fitness();
    std::cout << "\n";
}

template <typename T>
void Individual<T>::exe(){
    suffle();
    fitness();
}

//Class Gen_Poblacion Implementation

template <typename T>
Gen_Poblacion<T>::Gen_Poblacion(std::vector<T> &_pas, int _t){
    array = _pas;
    num_ind = _t;
}

template <typename T>
int Gen_Poblacion<T>::get_num(){
    return num_ind;
}

template <typename T>
std::vector<Individual<T>> Gen_Poblacion<T>::Generar(){
    std::vector< Individual<T> > new_pobl;
    for (int i = 0; i < get_num(); ++i){
        Individual<T> a = Individual<T>(array);
        a.exe();
        new_pobl.push_back(a);
    }
    return new_pobl;
}

//genetic implementation 

template <typename T>
Genetic<T>::Genetic(std::vector<T> &_arr,float mt_ch, int nm_ind, int ct_cr){
    for_sort = _arr;
    target = _arr;
    num_individuos = nm_ind;
    std::sort(target.begin(), target.end());
    Gen_Poblacion<int> p = Gen_Poblacion<int>(for_sort,num_individuos);
    population = p.Generar();
    cant_cruce = ct_cr;
}

template <typename T>
std::vector<Individual<T>> Genetic<T>::selection(){
    std::vector<T> lis_f;
    for (int i = 0; i < population.size(); ++i)
        lis_f.push_back(population[i].get_fitness());

    return population;
}

template <typename T>
std::vector<Individual<T>> Genetic<T>::sorted(){
    puts("Sorting");
    std::sort(population.begin(), population.end());
    return population;
}

template <typename T>
std::vector<Individual<T>> Genetic<T>::reproduction(){
    puts("Reproduciendo");
    
}

template <typename T>
std::vector<Individual<T>> Genetic<T>::mutation(){
  //falta :'v
}

template <typename T>
bool Genetic<T>::is_sorted_(){
  //falta :'v
}

template <typename T>
void Genetic<T>::print_pop(){
    for (int i = 0; i < population.size(); ++i)
        population[i].print();
    std::cout << "\n";
}

template <typename T>
void Genetic<T>::iniciar(){
    print_pop();
    selection();
    sorted();
    print_pop();
}

//Functions random 

template <typename T>
void printvec(std::vector<T> & _a){
    for (auto i : _a)
        std::cout << i << " ";
    std::cout << "\t";
}




