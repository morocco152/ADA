#ifndef _LIB_H_
#define _LIB_H_
#include <bits/stdc++.h>

int* Crea_matrix(int V){ // devuelvo un * a arreglo y recivo el tamaño
	int *new_ma = new int[V];//creo matriz con tamaño V
	srand((unsigned) time(0));//genear random real
	for(int i=0 ; i<V ; ++i)//recorrer
		new_ma[i] = (rand() % V)*(2*(rand() % 2) - 1);//lleno la matriz
	return new_ma;//retorno el arreglo dinamico
}

void printMatrix(int* M, int V) {//print arreglo a puntero
	for (int i = 0; i < V; ++i)
		std::cout << M[i] << "\t";//itero
	std::cout << std::endl;
}

void print_vec(std::vector<double> t){//print vectores 
    for(auto i : t)//iterador
        std::cout << i << "\t";//imprime
    std::cout << "\n";
}
//from geeksforgeeks
double tes_ins_sort(int M[], int V){//recibe el arreglo por valor y tamaño
    unsigned t0, t1;//declaro los tiempos inicial y final
    t0=clock();//inicio el contador
    int i, key, j;
    for( i=1; i<V; ++i){ //pa recorer todo el arreglo, pero empezamos en 1 para poder comparar con el anterior n-1 = 0
        key = M[i];//comparamos
        j = i-1;//la n posicion con n-1
        while (j >= 0 && M[j] > key){//si pos[0] >= 0 (existe) y el elemento pos[j] sea mayor que la llave
            M[j+1] = M[j];//movemos la posicion si se sigue cumpliento
            j = j-1;
        }
        M[j+1] = key;//pasamos al siguiente y se vuelve la nueva llave
    }   //hasta que se ordene
    t1=clock();//detenemos el tiempo
    double time = 1000L*(double(t1-t0)/CLOCKS_PER_SEC);//sacaos la diferencia y la convertimos a milisegundos
    return time;//retornamos el tiempo
}
//from geekforgeeks
double tes_bur_sort(int M[], int V){//recibe el arreglo por valor y tamaño
    unsigned t0, t1;//declaro los tiempos inicial y final
    t0=clock();//inicio el contador
	for(int i=0; i<V; ++i){//recorremos el array
        for(int j=0; j<(V-i-1); ++j){
            if(M[j] > M[j+1]){//comparamos 2 elementos adyacentes
                int temp = M[j];//intercambiamos los elementos
                M[j] = M[j+1];
                M[j+1] = temp;
            }
        }
    }
    t1=clock();//detenemos el tiempo
    double time = 1000L*(double(t1-t0)/CLOCKS_PER_SEC);//sacaos la diferencia y la convertimos a milisegundos
    return time;//retornamos el tiempo
}

#endif

