#include "dbOutput.h"
#include "dbInput.h"
#include "shared.h"

int main() {
    int isErr = 0, choose, flag = 0;
    while (!flag) {
        printMainMenu();
        choose = get_chooseStd(-1, 1);
        if (choose == 1) {
            isErr = showTables();
        } else if (choose == 0) {
            printf("0: MODULES\n1: LEVELS\n2: STATUS_EVENTS\n");
            choose = get_chooseStd(0, 2);
            if (choose == 0) {
                isErr = modules();
            } else if (choose == 1) {
                isErr = levels();
            } else if (choose == 2) {
                // isErr = events();
            }
        } else if (choose == -1) {
            flag = 1;
        }
        if (isErr) {
            flag = 1;
            printf("something went wrong");
        }
    }
}