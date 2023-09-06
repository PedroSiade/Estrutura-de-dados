#include <stdio.h>
#include <stdlib.h>

void insercaoUsuario(int v[]);
void insercaoAleatoria(int v[]);
void imprimirVetor(int v[]);
void buscaBinaria(int v[], int db);
void ordenacao(int v[], int tam);
//Oferi a opcao de criar uma lista com valores limitados a 1000, a fim de favorecer a testagem do programa.
int main() {
    int v[100], aux, auxWhile = 0, db;
    printf("Digite 0 se deseja digitar um valor para 100 posicoes de um vetor, ou digite 1 para gerar esses valores aleatoriamente(limitado entre 0 e 1000), sabendo que os valores serao ordenados de forma crescente automaticamente:\n");
    scanf("%d", &aux);
    if (aux == 1) {
        insercaoAleatoria(v);
    } else if (aux == 0) {
        insercaoUsuario(v);
    }
    ordenacao(v, 100);
    while (auxWhile != 9) {
        printf("Digite 1 para imprimir a lista\nDigite 2 para fazer uma busca\nDigite 9 para terminar o programa\n");
        scanf("%d", &auxWhile);
        if (auxWhile == 1) {
            imprimirVetor(v);
        } else if (auxWhile == 2) {
            setbuf(stdout, 0);
            printf("Digite o dado a ser buscado:\n");
            scanf("%d", &db);
            buscaBinaria(v, db);
        }
    }
    return 0;
}

void insercaoUsuario(int v[]) {
    for (int i = 0; i < 100; i++) {
        printf("Digite um valor para a posicao %d do vetor:\n", i);
        scanf("%d", &v[i]);
    }
}

void insercaoAleatoria(int v[]) {
    for (int i = 0; i < 100; i++) {
        v[i] = rand() % 1000;
    }
}

void imprimirVetor(int v[]) {
    for (int i = 0; i < 100; i++) {
        printf("v[%d]=%d\n", i, v[i]);
    }
}
//ordenação utilizando metodo de bubble sort
void ordenacao(int v[], int tam) {
    int i, j, meio, auxTroca;
    if (tam < 2)
        return;
    meio = v[tam / 2];
    for (i = 0, j = tam - 1;; i++, j--) {
        while (v[i] < meio)
            i++;
        while (meio < v[j])
            j--;
        if (i >= j)
            break;
        auxTroca = v[i];
        v[i] = v[j];
        v[j] = auxTroca;
    }
    ordenacao(v, i);
    ordenacao(v + i, tam - i);
}
//pi e pf representam respctivamente posicao inicial e posicao final do vetor
void buscaBinaria(int v[], int db) {
    int meio, pi = 0, pf = 99, auxSaida=1; //aux saida serve para permitir a saida do loop
    while ((pi < pf)&&(auxSaida==1)) {
        meio = ((pi + pf) / 2);
        if (v[meio] == db) {
            printf("Dado se encontra na lista\nPosicao: %d\n", meio);
            auxSaida=0;
        }
        if (v[meio] > db) {
            pf = (meio);
        }
        if (v[meio] < db) {
            pi = meio + 1;
        }
    }
    if ((pi==pf)&&(auxSaida!=0)) {
        if(v[pi]==db)
            printf("Dado se encontra na lista\nPosicao: %d\n", pi);
        else
            printf("Dado nao se encontra na lista\n");
    }
}
