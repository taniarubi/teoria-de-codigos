#include <stdio.h>
#include "polinomio.c"

void main() {
    Polinomio polinomio;
    Polinomio polinomio2;
    Polinomio suma;
    Polinomio resta;
    Polinomio mulesc;
    Polinomio multiplica;
    int x;
    int evaluacion;
    int n;

    polinomio = lee_polinomio();
    imprime_polinomio(polinomio);
    polinomio2 = lee_polinomio();
    imprime_polinomio(polinomio2);

    printf("\n Introduce el valor de x para evaluar al polinomio: ");
    scanf("%d", &x);
    evaluacion = evalua_polinomio(polinomio, x);
    printf("\n La evaluación es: %d \n", evaluacion);
    suma = suma_polinomios(polinomio, polinomio2);
    printf("\n La suma de los polinomios es: ");
    imprime_polinomio(suma);
    printf("\n La resta de los polinomios es: ");
    resta = resta_polinomios(polinomio, polinomio2);
    imprime_polinomio(resta);
    printf("El entero para multiplicar al polinomio es: ");
    scanf("%d", &n);
    printf("\n La multiplicación escalar es: ");
    mulesc = multiplica_entero(polinomio, n);
    imprime_polinomio(mulesc);
    printf("\n La multiplicación de ambos polinomios es: ");
    multiplica = multiplica_polinomios(polinomio, polinomio2);
    imprime_polinomio(multiplica);
}
