// ============================================================
//  PROGRAMA: DEMOSTRACIÓN DE FUNCIONES MATEMÁTICAS (math.h)
// ============================================================

#include <stdio.h>   // Para printf()
#include <math.h>    // Para ceil, floor, fmod, frexp, modf, etc.

int main()           // Función principal. No recibe argumentos.
{
    // Declaración de variables
    int exponente;   // Almacenará el exponente devuelto por frexp()
    double d, y;     // d: mantisa o parte fraccionaria, y: parte entera para modf()

    // ----------------------------------------------------------
    // 1. FUNCIÓN ceil() : redondea al entero superior más cercano
    // ----------------------------------------------------------
    // ceil(3.7) -> 4.0, ceil(3.4) -> 4.0
    // ceil(-3.7) -> -3.0  (porque -3 es mayor que -3.7)
    // ceil(-3.4) -> -3.0
    printf("\n ceil(3.7) = %.1f \t\t  ceil(3.4) = %.1f ", ceil(3.7), ceil(3.4));
    printf("\n ceil(-3.7) = %.1f \t\t  ceil(-3.4) = %.1f ", ceil(-3.7), ceil(-3.4));

    // ----------------------------------------------------------
    // 2. FUNCIÓN floor() : redondea al entero inferior más cercano
    // ----------------------------------------------------------
    // floor(3.7) -> 3.0, floor(3.4) -> 3.0
    // floor(-3.7) -> -4.0 (porque -4 es menor que -3.7)
    // floor(-3.4) -> -4.0
    printf("\n floor(3.7) = %.1f \t\t  floor(3.4) = %.1f ", floor(3.7), floor(3.4));
    printf("\n floor(-3.7) = %.1f \t\t  floor(-3.4) = %.1f ", floor(-3.7), floor(-3.4));

    // ----------------------------------------------------------
    // 3. FUNCIÓN fmod() : resto de la división (módulo) en punto flotante
    // ----------------------------------------------------------
    // fmod(5.6, 2.5) = 5.6 - 2*2.5 = 0.6
    // fmod(-5.6, 2.5) = -0.6 (el signo sigue al dividendo)
    printf("\n fmod(5.6,2.5) = %.1f \t\t  fmod(-5.6,2.5) = %.1f ", fmod(5.6, 2.5), fmod(-5.6, 2.5));
    
    // ----------------------------------------------------------
    // 4. FUNCIÓN frexp() : descompone un número en mantisa y exponente (base 2)
    // ----------------------------------------------------------
    // frexp(16.0, &exponente) devuelve la mantisa m tal que 16.0 = m * 2^exponente
    // Para 16.0: m = 0.5 y exponente = 5 (0.5 * 2^5 = 0.5*32 = 16)
    d = frexp(16.0, &exponente);   // d recibe la mantisa, exponente se actualiza
    printf("\n Mantisa de 16.0, m = %.1f \t\t  exponente = %d ", d, exponente);

    // ----------------------------------------------------------
    // 5. FUNCIÓN modf() : separa la parte fraccionaria y la entera
    // ----------------------------------------------------------
    // modf(-17.365, &y) devuelve la parte fraccionaria (con signo) y guarda la parte entera en y
    // Para -17.365: parte fraccionaria = -0.365, parte entera = -17.0
    d = modf(-17.365, &y);         // d = parte fraccionaria, y = parte entera
    printf("\n Parte fraccionaria de -17.365 = %.1f ", d);   // Muestra -0.4 (redondeo a 1 decimal)
    printf("\n Parte entera de -17.365 = %.1f ", y);         // Muestra -17.0

    return 0;   // Indica que el programa terminó correctamente
}