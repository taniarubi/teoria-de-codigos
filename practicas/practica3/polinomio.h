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
Polinomio lee() {
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

    while((polinomio.coeficiente[polinomio.grado] == 0) && (polinomio.grado))
        polinomio.grado--;
    return polinomio;
}

/*!
 * Dado un polinomio, lo imprime en la terminal.
 * @param polinomio el polinomio a imprimir.
 * @return el polinomio en la terminal.
 */ 
void imprime(Polinomio polinomio) {
    if((polinomio.grado == 0) && (polinomio.coeficiente[0] == 0)) {
        printf("0x^{0}");
        return;
    }

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
int evalua(Polinomio polinomio, int x) {
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
Polinomio suma(Polinomio polinomio1, Polinomio polinomio2) {
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
Polinomio multiplica_por_cte(Polinomio polinomio, int n) {
    Polinomio resultante;
    resultante.grado = polinomio.grado;

    for(int i = 0; i <= resultante.grado; i++)
        resultante.coeficiente[i] = 0;

    for(int i = 0; i <= polinomio.grado; i++)
        resultante.coeficiente[i] = n * polinomio.coeficiente[i];

    while((resultante.coeficiente[resultante.grado] == 0) && (polinomio.grado))
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
Polinomio resta(Polinomio polinomio1, Polinomio polinomio2) {
    Polinomio resultante;
    Polinomio negativo;

    negativo = multiplica_por_cte(polinomio2, -1);
    resultante = suma(polinomio1, negativo);
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

    if(((polinomio1.grado == 0) && (polinomio1.coeficiente[0] == 0)) || 
       ((polinomio2.grado == 0) && (polinomio2.coeficiente[0] == 0))) {
        resultante.grado = 0;
        resultante.coeficiente[0] = 0;
        return resultante;
    }

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
Polinomio divide(Polinomio polinomio1, Polinomio polinomio2) {
    Polinomio resultante;
    Polinomio residuo;
    Polinomio aux;
    resultante.grado = 0;
    resultante.coeficiente[0] = 0;

    if((polinomio2.grado == 0) && (polinomio2.coeficiente[0] == 0)) {
        printf("No se puede dividir entre cero.");
        return resultante;
    }

    if((polinomio1.grado < polinomio2.grado) ||
       ((polinomio1.grado == polinomio2.grado) && 
        (polinomio1.coeficiente[polinomio1.grado] < 
         polinomio2.coeficiente[polinomio2.grado])))
            return resultante;

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
        residuo = resta(polinomio1, aux);
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
Polinomio modulo(Polinomio polinomio1, Polinomio polinomio2) {
    Polinomio resultante;
    Polinomio residuo;
    Polinomio aux;
    resultante.grado = 0;
    resultante.coeficiente[0] = 0;

    if((polinomio2.grado == 0) && (polinomio2.coeficiente[0] == 0)) {
        printf("No se puede dividir entre cero.");
        return resultante;
    }

    if((polinomio1.grado < polinomio2.grado) ||
       ((polinomio1.grado == polinomio2.grado) && 
        (polinomio1.coeficiente[polinomio1.grado] < 
         polinomio2.coeficiente[polinomio2.grado])))
            return resultante;

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
        residuo = resta(polinomio1, aux);
    }

    return residuo;
}

/*!
 * Dado un polinomio, calcula el módulo 2 de cada uno de los coeficientes del 
 * polinomio. Con esto, lo que hacemos es "insertar" al polinomio en el 
 * campo finito de dimensión 2.
 * @param polinomio el polinomio al cual le vamos a calcular el módulo 2 
 * a cada uno de sus coeficientes.
 * @return el polinomio al que a cada una de sus entradas le calculamos el 
 * módulo 2.
 */
Polinomio inserta(Polinomio polinomio) {
    for(int i = 0; i <= polinomio.grado; i++)
        polinomio.coeficiente[i] &= 0x1; 
    
    while(polinomio.coeficiente[polinomio.grado] == 0)
        polinomio.grado--;
    return polinomio;
}

/*!
 * Dado un polinomio, nos dice si es irreducible o no en el campo finito de 
 * dimensión 2.
 * @param polinomio el polinomio a verificar.
 */
int es_irreducible(Polinomio polinomio)
