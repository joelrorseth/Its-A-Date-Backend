   /*******************************************************/
   /*      "C" Language Integrated Production System      */
   /*                                                     */
   /*               CLIPS Version 6.30  08/16/14          */
   /*                                                     */
   /*                USER FUNCTIONS MODULE                */
   /*******************************************************/

/*************************************************************/
/* Purpose:                                                  */
/*                                                           */
/* Principal Programmer(s):                                  */
/*      Gary D. Riley                                        */
/*                                                           */
/* Contributing Programmer(s):                               */
/*                                                           */
/* Revision History:                                         */
/*                                                           */
/*      6.24: Created file to seperate UserFunctions and     */
/*            EnvUserFunctions from main.c.                  */
/*                                                           */
/*      6.30: Removed conditional code for unsupported       */
/*            compilers/operating systems (IBM_MCW,          */
/*            MAC_MCW, and IBM_TBC).                         */
/*                                                           */
/*************************************************************/

/***************************************************************************/
/*                                                                         */
/* Permission is hereby granted, free of charge, to any person obtaining   */
/* a copy of this software and associated documentation files (the         */
/* "Software"), to deal in the Software without restriction, including     */
/* without limitation the rights to use, copy, modify, merge, publish,     */
/* distribute, and/or sell copies of the Software, and to permit persons   */
/* to whom the Software is furnished to do so.                             */
/*                                                                         */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS */
/* OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF              */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT   */
/* OF THIRD PARTY RIGHTS. IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY  */
/* CLAIM, OR ANY SPECIAL INDIRECT OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES */
/* WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN   */
/* ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF */
/* OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.          */
/*                                                                         */
/***************************************************************************/

#include "clips.h"

void UserFunctions(void);
void EnvUserFunctions(void *);

/*********************************************************/
/* UserFunctions: Informs the expert system environment  */
/*   of any user defined functions. In the default case, */
/*   there are no user defined functions. To define      */
/*   functions, either this function must be replaced by */
/*   a function with the same name within this file, or  */
/*   this function can be deleted from this file and     */
/*   included in another file.                           */
/*********************************************************/
void UserFunctions()
  {
   // Use of UserFunctions is deprecated.
   // Use EnvUserFunctions instead.
  }
  
/***********************************************************/
/* EnvUserFunctions: Informs the expert system environment */
/*   of any user defined functions. In the default case,   */
/*   there are no user defined functions. To define        */
/*   functions, either this function must be replaced by   */
/*   a function with the same name within this file, or    */
/*   this function can be deleted from this file and       */
/*   included in another file.                             */
/***********************************************************/
void EnvUserFunctions(
  void *environment)
  {
#if MAC_XCD
#pragma unused(environment)
#endif
      // declare c function
      //extern string myFunction(void*);
      
      
      // call DefineFunction to register user-defined functions.
      // first arg -> is environment for which function is to be defined.
      // sec arg -> is string name of your function.
      // third arg is the return value (see advanced guide pg 40 for types)
      // forth casts pointer to myFunction
      // match this name to the 4th arg.
      // EnvDefineFunction returns 0 if unsuccessful, anything else if it is.
      /*
            int EnvDefineFunction(environment,functionName,functionType,functionPointer,actualFunctionName);
            void *environment;
            const char *functionName, *actualFunctionName;
            char functionType;
            int (*functionPointer)(void *);
       
            OR****
       
            int EnvDefineFunction2(environment,functionName,functionType,
            functionPointer,actualFunctionName,
            functionRestrictions);
            void *environment;
            const char *functionName, functionType, *actualFunctionName;
            int (*functionPointer)(void *);
            const char *functionRestrictions;
       
       The first five arguments to DefineFunction2 are identical to the five arguments for
       DefineFunction. The sixth argument is a restriction string which indicates the number and types
       of arguments that the CLIPS function expects. The syntax format for the restriction string is
       
       <min-args> <max-args> [<default-type> <types>*]
       
       The restriction string for a function requiring a minimum of three arguments is:
       "3*"
       
       The restriction string for a function requiring no more than five arguments is:
       "*5"
       
       The restriction string for a function requiring at least three and no more than five arguments
       (each of which must be an integer or float) is:
       "35n"
       
       The restriction string for a function requiring exactly six arguments (of which the first must be a
       string, the third an integer, and the remaining arguments floats) is:
       "66fsui"
       
       
       */
      
      //EnvDefineFunction(environment, "myFunction", 's', PTIEF myFunction, "myFunction");
      
  }

