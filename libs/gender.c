#include "gender.h"
#include "string.h"
#include "stdlib.h"

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */

 char *gender_to_text (enum gender_t mhs_gender){
    char *data = malloc (10);
    if (mhs_gender == 0) strcpy (data, "male");
    else if (mhs_gender == 1) strcpy (data, "female");
    return data;

 }

