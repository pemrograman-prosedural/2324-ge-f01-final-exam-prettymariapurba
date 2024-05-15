// student.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./student.h"

struct student_t create_student(char* input) {
    struct student_t student;
    char* token = strtok(NULL, "#");
    strcpy(student.id, token);
    token = strtok(NULL, "#");
    strcpy(student.name, token);
    token = strtok(NULL, "#");
    strcpy(student.year, token);
    token = strtok(NULL, "#");
    student.gender = strcmp(token, "male") == 0 ? GENDER_MALE : GENDER_FEMALE;
    student.dorm = NULL;
    return student;
}

void print_student(struct student_t student) {
    printf("%s|%s|%s|%s|%s\n", student.id, student.name, student.year, student.gender == GENDER_MALE ? "male" : "female", student.dorm ? student.dorm->name : "left");
}

void print_student_detail(struct student_t student) {
    printf("ID: %s\nName: %s\nYear: %s\nGender: %s\nDorm: %s\n", student.id, student.name, student.year, student.gender == GENDER_MALE ? "male" : "female", student.dorm ? student.dorm->name : "left");
}

short find_id(struct student_t* students, int count, const char* id) {
    for (short i = 0; i < count; i++) {
        if (strcmp(students[i].id, id) == 0) {
            return i;
        }
    }
    return -1;
}

void assign_student(struct dorm_t* dorms, struct student_t* students, char* student_id, char* dorm_name, int student_count, int dorm_count, short(find_id)(struct student_t, int, const char*), short(find_dorm)(struct dorm_t, int, const char*)) {
    short studentIdx = find_id(students, student_count, student_id);
    short dormIdx = find_dorm(dorms, dorm_count, dorm_name);

    if (studentIdx >= 0 && dormIdx >= 0) {
        students[studentIdx].dorm = &dorms[dormIdx];
        dorms[dormIdx].residents_num++;
    }
}

void move_student(struct dorm_t* dorms, struct student_t* students, char* student_id, char* dorm_name, int student_count, int dorm_count, short(find_id)(struct student_t, int, const char*), short(find_dorm)(struct dorm_t, int, const char*)) {
    short studentIdx = find_id(students, student_count, student_id);
    short newDormIdx = find_dorm(dorms, dorm_count, dorm_name);
    short oldDormIdx = find_dorm(dorms, dorm_count, students[studentIdx].dorm->name);


    if (studentIdx >= 0 && newDormIdx >= 0 && oldDormIdx >= 0) {
        dorms[oldDormIdx].residents_num--;
        students[studentIdx].dorm = &dorms[newDormIdx];
        dorms[newDormIdx].residents_num++;
    }
}

void dorm_empty(char* dorm_name, int student_count, int dorm_count, struct student_t* students, struct dorm_t* dorms, short(find_dorm)(struct dorm_t, int, const char*)) {
    short dormIdx = find_dorm(dorms, dorm_count, dorm_name);

    for (int i = 0; i < student_count; i++) {
        if (students[i].dorm != NULL && strcmp(students[i].dorm->name, dorm_name) == 0) {
            students[i].dorm = NULL;
        }
    }
    dorms[dormIdx].residents_num = 0;
}

void student_leave(struct student_t* students, int student_count, char* student_id) {
    short studentIdx = find_id(students, student_count, student_id);
    if (studentIdx >= 0 && students[studentIdx].dorm != NULL) {
        students[studentIdx].dorm->residents_num--;
        students[studentIdx].dorm = NULL;
    }
}