#O que é uma árvore

###Estrutura de dados utilizada para organização e busca
dos dados.

- É extremamente importante para a computação
- Quando temos o disco local, quando temos as setas com infinidades
de pastas, seria a representação de arvores nos computadores
- O disco rigido implementa a questão de arvores tbm
Sendo cada subs-pastas apontar outras pastas
- O disco rigido implementa uma arvore do tipo B

* Arvore AVL
* Arvore B
* Arvore rubro negra
* Arvore binaria - Primeiro modelo de arvore a ser estudada

###Como construi-la
A arvore binaria é construida por nós, onde há uma informação, e um ponteiro
a arvore possui dois ponteiros
- direita
- esquerda

Se mantendo para todos os nós
* Raiz - Primeiro nó da arvore, inicia o caminho por esse nó
Podendo atingir qualquer nó pela direita ou pela esquerda
* Folhas - Nós que não possuem filhos, o final da arvore
Filhos nulos, ou seja, um nó sem filho
* sub arvore - toda arvore possui uma raiz, que tbm possui folhas
- Raiz da subarvore
- Folha da subarvore

###Como funciona percorrer pela arvore
- Um valor é analisado se é maior ou menor que a raiz, caso seja:
* MAIOR QUE A RAIZ - Vai para a direita da arvore;
* MENOR QUE A RAIZ - Vai para esquerda da arvore;

(A mesma ideia para a inserção, busca, remoção)

Nessa implementação de arvore binaria de busca, será feita a implementação separada de forma que
haverá um .h, .c e main.c;
- .H: possui as funções presentes na implementação da arvore
