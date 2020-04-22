#include <stdio.h>
#include "polinomio.h"

void main() {
    Polinomio pol1;
    Polinomio i;

    pol1 = lee();
    imprime(pol1);
    printf("\n");

    printf("Función inserta \n");
    i = inserta(pol1);
    imprime(i);
    printf("\n");
}