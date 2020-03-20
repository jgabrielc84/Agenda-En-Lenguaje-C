#ifndef CONSOLE_H_INCLUDED
#define CONSOLE_H_INCLUDED

#include <windows.h>
#include <unistd.h>
#include "file.h"
#include "agenda.h"


typedef enum{SALIR, AGREGAR, BUSCAR, LISTAR}ENUM_OPCION;


void openConsole(ST_NODE_AGENDA **, ENUM_BOOLEAN *);


#endif // CONSOLE_H_INCLUDED
