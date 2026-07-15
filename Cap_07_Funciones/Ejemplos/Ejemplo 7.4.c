/*
 * Programa: Verificar si un carácter es una letra.
 *
 * Solicita al usuario una inicial y, mientras no sea un carácter alfabético,
 * muestra un mensaje de error y pide una nueva inicial.
 * Al finalizar, indica que el proceso ha terminado.
 */

#include <stdio.h>
#include <ctype.h>   /* Para la función isalpha() */

int main()  
{
    char inicial;

    /* Mensaje inicial solicitando el primer carácter */
    printf("Cual es su primer caracter inicial?: ");
    scanf(" %c", &inicial);   /* Espacio antes de %c para ignorar espacios/ saltos de línea previos */

    /*
     * Bucle while: se ejecuta mientras el carácter introducido NO sea alfabético.
     * isalpha() devuelve un valor distinto de cero (verdadero) si el carácter es
     * una letra (A-Z o a-z), y 0 (falso) en caso contrario.
     */
    while (!isalpha(inicial))
    {
        /* Mensaje de error  */
        puts("Caracter no alfabetico");

        /* Solicita una nueva inicial */
        printf("Cual es su siguiente inicial?: ");
        scanf(" %c", &inicial);   /* De nuevo, espacio antes de %c */
    }

    /* Si se sale del bucle, es porque inicial ya es una letra */
    puts("Terminado!");

    return 0;   /* Añadido retorno exitoso */
}