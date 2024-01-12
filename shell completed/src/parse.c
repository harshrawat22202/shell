#include "../header files/globals.h"
#include "../header files/insert.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
int insert_2d(char ***argv, char *a, int *num, int *max)
{

    if (*num == 0)
    {
        (*max)++;
        *argv = (char **)realloc(*argv, sizeof(char *) * 1);
        (*argv)[*num] = (char *)malloc(sizeof(char) * (MAX_LEN + 1));
        memcpy((*argv)[*num], a, MAX_LEN * sizeof(char));
        (*argv)[*num][MAX_LEN] = '\0';
        (*num)++;
    }
    else if (*num == *max)
    {
        *max *= 2;
        *argv = (char **)realloc(*argv, sizeof(char *) * (*max));
        (*argv)[*num] = (char *)malloc(sizeof(char) * (MAX_LEN + 1));
        memcpy((*argv)[*num], a, MAX_LEN * sizeof(char));
        (*argv)[*num][MAX_LEN] = '\0';
        (*num)++;
    }
    else
    {
        (*argv)[*num] = (char *)malloc(sizeof(char) * (MAX_LEN + 1));
        memcpy((*argv)[*num], a, MAX_LEN * sizeof(char));
        (*argv)[*num][MAX_LEN] = '\0';
        (*num)++;
    }
    return 0;
}
int parse_input(char *arr, char ***argv)
{
    int arg_num = 0;
    int max = 0;
    char *token = strtok(arr, " ");
    while (token != NULL)
    {
        // argv[arg_num] = token;
        insert_2d(argv, token, &arg_num, &max);
        token = strtok(NULL, " ");
    }
    if (arg_num < max)
    {
        (*argv)[arg_num] = NULL;
    }
    else
    {
        *argv = (char **)realloc(*argv, sizeof(char *) * (max + 1));
        (*argv)[arg_num] = NULL;
        max++;
    }
    return arg_num + 1;
}
int insert_1d(char **arr)
{
    int num = 0;
    int max_length = 1;
    *arr = (char *)malloc(max_length * sizeof(char));

    while (1)
    {
        char c = getchar();
        if (c == '\n')
        {
            (*arr)[num] = '\0';
            break;
        }

        if (num == max_length - 1)
        {
            max_length *= 2;
            *arr = (char *)realloc(*arr, max_length * sizeof(char));
        }

        (*arr)[num++] = c;
    }

    return num;
}
int insert_1d_1(char **arr, int *num, int *max_length, char x)
{
    if (*arr == NULL)
    {
        *arr = (char *)malloc(1 * sizeof(char));
        *arr[0] = x;
        (*num)++;
        (*max_length)++;
    }
    else if (*num < *max_length)
    {
        *arr[(*num)++] = x;
    }
    else if (*num == *max_length)
    {
        *arr = (char *)realloc(*arr, 2 * (*max_length) * sizeof(char));
        *max_length *= 2;
        *arr[(*num)++] = x;
    }
    return 0;
}
int traverse(char **argv, int len)
{
    char **a = NULL;
    int num = 0;
    int max = 0;
    for (int i = 0; i < len; i++)
    {
        if (argv[i] != NULL)
        {
            if (memcmp(argv[i], "|", sizeof(char)) != 0)
            {
                insert_2d(&a, argv[i], &num, &max);
            }
            else
            {
                if (num < max)
                {
                    a[num++] = NULL;
                }
                else
                {
                    a = (char **)realloc(a, sizeof(char) * (max + 1));
                    a[num++] = NULL;
                }
                insert_in_array(a, num);
                for (int i = 0; i < num; i++)
                {
                    free(a[i]);
                    num--;
                }
                num--;
                max = 0;
                a = NULL;
            }
        }
        else
        {
            if (num < max)
            {
                a[num++] = NULL;
            }
            else
            {
                a = (char **)realloc(a, sizeof(char) * (max + 1));
                a[num++] = NULL;
            }
            insert_in_array(a, num);
            for (int i = 0; i < num; i++)
            {
                free(a[i]);
                num--;
            }
            num--;
            max = 0;
            a = NULL;
        }
    }
    return 0;
}
