#ifndef PROCESS_H
#define PROCESS_H
#define MAX_WORK 1000


#include <stdlib.h>
#include "manage_queue.h"
#include "functions.h"
#include "types.h"
#include <time.h>
#include <conio.h>
#include <math.h>

void process_model_array();
double generate_time(int t_start, int t_end);
void process_model_list();
void count_time();
int process_menu();

#endif // PROCESS_H
