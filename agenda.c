/* Fazer uma lista para armazenar dados em um Buffer. */

#include<stdio.h>
#include<stdlib.h>

typedef struct nom{
    char pessoa[20];
}nome;

void incluir();
void apagar();
void buscar();
void listar();

int main(void)
{
    void *pBuffer;
    int *op;

    if((pBuffer = (int *)malloc(1 * sizeof(int)))== NULL){
        printf("Memória inssufuciente!");
        exit(1);
    }
    op = pBuffer;

    printf("[ 1 ] INCLUIR\n [ 2 ] APAGAR\n [ 3 ] BUSCAR\n [ 4 ] LISTAR");

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
    }

    return 0;
}
void incluir(){
}
void apagar(){
}
void buscar(){
}
void listar(){
}
