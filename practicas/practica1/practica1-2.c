#include <stdio.h>

void main() {
    int alto;
    int ancho;
    int i, j;
    int paridad;
    int imagen[101][101];
    int c;
    int error = 0;
    int errorx = 0; 
    int errory = 0;
    int checksum = 0;

    scanf("%d %d\n", &alto, &ancho);
    /* Leemos y analizamos por filas. */
    for(i = 0; i <= alto; i++) {
        paridad = 0;
        for(j = 0; j <= ancho; j++) {
            imagen[i][j] = getchar();
            if(imagen[i][j] == '1') {
                paridad++;
                checksum++;
            }
        }

        getchar(); 
        if(paridad % 2) {
            if(error > 1) {
                printf("Se detectaron dos o más errores.");
                return; 
            } else {
                error = 1;
                errorx = i;
            } 
        } 
    }

    /* Analizamos por columnas. */
    for(j = 0; j <= ancho; j++) {
        paridad = 0;
        for(i = 0; i <= alto; i++) {
            if(imagen[i][j] =='1') {
                paridad++;
                checksum++;
            }
        }

        if(paridad % 2) {
            if(error > 1) {
                printf("Se detectaron dos o más errores.");
                return; 
            } else {
                error = 1;
                errory = j;
            }
        }
    }

    if(error) {
        printf("Se ha encontrado un error en las coordenadas (%d, %d)\n", 
               errorx, errory);
        
        /* Imprimimos. */
        for(i = 0; i < alto; i++) {
            for(j = 0; j < ancho; j++) {
                if(i == errorx && j == errory) {
                    if(imagen[i][j] == '0')
                        imagen[i][j] = '1';
                    else
                        imagen[i][j] = '0';
                }

                if(imagen[i][j] == '0')
                    putchar(' ');
            else
                putchar(219);
        }

        putchar('\n');
     }
    } else {
        /* Imprimimos. */
        for(i = 0; i < alto; i++) {
            for(j = 0; j < ancho; j++) {
                if(imagen[i][j] == '0')
                    putchar(' ');
                else
                    putchar(219);
            }

        putchar('\n');
        }
    }
}
