#include "console.h"


void printMainMenu(){
    printf("*MENU PRINCIPAL*\n\n");
    printf("\t1. Agregar\n");
    printf("\t2. Buscar\n");
    printf("\t3. Listar\n");
    printf("\t0. Salir\n");
    printf("\n\t\tOpcion:");
}

void openConsole(ST_NODE_AGENDA ** list, ENUM_BOOLEAN * isEnd){
    int option = -1;

    while(option != SALIR && option != AGREGAR && option != BUSCAR && option != LISTAR){
        system("CLS()");
        printMainMenu();
        scanf("%d", &option);

        switch(option){
            case SALIR:
                system("CLS");
                saveToFile();
                isEnd = true;
                printf("\nQue tenga un buen dia!!\n\n");
                Sleep(2000);
                break;
            case AGREGAR:
                system("CLS");
                printf("*AGREAGAR CONTACTO*\n\n");
                addToList(list);
                option = -1;
                break;
            case BUSCAR:
                system("CLS");
                printf("*BUSCAR CONTACTO*\n\n");
                option = -1;
                break;
            case LISTAR:
                system("CLS");
                printf("*LISTAR CONTACTOS*\n\n");
                printContactList(list);
                option = -1;
                break;
            default:
                printf("Te equivocaste de opcion!!\n\n");
                Sleep(2000);
                break;
        }
        //system("PAUSE");
        system("cls");
    }
}
