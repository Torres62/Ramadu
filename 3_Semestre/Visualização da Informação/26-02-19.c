#include <stdio.h>
#include <stdlib.h>

typedef struct n{
	int info;
	struct n *next;
}lista;

lista* inserir(lista *l){
	lista *novo=(lista *)malloc(sizeof(lista));
	printf("Digite a informacao:\n");
	scanf("%i",&novo->info);
	novo->next=l;
	return novo;
}

lista* inserir_ordenado(lista *l){
	lista *novo=(lista *)malloc(sizeof(lista));
	printf("Digite a informacao:\n");
	scanf("%i",&novo->info);
	lista *aux=l;
	lista *anterior=NULL;
	while(!vazia(aux)){
		if(novo->info < aux->info){
			break;
		}
		anterior=aux;
		aux=aux->next;
	}
	if(!vazia(aux)){
		if(vazia(anterior)){
			novo->next=l;
			return novo;
		}else{
			novo->next=anterior->next;
			anterior->next=novo;
			return l;
		}
	}else{
		novo->next=NULL;
		if(!vazia(anterior)){
			anterior->next=novo;	
			return l;
		}else{
			return novo;
		}	
	}	
}

void imprimir(lista *l){
	lista *aux=l;
	while(!vazia(aux)){
		printf("Info: %i\n",aux->info);
		aux=aux->next;
	}
}

lista* buscar(lista *l, int dado){
	lista *aux=l;
	while(!vazia(aux)){
		if(dado==aux->info){
			return aux;
		}
		aux=aux->next;
	}
	return NULL;
}

lista* excluir(lista *l, int dado){
	lista *aux=l;
	lista *anterior=NULL;
	while(!vazia(aux)){
		if(dado==aux->info){
			break;
		}
		anterior=aux;
		aux=aux->next;
	}
	if(!vazia(aux)){//foi encontrado
		if(!vazia(anterior)){//n?o ? o primeiro
			anterior->next=aux->next;
			free(aux);
		}else{
			l=l->next;
			free(aux);
		}
	}
	return l;
}

int vazia(lista *l){
	return l==NULL;
}

lista* inicia(){
	return NULL;	
}

void liberamemoria(lista *l){
	lista *aux=l;
	while(!vazia(aux)){
		l=aux->next;
		free(aux);
		aux=l;
	}
}

lista* clone(lista *l) {
	lista *clone = inicia();
	lista *aux1 = l;
	lista *aux2 = NULL;
	
	while (!vazia(aux1)) {
		lista *novo=(lista *)malloc(sizeof(lista));
		novo -> info = aux1 -> info;
		novo -> next = NULL;
		
		if (vazia(clone)) {
			clone = novo;
			aux2 = novo;
		} else {
			aux2 -> next = novo;
			aux2 = aux2 -> next;
		}
		
		aux1 = aux1 -> next;
	}
	
	return clone;
}

lista* deleta_impares(lista *l) {
	lista *aux = l;
	lista *previus = NULL;
	
	while(!vazia(aux)){
		if (aux -> info % 2 == 1) {
			
			if (!vazia(previus)) {
				previus -> next = aux -> next;
				free(aux);
				aux = previus -> next;
			} else {
				l = l -> next;
				free(aux);
				aux = l;
			}
			
			continue;
		}
		
		previus = aux;
		aux = aux -> next;
	}
	
	return l;
}

void imprimir_recursivo(lista *l) {
	if (!vazia(l)) {
		printf("\nInfo: %i", l -> info);
		imprimir_recursivo(l -> next);
	}
}

int main(int argc, char *argv[]) {
	lista *l=inicia();
	l=inserir_ordenado(l);
	l=inserir_ordenado(l);
	l=inserir_ordenado(l);
	printf("\nElementos gravados\n");
	imprimir_recursivo(l);
	
	printf("\nElementos duplicados\n");
	lista *clon = clone(l);
	imprimir_recursivo(clon);
	
	l = deleta_impares(l);
	printf("\nDeleta impares\n");
	imprimir_recursivo(l);
	
	l=excluir(l,10);
	printf("\nElementos excluidos\n");
	imprimir_recursivo(l);
	liberamemoria(l);
	liberamemoria(clon);
	return 0;
}
