/*************************************//**
* Author : Alexis Rodriguez
* Date : 2020-03-18
* Program : Sysre
*****************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defining our program colors //
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
// set color back to original color
#define RESET   "\x1b[0m" 


void os_detection()
{
	FILE *p;
    char ch;

	p = popen("uname -r","r");   /* Linux */
    if( p == NULL)
    {
        printf("Unsuccessful command execution\n");
        exit(1);
    }

	printf(RED "Operating System [-> " RESET);
    while( (ch = fgetc(p)) != EOF )
        putchar(ch);
    pclose(p);
}


int main()
{
	os_detection();
	return(0);
}
