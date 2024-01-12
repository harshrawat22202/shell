#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include "../header files/globals.h"
int record_history(char *s, int len)
{
    struct linked_list *i = NULL;
    i = (struct linked_list *)malloc(sizeof(struct linked_list));
    i->arr = NULL;
    i->next = NULL;
    i->arr = (char *)malloc(sizeof(char) * len);
    strcpy(i->arr, s);
    i->next = history;
    history = i;
    number_of_commands++;
    return 0;
}
int show_last_command()
{
    if (history == NULL)
    {
        printf("nothing to show\n");
        return 0;
    }
    struct linked_list *del = history;
    history = del->next;
    printf("%s\n", del->arr);
    free(del->arr);
    free(del);
    number_of_commands--;
    return 0;
}
int show_complete_history()
{
    for (int i = 0; i < number_of_commands; i++)
    {
        show_last_command();
    }
    return 0;
}
