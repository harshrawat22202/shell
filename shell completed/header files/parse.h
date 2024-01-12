#include "globals.h"
#include "insert.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#ifndef PARSE_H
int insert_2d(char ***argv, char *a, int *num, int *max);
int parse_input(char *arr, char ***argv);
int insert_1d(char **arr);
int insert_1d_1(char **arr, int *num, int *max_length, char x);
int traverse(char **argv, int len);
#endif