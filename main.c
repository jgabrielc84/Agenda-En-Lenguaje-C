#include <pthread.h>

#include "thread.h"
#include "file.h"
#include "console.h"
#include "agenda.h"

ENUM_BOOLEAN isEnd = false;

int main(){
    ST_NODE_AGENDA * list = NULL;
    pthread_t threadPreventSave;

    chargeListAgenda(&list);

    pthread_create(&threadPreventSave, NULL, (void *)preventiveSave, &list);

    Sleep(1000);

    openConsole(&list, &isEnd);

    Sleep(1000);

    pthread_exit(NULL);

    free(list);

    return 0;
}
