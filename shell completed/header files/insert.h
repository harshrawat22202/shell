#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include "globals.h"
#ifndef INSERT_H
#define INSERT_H
int insert_in_array(char **argv, int length_of_argv);
#endif