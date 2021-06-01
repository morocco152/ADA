#include <bits/stdc++.h>
#include "libre.hpp"//mi libreia de fx 

//Autor: Luis Angel Moroco Ramos 
//CUI: 20190743

int main(){

    int n,V; // n=cantidad de arreglos y V=tamaño
    double prom_ins_sort{};//promedio insert
    double prom_bub_sort{};//promedio bubble
    //entrada de texto de n y V
    std::cout << "#n:  #tam:"; std::cin >> n >> V;
    std::vector<double> sort_int_t;//para almacenar los tiempos de insert
    std::vector<double> sort_bub_t;//para almacenar los tiempos de bubble

    for(int i=0; i<n; ++i){ //recorrer cada arreglo y evaluarlo
        int *ne_wm = new int[V];//nuevo arreglo 
        ne_wm = Crea_matrix(V);//genero la matriz
        double tm_in = tes_ins_sort(ne_wm,V);//obtengo el tiempo
        double tm_bub = tes_bur_sort(ne_wm,V);//obtengo el tiempo
        sort_int_t.push_back(tm_in);//meto el valor en el array para promediar
        sort_bub_t.push_back(tm_bub);//x2
        prom_ins_sort += tm_in;//sumo para promediar
        prom_bub_sort += tm_bub;//sumo para promediar
        delete[] ne_wm;
    }

    std::cout << "prom_time ins_sort: " << prom_ins_sort/n << "\n";//imprimo el promedio
    std::cout << "prom_time bub_sort: " << prom_bub_sort/n << "\n"; // <<

    std::cout << "array de tiempos insert_sort: " << "\n";
    print_vec(sort_int_t);//imprimo el vector con los tiempos
    std::cout << "\n";
    std::cout << "array de tiempos bubble_sort_sort: " << "\n";
    print_vec(sort_bub_t);//
    
    return EXIT_SUCCESS;//termina
}