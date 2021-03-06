/***************************************************************************//**
  @file         sysre.h
  @author       Alexis Rodriguez
  @date         Created Thursday, 19 March 2020
  @brief        Sysre functionality
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <dirent.h>
#include "sysre.h"


FILE* exec_cmd(const char cmd[] );
void os_detection(); // detect operating system
void cpu__mem_usage(); // 
void disk_space();
void dir_list( const char directory[] );


/*
 * Function: cpu_usage   
 * -------------------------------
 * Executes command and stores command output, Type=Helper
 * 
 * Returns: FILE pointer
 */
FILE* exec_cmd( const char cmd[] ) {

    FILE *result;

    result = popen( cmd, "r" );
    if( result == NULL ) {
        printf( "Unsuccessful command execution\n" );
        exit( EXIT_FAILURE );
    }

    return result;
}


/*
 * Function: os_detection   
 * -------------------------------
 * Determines whether the current OS is Windows or Unix-based, Type=Performer
 */
void os_detection() {

    FILE* p;
    char ch;

    if ( OPERATING_SYSTEM == "Windows" )                                  /* Windows 32/64 bit*/
        p = exec_cmd( "ver" );
    else
	    p = exec_cmd( "uname -r" );                                       /* Unix */

	printf( YELLOW "\nOperating System:\n" RESET );
    while( (ch = fgetc(p)) != EOF )
        putchar( ch );

    pclose( p );
}


/*
 * Function: cpu_usage   
 * -------------------------------
 * Gets and prints the computers cpu usage levels, Type=Performer
 */
 void cpu_usage() {

    FILE *p;
    char ch;

    if( OPERATING_SYSTEM == "Windows" ) {                                 /* Windows 32/64 bit*/
        printf( RED "CPU / MEMORY UTILIZATION:\n" RESET );
        p = exec_cmd( "tasklist" );
    } else {
        printf( RED "CPU / MEMORY UTILIZATION:\n" RESET );
	    p = exec_cmd( "top -n 1" );                                         /* Unix */
    }

    while( (ch = fgetc(p)) != EOF)
        putchar( ch );

    pclose( p );
 }


/*
 * Function: disk_space   
 * -------------------------------
 * Displays the disk space being used by the computer, Type=Performer
 */
 void disk_space() {

    FILE *p;
    char ch;

    if( OPERATING_SYSTEM == "Windows" ) {
        p = exec_cmd( "wmic logicaldisk get size,freespace,caption" );
    } else {
        p = exec_cmd( "df -a" );
    }

    printf( GREEN "\nDISK SPACE INFORMATION:\n" RESET );
    while( (ch = fgetc(p)) != EOF)
        putchar( ch );
    pclose( p );
 }


/*
 * Function: dir_list   
 * -------------------------------
 *  List the files in important directories, Type=Performer
 * 
 *  directory (str): the directory to open
 */
 void dir_list( const char directory[] ) {

    DIR *d;
    struct dirent *dir;
    d = opendir( directory );

    if( dir ) {

        while( (dir = readdir(d)) != NULL )
            printf( "%s\n", dir->d_name );
        closedir( d );
    }
 }


int main( void ) {

    cpu_usage();
    os_detection();
    disk_space();

    if( OPERATING_SYSTEM == "Windows" ) {
        dir_list( "C:\\Windows\\Temp" );
    } else {
    	printf( BLUE "\nFILES IN /tmp FOLDER:\n" RESET );
        dir_list( "/tmp" );
        sleep( 1 );
        printf( BLUE "\nFILES IN /etc FOLDER:\n" RESET );
        dir_list( "/etc" );
        sleep( 1 );
        printf( BLUE "\nFILES IN /var/log FOLDER:\n" RESET );
        dir_list( "/var/log" );
    }
	return( 0 );
}
