#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include "globals.h"
#ifndef HISTORY_H
#define HISTORY_H
int record_history(char *s, int len);
int show_last_command();
int show_complete_history();
#endif