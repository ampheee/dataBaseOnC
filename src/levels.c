#include "levels.h"


struct levels getLevRec() {
    struct levels rec;
    while (1) {
        printf("Enter\nLevel||Nums of cells||Flag\n");
        if (scanf("%d %d %d", &(rec.level), &(rec.cells), &(rec.flag)) == 3)
            break;
        else
            printf("n/a\n");
    }
    return rec;
}

int addLevRec(FILE* file, struct levels rec) {
    int is_error = 0;
    if (file == NULL) {
        is_error = 1;
    } else {
        fseek(file, 0, SEEK_END);
        fwrite(&rec, sizeof(struct levels), 1, file);
        fseek(file, 0, SEEK_SET);
    }
    return is_error;
}

int delLevRec(FILE* file, int id) {
    int is_error = 0;
    if (file == NULL) {
        is_error = 1;
    } else {
        struct levels rec;
        int i = id;
        fseek(file, (i+1) * sizeof(struct levels), SEEK_SET);
        while (!feof(file)) {
            fseek(file, (i+1) * sizeof(struct levels), SEEK_SET);
            if (fread(&rec, sizeof(struct levels), 1, file) != 1)
                break;
            fseek(file, i * sizeof(struct levels), SEEK_SET);
            fwrite(&rec, sizeof(struct levels), 1, file);
            i++;
        }
        fseek(file, 0, SEEK_SET);
        truncate(levelsPath, i * sizeof(struct levels));
    }
    return is_error;
}

int insertLevRec(FILE* file, int id, struct levels new_rec) {
    int is_error = 0;
    if (file == NULL) {
        is_error = 1;
    } else {
        struct levels rec;
        int i;
        fseek(file, -sizeof(struct levels), SEEK_END);
        fread(&i, sizeof(int), 1, file);
        while (i >= id) {
            fseek(file, i * sizeof(struct levels), SEEK_SET);
            fread(&rec, sizeof(struct levels), 1, file);
            fseek(file, (i + 1) * sizeof(struct levels), SEEK_SET);
            fwrite(&rec, sizeof(struct levels), 1, file);
            i--;
        }
        fseek(file, (i+1) * sizeof(struct levels), SEEK_SET);
        fwrite(&new_rec, sizeof(struct levels), 1, file);
        fseek(file, 0, SEEK_SET);
    }
    return is_error;
}

int changeLevRec(FILE* file, int id, struct levels rec) {
    int is_error = 0;
    if (file == NULL) {
        is_error = 1;
    } else {
        fseek(file, id * sizeof(struct levels), SEEK_SET);
        fwrite(&rec, sizeof(struct levels), 1, file);
        fseek(file, 0, SEEK_SET);
    }
    return is_error;
}


int checkLId(FILE* file, int id) {
    int res = 0;
    fseek(file, 0, SEEK_END);
    int size = ftell(file)/sizeof(struct levels);
    if ((id >= 0) && (id < size))
        res = 1;
    return res;
}