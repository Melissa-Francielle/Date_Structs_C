#include <stdio.h>
#include <stdlib.h>
#include "ListaD.h"

struct lista{
    int info;
    Lista *proximo;
};
Lista* criarLista(void){
    return NULL;
}

// Inserir no inicio
Lista* lista_insere(Lista* lista, int val) {
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    if (novo) {
        novo->info = val;
        novo->proximo = lista;
        return novo; // Retorna o novo início da lista
    } else {
        printf("Erro ao alocar memoria\n");
        return lista; // Retorna a lista original
    }
}
// insere no fim da lista
Lista* insere_final(Lista *lista, int val) {
    Lista *aux, *novo = malloc(sizeof(Lista));

    if (novo) {
        novo->info = val;
        novo->proximo = NULL;

        // é o primeiro?
        if (lista == NULL) {
            lista = novo;
        } else {
            aux = lista;
            while (aux->proximo) {
                aux = aux->proximo;
            }
            aux->proximo = novo;
        }
        return lista;
    } else {
        printf("Erro ao alocar memoria");
        return lista;
    }
}


// insere no meio da lista
Lista* insere_meio(Lista *lista, int val, int elemento_anterior) {
    Lista *aux, *novo = malloc(sizeof(Lista));

    if (novo) {
        novo->info = val;
        // é o primeiro nó da lista?
        if (lista == NULL) {
            novo->proximo = NULL;
            lista = novo;
        } else {
            aux = lista;
            while (aux->proximo && aux->info != elemento_anterior) {
                aux = aux->proximo;
            }
            if (aux->info == elemento_anterior) {
                novo->proximo = aux->proximo;
                aux->proximo = novo;
            } else {
                printf("Elemento anterior nao encontrado na lista\n");
                free(novo);
            }
        }
        return lista;
    } else {
        printf("Erro ao alocar memoria\n");
        return lista;
    }
}
//Funcao de impressão
void lista_imprime(Lista* lista){
    Lista* aux;
    printf("\n\tLista: \n");
    for(aux = lista; aux != NULL; aux = aux->proximo){
        printf("%d ", aux->info);
    }
    printf("\n\n");
    printf("\nfinalizou a impressao");
}

Lista* lista_busca(Lista *lista, int val) {
    Lista* auxiliar;
    for (auxiliar = lista; auxiliar != NULL; auxiliar = auxiliar->proximo) {
        if (auxiliar->info == val) {
            return auxiliar;
        }
    }
    return NULL; // Retorna NULL apenas após percorrer toda a lista
}

Lista* lista_retira(Lista *lista, int val){
    Lista* anterior = NULL;
    Lista* auxiliar = lista;
    while(auxiliar != NULL && auxiliar->info != val){
        anterior = auxiliar;
        auxiliar = auxiliar->proximo;
    }
    if(auxiliar == NULL){
        return lista;
    }
    if(anterior == NULL){
        lista = auxiliar->proximo;
    }
    else{
        anterior->proximo = auxiliar->proximo;
    }
    free(auxiliar);
    return lista;
}

Lista* lista_insere_ordenado(Lista *lista, int val){
    Lista* novo;
    Lista* anterior = NULL;
    Lista* percorre = lista;

    while(percorre != NULL && percorre->info < val){
        anterior = percorre;
        percorre = percorre->proximo;
    }
    novo = (Lista*) malloc(sizeof(Lista));
    novo->info = val;
    if(anterior == NULL){
        novo->proximo = lista;
        lista = novo;
    }
    else{
        novo->proximo = anterior->proximo;
        anterior->proximo = novo;
    }
    return lista;
}

void lista_libera(Lista* lista){
    Lista* liberando;
    Lista* auxiliar = lista;
    while(auxiliar!= NULL){
        liberando = auxiliar->proximo;
        free(auxiliar);
        auxiliar = liberando;
    }
}
