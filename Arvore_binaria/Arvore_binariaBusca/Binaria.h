#ifndef BINARIA_H_INCLUDED
#define BINARIA_H_INCLUDED

typedef struct no No;
No* arvore_vazia();
int altura(No* raiz);
int quantidade_folhas(No* raiz);
int quantidade(No* raiz);
No* insercao_Arvore(No *raiz, int num);
//busca
No* busca_Arvore(No* raiz, int val);
//Imprimir
void imprimir_ver1(No *raiz);
//Imprimir de forma ordenada
void imprimir_ordenada(No *raiz);
No* remove_no(No*raiz, int chave);
#endif // BINARIA_H_INCLUDED
