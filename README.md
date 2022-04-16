# tree-projector
Biblioteca simples para projeção de árvores binárias no terminal

Criado para facilitar a visualização dos programas da matéria de Estruturas de Dados II. Feito em fevereiro de 2020.

O algoritmo espera nós com a seguinte estrutura:

```c
struct no {
	struct no *ptr_esq;
	int dado;
	struct no *ptr_dir;
};

typedef struct no No;
typedef No *PtrNo;
```

Para projetar a árvore na tela, chame a seguinte função:

```c
projetar_arvore(PtrRaiz);
```

Sendo `PtrRaiz` um ponteiro para o nó raiz da árvore.