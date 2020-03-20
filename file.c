#include "file.h"

FILE * openFile(const char * name, const char * mode){//si no puede abrir el archivo lo crea
    FILE * file = NULL;

    if((file = fopen(name, mode)) == NULL){
        perror("Error open file...\n");

        file = openFile(name, "wb+");
    }

    return file;
}

void saveToFile(ST_NODE_AGENDA ** list){
    FILE * file = openFile("agenda.dat", "wb+");
    ST_NODE_AGENDA * listAux = *list;

    while(listAux){
        fwrite(&listAux->contact, sizeof(ST_CONTACT), 1, file);

        listAux = listAux->ste;
    }
}
