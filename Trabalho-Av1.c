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


int agencia = 164874;
int numeroConta = 1;

void inicializarPilha(Pilha *p);
void inicializarFila(FilaClientes *f, FilaGerentes *fg, FilaAtendentes *fa, Pilha *p);
Pilha* adicionarSolicitacao(Pilha *p);

FilaGerentes* cadastrarGerente(FilaGerentes *f);
FilaAtendentes* cadastrarAtendentes(FilaAtendentes *f);
FilaClientes* adicionarLista(FilaClientes *f, FilaAtendentes *fa, FilaGerentes *fg, Pilha *p);



void remover(FilaClientes *f, Pilha *p);

void editar(FilaClientes *f, int cpf);
	void editarAtributos(Pessoa *ptr);


void main() {
	
	FilaClientes *filaClientes = (FilaClientes*) malloc(sizeof(FilaClientes));
	FilaAtendentes *filaAtendente = (FilaAtendentes*) malloc(sizeof(FilaAtendentes));
	FilaGerentes *filaGerente = (FilaGerentes*) malloc(sizeof(FilaGerentes));
	Pilha *p1 = (Pilha*) malloc(sizeof(Pilha));
	
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

}				
