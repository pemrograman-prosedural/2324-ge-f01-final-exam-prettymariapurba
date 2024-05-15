// dorm.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./dorm.h"

struct dorm_t create_dorm(char* input) {
    struct dorm_t dorm;
    char* token = strtok(NULL, "#");
    strcpy(dorm.name, token);
    token = strtok(NULL, "#");
    dorm.capacity = atoi(token);
    token = strtok(NULL, "#");
    dorm.gender = strcmp(token, "male") == 0 ? GENDER_MALE : GENDER_FEMALE;
    dorm.residents_num = 0;
    return dorm;
}

void print_dorm(struct dorm_t dorm) {
    printf("%s|%d|%s|%d\n", dorm.name, dorm.capacity, dorm.gender == GENDER_MALE ? "male" : "female", dorm.residents_num);
}

void print_dorm_detail(struct dorm_t dorm) {
    printf("Dorm: %s\nCapacity: %d\nGender: %s\nResidents: %d\n", dorm.name, dorm.capacity, dorm.gender == GENDER_MALE ? "male" : "female", dorm.residents_num);
}

short find_dorm(struct dorm_t* dorms, int count, const char* name) {
    for (short i = 0; i < count; i++) {
        if (strcmp(dorms[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}
