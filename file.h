#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"

typedef enum{
    false,
    true
}ENUM_BOOLEAN;


FILE * openFile(const char *, const char *);

void saveToFile();


#endif // FILE_H_INCLUDED
