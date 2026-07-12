/*
 * Ejercicio 7.2: Cálculo del volumen de un cono mediante una macro con argumentos.
 *
 * El programa pide al usuario el radio y la altura de un cono,
 * calcula su volumen usando la macro VOLCONO y muestra el resultado.
 *
 * Fórmula utilizada: V = (1/3) * π * r² * h
 */

#include <stdio.h>

/* Definición de la constante Pi */
#define Pi 3.141592

/*
 * Macro con argumentos VOLCONO
 *
 * Parámetros:
 *   radio  : radio de la base del cono
 *   altura : altura del cono
 *
 * Expansión:
 *   ((Pi * (radio * radio) * altura) / 3.0)
 *
 * Nota: Es una buena práctica encerrar cada parámetro y la macro completa
 * entre paréntesis para evitar problemas de precedencia cuando se invoca
 * con expresiones más complejas.
 */
#define VOLCONO(radio, altura) ((Pi * (radio * radio) * (altura)) / 3.0)

int main()
{
    float radio, altura, volumen;

    /* Solicitar el radio del cono */
    printf("\nIntroduzca radio del cono: ");
    scanf("%f", &radio);

    /* Solicitar la altura del cono */
    printf("Introduzca altura del cono: ");
    scanf("%f", &altura);

    /*
     * Llamada a la macro VOLCONO.
     * El preprocesador reemplaza VOLCONO(radio, altura) por la expresión
     * ((Pi * (radio * radio) * (altura)) / 3.0), utilizando los valores
     * actuales de las variables radio y altura.
     */
    volumen = VOLCONO(radio, altura);

    /* Mostrar el resultado con dos decimales */
    printf("\nEl volumen del cono es: %.2f\n", volumen);

    return 0;
}