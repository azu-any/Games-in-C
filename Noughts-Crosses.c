#include <stdio.h>

#define N 3

void print(char matriz[N][N]);
int fil();
int columna();
int winner(char matriz[N][N]);

int main()
{
	char matriz[N][N]={{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}; 
    char opc, nombre1[10], nombre2[10];
	int i, j;
	
	printf("Juego del gato!\n");
    print(matriz);
	
	printf("\n\nPresione Y para jugar / N para salir: ");
	scanf("%c", &opc);
	
	if(opc == 'Y' || opc == 'y')
	{
        int fila, col, ganador = 0, turno = 1;
        
		printf("Inserta nombre del jugador 1:\n");
	    scanf("%s", nombre1);
        printf("Inserta nombre del jugador 2:\n");
	    scanf("%s", nombre2);  
        
		do
		{
			if(turno%2==1)
			{
        
				do
				{
					printf("Turno de %s \n", nombre1);
					fila = fil();
                    col = columna();
                    
					if(matriz[fila][col] == 'x' || matriz[fila][col] == 'o' || fila > 2 || col > 2)
					{
						printf("\nCoordenadas no validas, pruebe otra vez.\n");
					}
				}
				while(matriz[fila][col] == 'x' || matriz[fila][col] == 'o' || fila > 2 || col > 2);
				
				matriz[fila][col] = 'x';
				print(matriz);
				turno++;
			} 
			else if(turno%2==0)
			{
				do
				{
          printf("Turno de %s \n", nombre2);
					fila=fil();
          col=columna();
					if(matriz[fila][col] == 'x' || matriz[fila][col] == 'o' || fila > 2 || col > 2)
					{
						printf("\nCoordenadas no validas, pruebe otra vez.\n");
					}
				}
                    
				while(matriz[fila][col] == 'x' || matriz[fila][col] == 'o' || fila > 2 || col > 2);
				
				matriz[fila][col]='o';
				
				print(matriz);
				turno++;
			}
			
		ganador = winner(matriz);
			
		} while(ganador==0);
	} 
  else 
	{
		printf("\nDe todas formas no queria que jugaras.\n");
	}
	
	return 0;
}

void print(char matriz[N][N])
{
    int i, j, k;
   	for(i=0; i<N+1; i++)
	{
		for(j=0; j<N; j++)
		{
		   if(i==0)
            {
                printf("\t");
                for(k=0; k<N; k++)
                {
                    printf("%d\t", k);                
                }
                break;
            }
            
            if(j==0)
            {
                printf("%d\t", i-1);
            }
      
			printf("[%c]\t", matriz[i-1][j]);
		}
	  printf("\n");
	}
}

int fil()
{
    int fila;
    
    printf("Digite fila: ");
	scanf("%d", &fila);	
    
    return fila;
}

int columna()
{
    int columna;
    
    printf("Digite columna: ");
    scanf("%d", &columna);
    
    return columna;
}

int winner(char matriz[3][3])
{
    int ganador = 0;
    
    if(matriz[0][0] == 'x' && matriz[0][0] == matriz[0][1] && matriz[0][0] == matriz[0][2]
    || matriz[1][0] == 'x' && matriz[1][0] == matriz[1][1] && matriz[1][0] == matriz[1][2]
	|| matriz[2][0] == 'x' && matriz[2][0] == matriz[2][1] && matriz[2][0] == matriz[2][2]
	|| matriz[0][0] == 'x' && matriz[0][0] == matriz[1][0] && matriz[0][0] == matriz[2][0]
	|| matriz[0][1] == 'x' && matriz[0][1] == matriz[1][1] && matriz[0][1] == matriz[2][1]
	|| matriz[0][2] == 'x' && matriz[0][2] == matriz[1][2] && matriz[0][2] == matriz[2][2]
	|| matriz[0][0] == 'x' && matriz[0][0] == matriz[1][1] && matriz[0][0] == matriz[2][2]
	|| matriz[0][2] == 'x' && matriz[0][2] == matriz[1][1] && matriz[0][2] == matriz[2][0])
	{
		ganador=1;
		printf("\nFelicidades! Gano el jugador 1.\n");
	}
	else
    {
        if(matriz[0][0] == 'o' && matriz[0][0] == matriz[0][1] && matriz[0][0] == matriz[0][2]
		|| matriz[1][0] == 'o' && matriz[1][0] == matriz[1][1] && matriz[1][0] == matriz[1][2]
    	|| matriz[2][0] == 'o' && matriz[2][0] == matriz[2][1] && matriz[2][0] == matriz[2][2]
		|| matriz[0][0] == 'o' && matriz[0][0] == matriz[1][0] && matriz[0][0] == matriz[2][0]
		|| matriz[0][1] == 'o' && matriz[0][1] == matriz[1][1] && matriz[0][1] == matriz[2][1]
		|| matriz[0][2] == 'o' && matriz[0][2] == matriz[1][2] && matriz[0][2] == matriz[2][2]
		|| matriz[0][0] == 'o' && matriz[0][0] == matriz[1][1] && matriz[0][0] == matriz[2][2]
        || matriz[0][2] == 'o' && matriz[0][2] == matriz[1][1] && matriz[0][2] == matriz[2][0])
        {
			ganador=2;
			printf("\nFelicidades! Gano el jugador 2.\n");
		}
        else
        {
            int cont = 0;
            for(int i=0; i<3; i++)
            {
                for(int j=0; j<3; j++)
                {
                    if(matriz[i][j] != ' ')
                    {
                        cont++;
                    }
                }         
            }

            if(cont == 9)
            {
                ganador=3;
                printf("\nEs un empate.\n");
            }
        }
    }
    
    return ganador;
}
