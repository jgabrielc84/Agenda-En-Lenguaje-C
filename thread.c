#include "thread.h"

void * preventiveSave(ST_NODE_AGENDA ** list){
    FILE * file = openFile("porlas.dat", "rb+");

    //levantar archivo

    while(1){

        //ir actualizando porlas.dat por si se corta la ejecucion

        Sleep(5000);
    }
}
