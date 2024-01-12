#ifndef GLOBALS_H
#define GLOBALS_H
#define MAX_LEN 15
extern struct linked_list *history;
extern struct cmd *list;
extern int num_of_elements;
extern int max_len;
extern int number_of_commands;
struct cmd
{
    char **arr;
};
struct linked_list
{
    char *arr;
    struct linked_list *next;
};
#endif