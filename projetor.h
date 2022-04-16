int altura(PtrNo arvptr) {
	if(arvptr == NULL) {
		return(-1);
	}
	else {
		int he = altura(arvptr->ptr_esq);
		int hd = altura(arvptr->ptr_dir);
		
		if(hd > he) {
			return(hd + 1);
		}
		else {
			return(he + 1);
		}
	}
}

void preencher_arvore(PtrNo arvptr, int *ptrmapa, int altura, int largura, int nivel) {
	int i;
	int *centro = ptrmapa;
	int valor = arvptr->dado;
	int braco = largura/(4*(pow(2, nivel)));
	
	ptrmapa++;
	while(valor > 0) {
		int digito = valor % 10;
		*ptrmapa = digito + 48;
		valor /= 10;
		ptrmapa--;
	}
	ptrmapa = centro;

	if(arvptr->ptr_esq != NULL) {
		ptrmapa -= 2;
		for(i = 0; i < braco; i++) {
			ptrmapa--;
			*ptrmapa = 196;
		}
		*ptrmapa = 255;
		ptrmapa++;
		*ptrmapa = 218;
		ptrmapa--;
		
		preencher_arvore(arvptr->ptr_esq, ptrmapa + largura + 1, altura, largura, nivel + 1);
		ptrmapa = centro;
	}
	
	if(arvptr->ptr_dir != NULL) {
		ptrmapa += 2;
		for(i = 0; i < braco; i++) {
			ptrmapa++;
			*ptrmapa = 196;
		}
		*ptrmapa = 255;
		ptrmapa--;
		*ptrmapa = 191;
		ptrmapa++;
		
		preencher_arvore(arvptr->ptr_dir, ptrmapa + largura - 1, altura, largura, nivel + 1);
		ptrmapa = centro;
	}
}

void projetar_arvore(PtrNo arvptr) {
	if(arvptr == NULL) {
		return;
	}
	
	int i, j;
	int alt = altura(arvptr) + 1;
	int lar = pow(2, alt - 1)*(8) - 1;
	
	int mapa[lar*alt], *ptrpos;
	
	for(i = 0; i < alt*lar; i++) {
		mapa[i] = ' ';
	}
	
	ptrpos = &mapa[(lar/2)];
	preencher_arvore(arvptr, ptrpos, alt, lar, 0);
	
	ptrpos = &mapa[0];
	for(i = 0; i < alt*lar; i++) {
		printf("%c", *ptrpos);
		if(i % lar == 0) {
			printf("\n");
		}
		ptrpos++;
	}
}
