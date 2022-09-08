#ifndef SHARED_H
#define SHARED_H

#include "dbOutput.h"
#include "dbInput.h"
#include "modules.h"
#include "levels.h"

#define modulesPath "../materials/master_modules.db"
#define levelsPath "../materials/master_levels.db"
#define eventsPath "../materials/master_status_events.db"

struct modules {
    int id;
    char name[30];
    int level;
    int cell;
    int flag;   
};

struct levels {
    int level;
    int cells;
    int flag;
};

struct status_events {
    int eventId;
    int moduleId;
    int newModuleStatus;
    char date[11];
    char time[9];
};


int modules();
int levels();

#endif  //  SHARED_H