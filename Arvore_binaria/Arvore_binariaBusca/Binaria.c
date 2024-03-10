#include <stdlib.h>
#include <stdio.h>
#include "Binaria.h"

//Inserção na arvore
/*Lembrando que a árvore utiliza a raiz para iniciar a inserção
ex:         50
           /  \
          25  100   */
struct no{
    int valor;
    No *direita;
    No *esquerda;
};

//cria a arvore
No* arvore_vazia(){
    return NULL;
}

//Insere na arvore
No* insercao_Arvore(No *raiz, int num){
    if(raiz == NULL){ //primeiro nó da arvore;
        No *aux = malloc(sizeof(No));
        aux->valor = num;
        aux->esquerda = NULL;
        aux->direita = NULL;
        return aux;
    }
    else{
        if(num < raiz->valor){
            raiz->esquerda = insercao_Arvore(raiz->esquerda, num);
        }
        else{
            raiz->direita = insercao_Arvore(raiz->direita, num);

        }
        return raiz;
    }
}
//Busca
No* busca_Arvore(No* raiz, int val){
    if(raiz){
        if(val == raiz->valor){
            return raiz;
        }
        else if(val < raiz->valor){
           return busca_Arvore(raiz->esquerda, val);
        }
        else{
           return busca_Arvore(raiz->direita, val);
        }
    }
    return NULL;
}
//Imprimir
void imprimir_ver1(No *raiz){
    if(raiz){
        printf("%d ", raiz->valor);
        imprimir_ver1(raiz->esquerda);
        imprimir_ver1(raiz->direita);
    }
}

//Imprimir de forma ordenada
void imprimir_ordenada(No *raiz){
    if(raiz){
        imprimir_ordenada(raiz->esquerda);
        printf("%d ", raiz->valor);
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
    //return (raiz == NULL) ? 0 : 1 +quantidade(raiz->esquerda) + quantidade(raiz->dirieta);
}
// quantidade de folhas
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
//Altura
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

//Removendo 
No* remove_no(No*raiz, int chave){
    if(raiz == NULL){
        printf("\nValor nao encontrado!\n");
        return NULL;
    }
    else{
        if(raiz->valor == chave){
                   //nó sem filhos
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
                           //troca informações
                    raiz->valor = aux->valor;
                    aux->valor= chave;
                    printf("\nElemento trocado: %d\n", chave);
                    raiz->esquerda = remove_no(raiz->esquerda, chave);
                    return raiz;
                }
                else{
                           //filhos em apenas uma das direções
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
            if(chave < raiz->valor){
                raiz->esquerda = remove_no(raiz->esquerda, chave);
            }
            else{
                raiz->direita = remove_no(raiz->direita, chave);
            }
            return raiz;
        }
    }
}


