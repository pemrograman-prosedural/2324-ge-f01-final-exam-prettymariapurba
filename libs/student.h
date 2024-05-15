// student.h
#ifndef STUDENT_H
#define STUDENT_H

#include "./gender.h"
#include "./dorm.h"

struct student_t {
    char id[50];
    char name[50];
    char year[10];
    gender_t gender;
    struct dorm_t* dorm;
};

struct student_t create_student(char* input);
void print_student(struct student_t student);
void print_student_detail(struct student_t student);
short find_id(struct student_t* students, int count, const char* id);
void assign_student(struct dorm_t* dorms, struct student_t* students, char* student_id, char* dorm_name, int student_count, int dorm_count, short(find_id)(struct student_t, int, const char*), short(find_dorm)(struct dorm_t, int, const char*));
void move_student(struct dorm_t* dorms, struct student_t* students, char* student_id, char* dorm_name, int student_count, int dorm_count, short(find_id)(struct student_t, int, const char*), short(find_dorm)(struct dorm_t, int, const char*));
void dorm_empty(char* dorm_name, int student_count, int dorm_count, struct student_t* students, struct dorm_t* dorms, short(find_dorm)(struct dorm_t, int, const char*));
void student_leave(struct student_t* students, int student_count, char* student_id);

#endif