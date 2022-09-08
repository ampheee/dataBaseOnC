#ifndef LEVELS_H
#define LEVELS_H

#include "shared.h"

struct levels getLevRec();
int addLevRec(FILE* file, struct levels rec);
int delLevRec(FILE* file, int id);
int insertLevRec(FILE* file, int id, struct levels new_rec);
int changeLevRec(FILE* file, int id, struct levels rec);
int checkLId(FILE* file, int id);


#endif  //  LEVELS_H