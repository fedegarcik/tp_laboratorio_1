#include <stdio.h>
#include <stdlib.h>

int main()
{
    char prueba = '0';
    if(!isdigit(prueba) && prueba != '0')
    {
        printf("entro");
    }
    else
    {
        printf("No entro");
    }

    return 0;
}
