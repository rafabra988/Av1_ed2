#include <stdio.h>
#include <locale.h>
#define tam 10



void heapsort(int *vet, int n) {
	int i, aux;

	for (i = (n / 2); i >= 0; i--) {
		criaheap(vet, i, n - 1);
	}

	for (i = n-1; i >= 1; i--) {
		aux = vet[0];
		vet[0] = vet[i];
		vet[i] = aux;
		criaheap(vet, 0, i-1);
	}
}

void criaheap(int *vet, int raiz, int fim) {
	int boolean, filho, aux;

	boolean = 0;
	while((raiz*2 <= fim) && (!boolean)) {
		if(raiz*2 == fim) {
			filho = raiz * 2;
		}
		else if(vet[raiz * 2] > vet[2*raiz+1]) {
			filho = raiz * 2;
		}
		else{
			filho = raiz * 2 + 1;
		}

	if(vet[raiz] < vet[filho]) {
		aux = vet[raiz];
		vet[raiz] = vet[filho];
		vet[filho] = aux;
		raiz = filho;
    }
	else{
      boolean = 1;
	}
  }
}

int main() {
    setlocale(LC_ALL,"portuguese");

	int vetor[tam];
	int r;

	printf("digite 10 numeros aleatoreos sem nenhuma repetição");
	for(int i=0;i<10;i++){
        printf("\n%dº numero\n\n", i+1);
        scanf("%d",&r);
        vetor[i]=r;
	}

	heapsort(vetor,tam);
	for (int i = 0; i < tam; i++)
		printf("%d ", vetor[i]);
}
