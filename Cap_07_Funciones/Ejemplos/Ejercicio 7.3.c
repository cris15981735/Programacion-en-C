/*
 * Programa: Secuencia de Fibonacci usando variables estáticas.
 *
 * Pide al usuario cuántos números de la secuencia desea ver,
 * imprime los dos primeros (0, 1) y luego genera los siguientes
 * mediante una función que mantiene el estado con variables static.
 */

#include <stdio.h>

/* Prototipo de la función que devuelve el siguiente número de Fibonacci */
long int fibonacci(void);

int main()
{
    int n, i;

    /* Solicitar la cantidad de números */
    printf("\nCuantos numeros de fibonacci ?: ");
    scanf("%d", &n);

    /* Imprimir los dos primeros números fijos de la secuencia */
    printf("\nSecuencia de fibonacci: 0, 1");

    /*
     * Bucle para generar e imprimir los números restantes.
     * Comienza en i = 2 porque ya se han impreso los índices 0 y 1.
     * La función fibonacci() devuelve el siguiente número, comenzando
     * por el tercero (índice 2) que es 1.
     */
    for (i = 2; i < n; i++)
    {
        printf(", %ld", fibonacci());
    }

    printf("\n");  // Salto de línea final
    return 0;
}

/*
 * Función fibonacci:
 *   Calcula el siguiente número de la secuencia de Fibonacci.
 *
 * Utiliza variables estáticas 'x' y 'y' para recordar el estado
 * entre llamadas sucesivas. Inicialmente x=0, y=1.
 *
 * Algoritmo:
 *   nuevo_y = y + x
 *   nuevo_x = y anterior
 *   (se intercambian los papeles para la próxima llamada)
 *
 * La primera llamada devuelve 1 (tercer número),
 * la segunda 2, la tercera 3, la cuarta 5, etc.
 */
long int fibonacci(void)
{
    static int x = 0;  /* Valor F(n-2) */
    static int y = 1;  /* Valor F(n-1) */

    /*
     * Actualización:
     *   y = y + x   (nuevo número de Fibonacci)
     *   x = y - x   (recupera el valor anterior de y)
     *
     * Ejemplo inicial (x=0, y=1):
     *   y = 1+0 = 1
     *   x = 1-0 = 1   -> ahora x=1 (antiguo y), y=1 (F(2))
     * Siguiente llamada:
     *   y = 1+1 = 2
     *   x = 2-1 = 1   -> x=1, y=2 (F(3))
     * Y así sucesivamente.
     */
    y = y + x;
    x = y - x;

    return y;
}