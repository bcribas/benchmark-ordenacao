#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "radixsort.h"
#include "ordenacaomacros.h"

void radixsort(Item *v, int l, int n){
  // v = vetor de números
  // n = quantidade de números no vetor
  // ex.: [0, 1, 2, 3] -> n=4

  int aux, aux1, maxdigitos = 1;
  n++;

  // Calcula a maior quantidade de dígitos de um
  // único número no vetor
  for (int i = l; i < n; i++){
    int div = 10;
    int maior = 1;
    while (v[i] / div != 0){
      div *= 10;
      maior++;
    }
    if (maior > maxdigitos){
      maxdigitos = maior;
    }
  }

  for (int j = 0; j < maxdigitos; j++){
    int z = 0, u = 0, d = 0, t = 0, q = 0, c = 0, s = 0, st = 0, o = 0, nv = 0;

    int *zero = malloc(n * sizeof(int));
    int *um = malloc(n * sizeof(int));
    int *dois = malloc(n * sizeof(int));
    int *tres = malloc(n * sizeof(int));
    int *quatro = malloc(n * sizeof(int));
    int *cinco = malloc(n * sizeof(int));
    int *seis = malloc(n * sizeof(int));
    int *sete = malloc(n * sizeof(int));
    int *oito = malloc(n * sizeof(int));
    int *nove = malloc(n * sizeof(int));

    int k = 0, h = 0, zeros = 0;
    aux1 = pow(10, j);
    aux = pow(10, j + 1);

    // Dividindo os valores de acordo com a casa de unidade/dezena/...
    for (int i = l; i < n; i++){

      if (v[i] == 0){
        zeros++;
        k++;
      }
      else if (((v[i] % aux) / aux1) == 0){
        zero[z] = v[i];
        z++;
        k++;
      }
      else if (((v[i] % aux) / aux1) == 1){
        um[u] = v[i];
        u++;
        k++;
      }
      else if (((v[i] % aux) / aux1) == 2){
        dois[d] = v[i];
        d++;
        k++;
      }
      else if (((v[i] % aux) / aux1) == 3){
        tres[t] = v[i];
        t++;
        k++;
      }
      else if (((v[i] % aux) / aux1) == 4){
        quatro[q] = v[i];
        q++;
        k++;
      }
      else if (((v[i] % aux) / aux1) == 5){
        cinco[c] = v[i];
        c++;
        k++;
      }
      else if (((v[i] % aux) / aux1) == 6){
        seis[s] = v[i];
        s++;
        k++;
      }
      else if (((v[i] % aux) / aux1) == 7){
        sete[st] = v[i];
        st++;
        k++;
      }
      else if (((v[i] % aux) / aux1) == 8){
        oito[o] = v[i];
        o++;
        k++;
      }
      else if (((v[i] % aux) / aux1) == 9){
        nove[nv] = v[i];
        nv++;
        k++;
      }
    }

    // Reagrupando os vetores que estão divididos
    for (int i = 0; i < zeros && zeros != 0; i++){
      v[h] = 0;
      h++;
    }
    for (int i = 0; zero[i] != '\0'; i++){
      v[h] = zero[i];
      h++;
    }
    for (int i = 0; um[i] != '\0'; i++){
      v[h] = um[i];
      h++;
    }
    for (int i = 0; dois[i] != '\0'; i++){
      v[h] = dois[i];
      h++;
    }
    for (int i = 0; tres[i] != '\0'; i++){
      v[h] = tres[i];
      h++;
    }
    for (int i = 0; quatro[i] != '\0'; i++){
      v[h] = quatro[i];
      h++;
    }
    for (int i = 0; cinco[i] != '\0'; i++){
      v[h] = cinco[i];
      h++;
    }
    for (int i = 0; seis[i] != '\0'; i++){
      v[h] = seis[i];
      h++;
    }
    for (int i = 0; sete[i] != '\0'; i++){
      v[h] = sete[i];
      h++;
    }
    for (int i = 0; oito[i] != '\0'; i++){
      v[h] = oito[i];
      h++;
    }
    for (int i = 0; nove[i] != '\0'; i++){
      v[h] = nove[i];
      h++;
    }
    if (k == 0){
      j = 10;
    }
  }
}