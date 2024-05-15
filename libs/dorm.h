// dorm.h
#ifndef DORM_H
#define DORM_H

#include "./gender.h"

struct dorm_t {
    char name[50];
    unsigned short capacity;
    gender_t gender;
    unsigned short residents_num;
};

struct dorm_t create_dorm(char* input);
void print_dorm(struct dorm_t dorm);
void print_dorm_detail(struct dorm_t dorm);
short find_dorm(struct dorm_t* dorms, int count, const char* name);

#endif
