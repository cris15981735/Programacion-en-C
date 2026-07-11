/*
 * PROGRAMA: Búsqueda del máximo en una lista variable de argumentos
 * 
 * Este programa muestra cómo implementar y usar una función que recibe
 * un número indeterminado de parámetros (en este caso, valores double).
 * La función maximo recorre todos los valores y encuentra el mayor.
 * 
 * Se utilizan las macros definidas en <stdarg.h> para manejar la lista
 * de argumentos: va_list, va_start, va_arg y va_end.
 */

#include <stdio.h>   // Para printf, puts
#include <stdarg.h>  // Para va_list, va_start, va_arg, va_end

// Prototipo de la función: indica que recibe un entero (fijo) y luego
// una lista variable de argumentos representada por "..."
void maximo(int n, ...);

/*
 * Función maximo
 * 
 * Parámetros:
 *   n     : Cantidad de números double que se pasarán a continuación
 *   ...   : lista variable de exactamente n argumentos de tipo double
 *
 * Encuentra el valor máximo entre esos n números e imprime el resultado.
 */
void maximo(int n, ...)
{
    double mx;         // Almacenará el valor máximo encontrado
    double actual;     // Almacenará el argumento recién leído
    va_list puntero;   // Puntero especial que recorrerá la lista de argumentos
    int i;             // Contador del bucle

    /*
     * va_start: inicializa el puntero para que apunte al primer argumento
     * variable, justo después del último parámetro fijo (n).
     * 
     * Parámetros:
     *   puntero : variable de tipo va_list que será inicializada.
     *   n       : último parámetro fijo de la función (sirve de referencia
     *             para saber dónde empieza la lista variable).
     */
    va_start(puntero, n);

    /*
     * Leemos el primer número de la lista con va_arg.
     * Lo asignamos tanto a 'actual' (para imprimirlo) como a 'mx'
     * (para que sea el máximo inicial, ya que es el único conocido).
     * 
     * va_arg: obtiene el siguiente argumento de la lista y avanza el puntero.
     * Se le debe indicar el tipo esperado (double) para que pueda leer
     * la cantidad correcta de bytes de la pila.
     */
    mx = actual = va_arg(puntero, double);

    // Mostramos el primer argumento por pantalla
    printf("\t\tArgumento actual: %.2lf\n", actual);

    /*
     * Bucle para leer los argumentos restantes.
     * Empezamos en i = 2 porque ya leímos el primero.
     * Continuamos mientras i <= n, es decir, leemos exactamente n argumentos.
     */
    for (i = 2; i <= n; i++)
    {
        // Obtenemos el siguiente argumento double
        actual = va_arg(puntero, double);

        // Imprimimos el valor recién leído
        printf("\t\tArgumento actual: %.2lf\n", actual);

        // Si el nuevo valor es mayor que el máximo hasta ahora,
        // actualizamos mx.
        if (actual > mx)
        {
            mx = actual;
        }
    }

    /*
     * Terminado el bucle, mx contiene el máximo de los n números.
     * Lo mostramos con un mensaje final.
     */
    printf("\t\tMaximo de la lista de %d numeros es %.2lf\n", n, mx);

    /*
     * va_end: finaliza el uso del puntero. Realiza tareas de limpieza
     * dependientes del sistema. Es obligatorio llamarlo si se ha usado
     * va_start, para mantener la portabilidad y evitar comportamientos
     * indefinidos en posteriores llamadas.
     */
    va_end(puntero);
}

/*
 * Función principal: prueba la función maximo con dos ejemplos.
 */
int main(void)
{
    // Primer ejemplo: máximo entre 6 números double
    puts("\t\tPRIMERA BUSQUEDA DEL MAXIMO\n");
    maximo(6, 3.0, 4.0, -12.5, 1.2, 4.5, 6.4);

    // Segundo ejemplo: máximo entre 4 números double
    puts("\n\t\tNUEVA BUSQUEDA DEL MAXIMO\n");
    maximo(4, 5.4, 17.8, 5.9, -17.99);

    // Fin del programa sin errores
    return 0;
}