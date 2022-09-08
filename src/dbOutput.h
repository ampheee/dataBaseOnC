#ifndef DATABASEIO_H
#define DATABASEIO_H

#include <stdlib.h>
#include <stdio.h>
#include "shared.h"

void printMainMenu();
void printModulesMenu();
void printLevelsMenu();

int showTables();

int printModules(FILE* file);
int printLevels(FILE* file);
int printEvents(FILE* file);

#endif  //  DATABASEIO_H