#include <stdio.h>

/*!
 * Definimos el tipo de dato Polinomio. Un polinomio a^0+a^1+...+a^n es un  
 * arreglo conformado por términos o monomios, donde cada entrada del 
 * arreglo representa el coeficiente ai y cuya longitud del arreglo es el
 * grado del polinomio.
 */
typedef struct {
    /* El grado del polinimio. */
    int grado;
    /* Los coeficientes del polinimio. */
    int coeficiente[50];
} Polinomio;

/*!
 *  Lee un polinomio desde la terminal. 
 *  @return el polinomio que fue leído desde la terminal.
 */
Polinomio lee_polinomio() {
    Polinomio polinomio;
    Polinomio final;
    int grd;
    int coef;

    printf("Ingrese el grado del polinomio: ");
    scanf("%d", &grd);
    polinomio.grado = grd;
    for(int i = 0; i <= grd; i++) {
        printf("Coeficiente de la %d-esima potencia: ", i);
        scanf("%d", &coef);
        polinomio.coeficiente[i] = coef;
    }

    while(polinomio.coeficiente[polinomio.grado] == 0)
        polinomio.grado--;
    return polinomio;
}

/*!
 * Dado un polinomio, lo imprime en la terminal.
 * @param polinomio el polinomio a imprimir.
 * @return el polinomio en la terminal.
 */ 
void imprime_polinomio(Polinomio polinomio) {
    for(int i = 0; i <= polinomio.grado; i++) {
        if(polinomio.coeficiente[i] == 0)
            printf("");
        else  { 
            printf("%dx^{%d} ", polinomio.coeficiente[i], i);
            if(i != polinomio.grado) 
            printf("+ ");
        }
    }
}

/*!
 *  Dado un polinomio, regresa su evaluación respecto a un número entero.
 *  @param polinomio el polinomio al cual vamos a evaluar. 
 *  @param x el entero con el cual vamos a evaluar el polinomio.
 *  @return la evaluación del polinomio con respecto a un número entero.
 */
int evalua_polinomio(Polinomio polinomio, int x) {
    int evaluacion = 0;

    for(int i = 0; i <= polinomio.grado; i++)
        evaluacion = (x * evaluacion) + polinomio.coeficiente[i];
    return evaluacion;
}

/*!
 * Dados dos polinomios, regresa el resultado de la suma entre ellos.
 * @param polinomio1 el primer polinomio para sumar.
 * @param polinomio2 el segundo polinomio para sumar.
 * @return el resultado de la suma entre los dos polinomios.
 */
Polinomio suma_polinomios(Polinomio polinomio1, Polinomio polinomio2) {
    Polinomio resultante;

    if(polinomio1.grado > polinomio2.grado) 
        resultante.grado = polinomio1.grado;
    else 
        resultante.grado = polinomio2.grado;

    for(int i = 0; i <= resultante.grado; i++)
        resultante.coeficiente[i] = 0;
    
    for(int i = 0; i <= polinomio1.grado; i++) 
        resultante.coeficiente[i] += polinomio1.coeficiente[i];

    for(int i = 0; i <= polinomio2.grado; i++)
        resultante.coeficiente[i] += polinomio2.coeficiente[i];

    while(resultante.coeficiente[resultante.grado] == 0)
        resultante.grado--;
    return resultante;
}

/**
 * Dado un polinomio, multiplica cada uno de sus coeficientes por el entero n.
 * @param polinomio el polinomio a multiplicar.
 * @param n el entero por el cual vamos a multiplicar el polinomio.
 * @return el polinomio cuyos coeficientes son multiplicados por n.
 */
Polinomio multiplica_entero(Polinomio polinomio, int n) {
    Polinomio resultante;
    resultante.grado = polinomio.grado;

    for(int i = 0; i <= resultante.grado; i++)
        resultante.coeficiente[i] = 0;

    for(int i = 0; i <= polinomio.grado; i++)
        resultante.coeficiente[i] = n * polinomio.coeficiente[i];

    while(resultante.coeficiente[resultante.grado] == 0)
       resultante.grado--;
    return resultante;
}

/**
 * Dados dos polinomios, regresa el resultado de restar el primer polinomio con 
 * el segundo polinomio.
 * @param polinomio1 el primer polinomio para restar.
 * @param polinomio2 el segundo polinomio para restar.
 * @return el resultado de la resta entre los dos polinomios.
 */
Polinomio resta_polinomios(Polinomio polinomio1, Polinomio polinomio2) {
    Polinomio resultante;
    Polinomio invertido;

    invertido = multiplica_entero(polinomio2, -1);
    resultante = suma_polinomios(polinomio1, invertido);
    return resultante;
}

/**
 * Dados dos polinomios, regresa el resultado de multiplicar ambos polinomios.
 * @param polinomio1 el primer polinomio para multiplicar.
 * @param polinomio2 el segundo polinomio para multiplicar.
 * @return el resultado de multiplicar ambos polinomios.
 */
Polinomio multiplica_polinomios(Polinomio polinomio1, Polinomio polinomio2) {
    Polinomio resultante;
    resultante.grado = polinomio1.grado + polinomio2.grado;

    for(int i = 0; i <= resultante.grado; i++)
        resultante.coeficiente[i] = 0; 
    
    for(int i = 0; i <= polinomio1.grado; i++) {
        for(int j = 0; j <= polinomio2.grado; j++) {
            resultante.coeficiente[i+j] += 
                polinomio1.coeficiente[i] * polinomio2.coeficiente[j]; 
        }
    }

    return resultante;
} 

/**
 * Dados dos polinomios, regresa el cociente de dividir el primer polinomio
 * entre el segundo.
 * @param polinomio1 el polinomio correspondiente al dividendo.
 * @param polinomio2 el polinomio correspondiente al divisor.
 * @return el cociente de dividir el primer polinomio entre el segundo.
 */
Polinomio divide_polinomios(Polinomio polinomio1, Polinomio polinomio2) {
    Polinomio resultante;
    Polinomio residuo;
    Polinomio aux;

    if(polinomio2.grado == 0)
        printf("No se puede dividir entre cero.");

    if(polinomio1.grado < polinomio2.grado)
        return polinomio1;

    resultante.grado = polinomio1.grado - polinomio2.grado;
    for(int i = 0; i <= resultante.grado; i++)
        resultante.coeficiente[i] = 0;

    residuo.grado = polinomio1.grado;
    for(int i = 0; i <= residuo.grado; i++)
        residuo.coeficiente[i] = polinomio1.coeficiente[i];

    for(int i = resultante.grado; i >= 0; i--) {
        resultante.coeficiente[i] = 
            residuo.coeficiente[polinomio2.grado + i] / 
            polinomio2.coeficiente[polinomio2.grado];
        aux = multiplica_polinomios(resultante, polinomio2);
        residuo = resta_polinomios(polinomio1, aux);
    }

    return resultante;
}

/*!
 * Dados dos polinomios, regresa el residuo tras dividir el primer polinomio 
 * entre el segundo.
 * @param polinomio1 el polinomio correspondiente al dividendo.
 * @param polinomio2 el polinomio correspondiente al divisor.
 * @return el residuo tras dividir el primer polinomio entre el segundo.
 */
Polinomio modulo_polinomios(Polinomio polinomio1, Polinomio polinomio2) {
    Polinomio resultante;
    Polinomio residuo;
    Polinomio aux;

    if(polinomio2.grado == 0)
        printf("No se puede dividir entre cero.");

    if(polinomio1.grado < polinomio2.grado)
        return polinomio1;

    resultante.grado = polinomio1.grado - polinomio2.grado;
    for(int i = 0; i <= resultante.grado; i++)
        resultante.coeficiente[i] = 0;

    residuo.grado = polinomio1.grado;
    for(int i = 0; i <= residuo.grado; i++)
        residuo.coeficiente[i] = polinomio1.coeficiente[i];

    for(int i = resultante.grado; i >= 0; i--) {
        resultante.coeficiente[i] = 
            residuo.coeficiente[polinomio2.grado + i] / 
            polinomio2.coeficiente[polinomio2.grado];
        aux = multiplica_polinomios(resultante, polinomio2);
        residuo = resta_polinomios(polinomio1, aux);
    }

    return residuo;
}
