#ifndef MODULES_H
#define MODULES_H

#include <stdlib.h>
#include <unistd.h>
#include "shared.h"

void getPath(char* Path);

struct modules getModRec(int id);

int checkId(FILE* file, int id);
int getPrevId(FILE* file);
int addModRec(FILE* file, struct modules record);
int delModRec(FILE* file, int id);
int insertModRec(FILE* file, int id, struct modules new_rec);
int changeModRec(FILE* file, int id, struct modules record);


#endif  //  MODULES_H