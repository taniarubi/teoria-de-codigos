#include <stdio.h>

void main() {
    int alto;
    int ancho;
    char c;

    scanf("%d %d\n", &alto, &ancho);
    printf("%d %d\n", alto, ancho);
    for(int i = 0; i < alto; i++) {
        for(int j = 0; j < ancho; j++) {
            c = getchar();
            if(c == '0')
                putchar(' ');
            else
                putchar(219);
        }
        
        c = getchar();
        putchar(c);
        c = getchar();
        putchar(c);
    }
}
