/*
 * Programa: MAYMIN.c
 * 
 * Comprueba si la entrada del usuario es 'V' (varón) o 'H' (hembra).
 * Normaliza la entrada a mayúsculas con toupper() y muestra un mensaje
 * acorde usando un switch.
 */

#include <stdio.h>
#include <ctype.h>   /* Para toupper() */

int main()
{
    char resp;   /* Carácter introducido por el usuario */
    char c;      /* Variable auxiliar (no usada, se puede omitir) */

    /* Solicitar la respuesta */
    printf("Es un varon o una hembra (V/H)?: ");
    scanf(" %c", &resp);   /* El espacio antes de %c evita leer el '\n' sobrante */

    /*
     * toupper() convierte una letra minúscula a mayúscula.
     * Si resp ya es mayúscula o no es una letra, la deja igual.
     * Se guarda el resultado en la misma variable resp.
     */
    resp = toupper(resp);

    /* 
     * Estructura switch: evalúa el valor de resp y ejecuta el bloque
     * correspondiente al caso que coincida.
     */
    switch (resp)
    {
        case 'V':   /* Si es V (varón) */
            puts("Es un enfermero");
            break;   /* Salir del switch para no ejecutar los siguientes casos */

        case 'H':   /* Si es H (hembra) */
            puts("Es una maestra");
            break;

        default:    /* Cualquier otro carácter */
            puts("No es ni enfermero ni maestra");
            break;
    }

    return 0;   /* El programa terminó correctamente */
}