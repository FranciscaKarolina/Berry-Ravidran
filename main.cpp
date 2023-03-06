#include <stdio.h>
#include <string.h>

#define ASIZE 256 // Tamanho do alfabeto
/* A função preBrBc recebe uma string x e seu comprimento m, e uma matriz brBc de tamanho ASIZE x ASIZE.
   Ela preenche a matriz brBc com valores inteiros que serão usados pelo algoritmo BR para fazer a busca.
   A matriz brBc representa uma tabela de saltos, que contém informações sobre quantas posições podem ser saltadas
   na string y durante a busca. */
void preBrBc(char *x, int m, int brBc[ASIZE][ASIZE]) {
   int a, b, i;

   // Inicializando a matriz com valores altos
   for (a = 0; a < ASIZE; ++a)
      for (b = 0; b < ASIZE; ++b)
         brBc[a][b] = m + 2;

   // Preenchendo a primeira coluna da matriz com valores específicos
   for (a = 0; a < ASIZE; ++a)
      brBc[a][x[0]] = m + 1;

   // Preenchendo a matriz com valores específicos
   for (i = 0; i < m - 1; ++i)
      brBc[x[i]][x[i + 1]] = m - i;

   // Preenchendo a última linha da matriz com valores específicos
   for (a = 0; a < ASIZE; ++a)
      brBc[x[m - 1]][a] = 1;
}

/* A função BR recebe uma string x e seu comprimento m, uma string y e seu comprimento n.
   Ela utiliza a matriz brBc preenchida pela função preBrBc para procurar a ocorrência de x em y.
   Quando encontra uma ocorrência, a função SAÍDA é chamada. */
void BR(char *x, int m, char *y, int n) {
   int j, brBc[ASIZE][ASIZE];

   /* Pré-processando */
   preBrBc(x, m, brBc);

   /* Procurando */
   // Adicionando um caractere nulo à string y
   y[n + 1] = '\0';
   j = 0;

   // Realizando a busca
   while (j <= n - m) {
      // Comparando a string x com uma sub-string de y
      if (memcmp(x, y + j, m) == 0)
         printf("Ocorrencia encontrada na posicao %d.\n", j);
      // Atualizando o índice j usando os valores da matriz brBc
      j += brBc[y[j + m]][y[j + m + 1]];
   }
}
int main() {
char x[] = "abba"; // String a ser procurada
char y[] = "abbabbabbabbabba"; // String onde a busca será realizada
int m = strlen(x);
int n = strlen(y);

BR(x, m, y, n);

return 0;
}
