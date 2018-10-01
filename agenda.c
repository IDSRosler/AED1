/* Fazer uma lista para armazenar dados em um Buffer. */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void *pBuffer;

typedef struct nom{
    char pessoa[20];
}nome;

typedef struct var{
	int op,i,j,cont,a;
	nome atual;
}variavel;

void incluir(variavel *inicio);
void apagar(variavel *inicio);
void buscar(variavel *inicio);
void listar(variavel *inicio);
void insertionSort(variavel *inicio);

int main(void)
{
    variavel *inicio; 

    if((pBuffer = (variavel *)malloc(sizeof(variavel)))== NULL){
        printf("Memória insufuciente!");
        exit(1);
    }
    inicio = pBuffer;
    inicio->cont = 0;
    inicio->a = 0;

    do{
        printf("[ 1 ] INCLUIR\n[ 2 ] APAGAR\n[ 3 ] BUSCAR\n[ 4 ] LISTAR\nEscolha: ");
        scanf("%d",&inicio->op);
       	printf("\n");

        switch (inicio->op){
            case 1:
				incluir(inicio);
            break;
            case 2:
                apagar(inicio);
            break;
            case 3:
                buscar(inicio);
            break;
            case 4:
                listar(inicio);
            break;
            default:
				free(pBuffer);
                exit(1);
            }
        }while(1);

    return 0;
}
void incluir(variavel *inicio){
	nome *pessoa;
	
	if((pBuffer = (nome *)realloc(pBuffer,sizeof(variavel) + sizeof(nome) + (inicio->cont * sizeof(nome))))== NULL){
		printf("Memória insufuciente!");
        exit(1);
	}
	pessoa = pBuffer + sizeof(variavel) + (inicio->cont * sizeof(nome)) ;
	
	printf("Digite o nome: ");
	scanf("%s",pessoa->pessoa);
	
	inicio->cont++;
	
	insertionSort(inicio);
}

void apagar(variavel *inicio){
	if(inicio->cont > 0){
		if((pBuffer = realloc(pBuffer,sizeof(variavel) + (((inicio->cont-1) * sizeof(nome)))))== NULL){
			printf("Memória insufuciente!");
			exit(1);
		}
		inicio->cont--;
	}
	else{
		printf("Não há nomes na lista para remover!\n");
	}
}

void buscar(variavel *inicio){
	nome *buscar,*pessoa;
	pessoa = pBuffer + sizeof(variavel);
	if((buscar = (nome *)calloc(1,sizeof(nome)))== NULL){
		printf("Memória insufuciente!");
        exit(1);
	}
	printf("Digite o nome a ser pesquisado: ");
	scanf("%s",buscar->pessoa);
	printf("\n");
	for(inicio->i = 0; inicio->i < inicio->cont; inicio->i++){
		if((strcmp(buscar->pessoa,pessoa->pessoa))== 0){
			printf("%s\n",pessoa->pessoa);
			pessoa++;
			inicio->a++;
		}
		else 
			pessoa++;
	}
	if(inicio->a == 0){
		printf("O nome nao foi encontrado na agenda.\n");
		}
	printf("\n");
	inicio->a = 0;
	free(buscar);
}

void listar(variavel *inicio){
	nome *pessoa;
	pessoa = pBuffer + sizeof(variavel);
	for(inicio->i = 0; inicio->i < inicio->cont; inicio->i++){
		printf("%s\n",pessoa->pessoa);
		pessoa++;
		}
	printf("\n");
}
void insertionSort(variavel *inicio){
	nome *dado;
	dado = pBuffer + sizeof(variavel);
	if(inicio->cont > 1){
		for (inicio->i = 1; inicio->i < inicio->cont; inicio->i++) {
			strcpy(inicio->atual.pessoa,dado[inicio->i].pessoa);
			for (inicio->j = inicio->i - 1; (inicio->j >= 0) && (strcmp(dado[inicio->j].pessoa,inicio->atual.pessoa) == 1); inicio->j--) {
				strcpy(dado[inicio->j + 1].pessoa,dado[inicio->j].pessoa);
				printf("teste\n");
			}
			strcpy(dado[inicio->j+1].pessoa,inicio->atual.pessoa);
			printf("teste1\n");
		}
	}
}
