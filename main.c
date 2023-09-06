#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct pilha1{
    struct pilha1 *ligacao;
    int dado;
} pilha1;

typedef struct pilha2{
    struct pilha2 *ligacao1;
    char dado;
} pilha2;



int operacoes(pilha1 **topo, pilha2 **topo2);
void empilhar1(pilha1 **topo, int dado);
void empilhar2(pilha2 **topo2, char dado);
int desempilharAlgarismo(pilha1 **topo);
char desempilharOperador(pilha2 **topo2);

int main() {
    pilha1 *topo=NULL;
    pilha2 *topo2=NULL;
    char addOperador;
    int auxWhile=0, dadoApagado, resultado=0, auxInsercao, addNumero;
    while(auxWhile!=9) {
        printf("Digite 1 adicionar algarismos ou operadores\nDigite 2 para para apagar o ultimo dado\n Digite 3 para conferir o resultado das operacoes momentaneo\nDigite 9 para finalizar o programa\n");
        scanf("%d", &auxWhile);
        if(auxWhile==1){
            printf("Digite 1 para adicionar um numero a expressao, ou digite dois para adicionar um operado");
            scanf("%d", &auxInsercao);
            if(auxInsercao==1){
                scanf("%d", &addNumero);
                empilhar1(&topo, addNumero);
            }
            else if(auxInsercao==2){
                scanf("%c", &addOperador);
                empilhar2(&topo2, addOperador);
                resultado=operacoes(&topo, &topo2);
            }
        }
        else if(auxWhile==2){
            dadoApagado=desempilharAlgarismo(&topo);
            printf("Dado apagado:%d", dadoApagado);
        }
        else{
            printf("Resultado=momentaneo: %d", resultado);
        }

    }
    return 0;
}

void empilhar1(pilha1 **topo, int dado){
    pilha1 *p=NULL, *q=NULL;
    p = ((pilha1*) malloc(sizeof(pilha1)));
    p->dado=dado;
    p->ligacao=q;
    *topo=p;
    q=p;
}

void empilhar2(pilha2 **topo, char dado){
    pilha2 *p=NULL, *q=NULL;
    p = ((pilha2*) malloc(sizeof(pilha2)));
    p->dado=dado;
    p->ligacao1=q;
    *topo=p;
    q=p;
}

int desempilharAlgarismo(pilha1 **topo){
    pilha1 *q=NULL;
    int dado;
    q=*topo;
    dado=q->dado;
    (*topo)=q->ligacao;
    free(q);
    return dado;
}

char desempilharOperador(pilha2 **topo){
    pilha2 *q=NULL;
    char dado;
    q=*topo;
    dado=q->dado;
    (*topo)=q->ligacao1;
    free(q);
    return dado;
}

int operacoes(pilha1 **topo, pilha2 **topo2) {
    int operacao;
    char dado;
    int dado2, dado3;
    dado = desempilharOperador(&(*topo2));
    dado2 = desempilharAlgarismo(&*topo);
    dado3 = desempilharAlgarismo(&*topo);
    if (dado == '+')
        operacao = dado2 + dado3;
    else if (dado == '-')
        operacao = dado2 - dado3;
    else if(dado=='*')
        operacao =  dado2 * dado3;
    else if(dado=='/')
        operacao = dado2 / dado3;
    else{
        printf("Operacao invalida");
        return -1000;
    }
    empilhar1(&*topo,operacao);
    return operacao;
}

