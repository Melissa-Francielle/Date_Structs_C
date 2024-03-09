#include <stdlib.h>
#include <stdio.h>
#include "Arvore_ABB.h"

struct aluno{
    char nome[100];
    int matricula;
};

//Inserção na arvore
struct no{
    Aluno aluno;
    No *direita;
    No *esquerda;
};


//cria a arvore
No* arvore_vazia(){
    return NULL;
}

Aluno crialuno(){
    Aluno aluno;
    printf("\nDigite o nome do aluno: ");
    scanf("%*c");
    fgets(aluno.nome, 99, stdin);

    printf("\nDigite a matricula: ");
    scanf("%d", &aluno.matricula);
    return aluno;
}

//Insere na arvore
No* insercao_Arvore(No *raiz){
     Aluno *aluno = malloc(sizeof(Aluno));
    if(raiz == NULL){ //primeiro nó da arvore;

        *aluno = crialuno();
        No *aux = malloc(sizeof(No));
        aux->aluno = *aluno;
        aux->esquerda = NULL;
        aux->direita = NULL;
        return aux;
    }
    else{
        if(aluno->matricula < raiz->aluno.matricula){
            raiz->esquerda = insercao_Arvore(raiz->esquerda);
        }
        else{
            raiz->direita = insercao_Arvore(raiz->direita);
        }
        return raiz;
    }
}


//Busca
No* busca_Arvore(No* raiz, int matricula){
    if(raiz){
        if(matricula == raiz->aluno.matricula){
            return raiz;
        }
        else if(matricula < raiz->aluno.matricula){
           return busca_Arvore(raiz->esquerda, matricula);
        }
        else{
           return busca_Arvore(raiz->direita, matricula);
        }
    }
    return NULL;
}

//Imprimir
void imprimir_ver1(No *raiz){
    if(raiz){
        printf("\nNome: %s\nMatricula: %d\n", raiz->aluno.nome, raiz->aluno.matricula);
        imprimir_ver1(raiz->esquerda);
        imprimir_ver1(raiz->direita);
    }
}

//Imprimir de forma ordenada
void imprimir_ordenada(No *raiz){
    if(raiz){
        imprimir_ordenada(raiz->esquerda);
        printf("\nNome: %s\nMatricula: %d\n", raiz->aluno.nome, raiz->aluno.matricula);
        imprimir_ordenada(raiz->direita);
    }
}

//Contar a quantidade de nós da arvore
int quantidade(No* raiz){
    if(raiz == NULL){
        return 0;
    }
    else{
        return 1 + quantidade(raiz->esquerda) + quantidade(raiz->direita);
    }
}

// Quantidade de folhas
int quantidade_folhas(No* raiz){
    if(raiz == NULL){
        return 0;
    }
    else if(raiz->esquerda == NULL && raiz->direita == NULL){
        return 1;
    }
    else{
        return quantidade_folhas(raiz->esquerda) + quantidade_folhas(raiz->direita);
    }
}

// Altura
int altura(No* raiz){
    if(raiz == NULL){
        return 0;
    }
    else{
        int esq = altura(raiz->esquerda);
        int dir = altura(raiz->direita);
        if(esq > dir){
            return esq + 1;
        }
        else{
            return dir + 1;
        }
    }
}

// Removendo um nó folha
No* remove_no(No*raiz, int chave){
    if(raiz == NULL){
        printf("\nValor nao encontrado!\n");
        return NULL;
    }
    else{
        if(raiz->aluno.matricula == chave){
            if(raiz->esquerda == NULL && raiz->direita == NULL){
                free(raiz);
                printf("Elemento folha removido: %d\n", chave);
                return NULL;
            }
            else{
                //remover nós que possuem 1 ou 2 filhos;
                if(raiz->esquerda != NULL && raiz->direita != NULL){
                    No* aux = raiz->esquerda;
                    while(aux->direita != NULL){
                        aux = aux->direita;
                    }
                    raiz->aluno.matricula = aux->aluno.matricula;
                    aux->aluno.matricula= chave;
                    printf("\nElemento trocado: %d\n", chave);
                    raiz->esquerda = remove_no(raiz->esquerda, chave);
                    return raiz;
                }
                else{
                    No* aux;
                    if(raiz->esquerda != NULL){
                        aux = raiz->esquerda;
                    }
                    else{
                        aux = raiz->direita;
                    }
                    free(raiz);
                    printf("Elemento com 1 fiho removido: %d\n", chave);
                    return aux;
                }
            }

        }else{
            if(chave < raiz->aluno.matricula){
                raiz->esquerda = remove_no(raiz->esquerda, chave);
            }
            else{
                raiz->direita = remove_no(raiz->direita, chave);
            }
            return raiz;
        }
    }
}


