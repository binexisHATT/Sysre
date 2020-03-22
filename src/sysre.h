/***************************************************************************//**
  @file         sysre.h
  @author       Alexis Rodriguez
  @date         Created Thursday, 19 March 2020
  @brief        Sysre declarations
*******************************************************************************/

#ifndef SYSRE_H
#define SYSRE_H

//        Colors        //
#define RED     "\x1b[91m"
#define GREEN   "\x1b[92m"
#define YELLOW  "\x1b[93m"
#define BLUE    "\x1b[94m"
#define MAGENTA "\x1b[95m"
#define CYAN    "\x1b[36m"
//    Original color    //
#define RESET   "\x1b[0m" 

//          Get Array Length           //
#define LEN(x) ( sizeof(x) / sizeof(*x) )

//           Determine OS            //
#ifdef _WIN32
    #define OPERATING_SYSTEM "Windows"
    #include <Windows.h>
#else
    #define OPERATING_SYSTEM "Unix"
    #include <unistd.h>
#endif

#endif // end SYSRE_H
