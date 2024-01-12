#include "../header files/parse.h"
#include "../header files/pipes.h"
#include "../header files/insert.h"
#include "../header files/globals.h"
#include "../header files/history.h"
int main()
{
    char *arr = NULL;
    char *for_history = NULL;
    char **argv = NULL;
    while (1)
    {
        printf("shell~$");
        int cleanup = 1;
        int len = insert_1d(&arr);
        for_history = (char *)malloc(sizeof(char) * len);
        strcpy(for_history, arr);
        int num = parse_input(arr, &argv);
        if (strcmp(arr, "exit") == 0)
        {
            cleanup--;
            show_complete_history();
            break;
        }
        else if (strcmp(arr, "last_command") == 0)
        {
            cleanup--;
            show_last_command();
        }
        else if (strcmp(arr, "history") == 0)
        {
            cleanup--;
            show_complete_history();
        }
        else if (strncmp(arr, "cd", 2) == 0)
        {
            char *directory = arr + 3;
            char *full_path = realpath(directory, NULL);
            if (chdir(full_path) == 0)
            {
                getcwd(full_path, sizeof(full_path));
            }
            else
            {
                perror("cd failed\n");
            }
        }
        else if (strncmp(arr, "./", 2) == 0)
        {
            pid_t pid = system(arr);
            if (pid == -1)
            {
                printf("error while creating new process\n");
                exit(0);
            }
            wait(NULL);
        }
        else if (strncmp(arr, "submit", 6) == 0)
        {
            // make a new char array without submit
            char *new = NULL;
            int num = 0;
            int max_length = 0;
            for (int i = 7; i < len; i++)
            {
                insert_1d_1(&new, &num, &max_length, arr[i]);
            }
            pid_t pid = system(new);
            if (pid == -1)
            {
                perror("child process cannot be created or its status cannot be retrieved\n");
            }
            else if (pid == 0)
            {
                kill(pid, SIGSTOP);
            }
            else
            {
                free(new);
            }
        }
        else
        {
            traverse(argv, num);
            pid_t pid = fork();
            if (pid == -1)
            {
                printf("error\n");
                exit(1);
            }
            else if (pid == 0)
            {
                pipes(list, num_of_elements);
            }
            else
            {
                wait(NULL);
            }
        }
        if (cleanup == 1)
        {
            record_history(for_history, len);
            /*clean up starts here*/
            for (int i = 0; i < num; i++)
            {
                free(argv[i]);
            }
            argv = NULL;
            free(arr);
            free(for_history);
            arr = NULL;
            free(list->arr);
            free(list);
            list = NULL;
            num_of_elements = 0;
            max_len = 0;
            /*ends here*/
        }
    }
}