#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    char conteudo;
    struct no *esquerda, *direita;
}No;

No* inserirNovaVersao(No *raiz, char *valor){
    char esq[10], dir[10];
    int incre = 0;

    int tam = quantidade(valor);

    for(int i=tam; i > -1; i--){
           if(valor[i] == '+' || valor[i] == '-'){
                if(raiz == NULL){
                    No *novo = (No*)malloc(sizeof(No));
                    novo->conteudo = valor[i];
                    novo->esquerda = NULL;
                    novo->direita = NULL;

                    for(int j=i+1; j < 10; j++){
                        if(valor[j]!='\0'){
                            dir[incre]=valor[j];
                            incre++;
                        }
                    }

                    for(int j=i-1; j > -1; j--){
                        esq[j]=valor[j];
                    }

                    raiz->direita = inserirNovaVersao(raiz->direita, dir);
                    raiz->esquerda = inserirNovaVersao(raiz->esquerda, esq);

                    return raiz;
                }


            }else if(valor[i] == '*' || valor[i] == '/'){
                if(raiz == NULL){
                    No *novo = (No*)malloc(sizeof(No));
                    novo->conteudo = valor[i];
                    novo->esquerda = NULL;
                    novo->direita = NULL;

                    for(int j=i+1; j < 10; j++){
                        if(valor[j]!='\0'){
                            dir[incre]=valor[j];
                            incre++;
                        }
                    }

                    for(int j=i-1; j > -1; j--){
                        esq[j]=valor[j];
                    }

                    raiz->direita = inserirNovaVersao(raiz->direita, dir);
                    raiz->esquerda = inserirNovaVersao(raiz->esquerda, esq);

                    return raiz;
                }
            }
    }

    return raiz;

}

int quantidade(char *vet){
    int cont;

    for(int i=0; i<10;i++){
        if(vet[i] == '\0'){
            break;
        }
        cont++;
    }

    return cont;
}

void imprimir (No *raiz){
    if(raiz != NULL){
        imprimir(raiz->esquerda);
        printf("%c", raiz->conteudo);
        imprimir(raiz->direita);
    }
}

int main()
{
    char expressao[20] = "2+3*5-4/2";
    int cont=0;
    No *raiz = NULL;


    inserirNovaVersao(raiz, expressao);
    imprimir(raiz);

    return 0;
}



//int getLevelCount(No *node)
//{
//    if (node == NULL)
//    {
//        return 0;
//    }
//    int leftMaxLevel = 1 + getLevelCount(node->esquerda);
//    int rightMaxLevel = 1 + getLevelCount(node->direita);
//    if (leftMaxLevel > rightMaxLevel)
//    {
//        return leftMaxLevel;
//    }
//    else
//    {
//        return rightMaxLevel;
//    }
//}
//
//void printLevel(No *node, int level)
//{
//    if (node != NULL && level == 0)
//    {
//        printf("   %c\n", node->conteudo);
//    }
//    else if (node != NULL)
//    {
//        printLevel(node->esquerda, level - 1);
//        printLevel(node->direita, level - 1);
//    }
//}
//
//
//void printElements(No *node)
//{
//    int i;
//    int levelCount = getLevelCount(node);
//    for (i = 0; i < levelCount; i++)
//    {
//        printLevel(node, i);
//    }
//}
//
//void treeprint(No *root, int level)
//{
//        if (root == NULL)
//                return;
//        for (int i = 0; i < level; i++)
//                printf(i == level - 1 ? "|" : "  ");
//        printf("%c\n", root->conteudo);
//        treeprint(root->esquerda, level + 1);
//        treeprint(root->direita, level + 1);
//}
