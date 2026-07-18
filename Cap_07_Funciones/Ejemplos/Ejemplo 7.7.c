#include <stdio.h>   
#include <stdlib.h>  

int main(void)
{
    int i;  // Contador del bucle

    for (i = 1; i <= 10; i++)
    {
        printf(" %d ", rand()); 
    }

    return 0;
}
