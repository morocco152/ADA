#include "libre.hpp"

template <typename T>
Individual<T>::Individual(std::vector<T> & _array){
    array = _array;
    copy_array = _array;
    std::sort(copy_array.begin(), copy_array.end());
    fit_ = 0;
    estado.resize(array.size());
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
void Individual<T>::set_array(std::vector<T> & _new_a){
    array = _new_a;
    fitness();
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
void Individual<T>::mutar(int genes){
    int mejora = get_fitness() + genes;
    while (get_fitness() <= mejora){
        l_suffle();
        print();
    }
}

template <typename T>
void Individual<T>::l_suffle(){
    int tmp, rand_idx;
    std::vector<T> per;
    per.resize(array.size() - get_fitness()); 

    int j = 0;
    for (int i = 0; i < get_len(); i++){
        if (estado[i] == false){
            per[j] = array[i];
            j++;
        }
    }
    
    for (int i = 0; i < per.size(); ++i){
        tmp = per[i];
        rand_idx = rand() % per.size();

        per[i] = per[rand_idx];
        per[rand_idx] = tmp;
    }

    j = 0;
    for (int i = 0; i < get_len(); i++){
        if (estado[i] == false){
            array[i] = per[j];
            j++;
        }
    }

    int fit = 0;
    for (int i = 0; i < get_len(); ++i){
        if(array[i] == copy_array[i]){
            ++fit;
            estado[i] = true;
        }
    }
    set_fitness(fit);
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
    std::vector<Individual<T>> better;

    for (int i = key_bett(); i < population.size(); ++i)
        better.push_back(population[i]);

    int bet_t = better.size();

    for (int i = 0; i < population.size(); ++i)
    {
        std::vector<T> padre = better[random_pos(bet_t)].getArray();
        std::vector<T> madre = better[random_pos(bet_t)].getArray();
        std::vector<T> aux = population[i].getArray();
        std::vector<T> _new = cruzar(padre, madre, aux);
        population[i].set_array(_new);
    }
 
    return population;
}

template <typename T>
std::vector<T> Genetic<T>::cruzar(std::vector<T> & _p, std::vector<T> & _m, std::vector<T> & _a){
    int change = random_pos(_p.size());
    for (int i = 0; i < change; ++i)
        _a[i] = _p[i];
    for (int i = change; i < _a.size(); ++i)
        _a[i] = _m[i];
    return _a;
}

template <typename T>
int Genetic<T>::random_pos(int _size){
    int position_rand;
    position_rand = rand() % _size;
    return position_rand;
}

template <typename T>
int Genetic<T>::key_bett(){
    int init = population.size() - cant_cruce;
    return init;
}

template <typename T>
bool Genetic<T>::is_sorted_(){
    return false;
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
    sorted();
    print_pop();
    reproduction();
    print_pop();
    sorted();
    print_pop();
    reproduction();
    sorted();
    print_pop();
    population[population.size()-1].mutar(2);

}

//Functions random 

template <typename T>
void printvec(std::vector<T> & _a){
    for (auto i : _a)
        std::cout << i << " ";
    std::cout << "\t";
}
