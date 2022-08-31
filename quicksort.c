#include <stdio.h>

void trocar(int *a, int *b) {
  int aux = *a;
  *a = *b;
  *b = aux;
}

int particao(int vetor[], int menor, int maior) {
  
  int pivot = vetor[maior];
  
  int i = (menor - 1);

  for (int j = menor; j < maior; j++) {
    if (vetor[j] <= pivot) {
        
      i++;
      
      trocar(&vetor[i], &vetor[j]);
    }
  }

  trocar(&vetor[i + 1], &vetor[maior]);
  
  return (i + 1);
}

void quickSort(int vetor[], int menor, int maior) {
  if (menor < maior) {
    
    int pi = particao(vetor, menor, maior);
    
    quickSort(vetor, menor, pi - 1);
    
    quickSort(vetor, pi + 1, maior);
  }
}

void printVetor(int vetor[], int tamanho) {
  for (int i = 0; i < tamanho; ++i) {
    printf("%d  ", vetor[i]);
  }
  printf("\n");
}

int main() {
  int entrada[] = {11, 17, 2, 31, 1, 92, 117, 15, 46}; //colocar qualquer valor para a entrada
  
  int aux = sizeof(entrada) / sizeof(entrada[0]);
  
  printf("Vetor não ordenado\n");
  printVetor(entrada, aux);
  
  quickSort(entrada, 0, aux - 1);
  
  printf("Vetor ordenado: \n");
  printVetor(entrada, aux);
}