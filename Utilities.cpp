/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
//                              Utilities.cpp                                  //
//                                                                             //
// Purpose : Common utility applications used in lots of programs.             //
//                                                                             //
//  Written By : Thomas E. Hicks         Environment : Windows 10              //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++  //
/////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////// 
# include "Utilities.hpp"
# define _CRT_SECURE_NO_DEPRECATE 1

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                              flush_stream                                    //
//                                                                              //
// Purpose : Empty the stream buffer.                                           //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
void flush_stream(FILE *fp)
{
	if (NULL != fp)
		fseek(fp, 0, SEEK_END);
}

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                              FileLength                                      //
//                                                                              //
// Purpose : Explicitly return the number of records in the open direct         //
//            access file referenced by FilePtr.                                //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
long int FileLength (FILE *FilePtr, long int NoBytesPerRecord)
{
	long int
		Bytes;

	fseek (FilePtr, 0L, SEEK_END);
	Bytes = ftell (FilePtr);
	return (Bytes / NoBytesPerRecord);    //Returns number of records in file
}

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                              FileLength                                      //
//                                                                              //
// Purpose : Explicitly return the number of records in the closed direct       //
//            access file whose name is FileName.                               //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
long int FileLength (char FileName[], long int NoBytesPerRecord)
{
FILE
	*fp;
long int
	NoRecords;

	fp = fopen (FileName, "rb+");
	NoRecords =  FileLength (fp,NoBytesPerRecord);
	fclose(fp);
	return (NoRecords);    //Returns number of records in file
}

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                           StripLeadingBlanks                                 //
//                                                                              //
// Purpose : Remove all leading blanks from String[].                           //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 
void StripLeadingBlanks (char String[])
{
   long int 
      Pos2, // First Non-Blank Char
      Pos1;

   Pos2 = 0;

// Set Pos2 to the first non blank character.
   while (String [Pos2] == ' ')
      Pos2 ++;

// Copy valid characters to the beginning of the string..
   for (Pos1 = 0; String[Pos2] != '\0'; Pos1++, Pos2++)
      String[Pos1] = String[Pos2];

// Insert the End of String Marker..
      String[Pos1] = '\0';
}

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                             StripTrailingBlanks                              //
//                                                                              //
//  Purpose : Remove all trailing blanks. String *Tom Hicks * becomes string    //
//  *Tom Hicks*                                                                 //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 
void StripTrailingBlanks (char String[])
{
  size_t 
      Pos;

   Pos = strlen(String)-1;

// Set Pos to the last non blank character.
   while (String [Pos] == ' ')
   {
      Pos --;
   }

// Insert the End of String Marker..
   String[Pos +1] = '\0';
}

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                ToLowerCase                                   //
//                                                                              //
//  Purpose : Convert String[] to all lower case characters. String *tOm HiCKs* //
//  becomes string *tom hicks*                                                  //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 
void ToLowerCase (char String[])
{
   unsigned long int 
      Pos;

   for (Pos = 0; Pos <= strlen(String); Pos ++)
   {
      if ((String[Pos] >= 'A') && (String[Pos] <= 'Z')) 
         String[Pos] = String[Pos] + ' ';
   }
}

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                   ToUpperCase                                //
//                                                                              //
// Purpose : Convert String[] to all upper case characters. String *tOm HiCKs*  //
// becomes string *TOM HICKS*                                                   //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 
void ToUpperCase (char String[])
{
   unsigned long int 
      Pos;

   for (Pos = 0; Pos <= strlen(String); Pos ++)
   {
      if ((String[Pos] >= 'a') && (String[Pos] <= 'z')) 
         String[Pos] = String[Pos] - ' ';
   }
}

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                           CompressMultipleBlanks                             //
//                                                                              //
// Purpose : Compress multiple blanks to a single blank. String *Tom Hicks*     //
// becomes string *Tom Hicks*                                                   //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 
void CompressMultipleBlanks (char String[])
{
// For you to do if you want it!
}

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                           PrepareMatchString                                 //
//                                                                              //
// Purpose : Strip Leading Blanks, Strip Trailing Blanks, Compress Multiple     //
// Blanks and change to Lower Case. String * tOm HiCKs *                        //
// would be changed to *tom hicks* for more accurate pattern                    //
// matching.                                                                    //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 
void PrepareMatchString (char String[])
{
   StripLeadingBlanks (String);
   StripTrailingBlanks (String);
   ToLowerCase (String);
   CompressMultipleBlanks (String);
}

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                        HitCarriageReturnToContinue                           //
//                                                                              //
// Purpose : Delay until the user strikes the return key.                       //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 
void HitCarriageReturnToContinue(void)
{
	char
		JunkString[5000];

	flush_stream(stdin);
	printf("--------- <Hit Enter/Return Key To Continue> ---------- ");
	gets_s(JunkString);
}

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                 LOG2                                         //
//                                                                              //
// Purpose : Explicitly return Log(Base 2) Of N.                                //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 
double LOG2(double N)
{
	return log(N) / log(2.);
}

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                    RandomNo                                  //
//                                                                              //
// Purpose : Explicitly return a Random Number (1 Billion Possibilities)        //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
long int RandNo(long int Low, long int High)
{
long int 
	A, B, C, No;
			
	A = rand() % 1000;
	B = rand() % 1000;
	C = rand() % 1000;

	 No = ((A * 1000000 + B * 1000 + C) % (High - Low + 1)) + Low;
	return No;
}

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                ClearScreen                                   //
//                                                                              //
// Purpose : Clear the console window in accordance with the monitor/operating  //
//           System.                                                            //
//                                                                              //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
void ClearScreen(void)
{
#ifdef SYMANTEC_MAC //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	printf("\f");
#endif //SYMANTEC_MAC ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#ifdef MICROSOFT_VISUAL //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	system("cls");
#endif //MICROSOFT_VISUAL ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#ifdef BORLAND_IBM //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	clrscr();
#endif //BORLAND_IBM +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#ifdef LINUX //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	system("clear");
#endif //LINUX ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#ifdef CURSES //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	clear();
	refresh();
#endif //CURSES ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
}
