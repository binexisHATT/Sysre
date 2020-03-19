/*************************************//**
* Author : Alexis Rodriguez
* Date : 2020-03-18
* Program : Sysre
*****************************************/


// defining our program colors //
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#include <stdio.h>
#include <stdlib.h>


int main() {
	printf(ANSI_COLOR_RED "Hello World!\n" ANSI_COLOR_RESET);
}
