#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include "../header files/globals.h"
int insert_in_array(char **argv, int length_of_argv)
{
    if (num_of_elements == 0)
    {
        max_len++;
        list = (struct cmd *)realloc(list, max_len * sizeof(struct cmd));
        if (!list)
        {
            printf("Failed to allocate memory");
            return 1;
        }
        list[0].arr = (char **)malloc(sizeof(char *) * length_of_argv);
        for (int i = 0; i < length_of_argv; i++)
        {
            if (argv[i] != NULL)
            {
                list[0].arr[i] = (char *)malloc(sizeof(char) * (MAX_LEN + 1));
                strcpy(list[0].arr[i], argv[i]);
            }
            else
            {
                list[0].arr[i] = NULL;
            }
        }
        num_of_elements++;
    }
    else if (num_of_elements < max_len)
    {
        list[num_of_elements].arr = (char **)malloc(sizeof(char *) * length_of_argv);
        for (int i = 0; i < length_of_argv; i++)
        {
            if (argv[i] != NULL)
            {
                list[num_of_elements].arr[i] = (char *)malloc(sizeof(char) * (MAX_LEN + 1));
                strcpy(list[num_of_elements].arr[i], argv[i]);
            }
            else
            {
                list[num_of_elements].arr[i] = NULL;
            }
        }
        num_of_elements++;
    }
    else if (num_of_elements == max_len)
    {
        list = (struct cmd *)realloc(list, max_len * 2 * sizeof(struct cmd));
        max_len *= 2;
        list[num_of_elements].arr = (char **)malloc(sizeof(char *) * length_of_argv);
        for (int i = 0; i < length_of_argv; i++)
        {
            if (argv[i] != NULL)
            {
                list[num_of_elements].arr[i] = (char *)malloc(sizeof(char) * (MAX_LEN + 1));
                strcpy(list[num_of_elements].arr[i], argv[i]);
            }
            else
            {
                list[num_of_elements].arr[i] = NULL;
            }
        }
        num_of_elements++;
    }
    return 0;
}
