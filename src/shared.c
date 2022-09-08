#include "shared.h"

int modules() {
    int flag = 0, choose, id, isErr = 0;
    struct modules records;
    FILE * file = fopen(modulesPath, "r+b");
    while (!flag) {
        printModulesMenu();
        choose = get_chooseStd(-1, 4);
        if (choose == 0) {
            printModules(file);
        } else if (choose == 1) {
            id = getPrevId(file);
            records = getModRec(id+1);
            isErr = addModRec(file, records);
        } else if (choose == 2) {
            printf("Please, select a module by id:\n");
            id = get_chooseStd(-9999999, 9999999);
            if (checkId(file, id)) {
                records = getModRec(id);
                isErr = insertModRec(file, id, records);
                printModules(file);
            } else {
                printf("n/a\n");
            }
        } else if (choose == 3) {
            printf("Please, select a module by id:\n");
            id = get_chooseStd(-9999999, 9999999);
            if (checkId(file, id)) {
                records = getModRec(id);
                isErr = changeModRec(file, id, records);
                printModules(file);
            } else {
                printf("n/a\n");
            }
        } else if (choose == 4) {
            printf("Please, select a module by id:\n");
            id = get_chooseStd(-9999999, 9999999);
            if (checkId(file, id)) {
                delModRec(file, id);
                printModules(file);
            } else {
                printf("n/a\n");
            }
        } else if (choose == -1) {
            flag = 1;
        }
        if (isErr) {
            flag = 1;
        }
    }
    return isErr;
}


int levels() {
    int flag = 0, choose, level, isErr = 0;
    struct levels records;
    FILE * file = fopen(levelsPath, "r+b");
    while (!flag) {
        printLevelsMenu();
        choose = get_chooseStd(-1,4);
        if (choose == 0) {
            printLevels(file);
        } else if (choose == 1) {
            records = getLevRec(file);
            isErr = addLevRec(file, records);
            printLevels(file);
        } else if (choose == 2) {
            printf("Please, select a level:\n");
            level = get_chooseStd(-9999999, 9999999);
            if (checkLId(file, level)) {
                records = getLevRec(file);
                isErr = insertLevRec(file, level, records);
                printLevels(file);
            } else {
                printf("n/a\n");
            }
        } else if (choose == 3) {
            printf("Please, select a level:\n");
            level = get_chooseStd(-9999999, 9999999);
            if (checkLId(file, level)) {
                records = getLevRec(file);
                isErr = changeLevRec(file, level, records);
                printLevels(file);
            } else {
                printf("n/a\n");
            }
        } else if (choose == 4) {
            printf("Please, select a level:\n");
            level = get_chooseStd(-9999999, 9999999);
            if (checkLId(file, level)) {
                isErr = delLevRec(file, level);
            } else {
                printf("n/a\n");
            }
        } else if (choose == -1) {
            flag = 1;
        }
    }
    if (isErr) {
        flag = 1;
    }
    return isErr;
}

// int events() {
//     int flag = 0, choose, level, isErr = 0;
// }
