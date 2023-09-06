#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elemento{
    char letra;
    struct elemento *link;
} pilha;

pilha *empilhar(char palindromo[], int tamanho){
    pilha *topo = NULL, *p, *q;
    int i;
    for(i = 0; i <= tamanho; i++){
        if(topo == NULL){
            topo = (pilha *) malloc(sizeof(pilha));
            topo->letra = palindromo[i];
            topo->link = NULL;
            q = topo;
        }else if(topo != NULL){
            p = (pilha *) malloc(sizeof(pilha));
            p->letra = palindromo[i];
            p->link = q;
            topo = p;
            q = p;
        }
    }
    return topo;
}

void desempilhar(pilha *p, char vet[], int tamanho){
    pilha *topo, *q;
    int i = 0;
    topo = p;
    do{
        vet[i] = topo->letra;
        q = topo;
        topo = q->link;
        free(q);
        i++;
    }while(i != 6);
}

int main(){
    char palindromo[5];
    char inverso[5];
    int iguais;
    pilha *aux;
    printf("\nDigite um palindromo de 5 caracteres: ");
    fflush(stdin);
    fgets(palindromo, 10, stdin);
    aux = empilhar(palindromo, 5);
    desempilhar(aux, inverso, 5);
    iguais = strcmp(palindromo, inverso);
    if(iguais > 0){
        printf("\nA palavra e um palindromo");
    }else{
        printf("\nA palavra NAO e um palindromo");
    }
    return 0;
}