#O que � uma �rvore

###Estrutura de dados utilizada para organiza��o e busca
dos dados.

- � extremamente importante para a computa��o
- Quando temos o disco local, quando temos as setas com infinidades
de pastas, seria a representa��o de arvores nos computadores
- O disco rigido implementa a quest�o de arvores tbm
Sendo cada subs-pastas apontar outras pastas
- O disco rigido implementa uma arvore do tipo B

* Arvore AVL
* Arvore B
* Arvore rubro negra
* Arvore binaria - Primeiro modelo de arvore a ser estudada

###Como construi-la
A arvore binaria � construida por n�s, onde h� uma informa��o, e um ponteiro
a arvore possui dois ponteiros
- direita
- esquerda

Se mantendo para todos os n�s
* Raiz - Primeiro n� da arvore, inicia o caminho por esse n�
Podendo atingir qualquer n� pela direita ou pela esquerda
* Folhas - N�s que n�o possuem filhos, o final da arvore
Filhos nulos, ou seja, um n� sem filho
* sub arvore - toda arvore possui uma raiz, que tbm possui folhas
- Raiz da subarvore
- Folha da subarvore

###Como funciona percorrer pela arvore
- Um valor � analisado se � maior ou menor que a raiz, caso seja:
* MAIOR QUE A RAIZ - Vai para a direita da arvore;
* MENOR QUE A RAIZ - Vai para esquerda da arvore;

(A mesma ideia para a inser��o, busca, remo��o)

Nessa implementa��o de arvore binaria de busca, ser� feita a implementa��o separada de forma que
haver� um .h, .c e main.c;
- .H: possui as fun��es presentes na implementa��o da arvore
