#include "dbOutput.h"


void printMainMenu() {
    printf("==============================\n"
    "0 : CHOOSE TABLE\n"
    "1 : SHOW TABLE\n"
    "-1: EXIT\n"
    "==============================\n");
}

void printModulesMenu() {
    printf("=================================\n"
        "0 : SHOW MODULES\n"
        "1 : ADD MODULE\n"
        "2 : INSERT MODULE\n"
        "3 : UPDATE MODULE\n"
        "4 : DELETE MODULE\n\n"
        "-1: BACK\n"
        "=================================\n");
}

void printLevelsMenu() {
    printf("=================================\n"
        "0 : SHOW LEVELS\n"
        "1 : ADD LEVEL\n"
        "2 : INSERT LEVEL\n"
        "3 : UPDATE LEVEL\n"
        "4 : DELETE LEVEL\n\n"
        "-1: BACK\n"
        "=================================\n");
}


int printModules(FILE* file) {
    int isErr = 0;
    struct modules rec;
    if (file == NULL) {
        isErr = 1;
    } else {
        printf("MODULES\n");
        fread(&rec, sizeof(struct modules), 1, file);
        while(!feof(file)) {
            printf("%d %s %d %d %d\n", rec.id, rec.name, rec.level, rec.cell, rec.flag);   
            fread(&rec, sizeof(struct modules), 1, file);
        }
    }
    return isErr;
}

int printLevels(FILE* file) {
    int is_error = 0;
    struct levels rec;
    if (file == NULL) {
        is_error = 1;
    } else {
        printf("LEVELS\n");
        fread(&rec, sizeof(struct levels), 1, file);
        while(!feof(file)) {
            printf("%d %d %d\n", rec.level, rec.cells, rec.flag);   
            fread(&rec, sizeof(struct levels), 1, file);
        }
    }
    return is_error;
}

int printEvents(FILE* file) {  // OUTPUT
    int is_error = 0;
    struct status_events rec;
    if (file == NULL) {
        is_error = 1;
    } else {
        fread(&rec, sizeof(struct status_events), 1, file);
        while(!feof(file)) {
            printf("%d %d %d %s %s\n", rec.eventId, rec.moduleId, rec.newModuleStatus, rec.date, rec.time);   
            fread(&rec, sizeof(struct status_events), 1, file);
        }
    }
    return is_error;
}


int showTables() {
    int isErr = 0;
    FILE* mf = fopen(modulesPath, "rb");
    FILE* lf = fopen(levelsPath, "rb");
    FILE* ef = fopen(eventsPath, "rb");
    if ((mf == NULL) || (lf == NULL) || (ef == NULL)) {
        isErr = 1;
    } else {
        printf("=======================\n");
        printf("MODULES\n");
        printf("=======================\n");
        printModules(mf);
        printf("=======================\n");
        printf("LEVELS\n");
        printf("=======================\n");
        printLevels(lf);
        printf("=======================\n");
        printf("STATUS_EVENTS\n");
        printf("=======================\n");
        printEvents(ef);
    }
    fclose(mf);
    fclose(lf);
    fclose(mf);
    return isErr;
}