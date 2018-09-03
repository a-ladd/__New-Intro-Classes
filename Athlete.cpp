
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                                                              //
//                                  Athlete.cpp                                 //
//                                                                              //
//  Purpose    : Include all of the non-template methods & functions that       //
//               support the Athlete Class --> Including the test code.         //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

# include "Athlete.hpp"

# pragma region ATHLETE_DIAGNOSTIC_LEVEL_1___Constructor_Destructor //===========
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                    Athlete                                   //
//                                                                              //
//  Purpose : Constructors for Class Athlete. Set Name to NewName and No to     //
//           NewNo, SportNo to NewSportNo, and EquipmentValue to                //
//           NewEquipmentValue.  Defaults for Character Data Members shall be   //
//           blank. Defaults for Numeric Data Members shall be 0.               //
//                                                                              //
//  Written By : Dr. Tom Hicks           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
Athlete::Athlete (char NewName[], int NewNo, int NewSportNo, 
                  double NewEquipmentValue)
{
# ifdef ATHLETE_DIAGNOSTIC_LEVEL //---------------------------------------------------
	if (ATHLETE_DIAGNOSTIC_LEVEL <= 1)
		puts("Evoking Constructor Athlete (NewName,NewNo,NewSportNo,NewEquipmentValue)");
# endif // ATHLETE_DIAGNOSTIC_LEVEL --------------------------------------------------

	Set (NewName, NewNo, NewSportNo, NewEquipmentValue);
}

Athlete::Athlete (int NewNo, char NewName[], int NewSportNo, 
            double NewEquipmentValue)
{
# ifdef ATHLETE_DIAGNOSTIC_LEVEL //---------------------------------------------------
	if (ATHLETE_DIAGNOSTIC_LEVEL <= 1)
		puts("Evoking Constructor Athlete (NewNo,NewName,NewSportNo,NewEquipmentValue)");
# endif // ATHLETE_DIAGNOSTIC_LEVEL --------------------------------------------------

	Set (NewName, NewNo, NewSportNo, NewEquipmentValue);
}

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                    ~Athlete                                  //
//                                                                              //
//  Purpose : Do all that is necessary to destroy an object. In this class we   //
//            are only going to insert a diagnostic display to verify the the   //
//            destructor is firing properly.                                    //
//                                                                              //
//  Written By : Dr. Tom Hicks           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
Athlete::~Athlete (void)
{
# ifdef ATHLETE_DIAGNOSTIC_LEVEL //---------------------------------------------------
	if (ATHLETE_DIAGNOSTIC_LEVEL <= 1)
		puts("Evoking Destructor ~Athlete (void)");
# endif // ATHLETE_DIAGNOSTIC_LEVEL --------------------------------------------------
}

# pragma endregion

# pragma region ATHLETE_DIAGNOSTIC_LEVEL_2___Display //==========================
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                 Method Display                               //
//                                                                              //
//  Purpose : If there is a message, display it --> Return.                     //
//           Then display each of the private data members, one to a line. The  //
//           output should look like:                                           //
//                                                                              //
//           Optional Message .................                                 //
//               Name ...........: Sarah                                        // 
//               No .............: 111                                          // 
//               Sport No .......: 1                                            // 
//               Equipment Value : $ 11.11                                      // 
//               ---- Skip a line ----    .                                     // 
//                                                                              //
//  Written By : Dr. Tom Hicks           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
void Athlete::Display (char Message[])
{
	if (strlen (Message) > 0)
		puts( Message);
	printf("Name ...........: %s\n", Name);
	printf("No .............: %ld\n", No);
	printf("Sport No .......: %ld\n", SportNo);
	printf("Equipment Value : %.2f\n\n", EquipmentValue);
}

# pragma endregion

# pragma region ATHLETE_DIAGNOSTIC_LEVEL_3___Set//================================
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                     Set                                      //
//                                                                              //
//  Purpose : Assign the following: All Character Strings shall default to      //
//                                  blank & all Numerics to 0.                  //
//           Name = NewName                                                     //
//           No = NewNo                                                         //
//           SportNo = NewSportNo                                               //
//           EquipmentValue = NewEquipmentValue                                 //
//                                                                              //
//  Written By : Dr. Tom Hicks           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
void Athlete:: Set (char NewName[], int NewNo, int NewSportNo, 
                    double NewEquipmentValue)
{
   strcpy (Name, NewName);
   No = NewNo;
   SportNo = NewSportNo;
   EquipmentValue = NewEquipmentValue;
}

# pragma endregion

# pragma region ATHLETE_DIAGNOSTIC_LEVEL_4___Get//=================================
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                     Get                                      //
//                                                                              //
//  Purpose : Set is an interactive function in which we will allow the user    //
//            enter data from keyboard.                                         //
//            The prompt for the First Data Member will be:                     //
//	                                                                            //
//                  Enter Name [Hit Return/Enter To Exit]:                      //
//	                                                                            //
//	          This provides the user with an opportunity to exit the function   //
//            without entering all of the data members; after all, they may     //
//            have entered this function by mistake.                            //
//                                                                              //
//            This function will explicitly returns INVALID if user chooses to  //
//            opt out by hitting the return key; otherwise return VALID after   //
//            the user has entered all of the data members. Your processing     //
//            must be exactly as shown below:                                   //
//	                                                                            //
//               Enter Name [Hit Return/Enter To Exit]..: Paul                  // 
//               Enter No ..............................: 3333                  // 
//               Enter Sport No ........................: 11                    // 
//               Enter Equipment Value ................:$ 11.11                 // 
//                                                                              //
//  Written By : Dr. Tom Hicks           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
bool Athlete::Get(void)
{
char
	Temp[200];

	flush_stream(stdin);
	printf ("\nEnter Name [Hit Return/Enter To Exit]..: ");
	gets_s(Temp);
	if (strlen(Temp) == 0)
		return (UNSUCCESSFUL);
	strncpy(Name, Temp, 25);
	Name[25] = 0;

	flush_stream(stdin);
	printf ("\nEnter No ..............................: ");
	scanf ("%ld", &No);

	flush_stream(stdin);
	printf ("\nEnter Sport No ........................: ");
	scanf ("%ld", &SportNo);

	flush_stream(stdin);
	printf ("\nEnter Equipment Value ................:$ ");
	scanf ("%lf", &EquipmentValue);

	flush_stream(stdin);
	return (SUCCESSFUL);
}
# pragma endregion

# pragma region ATHLETE_DIAGNOSTIC_LEVEL_5___Display50//==========================
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                 Display50                                    //
//                                                                              //
//  Purpose : This is nothing more than a diagnostic display utility that will  //
//            display the most important 50 characters of the class. We will    //
//            develop several such utilities. Selecting the items to display    //
//            will often be tough in a class with 100 data members, but it is   //
//            quite easy for this class. This function uses puts & printf.      //
//                                                                              //
//            There will be no line feed. The format is to be  [26 char for     //
//            Name,  2 blanks, 8 char for No, 2 blanks,  2 char for SportNo,    //
//            2 blank, 8 char for EquipmentValue (2 to right of decimal point)  //
//                                                                              //
//           12345678901234567890123456789012345678901234567890                 //
//           --------------------------------------------------                 //
//           Basketball                  123456  22      123.55                 //
//                                                                              //
//  Written By : Dr. Tom Hicks           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
void Athlete::Display50(void)
{
	char
		TempName[30];

	strncpy(TempName, Name, 26);
	TempName[26] = 0;

	printf("%-26s  %8d  %2d  %8.2f", TempName, No, SportNo, EquipmentValue);
}
# pragma endregion

# pragma region ATHLETE_DIAGNOSTIC_LEVEL_6___cout//===============================
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                  << Overload                                 //
//                                                                              //
//  Purpose : This is nothing more than a diagnostic display utility that will  //
//            display the most important 50 characters of the class. We will    //
//            develop several such utilities. Selecting the items to display    //
//            will often be tough in a class with 100 data members, but it is   //
//            quite easy for this class. This function uses puts & printf.      //
//                                                                              //
//            There will be no line feed. The format is to be  [26 char for     //
//            Name,  2 blanks, 8 char for No, 2 blanks,  2 char for SportNo,    //
//            2 blank, 8 char for EquipmentValue (2 to right of decimal point)  //
//                                                                              //
//           12345678901234567890123456789012345678901234567890                 //
//           --------------------------------------------------                 //
//           Basketball                  123456  22      123.55                 //
//                                                                              //
//  Written By : Dr. Tom Hicks           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
ostream & operator << (ostream & OutputStream, Athlete A)
{
	char
		TempName[30];

	strncpy(TempName, A.Name, 26);
	TempName[26] = 0;

	OutputStream << setw(26) << left << TempName;
	OutputStream << "  " << setw(8) << right << A.No;
	OutputStream << "  " << setw(2) << A.SportNo;
	OutputStream.setf(ios::fixed);
	OutputStream.precision(2);
	OutputStream << "  " << setw(8) << A.EquipmentValue;
	return (OutputStream);
}

# pragma endregion

# pragma region ATHLETE_DIAGNOSTIC_LEVEL_7___Key//================================
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                     Key                                      //
//                                                                              //
//  Purpose : Explicitly Return a longeger that represents this Athlete.        //
//            In some classes it will be difficult to determine which long      //
//            integer best represents the object; in this class we have but     //
//            one. Explicitly return the No.                                    //
//                                                                              //
//            Since the data members are generally private, it is not at all    //
//            to have several accessor methods                                  //
//                                                                              //
//  Written By : Dr. Tom Hicks           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 
long int  Athlete::Key(void)
{
	return (No);
}
# pragma endregion

# pragma region ATHLETE_DIAGNOSTIC_LEVEL_8___Char_String_Overloads //=============
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                        char operator Overloads                               //
//                                                                              //
//  Purpose : Overload the operators in such a way that the Name becomes the    //
//            primary character key for the Athlete Class.                      //
//                                                                              //
//            These overloads will better enable us to search, sort, and make   // 
//            decisions involving Athlete objects.                              //
//                                                                              //
//  Written By : Dr. Tom Hicks           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 
bool Athlete::operator == (const char Key[])   
{
   if (strcmp(Name, Key) == 0)
      return (true);
   else 
      return (false);
}
   
bool Athlete::operator > (const char Key[])   
{
   if (strcmp(Name, Key) > 0)
      return (true);
   else 
      return (false);
}

bool Athlete::operator >= (const char Key[])   
{
   if (strcmp(Name, Key) >= 0)
      return (true);
   else 
      return (false);
}

bool Athlete::operator < (const char Key[])   
{
   if (strcmp(Name, Key) < 0)
      return (true);
   else 
      return (false);
}

bool Athlete::operator <= (const char Key[])   
{
   if (strcmp(Name, Key) <= 0)
      return (true);
   else 
      return (false);
}

bool Athlete::operator != (const char Key[])   
{
   if (strcmp(Name, Key) != 0)
      return (true);
   else 
      return (false);
}

void Athlete::operator = (const char Key[])   
{
   strcpy(Name, Key);
}
# pragma endregion

# pragma region ATHLETE_DIAGNOSTIC_LEVEL_9___Long_Integer_Overloads //===========
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                              long Overloads                                  //
//                                                                              //
//  Purpose : Overload the operators in such a way that the No becomes the      //
//            primary longeger key for the Athlete Class.                       //
//                                                                              //
//            These overloads will better enable us to search, sort, and make   // 
//            decisions involving Athlete objects.                              //
//                                                                              //
//  Written By : Dr. Tom Hicks           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 
bool Athlete::operator == (const long int Key)
{
	if (No == Key)
		return (true);
	else
		return (false);
}

bool Athlete::operator > (const long int Key)
{
	if (No > Key)
		return (true);
	else
		return (false);
}

bool Athlete::operator >= (const long int Key)
{
	if (No >= Key)
		return (true);
	else
		return (false);
}

bool Athlete::operator < (const long int Key)
{
	if (No < Key)
		return (true);
	else
		return (false);
}

bool Athlete::operator <= (const long int Key)
{
	if (No <= Key)
		return (true);
	else
		return (false);
}

bool Athlete::operator != (const long int Key)
{
	if (No != Key)
		return (true);
	else
		return (false);
}

void Athlete::operator = (const long int Key)
{
	No = Key;
}

# pragma endregion

# pragma region ATHLETE_DIAGNOSTIC_LEVEL_10___Athlete_Overloads //================
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                            Athlete Object Overloads                          //
//                                                                              //
//  Purpose : Overload the operators in such a way that the Name becomes the    //
//            primary key when comparing two objects of Athlete type.           //
//                                                                              //
//            These overloads will better enable us to search, sort, and make   // 
//            decisions involving Athlete objects.                              //
//                                                                              //
//  Written By : Dr. Tom Hicks           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 
bool Athlete::operator == (const Athlete & A)
{
   if (strcmp(Name, A.Name) == 0)
      return (true);
   else 
      return (false);
}

bool Athlete::operator > (const Athlete & A)
{
   if (strcmp(Name, A.Name) > 0)
      return (true);
   else 
      return (false);
}

bool Athlete::operator >= (const Athlete & A)
{
   if (strcmp(Name, A.Name) >= 0)
      return (true);
   else 
      return (false);
}

bool Athlete::operator < (const Athlete & A)
{
   if (strcmp(Name, A.Name) < 0)
      return (true);
   else 
      return (false);
}

bool Athlete::operator <= (const Athlete & A)
{
   if (strcmp(Name, A.Name) <= 0)
      return (true);
   else 
      return (false);
}


bool Athlete::operator != (const Athlete & A)
{
   if (strcmp(Name, A.Name) != 0)
      return (true);
   else 
      return (false);
}

void Athlete::operator = (const Athlete & A)
{
   strcpy (Name, A.Name);
   No = A.No;
   SportNo = A.SportNo;
   EquipmentValue = A.EquipmentValue;
}

# pragma endregion

# pragma region ATHLETE_DIAGNOSTIC_LEVEL_11__EquipmentValue//=====================
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                               EquipmentValue_                                //
//                                                                              //
//  Purpose : Explicitly Return the EquipmentValue that represents this .       //
//            Athlete.                                                          //
//                                                                              //
//            Since the data members are generally private, it is not at all    //
//            to have several accessor methods                                  //
//                                                                              //
//  Written By : Dr. Tom Hicks           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 
double Athlete::EquipmentValue_(void)
{
	return (EquipmentValue);
}

# pragma endregion

# pragma region ATHLETE_DIAGNOSTIC_LEVEL_12___SportNo//===========================
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                   SportNo_                                   //
//                                                                              //
//  Purpose : Explicitly Return the SportNo that represents this Athlete.       //
//                                                                              //
//            Since the data members are generally private, it is not at all    //
//            to have several accessor methods                                  //
//                                                                              //
//  Written By : Dr. Tom Hicks           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 
int Athlete::SportNo_(void)
{
	return (SportNo);
}

# pragma endregion

# pragma region ATHLETE_DIAGNOSTIC_LEVEL_13___No//================================
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                      No_                                     //
//                                                                              //
//  Purpose : Explicitly Return the No that represents this Athlete.            //
//                                                                              //
//            Since the data members are generally private, it is not at all    //
//            to have several accessor methods                                  //
//                                                                              //
//  Written By : Dr. Tom Hicks           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 
long int  Athlete::No_(void)
{
	return (No);
}

# pragma endregion

# ifdef ATHLETE_DIAGNOSTIC_LEVEL //---------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                 Function TestAthlete                         //
//                                                                              //
//  Purpose : Test each and every method in class Athlete.                      //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
void TestAthlete(void)
{
	puts("\n\n");
	puts("*******************************************************************");
	puts("*******************************************************************");
	puts("*******************************************************************");
	puts("************************ Start TestAthlete ************************");
	puts("*******************************************************************");
	puts("*******************************************************************");
	puts("*******************************************************************");
	puts("*******************************************************************");

# pragma region ATHLETE_DIAGNOSTIC_LEVEL_1___Constructor_Destructor //============
	if (ATHLETE_DIAGNOSTIC_LEVEL <= 1)
	{
	puts("\n\n");
	puts("===================================================================");
	puts("===================================================================");
	puts("===========     Testing Constructor & Destructor     ==============");
	puts("===========       ATHLETE_DIAGNOSTIC_LEVEL = 1       ==============");
	puts("===================================================================");
	puts("===================================================================\n");
		Athlete
			Athlete1,
			Athlete2("Tom"),
			Athlete3("Dick", 333),
			Athlete4("Harry", 444, 11),
			Athlete5("Sally", 555, 1, 55.55),
			Athlete6(666),
			Athlete7(777, "Susan"),
			Athlete8(888, "Angela", 5),
			Athlete9(999, "Rhonda", 4, 99.99),
			CSCI310[4];

   			HitCarriageReturnToContinue();
	}
# pragma endregion

# pragma region ATHLETE_DIAGNOSTIC_LEVEL_2___Display //===========================
	if (ATHLETE_DIAGNOSTIC_LEVEL <= 2)
	{
	puts("\n\n");
	puts("===================================================================");
	puts("===================================================================");
	puts("===========            Testing Display               ==============");
	puts("===========       ATHLETE_DIAGNOSTIC_LEVEL = 2       ==============");
	puts("===================================================================");
	puts("===================================================================\n");
	int
		Pos;
	Athlete
		Athlete1,
		Athlete2("Tom"),
		Athlete3("Dick", 333),
		Athlete4("Harry", 444, 11),
		Athlete5("Sally", 555, 1, 55.55),
		Athlete6(666),
		Athlete7(777, "Susan"),
		Athlete8(888, "Angela", 5),
		Athlete9(999, "Rhonda", 4, 99.99),
		CSCI310[4];

	Athlete9.Display();
	printf("\n----------------------------\n\n");
	Athlete5.Display("Athlete5 Info Is As Follows:");
	printf("\n----------------------------\n\n");
	Athlete1.Display("\nAthlete1 Info Is As Follows:");
	Athlete2.Display("\nAthlete2 Info Is As Follows:");
	Athlete3.Display("\nAthlete3 Info Is As Follows:");
	Athlete4.Display("\nAthlete4 Info Is As Follows:");
	Athlete5.Display("\nAthlete5 Info Is As Follows:");
	Athlete6.Display("\nAthlete6 Info Is As Follows:");
	Athlete7.Display("\nAthlete7 Info Is As Follows:");
	Athlete8.Display("\nAthlete8 Info Is As Follows:");
	Athlete9.Display("\nAthlete9 Info Is As Follows:");
	printf("\n----------------------------\n\n");
	for (Pos = 0; Pos <= 3; Pos++)
		CSCI310[Pos].Display("Displaying An Array Element");
	HitCarriageReturnToContinue();
	}
# pragma endregion	
	
# pragma region ATHLETE_DIAGNOSTIC_LEVEL_3___Set//================================
	if (ATHLETE_DIAGNOSTIC_LEVEL <= 3)
	{
	puts("\n\n");
	puts("===================================================================");
	puts("===================================================================");
	puts("===========              Testing Set                 ==============");
	puts("===========       ATHLETE_DIAGNOSTIC_LEVEL = 3       ==============");
	puts("===================================================================");
	puts("===================================================================\n");
	Athlete
		Athlete1("Sally", 111, 1, 11.11),
		Athlete2(222, "Rhonda", 2, 22.22),
		Athlete3("Angela", 333, 3, 33.33),
		Athlete4(444, "Paul", 14, 44.44),
		Athlete5("Randy", 555, 15, 55.55);

	Athlete1.Display("\nInitial Contents Of Athlete1");
	Athlete2.Display("\nInitial Contents Of Athlete2");
	Athlete3.Display("\nInitial Contents Of Athlete3");
	Athlete4.Display("\nInitial Contents Of Athlete4");
	Athlete5.Display("\nInitial Contents Of Athlete5");

	Athlete1.Set("AAA", 123, 34, 56.78);
	Athlete2.Set("BBB", 234, 56);
	Athlete3.Set("CCC", 345);
	Athlete4.Set("DDD");
	Athlete5.Set();

	Athlete1.Display("\nNew Contents Of Athlete1");
	Athlete2.Display("\nNew Contents Of Athlete2");
	Athlete3.Display("\nNew Contents Of Athlete3");
	Athlete4.Display("\nNew Contents Of Athlete4");
	Athlete5.Display("\nNew Contents Of Athlete5");

	HitCarriageReturnToContinue();
	}
# pragma endregion
	
# pragma region ATHLETE_DIAGNOSTIC_LEVEL_4___Get//================================
	if (ATHLETE_DIAGNOSTIC_LEVEL <= 4)
	{
	puts("\n\n");
	puts("===================================================================");
	puts("===================================================================");
	puts("===========              Testing Get                 ==============");
	puts("===========       ATHLETE_DIAGNOSTIC_LEVEL = 4       ==============");
	puts("===================================================================");
	puts("===================================================================\n");
	Athlete
		Athlete1;

	Athlete1.Display("Blank Athlete1");

	while (Athlete1.Get())
	{
		Athlete1.Display("Newly Filled Athlete1");
		puts("\n\n\n");
	}
	puts("Athlete Fill Was Aborted By Entering A Blank Description");
	HitCarriageReturnToContinue();

	}
# pragma endregion
	
# pragma region ATHLETE_DIAGNOSTIC_LEVEL_5___Display50//===========================
	if (ATHLETE_DIAGNOSTIC_LEVEL <= 5)
	{
	puts("\n\n");
	puts("===================================================================");
	puts("===================================================================");
	puts("===========            Testing Display50             ==============");
	puts("===========       ATHLETE_DIAGNOSTIC_LEVEL = 5       ==============");
	puts("===================================================================");
	puts("===================================================================\n");
	Athlete
		Athlete1("Sally", 111, 1, 11.11),
		Athlete2("Thomas", 222, 2, 22.22);

	puts("------------------------------------------------------");
	puts("| 12345678901234567890123456789012345678901234567890 |");
	puts("------------------------------------------------------");
	printf("| ");
	Athlete1.Display50();
	puts(" |");

	puts("------------------------------------------------------");
	printf("| ");
	Athlete2.Display50();
	puts(" |");
	puts("------------------------------------------------------");

	HitCarriageReturnToContinue();
	}
# pragma endregion
	
# pragma region ATHLETE_DIAGNOSTIC_LEVEL_6___Cout//===============================
	if (ATHLETE_DIAGNOSTIC_LEVEL <= 6)
	{
	puts("\n\n");
	puts("===================================================================");
	puts("===================================================================");
	puts("===========          Testing << Overload             ==============");
	puts("===========        ATHLETE_DIAGNOSTIC_LEVEL = 6      ==============");
	puts("===================================================================");
	puts("===================================================================\n");
	Athlete
	   Athlete1("Sally", 111, 1, 11.11),
	   Athlete2("Thomas", 222, 2, 22.22);

	puts("------------------------------------------------------");
	puts("| 12345678901234567890123456789012345678901234567890 |");
	puts("------------------------------------------------------");
	cout << "| " << Athlete1 << " |" << endl;

	puts("------------------------------------------------------");
	cout << "| " << Athlete2 << " |" << endl;
	puts("------------------------------------------------------");

	HitCarriageReturnToContinue();
	}
# pragma endregion

# pragma region ATHLETE_DIAGNOSTIC_LEVEL_7___Key//================================
	if (ATHLETE_DIAGNOSTIC_LEVEL <= 7)
	{
	puts("\n\n");
	puts("===================================================================");
	puts("===================================================================");
	puts("===========                Testing Key               ==============");
	puts("===========        ATHLETE_DIAGNOSTIC_LEVEL = 7      ==============");
	puts("===================================================================");
	puts("===================================================================\n");
	Athlete
		Athlete1("Sally", 111, 1, 11.11),
		Athlete2(222, "Rhonda", 2, 22.22),
		Athlete3("Angela", 333, 3, 33.33),
		Athlete4(444, "Paul", 14, 44.44),
		Athlete5("Randy", 555, 15, 55.55);


	printf("Athlete1.Key() = %ld\n", Athlete1.Key());
	printf("Athlete2.Key() = %ld\n", Athlete2.Key());
	printf("Athlete3.Key() = %ld\n", Athlete3.Key());
	printf("Athlete4.Key() = %ld\n", Athlete4.Key());
	printf("Athlete5.Key() = %ld\n", Athlete5.Key());

	HitCarriageReturnToContinue();
	}
# pragma endregion

# pragma region ATHLETE_DIAGNOSTIC_LEVEL_8___Char_String_Overloads //=============
	if (ATHLETE_DIAGNOSTIC_LEVEL <= 8)
	{
		puts("\n\n");
		puts("===================================================================");
		puts("===================================================================");
		puts("===========   Test Operator Comparison With Strings  ==============");
		puts("===========      ATHLETE_DIAGNOSTIC_LEVEL = 8        ==============");
		puts("===================================================================");
		puts("===================================================================\n");
		Athlete
			Athlete1("AAA", 444, 4, 44.44),
			Athlete3("TTT", 111, 1, 11.11),
			Athlete5("CCC", 333, 3, 33.33);

		if (Athlete5 == "AAA")                   // Test == Char
			puts("ERROR --> True ---> CCC == AAA");
		else
			puts("CORRECT --> False --> CCC == AAA");
		if (Athlete5 == "CCC")                   // Test == Char
			puts("CORRECT --> True ---> CCC == CCC\n");
		else
			puts("ERROR --> False --> CCC == CCC\n");


		if (Athlete5 > "AAA")                   // Test > Char
			puts("CORRECT --> True ---> CCC > AAA");
		else
			puts("ERROR --> False --> CCC > AAA");
		if (Athlete5 > "FFF")                   // Test > Char
			puts("ERROR --> True ---> CCC > FFF\n");
		else
			puts("CORRECT --> False --> CCC > FFF\n");


		if (Athlete5 >= "AAA")                  // Test >= Char
			puts("CORRECT --> True ---> CCC >= AAA");
		else
			puts("ERROR --> False --> CCC >= AAA");
		if (Athlete5 >= "CCC")                  // Test >= Char
			puts("CORRECT --> True ---> CCC >= CCC");
		else
			puts("ERROR --> False --> CCC >= CCC");
		if (Athlete5 >= "FFF")                  // Test >= Char
			puts("ERROR --> True ---> CCC >= FFF\n");
		else
			puts("CORRECT --> False --> CCC >= FFF\n");


		if (Athlete5 < "AAA")                   // Test < Char
			puts("ERROR --> True ---> CCC < AAA");
		else
			puts("CORRECT --> False --> CCC < AAA");
		if (Athlete5 < "FFF")                   // Test < Char
			puts("CORRECT --> True ---> CCC < FFF\n");
		else
			puts("ERROR --> False --> CCC < FFF\n");


		if (Athlete5 <= "AAA")                   // Test <= Char
			puts("ERROR --> True ---> CCC <= AAA");
		else
			puts("CORRECT --> False --> CCC <= AAA");
		if (Athlete5 <= "CCC")                   // Test <= Char
			puts("CORRECT --> True ---> CCC <= CCC");
		else
			puts("ERROR --> False --> CCC <= CCC");
		if (Athlete5 <= "FFF")                   // Test <= Char
			puts("CORRECT --> True ---> CCC <= FFF\n");
		else
			puts("ERROR --> False --> CCC <= FFF\n");


		if (Athlete5 != "AAA")                   // Test != Char
			puts("CORRECT --> True ---> CCC != AAA");
		else
			puts("ERROR --> False --> CCC != AAA");
		if (Athlete5 != "CCC")                   // Test != Char
			puts("ERROR --> True ---> CCC != CCC\n");
		else
			puts("CORRECT --> False --> CCC != CCC\n");

		Athlete5.Display("\nContents of Athlete5"); // Test = Char
		Athlete5 = "Runner, Road";
		Athlete5.Display("\nNew Contents of Athlete5");

		HitCarriageReturnToContinue();
	}

# pragma endregion

# pragma region ATHLETE_DIAGNOSTIC_LEVEL_9___Long_Overloads //====================
	if (ATHLETE_DIAGNOSTIC_LEVEL <= 9)
	{
		puts("\n\n");
		puts("===================================================================");
		puts("===================================================================");
		puts("===========   Test Operator Comparison With Longs    ==============");
		puts("===========       ATHLETE_DIAGNOSTIC_LEVEL = 9       ==============");
		puts("===================================================================");
		puts("===================================================================\n");

		Athlete
			Athlete5("CCC", 3, 3, 33.33);

		if (Athlete5 == 5)                   // Test == Integer
			puts("ERROR --> True ---> 3 == 5");
		else
			puts("CORRECT --> False --> 3 == 5");
		if (Athlete5 == 3)                   // Test == Integer
			puts("CORRECT --> True ---> 3 == 3\n");
		else
			puts("ERROR --> False --> 3 == 3\n");


		if (Athlete5 > 5)                   // Test > Integer
			puts("ERROR --> True ---> 3 > 5");
		else
			puts("CORRECT --> False --> 3 > 5");
		if (Athlete5 > 1)                   // Test > Integer
			puts("CORRECT --> True ---> 3 > 1\n");
		else
			puts("ERROR --> False --> 3 > 1\n");


		if (Athlete5 >= 5)                   // Test >= Integer
			puts("ERROR --> True ---> 3 >= 5");
		else
			puts("CORRECT --> False --> 3 >= 5");
		if (Athlete5 >= 1)                   // Test >= Integer
			puts("CORRECT --> True ---> 3 >= 1");
		else
			puts("ERROR --> False --> 3 >= 1");
		if (Athlete5 >= 3)                   // Test >= Integer
			puts("CORRECT --> True ---> 3 >= 3\n");
		else
			puts("ERROR --> False --> 3 >= 3\n");


		if (Athlete5 < 5)                   // Test < Integer
			puts("CORRECT --> True ---> 3 < 5");
		else
			puts("ERROR --> False --> 3 < 5");
		if (Athlete5 < 1)                   // Test < Integer
			puts("ERROR --> True ---> 3 < 1\n");
		else
			puts("CORRECT --> False --> 3 < 1\n");


		if (Athlete5 <= 5)                   // Test <= Integer
			puts("CORRECT --> True ---> 3 <= 5");
		else
			puts("ERROR --> False --> 3 <= 5");
		if (Athlete5 <= 1)                   // Test <= Integer
			puts("ERROR --> True ---> 3 <= 1");
		else
			puts("CORRECT --> False --> 3 <= 1");
		if (Athlete5 <= 3)                   // Test <= Integer
			puts("CORRECT --> True ---> 3 <= 3\n");
		else
			puts("ERROR --> False --> 3 <= 3\n");


		if (Athlete5 != 5)                   // Test != Integer
			puts("CORRECT --> True ---> 3 != 5");
		else
			puts("ERROR --> False --> 3 != 5");
		if (Athlete5 != 3)                   // Test != Integer
			puts("ERROR --> True ---> 3 != 3\n");
		else
			puts("CORRECT --> False --> 3 != 3\n");

		Athlete5.Display("\n\nContents of Athlete5"); // Test = Integer
		Athlete5 = 21;
		Athlete5.Display("\nNew Contents of Athlete5");
		HitCarriageReturnToContinue();
	}

# pragma endregion

# pragma region ATHLETE_DIAGNOSTIC_LEVEL10___Athlete_Overloads //=================
	if (ATHLETE_DIAGNOSTIC_LEVEL <= 10)
	{
		puts("\n\n");
		puts("===================================================================");
		puts("===================================================================");
		puts("===========   Test Operator Comparison With Athletes  =============");
		puts("===========       ATHLETE_DIAGNOSTIC_LEVEL = 10       =============");
		puts("===================================================================");
		puts("===================================================================\n");

		Athlete
			Athlete1("AAA", 3, 3, 33.33),
			Athlete3("TTT", 222, 2, 22.22),
			Athlete5("CCC", 111, 1, 11.11);

		if (Athlete5 == Athlete3)                 // Test == Athlete
			puts("ERROR --> True ---> CCC = TTT");
		else
			puts("CORRECT --> False --> CCC = TTT");
		if (Athlete5 == Athlete5)                 // Test == Athlete
			puts("CORRECT --> True ---> CCC = CCC\n");
		else
			puts("ERROR --> False --> CCC = CCC\n");


		if (Athlete5 > Athlete3)                  // Test > Athlete
			puts("ERROR --> True ---> CCC > TTT");
		else
			puts("CORRECT --> False --> CCC > TTT");
		if (Athlete5 > Athlete1)                  // Test > Athlete
			puts("CORRECT --> True ---> CCC > AAA\n");
		else
			puts("ERROR --> False --> CCC > AAA\n");


		if (Athlete5 >= Athlete3)                  // Test >= Athlete
			puts("ERROR --> True ---> CCC >= TTT");
		else
			puts("CORRECT --> False --> CCC >= TTT");
		if (Athlete5 >= Athlete5)                  // Test >= Athlete
			puts("CORRECT --> True ---> CCC >= CCC");
		else
			puts("ERROR --> False --> CCC >= CCC");
		if (Athlete5 >= Athlete1)                  // Test >= Athlete
			puts("CORRECT --> True ---> CCC >= AAA\n");
		else
			puts("ERROR --> False --> CCC >= AAA\n");


		if (Athlete5 < Athlete3)                   // Test < Athlete
			puts("CORRECT --> True ---> CCC < TTT");
		else
			puts("ERROR --> False --> CCC < TTT");
		if (Athlete5 < Athlete1)                   // Test < Athlete
			puts("ERROR --> True ---> CCC < AAA\n");
		else
			puts("CORRECT --> False --> CCC < AAA\n");


		if (Athlete5 <= Athlete3)                   // Test <= Athlete
			puts("CORRECT --> True ---> CCC <= TTT");
		else
			puts("ERROR --> False --> CCC <= TTT");
		if (Athlete5 <= Athlete5)                   // Test <= Athlete
			puts("CORRECT --> True ---> CCC <= CCC");
		else
			puts("ERROR --> False --> CCC <= CCC");
		if (Athlete5 <= Athlete1)                   // Test <= Athlete
			puts("ERROR --> True ---> CCC <= AAA\n");
		else
			puts("CORRECT --> False --> CCC <= AAA\n");


		if (Athlete5 != Athlete3)                   // Test != Athlete
			puts("CORRECT --> True ---> CCC != TTT");
		else
			puts("ERROR --> False --> CCC != TTT");
		if (Athlete5 != Athlete5)                   // Test != Athlete
			puts("ERROR --> True ---> CCC != CCC\n");
		else
			puts("CORRECT --> False --> CCC != CCC\n");

		Athlete5.Display("\nContents of Athlete5");
		Athlete3.Display("\nContents of Athlete3");
		Athlete5 = Athlete3;                        // Test = Athlete
		Athlete5.Display("\nNew Contents of Athlete5");
		Athlete3.Display("\nNew Contents of Athlete3");

		HitCarriageReturnToContinue();
	}

# pragma endregion

# pragma region ATHLETE_DIAGNOSTIC_LEVEL_11___EquipmentValue//====================
	if (ATHLETE_DIAGNOSTIC_LEVEL <= 11)
	{
	puts("\n\n");
	puts("===================================================================");
	puts("===================================================================");
	puts("===========          Testing EquipmentValue_         ==============");
	puts("===========       ATHLETE_DIAGNOSTIC_LEVEL = 11      ==============");
	puts("===================================================================");
	puts("===================================================================\n");
	Athlete
		Athlete1("Sally", 111, 1, 11.11),
		Athlete2(222, "Rhonda", 2, 22.22),
		Athlete3("Angela", 333, 3, 33.33),
		Athlete4(444, "Paul", 14, 44.44),
		Athlete5("Randy", 555, 15, 55.55);

	printf("Athlete1.EquipmentValue_() = %lf\n", Athlete1.EquipmentValue_());
	printf("Athlete2.EquipmentValue_() = %lf\n", Athlete2.EquipmentValue_());
	printf("Athlete3.EquipmentValue_() = %lf\n", Athlete3.EquipmentValue_());
	printf("Athlete4.EquipmentValue_() = %lf\n", Athlete4.EquipmentValue_());
	printf("Athlete5.EquipmentValue_() = %lf\n", Athlete5.EquipmentValue_());

	HitCarriageReturnToContinue();

	}
# pragma endregion

# pragma region ATHLETE_DIAGNOSTIC_LEVEL_12___SportNo//===========================
	if (ATHLETE_DIAGNOSTIC_LEVEL <= 12)
	{
	puts("\n\n");
	puts("===================================================================");
	puts("===================================================================");
	puts("===========               Testing SportNo_           ==============");
	puts("===========        ATHLETE_DIAGNOSTIC_LEVEL = 12     ==============");
	puts("===================================================================");
	puts("===================================================================\n");
	Athlete
		Athlete1("Sally", 111, 1, 11.11),
		Athlete2(222, "Rhonda", 2, 22.22),
		Athlete3("Angela", 333, 3, 33.33),
		Athlete4(444, "Paul", 14, 44.44),
		Athlete5("Randy", 555, 15, 55.55);

	printf("Athlete1.SportNo_() = %ld\n", Athlete1.SportNo_());
	printf("Athlete2.SportNo_() = %ld\n", Athlete2.SportNo_());
	printf("Athlete3.SportNo_() = %ld\n", Athlete3.SportNo_());
	printf("Athlete4.SportNo_() = %ld\n", Athlete4.SportNo_());
	printf("Athlete5.SportNo_() = %ld\n", Athlete5.SportNo_());
	HitCarriageReturnToContinue();
	}
# pragma endregion

# pragma region ATHLETE_DIAGNOSTIC_LEVEL_13___No//================================
	if (ATHLETE_DIAGNOSTIC_LEVEL <= 13)
	{
	puts("\n\n");
	puts("===================================================================");
	puts("===================================================================");
	puts("===========                Testing No_               ==============");
	puts("===========        ATHLETE_DIAGNOSTIC_LEVEL = 13     ==============");
	puts("===================================================================");
	puts("===================================================================\n");
	Athlete
		Athlete1("Sally", 111, 1, 11.11),
		Athlete2(222, "Rhonda", 2, 22.22),
		Athlete3("Angela", 333, 3, 33.33),
		Athlete4(444, "Paul", 14, 44.44),
		Athlete5("Randy", 555, 15, 55.55);

	printf("Athlete1.No_() = %ld\n", Athlete1.No_());
	printf("Athlete2.No_() = %ld\n", Athlete2.No_());
	printf("Athlete3.No_() = %ld\n", Athlete3.No_());
	printf("Athlete4.No_() = %ld\n", Athlete4.No_());
	printf("Athlete5.No_() = %ld\n", Athlete5.No_());
	HitCarriageReturnToContinue();
	}
# pragma endregion

# pragma region ATHLETE_DIAGNOSTIC_LEVEL_14___Athlete_Arrays //===================

	if (ATHLETE_DIAGNOSTIC_LEVEL <= 14)
	{
	puts("\n\n===================================================================");
	puts("===================================================================");
	puts("================      Final Testing Of Array      =================");
	puts("================  ATHLETE_DIAGNOSTIC_LEVEL = 14   =================");
	puts("===================================================================");
	puts("===================================================================\n");
	long
	   Counter;
	Athlete
		Trinity[50];

	Trinity[0].Set("Randy", 1000, 2, 121.11),
	Trinity[1].Set("Sarah", 1001, 1, 11.11),
	Trinity[2].Set("Michael", 1002, 11, 22.22),
	Trinity[3].Set("Rebecca", 1003, 2, 33.33),
	Trinity[4].Set("Thomas", 1004, 12, 44.44),
	Trinity[5].Set("Nancy", 1005, 3, 44.44);
	Trinity[6].Set("David", 1006, 15, 66.66);
	Trinity[7].Set("Hunter", 1007, 11, 77.77);
	Trinity[8].Set("Jeremy", 1008, 12, 88.88);
	Trinity[9].Set("David", 1009, 13, 99.99);
	Trinity[10].Set("Mahlon", 1010, 14, 10.10);
	Trinity[11].Set("Richard", 1011, 15, 11.11);
	Trinity[12].Set("Paul", 1012, 11, 12.12);
	Trinity[13].Set("Benjamin", 1013, 11, 123.);
	Trinity[14].Set("Reed", 1014, 1, 234.);
	Trinity[15].Set("Lamonte", 1015, 2, 15.5);
	Trinity[16].Set("Thoai", 1016, 1, 22.33);
	Trinity[17].Set("Zachary", 1017, 2, 34.34);
	Trinity[18].Set("Ben", 1018, 1, 19.9);
	Trinity[19].Set("Yusuf", 1019, 14, 87.33);
	Trinity[20].Set("Gabriel", 1020, 1, 104.44);
	Trinity[21].Set("Eric", 1021, 2, 123.45);
	Trinity[22].Set("Aexander", 1022, 3, 29.19);
	Trinity[23].Set("Mohamed", 1023, 3, 99.99);
	Trinity[24].Set("Justino", 1024, 3, 88.88);
	Trinity[25].Set("Lauren", 1025, 4, 177.77);
	Trinity[26].Set("Robert", 1026, 4, 66.66);
	Trinity[27].Set("Jane", 1027, 5, 55.55);
	Trinity[28].Set("Judy", 1028, 6, 3.42);
	Trinity[29].Set("Carol", 1029, 7, 22.23);
	Trinity[30].Set("Doc", 1030, 8, 12.12);

	puts("      ------------------------------------------------------");
	puts("      | 12345678901234567890123456789012345678901234567890 |");
	puts("      ------------------------------------------------------");
	for (Counter = 0; Counter <= 30; Counter++)
	{
		printf("%5ld | ", Counter);
		flush_stream(stdout);
		cout << Trinity[Counter];
		puts(" |");
	}
	puts("      ------------------------------------------------------");
	HitCarriageReturnToContinue();
	}
# pragma endregion
	
	puts("\n\n");
	puts("*******************************************************************");
	puts("*******************************************************************");
	puts("*******************************************************************");
	puts("*******************************************************************");
	puts("************************** End TestAthlete ************************");
	puts("*******************************************************************");
	puts("*******************************************************************");
	puts("*******************************************************************");
	puts("*******************************************************************\n\n");
}

# endif // ATHLETE_DIAGNOSTIC_LEVEL --------------------------------------------------

