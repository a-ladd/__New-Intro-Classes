//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                                                              //
//                               Utilities.hpp                                  //
//                                                                              //
// Purpose : Collection of often used utilities.                                //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 
# ifndef UTILITIES //-------------------------------------------------------------

#ifndef _DEPRECATION_DISABLE   /* One time only */
#define _DEPRECATION_DISABLE   /* Disable deprecation true */
#if (_MSC_VER >= 1400)         /* Check version */
#pragma warning(disable: 4996) /* Disable deprecation */
#endif /* #if defined(NMEA_WIN) && (_MSC_VER >= 1400) */
#endif /* #ifndef _DEPRECATION_DISABLE */

# define VISUALC
//# define GNUC

// ----------------------------------- Includes ----------------------------------

// -------------- Add in Main/hpp's As You Need Stream Output ------------ 
#ifdef VISUALC  //===================================================
# include <iostream>
# include <fstream>   
# include <iomanip>
# define VISUALC

#endif// VISUALC  ===================================================

#ifdef GNUC  //======================================================
# include <iostream.h>
# include <iomanip.h>
# include <fstream.h>
# define GNUC
#endif// GNUC  ======================================================

# include <stdio.h> 
# include <string.h> 
# include <stdlib.h>


// ----------------------------------- Defines -----------------------------------
# define UTILITIES 
# define INTERACTIVE // Comment Out To Eliminate all Delays, Clears, etc.

// I/O is not standardized in C/C++ These defines will be used for I/0 processing
// such as clearing the screen, moving the cursor, etc. Select one of the following:

//# define BORLAND_IBM
//# define SYMANTEC_IBM
//# define SYMANTEC_MAC
//# define LINUX
//# define CODE_WARRIOR_IBM
//# define CODE_WARRIOR_MAC
# define MICROSOFT_VISUAL

# define SUCCESSFUL 1
# define UNSUCCESSFUL 0
# define VALID 1
# define INVALID 0

// Define Some Of The Commonly Used Keyboard Characters
# define ESC 27
# define CARRIAGE_RETURN 10
# define LINE_FEED 13

# define UP_ARROW 30
# define DOWN_ARROW 31
# define LEFT_ARROW 28
# define RIGHT_ARROW 29
# define DELETE_KEY 8
# define END_OF_STRING 0
# define BLANK 32
# define NILL 0

using namespace std;

// ------------------------------ String Processing ----------------------------
void StripLeadingBlanks (char String[]);
void StripTrailingBlanks (char String[]);
void ToLowerCase (char String[]);
void ToUpperCase (char String[]);
void CompressMultipleBlanks (char String[]);
void PrepareMatchString (char String[]);
long int RandNo (long int Low, long int High);
// ------------------------------ Screen Processing -----------------------------
void ClearScreen(void);
void HitCarriageReturnToContinue (void);

// ------------------------------ String Processing ----------------------------
template <class T>
void Swap (T & Value1, T & Value2);

// ------------------------------- Non-Template Functions ------------------------
long int FileLength (FILE *FilePtr, long int NoBytesPerRecord);
long int RandNo(long int Low, long int High);
double LOG2(double N);
long int FileLength (char FileName[], long int NoBytesPerRecord);

// ------------------------------ Template Prototypes -----------------------------
template <class InfoType>
bool WriteRecord(InfoType *Info, long int RecordNo, FILE *fp);
template <class InfoType>
bool ReadRecord(InfoType *Info, long int RecordNo, FILE *fp);
void flush_stream(FILE *fp);

// ------------------------------ Template Functions -----------------------------

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                                                              //
//                                      Swap                                    //
//                                                                              //
// Purpose : Exchange the values Value1 and Value2.                             //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 
template <class T>
void Swap (T & Value1, T & Value2)
{
   T
      Temp;

   Temp = Value1;
   Value1 = Value2;
   Value2 = Temp;
}

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                                                              //
//                                 ReadRecord                                   //
//                                                                              //
// Purpose : Read the direct access record RecordNo from file *fp into          //
//           container Info.  No error checking yet!                            //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 
template <class InfoType>
bool ReadRecord(InfoType *Info, long int RecordNo, FILE *fp)
{
	fseek(fp, RecordNo * sizeof(InfoType), SEEK_SET);
	fread(Info, (long)sizeof(InfoType), 1L, fp);
	return (SUCCESSFUL);
}

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                                                              //
//                                WriteRecord                                   //
//                                                                              //
// Purpose : Write the direct access record RecordNo from file *fp from         //
//           container Info.  No error checking yet!                            //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 
template <class InfoType>
bool WriteRecord(InfoType *Info, long int RecordNo, FILE *fp)
{
	fseek(fp, RecordNo * sizeof(InfoType), SEEK_SET);
	fwrite(Info, (long)sizeof(InfoType), 1L, fp);
	return (SUCCESSFUL);
}

# endif