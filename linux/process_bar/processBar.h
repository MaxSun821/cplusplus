#ifndef C_CODE_PROCESSBAR_H
#define C_CODE_PROCESSBAR_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BODY '='
#define TOP '>'
#define LOAD 100

void processBar(int rate);
void initBar();

#endif
