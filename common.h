#pragma once

#include <stdbool.h>
#include <stddef.h>

/* maximum size of input string */
size_t BUFF_SIZE = 4096;

char shift_by(char, int);
void shift_str_by(char*, int, char*);
bool all_digits(char*);

