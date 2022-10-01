#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct Pessoa{
	char nome[100];
	char cpf[15];
	struct Pessoa* proximo;
}Pessoa;


typedef struct Fila{
	Pessoa *inicio;
	Pessoa *fim;
}Fila;


void inicializarFila(Fila *f){
	f->inicio= NULL;
	f->fim = NULL;
}

Fila* adicionarLista(Fila *f){
	Pessoa *novaPessoa = (Pessoa*) malloc(sizeof(Pessoa));
	
	if(novaPessoa == NULL){
		printf("ERRO DE ALOCAÇÃO.\n");
		return;
	}else{
		
		printf("Digite o nome da pessoa a entrar na fila: ");
		scanf("%s", &novaPessoa->nome);
						
		printf("\nDigite o cpf da pessoa a entrar na fila: ");
		scanf("%s", &novaPessoa->cpf);
		novaPessoa->proximo = NULL;
		if(f->inicio == NULL){
			f->inicio = novaPessoa;
		}else{
			f->fim->proximo = novaPessoa;
		}
		f->fim = novaPessoa;
	}
	return f;
	
}


void remover(Fila *f){
	Pessoa *ptr = f->inicio;
	
	if(ptr != NULL){
		f->inicio = ptr->proximo;
		ptr->proximo = NULL;
		free(ptr);
		if(f->inicio == NULL){	
		}
	}else{
		printf("FILA VAZIAZ\n");
		return;
	}
}

void imprimeFila(Fila *f){
	Pessoa *ptr = f->inicio;
	if(ptr != NULL){
		int i=1;
		while(ptr != NULL){
			printf("-----------------FILA-%d-----------------\n", i);
			printf("------Nome: %s", ptr->nome);
			printf("\n------Cpf: %s\n\n", ptr->cpf);
			
			i++;
			ptr = ptr->proximo;
		}
	}else{
		printf("FILA VAZIA.\n");
	}
}



int main(){
	Fila *f1 = (Fila*) malloc(sizeof(Fila));
	
	int opcao, existe = 0;
	char nome, cpf;	
	
	if(f1 == NULL){
		printf("Erro de alocação.\n");
		exit(0);
	}else{
		while(opcao!=5){
			printf("1 - Iniciar Atendimento\n2 - Entrar em ultimo na fila\n3 - Atender cliente\n4 - vizualizar fila\n");
			scanf("%d", &opcao);
			switch(opcao){
				case 1:
					if(existe == 0){
						inicializarFila(f1);
						system("cls");
						printf("Iniciando o atendimento");
						Sleep(1000);
				        printf(".");
				        Sleep(1000);
				        printf(".");
				        Sleep(1000);
				        printf(".");
				        Sleep(1000);
				        printf("\nATENDIMENTO INICIADO\n\n");
						existe = 1;
					}else{
						printf("A FILA JA EXISTE\n");
						system("pause");
						system("cls");
					}
					break;
				
				case 2:
					if(existe == 1){
						
						f1 = adicionarLista(f1);
						system("cls");
					}else{
						printf("FILA VAZIA\n");
						system("pause");
						system("cls");
						
					}
					break;
				
				case 3:
					if(existe == 1){
						if(f1==NULL){
							printf("FILA VAZIA\n");	
							system("pause");
							system("cls");
						}else{
							printf("cliente atendido...\n");
							remover(f1);
							system("pause");
							system("cls");
						}
					}else{
						printf("FILA NAO INCIADA!\n");
					}
					break;
					
				case 4:
					if(existe == 1){
						if(f1==NULL){
							printf("FILA VAZIA!\n");
							system("pause");
							system("cls");
						}
						else{
							imprimeFila(f1);
							system("pause");
							system("cls");
						}
					}else{
						printf("FILA NAO INCIADA!\n");
						system("pause");
						system("cls");
					}
					break;
					
			}
		}
		
		//enfileira();
	}
	
}

