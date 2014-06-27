#include <stdio.h>
#include <stdlib.h>

int borrarCoincidencias(char*, char*);

int main()
{
    char cad1[100], cad2[100];
    int coincidencias;

    // La unica forma que encontre de leer lineas completas usando scanf() es usando el delimitador [^\n],
    // que hace que scanf() considere todo lo ingresado hasta que encuentra un salto de linea, en lugar
    // de un espacio, segun San Google. Magia pura. Si no hay un espacio antes del %delimitador el programa hace cosas raras
    // asique es mejor no cuestionar su poder.
    printf("Ingrese las cadenas, en lineas diferentes:\n\n\t");
    scanf(" %[^\n]", cad1);
    printf("\t");
    scanf(" %[^\n]", cad2);

    coincidencias = borrarCoincidencias(cad1, cad2);

    printf("\n\n------------ Hubo %d coincidencias. ------------\n\n", coincidencias);

    printf("\t%s\n", cad1);
    printf("\t%s", cad2);

    printf("\n\n-----------------------------------------------\n\n");
    return 0;
}

int borrarCoincidencias(char *s1, char *s2)
{
    int coincidencias = 0;
    char *aux;

    while(*s1 && *s2)
    {
        if(*s1 == *s2)
        {
            aux = s1;
            while(*aux)
            {
                *aux = *(aux+1);
                aux++;
            }

            aux = s2;
            while(*aux)
            {
                *aux = *(aux+1);
                aux++;
            }

            coincidencias++;
        }
        else
        {
            s1++;
            s2++;
        }
    }

    return coincidencias;
}
