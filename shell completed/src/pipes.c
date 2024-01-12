#include "../header files/globals.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
int pipes(struct cmd *list, int N)
{
    int pipes[2];
    int previous_buffer = STDIN_FILENO;

    for (int i = 0; i < N - 1; i++)
    {
        if (pipe(pipes) == -1)
        {
            printf("pipe error\n");
            exit(2);
        }
        pid_t id = fork();
        if (id == -1)
        {
            printf("fork error\n");
            exit(1);
        }
        if (id == 0)
        { // child process
            if (previous_buffer != STDIN_FILENO)
            {
                dup2(previous_buffer, STDIN_FILENO);
                close(previous_buffer);
            }
            dup2(pipes[1], STDOUT_FILENO);
            close(pipes[1]);
            if (execvp(list[i].arr[0], list[i].arr) == -1)
            {
                printf("execvp error\n");
                exit(1);
            }
        }
        close(previous_buffer);
        close(pipes[1]);
        previous_buffer = pipes[0];
    }
    if (previous_buffer != STDIN_FILENO)
    {
        dup2(previous_buffer, STDIN_FILENO);
        close(previous_buffer);
    }
    if (execvp(list[N - 1].arr[0], list[N - 1].arr) == -1)
    {
        printf("execvp error\n");
        exit(1);
    }
    return 0;
}