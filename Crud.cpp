#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cadastro{
    char nome[30];
    int chaveCliente, cpf;
    struct cadastro *proximo, *anterior;
} cadastro;

void insereFinal(cadastro **primeiro, cadastro **final, int numeroInseridos, int auxInserir);
cadastro *busca(int numeroBuscado, cadastro *primeiro, int auxInserir);
void exibirLista(cadastro *primeiro, int auxInserir);
void atualiza(int numeroPoste, cadastro *primeiro, int auxInserir);
void delete(cadastro **primeiro, cadastro **final, cadastro *tempBusca);


int main() {
    cadastro *primeiro=NULL, *final=NULL, *tempBusca=NULL;
    int numeroInseridos=0, auxInserir = 0, auxWhile = 0, buscaCliente;
    while (auxWhile != 9) {
        printf("Digite 1 se deseja inserir clientes na lista\nDigite 2 se deseja exibir a lista\nDigite 3 se deseja buscar um cliente\nDigite 4 se deseja atualizar a lista\nDigite 5 se deseja remover algum cliente da lista\nDIgite 9 se deseja terminar o programa\n");
        scanf("%d", &auxWhile);
        if (auxWhile==1) {
            printf("Digite quantos clientes deseja inserir:\n");
            scanf("%d", &numeroInseridos);
            numeroInseridos = auxInserir + numeroInseridos;
            insereFinal(&primeiro, &final, numeroInseridos, auxInserir);
            auxInserir = numeroInseridos;
        }
        else if(auxWhile==2){
            exibirLista(primeiro, auxInserir);
        }
        else if(auxWhile==3){
            printf("Digite a chave a ser buscada:\n");
            scanf("%d", &buscaCliente);
            tempBusca=busca(buscaCliente, primeiro, auxInserir);
            if(tempBusca==NULL){
                printf("O elemento nao foi encontrado\n");
            }
            else
                printf("O elemento foi encontrado\nCPF: %d\nNome: %s\n", tempBusca->cpf, tempBusca->nome);
        }
        else if(auxWhile==4){
            printf("Digite a chave a ser atualizada:\n");
            scanf("%d", &buscaCliente);
            atualiza(buscaCliente, primeiro, auxInserir);
        }
        else if(auxWhile==5){
            printf("Digite a chave a ser deletada:\n");
            scanf("%d", &buscaCliente);
            tempBusca=busca(buscaCliente, primeiro, auxInserir);
            if(tempBusca==NULL){
                printf("So e possivel deletar clientes que estao na lista\n");
            }
            else {
                delete(&primeiro, &final, tempBusca);
                auxInserir--;
            }
        }
    }
}

void insereFinal (cadastro **primeiro, cadastro **final, int numeroInseridos, int auxInserir){
int i=auxInserir, j=numeroInseridos, auxInsercao;
cadastro *p, *q=NULL, *temp=NULL;
for(i; i<j;i++){
p = (cadastro*) malloc(sizeof(cadastro));
auxInsercao=0;
printf("Escreva a chave do cliente, se ela for repetidade digite novamente:\n");
while(auxInsercao==0){
scanf("%d", &p->chaveCliente);
if(*primeiro!=NULL){
temp=busca(p->chaveCliente, *primeiro, auxInserir);
if(temp==NULL){
auxInsercao=1;
}
else
auxInsercao=0;
}
else
auxInsercao = 1;
}
auxInserir++;
fflush(stdin);
printf("Escreva o nome do estudante do cliente:\n");
fgets(p->nome, 30, stdin);
printf("Digite o seu cpf:\n");
scanf("%d", &p->cpf);
p->proximo=NULL;
p->anterior=NULL;
if(*primeiro==NULL){
*primeiro=p;
*final=*primeiro;
}
else {
q = *final;
*final=p;
(*final)->anterior=q;
q->proximo=*final;
}
}
(*final)->proximo=*primeiro;
}

void exibirLista(cadastro *primeiro, int auxInserir){
cadastro *temp;
int contador=0;
temp=primeiro;
while (contador!=auxInserir) {
printf("Chave do cliente: %d\nCPF: %d\nNome: %s\n", temp->chaveCliente, temp->cpf,temp->nome);
temp = temp->proximo;
contador++;
}
}

cadastro *busca(int numeroBuscado, cadastro *primeiro, int auxInserir){
    cadastro *temp = primeiro;
    int contador=0;
    while (contador!=auxInserir){
        if (temp->chaveCliente == numeroBuscado){
            return temp;
        }
        temp = temp->proximo;
        contador++;
    }
    return NULL;
}

void atualiza(int numeroPoste, cadastro *primeiro, int auxInserir) {
    cadastro *p;
    p = busca(numeroPoste, primeiro, auxInserir);
    if(p==NULL){
        printf("Essa chave nao esta na lista, primeira a insira\n");
    }
    else {
        fflush(stdin);
        printf("Escreva o nome de quem esta atualizando o cadastro:\n");
        fgets(p->nome, 30, stdin);
        printf("Escreva o cpf da pessoa que esta atualizando o cadastro:\n");
        scanf("%d", &p->cpf);
    }
}

void delete(cadastro **primeiro, cadastro **final, cadastro *tempBusca){
cadastro *p, *q, *r;
p=tempBusca;
if (p == *primeiro) {
q = p->proximo;
free(p);
p = q;
p->anterior=NULL;
*primeiro = p;
}
else if(p==*final){
q=p->anterior;
free(p);
q->proximo=*primeiro;
*final=q;
}
else{
q = *primeiro;
while (q->proximo->chaveCliente != p->chaveCliente) q = q->proximo;
r = p->proximo;
free(p);
p = NULL;
q->proximo = r;
r->anterior=q;
}
}
