/* Fazer uma lista para armazenar dados em um Buffer. */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*typedef struct nom{
    char pessoa=[20];
}nome;*/

void incluir();
void apagar();
void buscar();
void listar();

int main(void)
{
    void *pBuffer;
    int *op;
   // nome *pessoa;

    if((pBuffer = (int *)malloc(1 * sizeof(int)))== NULL){
        printf("Memória inssufuciente!");
        exit(1);
    }
    op = pBuffer;

    do{
        printf("[ 1 ] INCLUIR\n [ 2 ] APAGAR\n [ 3 ] BUSCAR\n [ 4 ] LISTAR");
        scanf("%d",op);

        switch (*op){
            case 1:
                incluir();
            break;
            case 2:
                apagar();
            break;
            case 3:
                buscar();
            break;
            case 4:
                listar();
            break;
            default:
                exit(1);
            }
        }while(1);

    return 0;
}
void incluir(void** pBuffer,int** op){
    char* nome;
    int *tam;

    if((nome = (char *)malloc(20 * sizeof(char)))== NULL){
        printf("Memória insuficiente!");
        exit(1);
    }
    if((tam = (int *)malloc(sizeof(int)))== NULL){
        printf("Memória insuficiente!");
        exit(1);
    }
    printf("Digite o nome: ");
    scanf("%s",nome);

    *tam = strlen(nome);

     if((nome = (char *)realloc(nome,(*tam) * sizeof(char)))== NULL){
        printf("Memória insuficiente!");
        exit(1);
    }
    free(tam);

}

void apagar(){
}
void buscar(){
}
void listar(){
}
