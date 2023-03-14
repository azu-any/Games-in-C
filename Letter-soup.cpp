#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define N 15
#define M 12

void imprimir(char sopa[N][M]);
int posicion_x();
int posicion_y();
int comparar(int eje_x, int eje_y, char sopa[N][M], char res[N][M]);

int main() {

  char sopa[N][M] = {
      {'I', 'H', 'D', 'J', 'A', 'L', 'Z', 'C', 'P', 'U', 'R', 'Z'},
      {'E', 'H', 'C', 'N', 'D', 'K', 'X', 'B', 'Z', 'R', 'Q', 'S'},
      {'S', 'A', 'D', 'H', 'O', 'W', 'M', 'O', 'N', 'Q', 'E', 'F'},
      {'R', 'S', 'A', 'I', 'U', 'H', 'G', 'K', 'F', 'I', 'U', 'P'},
      {'O', 'H', 'D', 'J', 'B', 'L', 'F', 'C', 'P', 'U', 'R', 'A'},
      {'P', 'H', 'D', 'J', 'L', 'L', 'O', 'C', 'P', 'U', 'R', 'B'},
      {'C', 'I', 'N', 'J', 'E', 'L', 'R', 'I', 'C', 'H', 'A', 'R'},
      {'A', 'H', 'D', 'J', 'A', 'L', 'Z', 'T', 'S', 'D', 'P', 'R'},
      {'Z', 'B', 'D', 'S', 'T', 'R', 'I', 'N', 'G', 'U', 'R', 'D'},
      {'Y', 'O', 'D', 'J', 'A', 'L', 'Z', 'C', 'P', 'U', 'C', 'N'},
      {'J', 'O', 'D', 'J', 'W', 'L', 'Z', 'C', 'P', 'U', 'O', 'P'},
      {'L', 'L', 'D', 'J', 'A', 'H', 'Z', 'C', 'P', 'U', 'U', 'O'},
      {'M', 'H', 'D', 'J', 'A', 'L', 'I', 'C', 'P', 'U', 'T', 'S'},
      {'G', 'H', 'D', 'J', 'A', 'L', 'Z', 'L', 'P', 'U', 'R', 'H'},
      {'H', 'S', 'I', 'N', 'T', 'R', 'P', 'Q', 'E', 'G', 'D', 'T'}};

  char res[N][M] = {
      {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', 'x', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', 'x', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', 'x', '.', '.', '.', 'x', 'x', '.', '.'},
      {'.', '.', '.', '.', 'x', '.', 'x', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', 'x', '.', 'x', '.', '.', '.', '.', '.'},
      {'x', 'x', 'x', '.', 'x', '.', 'x', '.', 'x', 'x', 'x', 'x'},
      {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', 'x', '.', 'x', 'x', 'x', 'x', 'x', 'x', '.', '.', '.'},
      {'.', 'x', '.', '.', '.', '.', '.', '.', '.', '.', 'x', '.'},
      {'.', 'x', '.', '.', 'x', '.', '.', '.', '.', '.', 'x', '.'},
      {'.', 'x', '.', '.', '.', 'x', '.', '.', '.', '.', 'x', '.'},
      {'.', '.', '.', '.', '.', '.', 'x', '.', '.', '.', 'x', '.'},
      {'.', '.', '.', '.', '.', '.', '.', 'x', '.', '.', '.', '.'},
      {'.', '.', 'x', 'x', 'x', '.', '.', '.', 'x', '.', '.', '.'}};
  int letras;
  int cont = 0, palabras = 0;

  imprimir(sopa);

  while (palabras < 10) {
    std::cout << "\n";
    cout << "Ingrese el numero de letras: " << endl;
    cin >> letras;

    for (int i = 0; i < letras; i++) {
      cont += comparar(posicion_x(), posicion_y(), sopa, res);
      if (i == letras - 1) {
        if (cont == letras) {
          cout << "¡Acertaste!" << endl;
          palabras++;

          imprimir(sopa);
        } else {
          cout << "Fallaste pendejo :)" << endl; // xd
          imprimir(sopa);
        }
      }
    }

    cont = 0;
  }
}

// Imprimir la sopa de letras
void imprimir(char sopa[N][M]) {
  int i, j, k;

  for (i = 0; i < N + 1; i++) {
    for (j = 0; j < M; j++) {
      if (i == 0) {
        std::cout << "\t";
        for (k = 0; k < M; k++) {
          std::cout << k << "\t";
        }
        break;
      }

      if (j == 0) {
        std::cout << i - 1 << "\t";
      }

      std::cout << sopa[i - 1][j] << "\t";
    }
    printf("\n");
  }
}

// Definir la posición en x de la letra
int posicion_x() {
  int coordenada_x;

  printf("Inserte posición en el eje x (horizontal):\n");
  scanf("%d", &coordenada_x);

  return coordenada_x;
}

// Definir la posición en y de la letra
int posicion_y() {
  int coordenada_y;

  printf("Inserte posición en el eje y (vertical):\n");
  scanf("%d", &coordenada_y);

  return coordenada_y;
}

// Checar si la casilla elegida tiene una letra correcta
int comparar(int eje_x, int eje_y, char sopa[N][M], char res[N][M]) {
  if (sopa[eje_y][eje_x] != 'x') {
    if (res[eje_y][eje_x] == 'x') {
      sopa[eje_y][eje_x] = (int)sopa[eje_y][eje_x] + 32;
      return 1;
    } else {
      sopa[eje_y][eje_x] = 'x';
      return 0;
    }
  } else {
    printf("Ese valor ya lo ingresaste\n");
    return 0;
  }
}
