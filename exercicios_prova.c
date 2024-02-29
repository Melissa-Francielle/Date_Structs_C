/* Neste arquivo possui a resposta dos seguintes exercicios
exericio 1
exercicio 2*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 19

typedef struct pessoa Pessoa;

struct pessoa{
    int matricula;
    float nota;
    char nome[100];
};

typedef struct no No;
struct no{
    Pessoa pessoa;
    No *prox;
};

typedef struct lista Lista;
struct lista{
    No *inicio;
    int tam;
};

Lista *tabela[TAM];

Pessoa criarPessoa(){
    Pessoa p;
    printf("\nDigite o nome da pessoa: ");
    scanf("%*c");
    fgets(p.nome, 99,stdin);
    printf("\nDigite a matricula da pessoa: ");
    scanf("%d", &p.matricula);
    printf("\nDigite a nota desse aluno: ");
    scanf("%f", &p.nota);
    return p;
}

void imprimirPessoa(Pessoa p){
    printf("\nMatricula: %d\nNome: %s\nNota: %.2f\n", p.matricula, p.nome, p.nota);

}
Lista* criarLista(){
    Lista *l = malloc(sizeof(Lista));

    l->inicio = NULL;
    l -> tam = 0;
    return l;
}

void inicializarHash(){
    int i; 
    for(i = 0; i < TAM; i++){
        tabela[i] = criarLista();
    }
}

int funcao_Hash(int chave) {
    return chave % TAM;
} 

//exercicio 1
int funcao_hash_string(char str[]){
    int i, tamanho = strlen(str);
    unsigned int hash = 0;
    
    for(i = 0; i < tamanho; i ++){
        hash += str[i] * (i+1);
    }
    return hash % TAM;
}

void inserirInicio(Pessoa p, Lista *lista){
    No *no = malloc (sizeof(No));
    no->pessoa = p;

    no->prox = lista->inicio;
    lista->inicio = no;
    lista->tam++;
}
//exercicio 2
void inserir(){
    Pessoa p = criarPessoa();
    int id = funcao_hash_string(p.nome);
    inserirInicio(p, tabela[id]);
}

void imprimirLista(No *inicio){
    while(inicio!= NULL){
        imprimirPessoa(inicio->pessoa);
        inicio = inicio->prox;
    }
}

// imprimir
void imprimirTabela(){
    int i;
    printf("\n-------------------Inicio da tabela---------------\n");

    for(i = 0; i < TAM; i++){
        printf("%d\n", i);
        printf("Lista tamanho: %d\n", tabela[i]->tam);
        imprimirLista(tabela[i]->inicio);
    }
    printf("\n----------------fim da tabela------------------\n");

}
//ex 3
Pessoa *buscarAluno(char *nome)
{
    int index = funcao_hash_string(nome);
    No *atual= tabela[index]->inicio;
    while (atual != NULL){
        if (strcmp(atual->pessoa.nome, nome) == 0){
            return &atual->pessoa;
        }
        atual = atual->prox;
    }
    return NULL;
}

int main (){
    Pessoa *pes;
    int op;
    char nome[100];

    inicializarHash();
    do{
        printf("0-Sair\n1-Inserir\n2-Buscar\n3-Imprimir\n");
        scanf("%d", &op);
        switch(op){
        case 0:
            break;
        case 1:
            inserir();
            break;
        case 2:
            printf("\nDigite o nome da pessoa: ");
            scanf("%*c");
            fgets(nome, 99,stdin);
            pes= buscarAluno(nome);
            if(pes) {
                    imprimirPessoa(*pes);
                }
                else {
                    printf("\nPessoa nao encontrada\n");
                }
            break;
        case 3:
            imprimirTabela();
            break;
        }
    }while(op != 0);
}