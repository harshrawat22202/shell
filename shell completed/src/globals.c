#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#define MAX_LEN 15
struct cmd
{
    char **arr;
};
struct linked_list
{
    char *arr;
    struct linked_list *next;
};
struct linked_list *history = NULL;
int number_of_commands = 0;
struct cmd *list = NULL;
int num_of_elements = 0;
int max_len = 0;