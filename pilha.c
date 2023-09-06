#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilha{
    struct pilha *ligacao;
    char dado;
} pilha;

void empilhar2(pilha **topo, char dado);
char desempilhar(pilha **topo);
int verificando(char dado);

int main() {
    pilha *topo=NULL;
    char dado, dado2, dado3, dado4, auxVer2, auxVer3, auxVer4;
    int inserir, numeroInseridos=0, operacao, auxWhile=0;
    while(auxWhile!=9) {
        printf("Digite 1 para adicionar dados a calculadora\n Digite 2 para o resultado\nDigite 9 para terminar o programa");
        scanf("%d", &auxWhile);
        if (auxWhile == 1) {
            printf("Quantos dados deseja adicionar a pilha?");
            scanf("%d", &inserir);
            empilhar2(&topo)
        }
        if (auxWhile == 2) {
                }
            }
    return 0;
}
void empilhar2(pilha **topo, char dado){
    pilha *p=NULL, *q=NULL;
        p = ((pilha*) malloc(sizeof(pilha)));
        p->dado=dado;
        p->ligacao=q;
        *topo=p;
        q=p;
}

char desempilhar(pilha **topo){
    pilha *q=NULL;
    char dado;
    q=*topo;
    dado=q->dado;
    (*topo)=q->ligacao;
    free(q);
    return dado;
}

int verificando(char dado){
    if((dado=='+')||(dado=='-')||(dado=='*')||(dado=='/'))
        return 0;
    else return 1;
}

int operacoes(char dado, char dado2, char dado3){
    int operacao;
    switch (dado) {
        case '+':
            operacao = (int) dado2 + (int) dado3;
            break;
        case '-':
            operacao = (int) dado2 - (int) dado3;

            break;
        case '*':
            operacao = (int) dado2 * (int) dado3;

            break;
        case '/':
            operacao = (int) dado2 / (int) dado3;
            break;
    }
    return operacao;
}

void desOPeracao(pilha **topo, char auxiliar){
    int auxVer1, auxVer2, auxOp;
    char dado, dado2, dado3, auxDado;
    while(topo!=NULL) {
        dado = desempilhar(&*topo);
        dado2 = desempilhar(&*topo);
        dado3= desempilhar(&*topo);
        auxVer1=verificando(dado2);
        auxVer1=verificando(dado3);

        if((auxVer1==1)&&(auxVer2==1)){
            auxOp=operacoes(dado, dado2, dado3);
            empilhar2(&*topo, auxOp);
        }
        else if(auxVer1==0)&&(aux1){
            auxDado=dado;
            dado=dado2;
            }
    }

}

