#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>   
#include <math.h>

typedef struct Solicitacao{
    int descricao;
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
		int opcao;
		enum menu{CHECAR=1, VERIFICARCONTA, SALDO, DEPOSITAR, SACAR};
		printf("Informe qual a sua solicitacao: \n");
		
		printf("1 - CHECAR CARTAO DE CREDITO\n");
		printf("2 - VERIFICAR SITUAÇÃO DA CONTA\n");
		printf("3 - VERIFICAR SALDO ATUAL\n");
		printf("4 - DEPOSITAR\n");
		printf("5 - SACAR\n");
		scanf("%d", &opcao);
		
		novaSolicitacao->descricao = opcao;
		
		
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
		if(ptr->descricao == 1){
			printf("Solicitacao: CHECAR CARTAO DE CREDITO\n");
		}
		if(ptr->descricao == 2){
			printf("Solicitacao: VERIFICAR SITUAÇÃO DA CONTA\n");
		}
		if(ptr->descricao == 3){
			printf("Solicitacao: VERIFICAR SALDO ATUAL\n");
		}
		if(ptr->descricao == 4){
			printf("Solicitacao: DEPOSITAR\n");
		}
		if(ptr->descricao == 5){
			printf("Solicitacao: SACAR\n");
		}
		
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
			
			if(ptr->descricao == 1){
				printf("Solicitacao: CHECAR CARTAO DE CREDITO\n");
			}
			if(ptr->descricao == 2){
				printf("Solicitacao: VERIFICAR SITUAÇÃO DA CONTA\n");
			}
			if(ptr->descricao == 3){
				printf("Solicitacao: VERIFICAR SALDO ATUAL\n");
			}
			if(ptr->descricao == 4){
				printf("Solicitacao: DEPOSITAR\n");
			}
			if(ptr->descricao == 5){
				printf("Solicitacao: SACAR\n");
			}
			
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
			        printf("\nSOLICITACAO INICIADO\n\n");
					existe = true;
					
				}else{
					printf("\nSolicitacao ja iniciado");
				}
				break;
			case 2:
				if(existe == true){
					
					p1 = adicionarSolicitacao(p1);
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
