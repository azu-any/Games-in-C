#include <stdio.h>

#define N 15

char letra();
int correcto(char letra, char palabra[N], char oculta[N]);
int ganador(char palabra[N], char oculta[N]);
int repetida(char letra, int longitud, char usada[longitud]);

//Función principal
int main(void) 
{

    char palabra[N] = "tacos de asada", oculta[N] = "_____ __ _____";
    int vidas = 5, longitud = 2;
    char usada[longitud];

    printf("¡Comienza el juego!\n");
    printf("%s\n\n", oculta);

    while(vidas > 0)
    {
        char caracter = letra();
        
        if(repetida(caracter, longitud, usada) == 1)
        {
            vidas -= correcto(caracter, palabra, oculta);
            printf("Vidas: %d\n\n", vidas);

            //Agregar la letra al arreglo
            longitud++;
            usada[longitud-2] = caracter;
        }
        else
        {
            printf("Ya utilizaste %c\n\n", caracter);
        }

        if(ganador(palabra, oculta) == 1)
        {
            printf("Felcidades, ganaste\n");
            break;
        }
        
        if(vidas == 0)
        {
            printf("Lo siento, perdiste\n");
        }
    }
        
    return 0;
}

//Pedir al usuario una letra
char letra()
{
    char caracter;
    
    printf("Inserte letra:\n");
    scanf(" %c", &caracter);
    printf("\n");

    return caracter;
}

//Verificar si la letra es correcta
int correcto(char letra, char palabra[N], char oculta[N])
{
    int cont = 0;
    
    for(int i=0; i<N; i++)
    {
        if(letra == palabra[i])
        {
            oculta[i] = palabra[i];
            cont = 1;
        }
    }

    printf("%s\n\n", oculta);

    if(cont == 1)
    {
        printf("¡Acertaste!\n");
        return 0;
    }
    else
    {
        printf("¡Ups! Intenta de nuevo\n");
        return 1;
    }
}

//Verificar si ganó
int ganador(char palabra[N], char oculta[N])
{
    int cont = 0;
    
    for(int i=0; i<N; i++)
    {
        if(oculta[i] == palabra[i])
        {
            cont++;
        }
    }

    if(cont == N)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//Verificar si la letra ya se ingresó
int repetida(char letra, int longitud, char usada[longitud])
{
    for(int i=0; i<longitud; i++)
    {
        if(letra == usada[i])
        {
            return 0;
        }
    }

    return 1;
}
