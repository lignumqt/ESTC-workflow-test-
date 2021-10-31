#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
 #include <ctype.h>
#include "types.h"

vector_t sum_vectors(vector_t first, vector_t second)
{
    vector_t result = {0};

    result.x = first.x + second.x;
    result.y = first.y + second.y;
    result.z = first.z + second.z;

    return result;
}

vector_t sub_vectors(vector_t minuend, vector_t subtrahend)
{
    vector_t result = {0};

    result.x = minuend.x - subtrahend.x;
    result.y = minuend.y - subtrahend.y;
    result.z = minuend.z - subtrahend.z;

    return result;
}

int dot_vectors(vector_t first, vector_t second)
{
    int result = 0;

    result = first.x*second.x + first.y*second.y + first.z*second.z;

    return result;
}

vector_t cross_vectors(vector_t first, vector_t second)
{
    vector_t result = {0};

    result.x = first.y*second.z - first.z*second.y;
    result.y = first.z*second.x - first.x*second.z;
    result.z = first.x*second.y - first.y*second.x;

    return result;
}

int main(int argc, char **argv)
{
    vector_t first_vector = {0};
    vector_t second_vector = {0};
    vector_t work_vector = {0};
    int result = 0;
    operations operation = wrong_operatoin;
    
    if (argc != 8 || !argv)
    {
        printf("You need to enter 3 coordinates of vectors for 2 vectors and operation\n");
        printf("Example: ./vector [three coord fst vector] [three coord scnd vector] [sum|sub|dot|cross]\n");
        return 1;
    }

    first_vector.x = atoi(argv[1]);
    first_vector.y = atoi(argv[2]);
    first_vector.z = atoi(argv[3]);

    second_vector.x = atoi(argv[4]);
    second_vector.y = atoi(argv[5]);
    second_vector.z = atoi(argv[6]);

    for (int i = 0; i < sizeof(string_to_operations) / sizeof(string_to_operations[0]); i++)
    {
        if (!strcmp(argv[7], string_to_operations[i].str_operation))
        {
            operation = string_to_operations[i].operation;
            break;
        }
    }

    switch (operation)
    {
    case sum:
        printf("you choose sum operation\n");
        work_vector = sum_vectors(first_vector, second_vector);
        printf("new vector coordinates = {x = %d, y = %d, z = %d}\n", work_vector.x, work_vector.y, work_vector.z);
        break;
    
    case sub:
        printf("you choose sub operation\n");
        work_vector = sub_vectors(first_vector, second_vector);
        printf("new vector coordinates = {x = %d, y = %d, z = %d}\n", work_vector.x, work_vector.y, work_vector.z);
        break;

    case dot:
        printf("you choose dot operation\n");
        result = dot_vectors(first_vector, second_vector);
        printf("dot product of vectors = %d\n", result);
        break;

    case cross:
        printf("you choose cross operation\n");
        work_vector = cross_vectors(first_vector, second_vector);
        printf("new vector coordinates = {x = %d, y = %d, z = %d}\n", work_vector.x, work_vector.y, work_vector.z);
        break;

    default:
        printf("Wrong operation\n");
        return 1;
    }

    return 0;
}