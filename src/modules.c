#include "modules.h"

int checkId(FILE* file, int id) {
    int res = 0;
    if ((id >=0) && (id <= getPrevId(file)))
        res = 1;
    return res;
}


int getPrevId(FILE* file) {
    int id = -1;
    if (file != NULL) {
        fseek(file, -sizeof(struct modules), SEEK_END);
        fread(&id, sizeof(int), 1, file);
        fseek(file, 0, SEEK_SET);
    }
    return id;
}

void getPath(char* Path) {
    int size = 0;
    char c = ' ';
    scanf("%c", &c);
    if (c == '\n')
        scanf("%c", &c);
    while ((c != '\n')&& (size != 30)) {
        Path[size++] = c;
        scanf("%c", &c);
    }
    if (size > 30)
        printf("n/a\n");
    else
        Path[size] = '\0';
}


struct modules getModRec(int id) {
    printf("Enter\n");
    struct modules record;
    record.id = id;
    printf("name:\n");
    getPath(record.name);
    printf("level:\n");
    while (1) {
        if (scanf("%d", &(record.level)) != 1)
            printf("n/a\n");
        else 
            break;
    }
    printf("cell:\n");
    while (1) {
        if (scanf("%d", &(record.cell)) != 1)
            printf("n/a\n");
        else 
            break;
    }
    printf("flag:\n");
    while (1) {
        if (scanf("%d", &(record.flag)) != 1)
            printf("n/a\n");
        else 
            break;
    }
    return record;
}

int addModRec(FILE* file, struct modules record) {
    int isErr = 0;
    if (file == NULL) {
        isErr = 1;
    } else {
        fseek(file, 0, SEEK_END);
        fwrite(&record, sizeof(struct modules), 1, file);
        fseek(file, 0, SEEK_SET);
        printf("DONE");
    }
    return isErr;
}

int delModRec(FILE* file, int id) {
    int isErr = 0;
    if (file == NULL) {
        isErr = 1;
    } else {
        struct modules record;
        int i = id;
        fseek(file, (i+1) * sizeof(struct modules), SEEK_SET);
        while (!feof(file)) {
            fseek(file, (i+1) * sizeof(struct modules), SEEK_SET);
            if (fread(&record, sizeof(struct modules), 1, file) != 1)
                break;
            fseek(file, i * sizeof(struct modules), SEEK_SET);
            record.id--;
            fwrite(&record, sizeof(struct modules), 1, file);
            i++;
        }
        fseek(file, 0, SEEK_SET);
        truncate(modulesPath, i * sizeof(struct modules));
        printf("DONE");
    }
    return isErr;
}


int insertModRec(FILE* file, int id, struct modules new_rec) {  //INSERT
    int isErr = 0;
    if (file == NULL) {
        isErr = 1;
    } else {
        struct modules record;
        int i;
        fseek(file, -sizeof(struct modules), SEEK_END);
        fread(&i, sizeof(int), 1, file);
        while (i >= id) {
            fseek(file, i * sizeof(struct modules), SEEK_SET);
            fread(&record, sizeof(struct modules), 1, file);
            fseek(file, (i + 1) * sizeof(struct modules), SEEK_SET);
            record.id++;
            fwrite(&record, sizeof(struct modules), 1, file);
            i--;
        }
        fseek(file, (i+1) * sizeof(struct modules), SEEK_SET);
        fwrite(&new_rec, sizeof(struct modules), 1, file);
        fseek(file, 0, SEEK_SET);
        printf("DONE");
    }
    return isErr;
}

int changeModRec(FILE* file, int id, struct modules record) {  // CHANGE
    int isErr = 0;
    if (file == NULL) {
        isErr = 1;
    } else {
        fseek(file, id * sizeof(struct modules), SEEK_SET);
        fwrite(&record, sizeof(struct modules), 1, file);
        fseek(file, 0, SEEK_SET);
        printf("DONE");
    }
    return isErr;
}