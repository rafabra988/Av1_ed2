#include <stdio.h>
#include <stdlib.h>

typedef struct genealogica{
    char name[10];
    struct genealogica *esquerda, *direita;
}Ag;

Ag* inserir(Ag* array, char *name){
    int confir;
    char pai[10], mae[10];

    if(array==NULL){
        Ag *novo = (Ag*)malloc(sizeof(Ag));
        strcpy(novo->name, name);
        novo->esquerda = NULL;
        novo->direita = NULL;
    }

    do{
        printf("gostarias de continuar inserindo(1 para sim/0 para nao)?\n");
        scanf("%d",&confir);

        switch (confir){

        case 0:
            break;
        case 1:
            printf("digite o nome do pai\n");
            scanf("%s",pai);

            printf("digite o nome da mae\n");
            scanf("%s",mae);

            array->esquerda=inserir(array->esquerda, mae);
            array->direita=inserir(array->direita, pai);
            break;
        default:
            printf("\tleia com atencao\n\n");
            printf("\tleia com atencao\n\n");
        }

    }while(confir != 0);

    return array;

}

int main()
{
    char nome[10];
    Ag *raiz=NULL;

    printf("digite o nome do filho\n");
    scanf("%s",&nome);

    inserir(raiz,nome);

    return 0;
}
