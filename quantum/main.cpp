#include <bits/stdc++.h>
#include "Genetic.h"

int main(int argc, char **argv)
{
    //Algorithm
    srand(static_cast<unsigned int>(time(nullptr)));
    Genetic a(20,10,10,100);
    a.exe();

    //free memory
    a.~Genetic();
    return EXIT_SUCCESS;

    /* INFORME 
     * - Debemos mejorar la función fitness
     * - Repair debe ser implementada
     * - Debemos asegurarnos que los datos se  seten correctamente en cada epoca
     * - Establecer la estrucutra de acuerdo al paper
     * - Generar y mostrar las mejores soluciones de acuerdo a la epoca y evolución
     * - Este paper no trae mutación quizá no es necesaria
     * - Plotear resultados de cada epoca para la presentación final (ideal: lunes ´todo´)
     */
}
