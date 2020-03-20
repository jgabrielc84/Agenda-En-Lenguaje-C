#ifndef AGENDA_H_INCLUDED
#define AGENDA_H_INCLUDED

#include "file.h"

#define LENGHT_NAME 30
#define LENGHT_DIRECTION 30
#define LENGHT_TELEPHONE 30


typedef struct{
    //int idContact; AGREGAR para llevar control
    char name[LENGHT_NAME+1];
    char direction[LENGHT_DIRECTION+1];
    char telephone[LENGHT_TELEPHONE+1];
}ST_CONTACT;

typedef struct nodeAgenda{
    ST_CONTACT contact;
    struct nodeAgenda * ste;
}ST_NODE_AGENDA;


void chargeListAgenda(ST_NODE_AGENDA **);

void addToList(ST_NODE_AGENDA **);

void printContactList(ST_NODE_AGENDA **);


#endif // AGENDA_H_INCLUDED
