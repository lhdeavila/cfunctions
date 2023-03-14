#include <string.h>
#include <stdio.h>
#include <stdlib.h>
/* Aplicacion vulnerable */
void func(char *arg)
{
    char nombre[32];
    strcpy(nombre, arg);
    printf("\nHola, %s\n\n", nombre);
}
int main(int argc, char *argv[])
{
    if ( argc != 2 ) {
        printf("Uso: %s NOMBRE\n", argv[0]);
        exit(0);
    }
    func(argv[1]);
    printf("Fin del programa\n\n");
    return 0;
}