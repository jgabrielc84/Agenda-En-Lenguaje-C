#include "agenda.h"

ST_NODE_AGENDA * createNodeAgenda(ST_CONTACT * contact){
    ST_NODE_AGENDA * node = malloc(sizeof(ST_NODE_AGENDA));

    strcpy(node->contact.name, contact->name);
    strcpy(node->contact.direction, contact->direction);
    strcpy(node->contact.telephone, contact->telephone);

    node->ste = NULL;

    return node;
}

ST_NODE_AGENDA * addListAgenda(ST_NODE_AGENDA ** list, ST_CONTACT * contact){
    ST_NODE_AGENDA * node = createNodeAgenda(contact);
    ST_NODE_AGENDA * listAux = *list;

    while(listAux != NULL && listAux->ste != NULL){
        listAux = listAux->ste;
    }

    if(listAux == NULL){
        *list = node;
    }else{
        listAux->ste = node;
    }

    return node;
}


void chargeListAgenda(ST_NODE_AGENDA ** list){
    FILE * archivo = openFile("agenda.dat", "rb");
    ST_CONTACT contact;

    fread(&contact, sizeof(ST_CONTACT), 1, archivo);

    while(!feof(archivo)){
        addListAgenda(list, &contact);

        fread(&contact, sizeof(ST_CONTACT), 1, archivo);
    }

    fclose(archivo);

    if(*list != NULL){
        printf("\nLista cargada!\n");//cargo los datos del archivo
    }else{
        printf("\nLista vacia!\n"); //el archivo estaba vacio
    }
}

ST_CONTACT getContactInfo(){
    ST_CONTACT contact;
    char * linea = malloc(sizeof(char)*(LENGHT_DIRECTION+1));

    fflush(stdin);
    memset(linea, '\0', (LENGHT_DIRECTION+1));
    printf("Ingresar nombre: ");
    strcpy(contact.name, gets(linea));
    memset(linea, '\0', (LENGHT_DIRECTION+1));
    printf("Ingresar direccion: ");
    strcpy(contact.direction, gets(linea));
    memset(linea, '\0', (LENGHT_DIRECTION+1));
    printf("Ingresar telefono: ");
    strcpy(contact.telephone, gets(linea));

    return contact;
}

void addToList(ST_NODE_AGENDA ** list){
    ST_CONTACT contact = getContactInfo();

    //revisar si el contacto ya existe

    addListAgenda(list, &contact);
}

void printContact(ST_CONTACT contact){
    printf("\nNombre: %s\n", contact.name);
    printf("Direccion: %s\n", contact.direction);
    printf("Telefono: %s\n", contact.telephone);
    printf("\n-----------------\n");
}

void printContactList(ST_NODE_AGENDA ** list){
    ST_NODE_AGENDA * listAux = *list;

    while(listAux){
        printContact(listAux->contact);

        listAux = listAux->ste;
    }

    system("PAUSE()");
}
