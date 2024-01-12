#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include "globals.h"
#ifndef PIPES_H
#define PIPES_H
int pipes(struct cmd *list, int N);
#endif