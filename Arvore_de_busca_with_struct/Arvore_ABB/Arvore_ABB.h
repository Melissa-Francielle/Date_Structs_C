#ifndef ARVORE_ABB_H_INCLUDED
#define ARVORE_ABB_H_INCLUDED

typedef struct no No;
typedef struct aluno Aluno;
No* arvore_vazia();
Aluno crialuno();

int altura(No* raiz);
int quantidade_folhas(No* raiz);
int quantidade(No* raiz);

No* insercao_Arvore(No *raiz);
//busca
No* busca_Arvore(No* raiz, int matricula);

//Imprimir
void imprimir_ver1(No *raiz);
//Imprimir de forma ordenada
void imprimir_ordenada(No *raiz);

No* remove_no(No* raiz, int chave_matricula);

#endif // ARVORE_ABB_H_INCLUDED
