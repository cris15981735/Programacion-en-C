/**
 * ============================================================================
 *  PROGRAMA: Genera 10 números aleatorios (0-999) y muestra el mayor de ellos.
 * ============================================================================
 */

/* ==========================  CABECERAS (bibliotecas) ========================= */

#include <stdio.h>   // Necesaria para printf()
#include <stdlib.h>  // Necesaria para rand() y srand()
#include <time.h>    // Necesaria para time() (usada en la semilla)


/* ==========================  DEFINICIONES DE MACROS ========================= */

/**
 * Macro: randomize
 * Propósito: Inicializa la semilla del generador de números aleatorios
 *            usando la hora actual. Se usa como una instrucción.
 * Equivale a: srand(time(NULL))
 */
#define randomize srand(time(NULL))

/**
 * Macro: random(num)
 * Propósito: Genera un número aleatorio entre 0 y (num-1).
 * Uso: random(100) devuelve un entero entre 0 y 99.
 * Equivale a: rand() % (num)
 */
#define random(num) (rand() % (num))

/**
 * Macro: MAX(x, y)
 * Propósito: Devuelve el valor mayor entre x e y.
 * Uso: MAX(5, 3) devuelve 5.
 * Equivale a: (x) > (y) ? (x) : (y)
 */
#define MAX(x, y) ((x) > (y) ? (x) : (y))

/**
 * Macro: TOPE
 * Propósito: Define el límite superior para los números aleatorios.
 *            Como se usa en random(TOPE), los números estarán entre 0 y (TOPE-1).
 *            En este caso TOPE=1000, así que los números serán de 0 a 999.
 */
#define TOPE 1000

/* ==========================  FUNCIÓN PRINCIPAL ============================== */

int main(void)  
{
    // Declaración de variables locales
    int mx;       // Almacenará el valor máximo encontrado hasta el momento
    int i;        // Contador para el bucle for

    /**
     * Paso 1: Inicializar la semilla aleatoria.
     * La macro randomize se expande a srand(time(NULL)).
     * Esto asegura que cada ejecución genere secuencias diferentes.
     */
    randomize;

    /**
     * Paso 2: Generar el primer número aleatorio y asignarlo a mx.
     * random(TOPE) se expande a (rand() % 1000), lo que da un valor entre 0 y 999.
     * Este será nuestro valor máximo inicial.
     */
    mx = random(TOPE);   // Ejemplo: mx = 347

    /**
     * Paso 3: Bucle for para generar los 9 números restantes (del 2 al 10 inclusive).
     * i empieza en 2 y termina en 10, total: 9 iteraciones.
     * En cada iteración:
     *   - Se genera un nuevo número aleatorio y se guarda en 'y'
     *   - Se actualiza mx con el mayor entre mx e y usando la macro MAX.
     */
    for (i = 2; i <= 10; i++)
    {
        int y;                 // Declaración local dentro del bucle (válida solo aquí)
        y = random(TOPE);      // Genera otro número aleatorio (0-999)
        mx = MAX(mx, y);       // mx = (mx > y) ? mx : y; (se queda con el mayor)
    }

    /**
     * Paso 4: Mostrar el resultado final.
     * Se imprime el mayor de los 10 números aleatorios generados.
     */
    printf("El mayor numero aleatorio generado: %d", mx);

    printf("\n");

    return 0;
}