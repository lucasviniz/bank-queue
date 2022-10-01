#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>   
#include <math.h>

typedef struct Solicitacao{
    char descricao[200];
	bool resolvido;
	struct Solicitacao *proximo;
    
}Solicitacao;


typedef struct{
	Solicitacao *topo;
}Pilha;


void inicializarPilha(Pilha *p){
	p->topo = NULL;
}

Pilha* adicionarSolicitacao(Pilha *p){
	Solicitacao *novaSolicitacao = (Solicitacao*) malloc(sizeof(Solicitacao));
	
	if(novaSolicitacao == NULL){
		printf("Erro de alocação.\n");
	}else{
		printf("Informe qual a sua solicitacao: ");
		fgets(novaSolicitacao->descricao, sizeof(novaSolicitacao->descricao), stdin);
		
		novaSolicitacao->proximo = p->topo;
		p->topo = novaSolicitacao;
	}
	return p;
}

void removerSolicitacao(Pilha *p){
	Solicitacao *ptr = p->topo;
	if(ptr==NULL){
		printf("Pilha Vazia.\n");
	}else{
		p->topo = ptr->proximo;
		ptr->proximo = NULL;
		free(ptr);
	}
}

void imprimePilha(Pilha *p){
	Solicitacao *ptr = p->topo;
	if(ptr == NULL){
		printf("Pilha Vazia.\n");
	}else{
		while(ptr!=NULL){ 
			printf("Solicitacao: %s \n", ptr->descricao);
			ptr = ptr->proximo;
		}
		printf("\n");
	}
}

int main(){
	Pilha *p1 = (Pilha*) malloc(sizeof(Pilha));
	Solicitacao *s;
	char descricao;
	int opcao;

	bool resolvido = false, existe = false;
	
	if(p1 == NULL){
		printf("Erro de alocação.\n");
	}else{
		
		while(opcao != 5){
			printf("1 - Iniciar Solicitacao\n2 - Adicionar uma nova solicitacao\n3 - Atender Solicitacao\n4 - Imprimir Solicitacao\n");
			scanf("%d", &opcao);
			getchar();
			
			switch(opcao){
			
			case 1:
				if(existe == false){
					inicializarPilha(p1);
					system("cls");
					printf("Iniciando o atendimento");
					Sleep(1000);
			        printf(".");
			        Sleep(1000);
			        printf(".");
			        Sleep(1000);
			        printf(".");
			        Sleep(1000);
			        printf("\nSOLICITACAO INICIADO\n\n");
					existe = true;
					
				}else{
					printf("\nSolicitacao ja iniciado");
				}
				break;
			case 2:
				if(existe == true){
					
					adicionarSolicitacao(p1);
					system("cls");
				}else{
					printf("PILHA VAZIA\n");
					system("pause");
					system("cls");
				}
				break;
			case 3:
				if(existe == true){
					if(p1==NULL){
						printf("Pilha vazia");
						system("pause");
						system("cls");
					}else{
						printf("cliente atendido...\n");
						removerSolicitacao(p1);
						system("pause");
						system("cls");
					}
				}
				break;
			case 4:
				if(existe == true){
					if(p1 == NULL){
						printf("Pilha vazia");
						system("pause");
						system("cls");
					}
					else{
						imprimePilha(p1);
						system("pause"); 
						system("cls");
					}
				}else{
					printf("PILHA NAO INCIADA!\n");
					system("pause");
					system("cls");
				}
				break;
			default:
				
				printf("ERROR");
		}
				
	}
	}
}
