#include <stdio.h>

void main() {
    int alto;
    int ancho;
    int i, j;
    int paridad;
    int imagen[101][101];
    int c;

    scanf("%d %d\n", &alto, &ancho);
    printf("%d %d\n", alto, ancho);
    /* Leemos y analizamos por filas. */
    for(i = 0; i < alto; i++) {
        paridad = 0;
        for(j = 0; j < ancho; j++) {
            imagen[i][j] = getchar();
            if(imagen[i][j] == '1')
                paridad++;
        }

        getchar(); 
        getchar();
        if(paridad % 2)
            imagen[i][j] = '1';
        else
            imagen[i][j] = '0';
    }

    /* Analizamos por columnas. */
    for(j = 0; j <= ancho; j++) {
        paridad = 0;
        for(i = 0; i < alto; i++) {
            if(imagen[i][j] =='1')
                paridad++;
        }

        if(paridad % 2) 
            imagen[i][j] = '1';
        else
            imagen[i][j] = '0';
    }

    /* Imprimimos. */
    for(i = 0; i <= alto; i++) {
        for(j = 0;j <= ancho; j++) 
            putchar(imagen[i][j]);
        putchar('\n');
    }
}
