// Azuany Mila - 177068
// Batalla naval

#include <stdio.h>

#define N 10

void imprimir(char mapa[N][N]);
int posicion_x();
int posicion_y();
int comparar(int eje_x, int eje_y, char barcos[N][N], char mapa[N][N]);

// Programa principal
int main(void) 
{
    char mapa[N][N] = {
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}
    };

    char barcos[N][N] = {
    {'.', '.', 'x', 'x', 'x', 'x', '.', '.', '.', 'x'},
    {'.', 'x', '.', '.', '.', '.', '.', '.', '.', 'x'},
    {'.', 'x', '.', '.', 'x', '.', '.', '.', '.', 'x'},
    {'.', 'x', '.', '.', 'x', '.', 'x', 'x', 'x', '.'},
    {'.', 'x', '.', '.', 'x', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', 'x', '.'},
    {'x', 'x', 'x', 'x', 'x', '.', '.', '.', 'x', '.'},
    {'.', '.', '.', '.', '.', 'x', '.', '.', 'x', '.'},
    {'.', 'x', 'x', 'x', '.', 'x', '.', '.', 'x', '.'},
    {'.', '.', '.', '.', '.', 'x', '.', '.', '.', '.'}
    };
    
    int eje_x, eje_y;
    int i = 0, fallos = 10, cont = 0;

    while (i <= fallos) 
    {
        imprimir(mapa);
        if (comparar(posicion_x(), posicion_y(), barcos, mapa) == 1) 
        {
            printf("¡Acertaste!\n");
            cont++;

            if (cont == 32) 
            {
                printf("¡Ganaste!\n");
                break;
            }
        } 
        else 
        {
            printf("Te queda(n) %d fallo(s)\n", fallos - i - 1);
            i++;
            if (i == fallos) 
            {
                printf("Perdiste :(\n");
                break;
            }
        }
    }

    return 0;
}

// Imprimir el mapa del juego
void imprimir(char mapa[N][N]) 
{
    int i, j, k;

    for (i = 0; i < N + 1; i++) 
    {
        for (j = 0; j < N; j++) 
        {
            if (i == 0) 
            {
                printf("\t");
                for (k = 0; k < N; k++) 
                {
                  printf("%d\t", k);
                }
                break;
            }

            if (j == 0) 
            {
                printf("%d\t", i - 1);
            }
            printf("%c\t", mapa[i - 1][j]);
        }
        printf("\n");
    }
}

// Definir la posición en x de la casilla del jugador
int posicion_x() 
{
    int coordenada_x;

    printf("Inserte posición en el eje x (horizontal):\n");
    scanf("%d", &coordenada_x);

    return coordenada_x;
}

// Definir la posición en y de la casilla del jugador
int posicion_y() 
{
    int coordenada_y;

    printf("Inserte posición en el eje y (vertical):\n");
    scanf("%d", &coordenada_y);

    return coordenada_y;
}

// Checar si la casilla elegida tiene un barco
int comparar(int eje_x, int eje_y, char barcos[N][N], char mapa[N][N]) 
{
    if (eje_x > N - 1 || eje_y > N - 1 || eje_y < 0 || eje_x < 0) 
    {
        printf("Valor(es) no válido(s)\n");
        return 0;
    }
    
    if (mapa[eje_y][eje_x] == '.') 
    {
        if (barcos[eje_y][eje_x] == 'x') 
        {
            mapa[eje_y][eje_x] = 'x';
            return 1;
        } 
        else 
        {
            mapa[eje_y][eje_x] = '-';
            return 0;
        }
    } 
    else     
    {
        printf("Ese valor ya lo ingresaste\n");
        return 0;
    }
}
