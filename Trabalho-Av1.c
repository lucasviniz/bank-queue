///////////////////////// *ATENDIMENDO EM UM BANCO* /////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <locale.h> // RECONHCE AS LETRAS PT-BR - PADRAO (ABNT2)
#include <string.h>
#include <Windows.h>
#include <stdbool.h>

typedef struct Solicitacao{
    int descricao;
	bool resolvido;
	struct Solicitacao *proximo;
    
}Solicitacao;

typedef struct Conta{
	char titular[50];
	char gerente[50];
	int agencia;
	int numero;
	double saldo;
	
}Conta;

typedef struct{
	Solicitacao *topo;
	
}Pilha;

 typedef struct Pessoa{
    int cpf; 
    char nome[50];
    Conta *conta;
    char tipoPessoa[30];
    struct Pessoa* proximo;
    Pilha *pilhaSolicitacoes;
    
} Pessoa;

typedef struct FilaClientes{
	Pessoa *inicio;
	Pessoa *fim;
	
}FilaClientes;

typedef struct FilaGerentes{
	Pessoa *inicio;
	Pessoa *fim;
	
}FilaGerentes;

typedef struct FilaAtendentes{
	Pessoa *inicio;
	Pessoa *fim;
	
}FilaAtendentes;

int agencia = 164874;
int numeroConta = 1;

void inicializarPilha(Pilha *p);
void inicializarFila(FilaClientes *f, FilaGerentes *fg, FilaAtendentes *fa, Pilha *p);
Pilha* adicionarSolicitacao(Pilha *p);

FilaGerentes* cadastrarGerente(FilaGerentes *f);
FilaAtendentes* cadastrarAtendentes(FilaAtendentes *f);
FilaClientes* adicionarLista(FilaClientes *f, FilaAtendentes *fa, FilaGerentes *fg, Pilha *p);

void imprimeFilaClientes(FilaClientes *f, Pilha *p);
void imprimeClienteAtual(FilaClientes *f, Pilha *p);
void imprimeFilaGerentes(FilaGerentes *f);
void imprimeFilaAtendentes(FilaAtendentes *f);
void imprimeProximosFila(FilaClientes *f, Pilha *p);

void imprimeFilaClientes(FilaClientes *f, Pilha *p){
	
	Pessoa *ptr = f->inicio;
	
	if(ptr != NULL){
		int i=1;
		printf("------------------------CLIENTES------------------------\n");
		while(ptr != NULL){
			printf("------%d - NOME: %s", i, ptr->nome);
			i++;
			ptr = ptr->proximo;
		}
	}else{
		printf("FILA VAZIA.\n");
	}
}

void imprimeClienteAtual(FilaClientes *f, Pilha *p){
	
	Pessoa *ptr = f->inicio;
	Pilha *aux = ptr->pilhaSolicitacoes->topo;
	
	if(ptr != NULL){
		int i=1;
		printf("====================CLIENTES=======================\n\n");
		printf("--------------------FILA-%d------------------------\n", i);
		printf("------ NOME: %s ------------------\n", ptr->nome);
		printf("------- CPF: %d ------------------\n", ptr->cpf);
		printf("\n--------------------------------------------------\n");
		printf("==================SOLICITACOES======================\n\n");
		
		while(ptr->pilhaSolicitacoes->topo != NULL){
			
			if(ptr->pilhaSolicitacoes->topo->descricao == 1){
				printf("SOLICITACAO: (1) - CHECAR CARTAO DE CREDITO\n");
			}
			if(ptr->pilhaSolicitacoes->topo->descricao == 2){
				printf("SOLICITACAO: (2) - VERIFICAR SITUAÇÃO DA CONTA\n");
			}
			if(ptr->pilhaSolicitacoes->topo->descricao == 3){
				printf("SOLICITACAO: (3) - VERIFICAR SALDO ATUAL\n");
			}
			if(ptr->pilhaSolicitacoes->topo->descricao == 4){
				printf("SOLICITACAO: (4) - DEPOSITAR\n");
			}
			if(ptr->pilhaSolicitacoes->topo->descricao == 5){
				printf("SOLICITACAO: (5) - SACAR\n");
			}
			
			ptr->pilhaSolicitacoes->topo = ptr->pilhaSolicitacoes->topo->proximo;
		}
		
		ptr->pilhaSolicitacoes->topo = aux;
		
		printf("\n------------CONTA----------");
		printf("\n-------TITULAR: %s", ptr->conta->titular);
		printf("\n-------AGENCIA: %d", ptr->conta->agencia);
		printf("\n-------NUMERO: %d", ptr->conta->numero);
		printf("\n-------GERENTE: %s", ptr->conta->gerente);
		printf("\n-------SALDO: %f", ptr->conta->saldo);
		printf("\n---------------------------");
		i++;
		
	}else{
		printf("FILA VAZIA!\n");
	}
}

void imprimeProximosFila(FilaClientes *f, Pilha *p){
	
	Pessoa *ptr = f->inicio->proximo;
	Pilha *aux = ptr->pilhaSolicitacoes->topo;
	
	if(ptr != NULL){
	
	int i=1;
	
	while(ptr!=NULL){
		
		printf("====================CLIENTES=======================\n\n");
		printf("--------------------FILA-%d------------------------\n", i);
		printf("------ NOME: %s ------------------\n", ptr->nome);
		printf("------- CPF: %d ------------------\n", ptr->cpf);
		printf("\n--------------------------------------------------\n");
		printf("==================SOLICITACOES======================\n\n");
		
		while(ptr->pilhaSolicitacoes->topo != NULL){
		
			if(ptr->pilhaSolicitacoes->topo->descricao == 1){
				printf("SOLICITACAO: (1) - CHECAR CARTAO DE CREDITO\n");
			}
			if(ptr->pilhaSolicitacoes->topo->descricao == 2){
				printf("SOLICITACAO: (2) - VERIFICAR SITUACAO DA CONTA\n");
			}
			if(ptr->pilhaSolicitacoes->topo->descricao == 3){
				printf("SOLICITACAO: (3) - VERIFICAR SALDO ATUAL\n");
			}
			if(ptr->pilhaSolicitacoes->topo->descricao == 4){
				printf("SOLICITACAO: (4) - DEPOSITAR\n");
			}
			if(ptr->pilhaSolicitacoes->topo->descricao == 5){
				printf("SOLICITACAO: (5) - SACAR\n");
			}
			
			ptr->pilhaSolicitacoes->topo = ptr->pilhaSolicitacoes->topo->proximo;
		}
		ptr->pilhaSolicitacoes->topo = aux;
		
		printf("\n------------CONTA----------\n");
		printf("\n-------TITULAR: %s", ptr->conta->titular);
		printf("\n-------AGENCIA: %d", ptr->conta->agencia);
		printf("\n-------NUMERO: %d", ptr->conta->numero);
		printf("\n-------GERENTE: %s", ptr->conta->gerente);
		printf("\n-------SALDO: %f", ptr->conta->saldo);
		printf("\n----------------------------\n\n");
		
		ptr = ptr->proximo;
		i++;
		}
	}else{
		printf("FILA VAZIA!\n");
	}
}

void imprimeFilaGerentes(FilaGerentes *f){
	
	Pessoa *ptr = f->inicio;
	
	if(ptr != NULL){
		int i=1;
		
		while(ptr != NULL){
			printf("-----------------FILA-%d-----------------\n", i);
			printf("------ NOME: %s ------------------\n", ptr->nome);
			printf("------- CPF: %d ------------------\n", ptr->cpf);
			printf("\n----------------------------------------\n");
			
			i++;
			ptr = ptr->proximo;
		}
	}else{
		printf("FILA VAZIA!\n");
	}
}

void imprimeFilaAtendentes(FilaAtendentes *f){
	Pessoa *ptr = f->inicio;
	if(ptr != NULL){
		int i=1;
		while(ptr != NULL){
			printf("-----------------FILA-%d-----------------\n", i);
			printf("------ NOME: %s ------------------\n", ptr->nome);
			printf("------- CPF: %d ------------------\n", ptr->cpf);
			printf("\n----------------------------------------\n");
			
			i++;
			ptr = ptr->proximo;
		}
	}else{
		printf("FILA VAZIA!\n");
	}
}

void remover(FilaClientes *f, Pilha *p);

void editar(FilaClientes *f, int cpf);
	void editarAtributos(Pessoa *ptr);


void main() {
	
	FilaClientes *filaClientes = (FilaClientes*) malloc(sizeof(FilaClientes));
	FilaAtendentes *filaAtendente = (FilaAtendentes*) malloc(sizeof(FilaAtendentes));
	FilaGerentes *filaGerente = (FilaGerentes*) malloc(sizeof(FilaGerentes));
	Pilha *p1 = (Pilha*) malloc(sizeof(Pilha));
	
setlocale(LC_ALL, "Portuguese");
	int opcao, existe = 0;
	char nome;
	int cpf;	
	
	if(filaClientes == NULL){
		printf("Erro de alocacao.\n");
		exit(0);
	}else{
		while(opcao!=11){
			printf("\t********************************************************\n");
			printf("\t******* [1] - INICIAR ATENDIMENTO **********************\n");
			printf("\t******* [2] - CADASTRAR GERENTE ************************\n");
			printf("\t******* [3] - CADASTRAR ATENDENTE **********************\n");
			printf("\t******* [4] - (CLIENTES) ENTRAR EM ULTIMO NA FILA ******\n");
			printf("\t******* [5] - ATENDER SOLICITACAO CLIENTE (REMOVER)*****\n");
			printf("\t******* [6] - VIZUALIZAR CLIENTE NA FILA ***************\n");
			printf("\t******* [7] - VIZUALIZAR CLIENTES ATUAIS NO ATENDIMENTO*\n");
			printf("\t******* [8] - STATUS CLIENTES EM ESPERA ****************\n");
			printf("\t******* [9] - VIZUALIZAR GERENTES **********************\n");
			printf("\t******* [10] - VIZUALIZAR ATENDENTES *******************\n");
			printf("\t******* [11] - EDITAR CLIENTE **************************\n");
			printf("\t********************************************************\n"); 
			printf("\nESCOLHA UMA DAS OPCOES ACIMA:");  
			scanf("%d", &opcao);
			getchar();
			
			switch(opcao){
				case 1:
					if(existe == 0){
						inicializarFila(filaClientes, filaGerente, filaAtendente, p1);
						system("cls");
						printf("INICIANDO O ATENDIMENTO...\n");
				        printf("ATENDIMENTO INICIADO!\n\n");
						existe = 1;
					}else{
						printf("A FILA JA EXISTE\n");
						system("pause");
						system("cls");
					}
					break;
				
				case 2:
					if(existe == 1){
						filaGerente = cadastrarGerente(filaGerente);
						system("cls");
					}else{
						printf("FILA VAZIA\n");
						system("pause");
						system("cls");
					}
					break;
					
				case 3:
					if(existe == 1){
						filaAtendente = cadastrarAtendentes(filaAtendente);
						system("cls");
					}else{
						printf("FILA VAZIA\n");
						system("pause");
						system("cls");
					}
					break;
				
				case 4:
					if(existe == 1){
						filaClientes = adicionarLista(filaClientes, filaAtendente, filaGerente, p1);
						system("cls");
					}else{
						printf("FILA VAZIA\n");
						system("pause");
						system("cls");
					}
					break;
				
				case 5:
					if(existe == 1){
						if(filaClientes==NULL){
							printf("FILA VAZIA\n");	
							system("pause");
							system("cls");
						}else{
							printf("CLIENTE ATENDIDO!\n");
							remover(filaClientes, p1);
							system("pause");
							system("cls");
						}
					}else{
						printf("FILA NAO INCIADA!\n");
					}
					break;
					
				case 6:
					if(existe == 1){
						if(filaClientes==NULL){
							printf("FILA VAZIA!\n");
							system("pause");
							system("cls");
						}
						else{
							imprimeFilaClientes(filaClientes, p1);
							system("pause");
							system("cls");
						}
					}else{
						printf("FILA NAO INCIADA!\n");
						system("pause");
						system("cls");
					}
					break;
					
				case 7:
					if(existe == 1){
						if(filaClientes==NULL){
							printf("FILA VAZIA!\n");
							system("pause");
							system("cls");
						}
						else{
							imprimeClienteAtual(filaClientes, p1);
							system("pause");
							system("cls");
						}
					}else{
						printf("FILA NAO INCIADA!\n");
						system("pause");
						system("cls");
					}
					break;
					
				case 8:
					if(existe == 1){
						if(filaClientes==NULL){
							printf("FILA VAZIA!\n");
							system("pause");
							system("cls");
						}
						else{
							imprimeProximosFila(filaClientes, p1);
							system("pause");
							system("cls");
						}
					}else{
						printf("FILA NAO INCIADA!\n");
						system("pause");
						system("cls");
					}
					break;
					
				case 9:
					if(existe == 1){
						if(filaAtendente==NULL){
							printf("FILA VAZIA!\n");
							system("pause");
							system("cls");
						}
						else{
							imprimeFilaGerentes(filaGerente);
							system("pause");
							system("cls");
						}
					}else{
						printf("FILA NAO INCIADA!\n");
						system("pause");
						system("cls");
					}
					break;
					
				case 10:
					if(existe == 1){
						if(filaGerente==NULL){
							printf("FILA VAZIA!\n");
							system("pause");
							system("cls");
						}
						else{
							imprimeFilaAtendentes(filaAtendente);
							system("pause");
							system("cls");
						}
					}else{
						printf("FILA NAO INCIADA!\n");
						system("pause");
						system("cls");
					}
					break;
					
				case 11:
					if(existe == 1){
						if(filaClientes==NULL){
							printf("FILA VAZIA\n");	
							system("pause");
							system("cls");
						}else{
							printf("DIGITE O CPF DA PESSOA QUE DESEJA EDITAR: ");
							scanf("%d", &cpf);
							editar(filaClientes, cpf);
							system("pause");
							system("cls");
						}
					}else{
						printf("FILA NAO INCIADA!\n");
					}
					break;
					
				default:
						system("cls");
						printf("\n\t --------------- OPCAO INVALIDA! ---------------\n");
						printf("\tVOCE NAO ESTA DIGITANDO UMA DAS OPCOES ABAIXO!\n"); 	
						printf("\t-------------------------------------------------\n\n");
			}
		}
	}
}


void inicializarPilha(Pilha *p){
	p->topo = NULL;
}

void inicializarFila(FilaClientes *f, FilaGerentes *fg, FilaAtendentes *fa, Pilha *p){
	f->inicio= NULL;
	f->fim = NULL;
		fg->inicio = NULL;
		fg->fim = NULL;
			fa->inicio = NULL;
			fa->fim = NULL;
}

Pilha* adicionarSolicitacao(Pilha *p){
	
	Solicitacao *novaSolicitacao = (Solicitacao*) malloc(sizeof(Solicitacao));
	
	int opcao;
	
	if(novaSolicitacao == NULL){
		printf("ERRO DE ALOCACAO.\n");
	}else{
		enum menu{CHECAR=1, 
					VERIFICARCONTA, 
					SALDO, 
					DEPOSITAR, 
					SACAR};
		
		printf("INFORME: QUAL A SUA SOLICITACAO?\n");
		printf("\t-------1 - CHECAR CARTAO DE CREDITO ------\n");
		printf("\t-------2 - VERIFICAR SITUAÇÃO DA CONTA ---\n");
		printf("\t-------3 - VERIFICAR SALDO ATUAL ---------\n");
		printf("\t-------4 - DEPOSITAR ---------------------\n");
		printf("\t-------5 - SACAR -------------------------\n");
		scanf("%d", &opcao);
		
		novaSolicitacao->descricao = opcao;
		novaSolicitacao->proximo = p->topo;
						p->topo = novaSolicitacao;
	}
	return p;
}

FilaGerentes* cadastrarGerente(FilaGerentes *f){
	
	Pessoa *novoGerente = (Pessoa*) malloc(sizeof(Pessoa));
	
	if(novoGerente == NULL){
		printf("ERRO DE ALOCAÇÃO.\n");
	}else{
		strcpy(novoGerente->tipoPessoa, "GERENTE");
		
		printf("INFORME O SEU NOME: ");
		fgets(novoGerente->nome, sizeof(novoGerente->nome), stdin);
		
		printf("\nDIGITE O CPF: ");
		scanf("%d", &novoGerente->cpf);
		
		novoGerente->conta = NULL;
		novoGerente->proximo = NULL;
		
		if(f->inicio == NULL){
			f->inicio = novoGerente;
		}else{
			f->fim->proximo = novoGerente;
		}
		f->fim = novoGerente;		
	}
	return f;
}

FilaAtendentes* cadastrarAtendentes(FilaAtendentes *f){
	
	Pessoa *novoAtendente = (Pessoa*) malloc(sizeof(Pessoa));
	
	if(novoAtendente == NULL){
		printf("ERRO DE ALOCAÇÃO.\n");
	}else{
		strcpy(novoAtendente->tipoPessoa, "ATENDENTE");
		
		printf("INFORME O SEU NOME: ");
		fgets(novoAtendente->nome, sizeof(novoAtendente->nome), stdin);
		
		printf("\nDIGITE O CPF: ");
		scanf("%d", &novoAtendente->cpf);
		
		novoAtendente->conta = NULL;
		novoAtendente->proximo = NULL;
		
		if(f->inicio == NULL){
			f->inicio = novoAtendente;
		}else{
			f->fim->proximo = novoAtendente;
		}
		f->fim = novoAtendente;
	}
	return f;
}

FilaClientes* adicionarLista(FilaClientes *f, FilaAtendentes *fa, FilaGerentes *fg, Pilha *p){
	
	Pessoa *novaPessoa = (Pessoa*) malloc(sizeof(Pessoa));
	Conta *novaConta = (Conta*) malloc(sizeof(Conta));
	Solicitacao *novaSolicitacao = (Solicitacao*) malloc(sizeof(Solicitacao));
	Pilha *novaPilha = (Pilha*) malloc(sizeof(Pilha));
	
	int opcao, numeroConta;
	
	if(novaPessoa == NULL || novaConta == NULL){
		printf("ERRO DE ALOCAÇÃO.\n");
	}else{
		if(fg->inicio == NULL){
			printf("NECESSARIO CADASTRAR UM GERENTE PRIMEIRO\n");
			system("pause");
		}
		if(fa->inicio == NULL){
			printf("NECESSARIO CADASTRAR UM ATENDENTE PRIMEIRO\n");
			system("pause");
		}else{
			
			strcpy(novaPessoa->tipoPessoa, "CLIENTE");
			
			printf("INFORME O SEU NOME: ");
			fgets(novaPessoa->nome, sizeof(novaPessoa->nome), stdin);
			
			printf("\nDIGITE O CPF: ");
			scanf("%d", &novaPessoa->cpf);
			
			printf("INICIANDO ABERTURA DE CONTA");
			Sleep(200);
	        printf(".");
	        Sleep(200);
	        printf("..");
	        Sleep(200);
	        printf("...");
	        Sleep(200);
	        printf("\nCONTA ABERTA COM SUCESSO\n\n");
	        
	        strcpy(novaConta->titular, novaPessoa->nome);
			strcpy(novaConta->gerente, fg->inicio->nome);
			
			agencia++;
			novaConta->agencia = agencia;
			
			numeroConta++;
			novaConta->numero = numeroConta;
			
			novaConta->saldo = 0.0;
			novaPessoa->conta = novaConta;
	
			inicializarPilha(novaPilha);
			
			do{
				novaPilha = adicionarSolicitacao(novaPilha);
				printf("DESEJA ADICIONAR OUTRA SOLICITACAO?\n");
				printf("DIGITE: (1) - PARA CONTINUAR");
				printf("\n--------------------------\n");
				printf("DIGITE: (0) - PARA SAIR");
				scanf("%d", &opcao);				
			}while(opcao==1 && opcao != 0);
			
			novaPessoa->pilhaSolicitacoes = novaPilha;
			novaPessoa->proximo = NULL;
			
			if(f->inicio == NULL){
				f->inicio = novaPessoa;
			}else{
				f->fim->proximo = novaPessoa;
			}
			f->fim = novaPessoa;
		}
	}
	return f;
}



void remover(FilaClientes *f, Pilha *p){
	
	Pessoa *ptr = f->inicio;
	Solicitacao *ptrp = f->inicio->pilhaSolicitacoes->topo;
	
	if(f->inicio->pilhaSolicitacoes->topo != NULL){
		if(f->inicio->pilhaSolicitacoes->topo->descricao == 1){
			printf("TUDO OK COM CARTAO DE CREDITO\n");
		}
		if(f->inicio->pilhaSolicitacoes->topo->descricao == 2){
			printf("CONTA ATIVA\n");
		}
		if(f->inicio->pilhaSolicitacoes->topo->descricao == 3){
			printf("SEU SALDO ATUAL EH DE: R$ XX\n");
		}
		if(f->inicio->pilhaSolicitacoes->topo->descricao == 4){
			printf("DEPOSITO EFETUADO COM SUCESSO\n");
		}
		if(f->inicio->pilhaSolicitacoes->topo->descricao == 5){
			printf("SAQUE EFETUADO COM SUCESSO\n");
		}
		
		f->inicio->pilhaSolicitacoes->topo = ptrp->proximo;
		ptrp->proximo = NULL;
		free(ptrp);
		
		if(ptrp == NULL){
			
			f->inicio = f->inicio->proximo;
			f->inicio->proximo = NULL;
			free(f->inicio);
			
			printf("CLIENTE ATENDIDO COM SUCESSO!");
			
			if(f->inicio == NULL){
				f->fim = NULL;}
		}
	}else{
		printf("FILA VAZIAZ\n");
		return;
	}
}
				

void editar(FilaClientes *f, int cpf){
	
	Pessoa *ptr = f->inicio;
	
	if(ptr != NULL){
		while(ptr != NULL){
			if(ptr->cpf == cpf){
				printf("NOME: %s", ptr->nome);
				editarAtributos(ptr);
				printf("NOVO NOME: %s", ptr->nome);
				break;
			}		
			
			ptr = ptr->proximo;
		}
	}else{
		printf("FILA VAZIA!\n");
	}
}

void editarAtributos(Pessoa *ptr){
	int aux = 9;
	
	while(aux!=0){
	
	printf("\nQUAL INFORMACAO DA PESSOA VOCE DESEJA EDITAR?");
	printf("\n-------------------------------------------\n");
	printf("--- (1)-Nome ------------\n");
	printf("--- (2)-CPF -------------\n");
	printf("--- (3)-NOME DO GERENTE -\n");
	printf("--- (4)-AGENCIA ---------\n");
	printf("--- (5)-NUMERO DA CONTA -\n");
	printf("--- (6)-SALDO DA CONTA --\n");
	printf("--- (0)-SAIR ------------\n");
	scanf ("%d", &aux); 
	getchar();
	
		switch (aux){
			
			case 1: 
				system("cls");
				printf("\nDIGITE A NOVA PESSOA: ");
				printf("\n-----------------------\n");
				fgets(ptr->nome, sizeof(ptr->nome), stdin);
				printf(" -- O NOME FOI EDITADO! --");
				break;
				
			case 2: 
				system("cls");
				printf("\nDIGITE O NOVO CPF DA PESSOA: ");
				printf("\n------------------------------\n");
				scanf("%d", &ptr->cpf);
				printf(" -- O CPF FOI EDITADO! -- ");
				break;
				
			case 3: 
				system("cls");
				printf("\nDIGITE O NOVO GERENTE: ");
				printf("\n------------------------\n");
				fgets(ptr->conta->gerente, sizeof(ptr->conta->gerente), stdin);
				getchar();
				printf(" - O GERENTE FOI EDITADO! - ");
				break;
				
			case 4: 
				system("cls");
				printf("\nDIGITE A NOVA AGENCIA: ");
				printf("\n-----------------------\n");
				scanf("%d", &ptr->conta->agencia);
				printf(" - A AGENCIA FOI EDITADO! - ");
				break;
				
			case 5: 
				system("cls");
				printf("\nDIGITE O NOVO NUMERO DA CONTA: ");
				printf("\n--------------------------------\n");
				scanf("%d", &ptr->conta->numero);
				printf(" - O NUMERO DA CONTA FOI EDITADO! - ");
				break; 
				
			case 6: 
				system("cls");
				printf("\nDIGITE O NOVO SALDO DA CONTA: ");
				printf("\n-------------------------------\n");
				scanf("%f", &ptr->conta->saldo);
				printf(" - O SALDO DA CONTA FOI EDITADO! - ");
				break;	
				
			default:
				system("cls");
				printf("\n\t --------------- OPCAO INVALIDA! ---------------\n");
				printf("\tVOCE NAO ESTA DIGITANDO UMA DAS OPCOES DO MENU!\n"); 	
				printf("\t-------------------------------------------------\n\n");
			}
		}  
}