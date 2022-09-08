#include "dbInput.h"


int get_chooseStd(int chooseMin, int chooseMax) {
    int choose = -2;
    char end = '\0';
    int scanf_result = 0;

    scanf_result = scanf("%d", &choose);
    if (scanf_result != 1 || choose < chooseMin || choose > chooseMax) {
        printf("n/a\n");
        choose = -2;
    }
    while (end != 10) {end = getchar();}
    return choose;
}
