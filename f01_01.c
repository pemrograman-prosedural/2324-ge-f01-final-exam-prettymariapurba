#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./libs/dorm.h"
#include "./libs/student.h"

int main(int _argc, char **_argv)
{
    char input[100];
    char command[50];
    int is_initial_state = 1;
    unsigned short int size_std = 0, size_dorm = 0;


     struct student_t *std = malloc(20 * sizeof(struct student_t));
     struct dorm_t *dorms = malloc(20 * sizeof(struct dorm_t));


    while (1) {
        fflush(stdin);
        fgets(input, sizeof(input), stdin);
        input[strcspn(input,"\r\n")] = 0;

        strcpy(command , strtok(input, "#"));
        if (strcmp(command, "student-print-all-detail") == 0){
            student_print_detail(std, size_std, is_initial_state);
        }else if(strcmp(command, "dorm-print-all-detail") == 0){
            print_dorm_detail(dorms, size_dorm);
        }else if(strcmp(command, "student-print-all") == 0){
            // printf("masuk\n");
            student_print_all(std, size_std);
        }else if(strcmp(command, "dorm-print-all") == 0){
            print_all_dorm(dorms, size_dorm);
        }
        else if (strcmp(command, "student-add") == 0){
            // printf("masuk\n");
            char data_id[10], data_name[50], data_year[10], data_gender[10];

            strcpy(data_id ,strtok(NULL, "#"));
            strcpy(data_name ,strtok(NULL, "#"));
            strcpy(data_year , strtok(NULL, "#"));
            strcpy(data_gender, strtok(NULL, "#"));
            
            std[size_std] = create_student(data_id, data_name, data_year, gender_to_value (data_gender));
            size_std++;
            is_initial_state = 0;
        }else if(strcmp(command, "dorm-add") == 0) {
            // printf("masuk\n");
            char dorm_name[10], dorm_size[5], dorm_gender[10];
            unsigned short int capacity = 0;

            strcpy(dorm_name ,strtok(NULL, "#"));
            strcpy(dorm_size , strtok(NULL, "#"));
            capacity = atoi(dorm_size);
            strcpy(dorm_gender, strtok(NULL, "#"));

            dorms[size_dorm] = create_dorm(dorm_name, capacity, gender_to_value (dorm_gender));
            size_dorm++;
        }else if(strcmp(command, "assign-student") == 0){
            char data_id[10], data_name[30];
            strcpy(data_id ,strtok(NULL, "#"));
            strcpy(data_name, strtok(NULL, "#"));
            
            unsigned short int poin_std = 0;
            unsigned short int poin_drm = 0;
            int found = 0;

            poin_std = get_index_student (std, size_std, data_id, &found);
            if(found == 0) continue;

            poin_drm = get_index_dorm (dorms, size_dorm, data_name);
            
            assign_student(std, dorms, poin_std, poin_drm);
        }else if(strcmp(command, "dorm-empty") == 0){
            char data_name[30];
            strcpy(data_name, strtok(NULL, "#"));
            
            unsigned short int poin_drm = 0;

            poin_drm = get_index_dorm (dorms, size_dorm, data_name);
            
            dorm_empty(std, dorms, poin_drm, size_std);

        }else if(strcmp(command, "move-student") == 0) {
            char data_id[10], data_name[30];
            strcpy(data_id ,strtok(NULL, "#"));
            strcpy(data_name, strtok(NULL, "#"));

            unsigned short int poin_std = 0;
            unsigned short int poin_drm = 0;
            int found = 0;

            poin_std = get_index_student (std, size_std, data_id, &found);
            if(found == 0) continue;
            poin_drm = get_index_dorm (dorms, size_dorm, data_name);

            move_student(std, dorms, &dorms[poin_drm], poin_std, poin_drm);
        }else if(strcmp(command, "student-leave") == 0){
            char data_id[10];
            strcpy(data_id ,strtok(NULL, "#"));

            unsigned short int poin_std = 0;
            int found = 0;

            poin_std = get_index_student (std, size_std, data_id, &found);
            if(found == 0) continue;

            leave_students(std, dorms, poin_std);
         }else if(strcmp(command, "---") == 0) {
            break;
        }
    }
    
    free(std);
    free(dorms);

    return 0;
}