/*************************************//**
* Author : Alexis Rodriguez
* Date : 2020-03-18
* Program : Sysre
*****************************************/


// defining our program colors //
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m" // set color back to original

#include <stdio.h>
#include <stdlib.h>


int main() {
	printf(RED "Hello World!\n" RESET);
}
