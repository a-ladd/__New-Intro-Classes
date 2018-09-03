//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                                                              //
//                                  Auto.cpp                                    //
//                                                                              //
//  Purpose    : Include all of the non-template methods & functions that       //
//               support the Auto Class --> Including the test code.            //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

# include "Auto.hpp"

# pragma region AUTO_DIAGNOSTIC_LEVEL_1___Constructor_Destructor //===========
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                    Auto                                      //
//                                                                              //
//  Purpose : Constructors for Class Auto. Set Description to NewDescription    //
//           and No to NewNo and Style to NewStyle. Default NewDescription =    //
//           blank. Default NewNo = 0. Default Style = CONVERTABLE = false.     //
//                                                                              //
//  Written By : Dr. Tom Hicks           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
Auto::Auto(char NewDescription[], long NewNo, bool NewStyle)
{
# ifdef AUTO_DIAGNOSTIC_LEVEL //---------------------------------------------------
	if (AUTO_DIAGNOSTIC_LEVEL <= 1)
		puts("Evoking Constructor Auto (NewDescription[], NewNo, NewStyle)");
# endif // AUTO_DIAGNOSTIC_LEVEL --------------------------------------------------

	strcpy_s(Description, NewDescription);
	No = NewNo;
	Style = NewStyle;
}

Auto::Auto(long NewNo, char NewDescription[], bool NewStyle)
{
# ifdef AUTO_DIAGNOSTIC_LEVEL //-------------------------------
	if (AUTO_DIAGNOSTIC_LEVEL <= 1)
		puts("Evoking Constructor Auto (NewNo, NewDescription[], NewStyle)");
# endif // AUTO_DIAGNOSTIC_LEVEL ------------------------------

	strcpy_s(Description, NewDescription);
	No = NewNo;
	Style = NewStyle;
}

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                    ~Auto                                     //
//                                                                              //
//  Purpose : Do all that is necessary to destroy an object. In this class we   //
//            are only going to insert a diagnostic display to verify the the   //
//            destructor is firing properly.                                    //
//                                                                              //
//  Written By : Dr. Tom Hicks           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
Auto::~Auto(void)
{
# ifdef AUTO_DIAGNOSTIC_LEVEL //--------------------------------------
	if (AUTO_DIAGNOSTIC_LEVEL <= 1)
		puts("Evoking Destructor ~Auto(void)");
# endif // AUTO_DIAGNOSTIC_LEVEL -------------------------------------

}
# pragma endregion

# pragma region AUTO_DIAGNOSTIC_LEVEL_2___Display //==========================
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                 Method Display                               //
//                                                                              //
//  Purpose : If there is a message, display it --> Return.                     //
//           Then display each of the private data members, one to a line. The  //
//           output should look like:                                           //
//                                                                              //
//           Optional Message .................                                 //
//           Description ...:  Proche 911                                       //
//           No ............:  1207                                             //
//           Style .........:  Convertable                                      //
//             ---- Skip a line ----    .                                       // 
//                                                                              //
//  Written By : Dr. Tom Hicks           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 
void Auto::Display(char Message[])

{
	if (strlen(Message) > 0)
		puts(Message);
	printf("Description ...:  %-s\n", Description);
	printf("No ............:  %ld\n", No);
	if (Style == CONVERTABLE)
		puts("Style .........:  Convertable\n\n");
	else
		puts("Style .........:  Coop\n\n");
}
# pragma endregion

# pragma region AUTO_DIAGNOSTIC_LEVEL_3___Set//================================
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                     Set                                      //
//                                                                              //
//  Purpose : Assign the following:                                             //
//                                                                              //
//           Description = NewDescription                                       //
//           No = NewNo                                                         //
//           Style = NewStyle                                                   //
//                                                                              //
//  Written By : Dr. Tom Hicks           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
void Auto::Set(char NewDescription[], long int NewNo, bool NewStyle)
{
	strcpy_s(Description, NewDescription);
	No = NewNo;
	Style = NewStyle;
}
# pragma endregion

# pragma region AUTO_DIAGNOSTIC_LEVEL_4___Get//===============================
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                     Get                                      //
//                                                                              //
//  Purpose : Set is an interactive function in which we will allow the user    //
//            enter data from keyboard.                                         //
//            The prompt for the First Data Member will be:                     //
//	                                                                            //
//                  Enter Description [Hit Return/Enter To Exit]:               //
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
//           Enter Description [Hit Return/Enter To Exit].: Proche 911          //  
//           Enter No ....................................: 1207                //
//           Enter Coop Or Convertable [C/V)].............: C                   //
//                                                                              //
//  Written By : Dr. Tom Hicks           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
bool Auto::Get(void)
{
	char
		Temp[200],
		StyleChar;

	flush_stream(stdin);
	printf("\nEnter Description [Hit Return/Enter To Exit].: ");
	gets_s(Temp);
	if (strlen(Temp) == 0)
		return (INVALID);
	strncpy_s(Description, Temp, 19);
	Description[19] = 0;
	flush_stream(stdin);
	printf("\nEnter No ....................................: ");
	scanf("%d", &No);

	flush_stream(stdin);
	printf("\nEnter Coop Or Convertable [C/V)].............: ");
	scanf("%c", &StyleChar);
	if (StyleChar == 'C')
		Style = COUP;
	else
		Style = CONVERTABLE;
	flush_stream(stdin);
	return (VALID);
}
# pragma endregion

# pragma region AUTO_DIAGNOSTIC_LEVEL_5___Display50//==========================
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
//            Description,  2 blanks, 9 char for No, 2 blanks,  and the         //
//            specified Style {i.e.Coop Or Convertable}.                        //
//                                                                              //
//           12345678901234567890123456789012345678901234567890                 //
//           --------------------------------------------------                 //
//           Jaguar                      123456789  Convertable                 //
//                                                                              //
//  Written By : Dr. Tom Hicks           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
void Auto::Display50(void)
{
	if (Style == CONVERTABLE)
		printf("%-26s  %9ld  Convertable", Description, No);
	else
		printf("%-26s  %9ld  Coop       ", Description, No);
}
# pragma endregion

# pragma region AUTO_DIAGNOSTIC_LEVEL_6___cout//===============================
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
//            Description,  2 blanks, 9 char for No, 2 blanks,  and the         //
//            specified Style {i.e.Coop Or Convertable}.                        //
//                                                                              //
//           12345678901234567890123456789012345678901234567890                 //
//           --------------------------------------------------                 //
//           Jaguar                      123456789  Convertable                 //
//                                                                              //
//  Written By : Dr. Tom Hicks           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
ostream & operator << (ostream & OutputStream, Auto S)
{
	char
		TempDescription[50];

	strncpy_s(TempDescription, S.Description, 26);
	TempDescription[26] = 0;

	flush_stream(stdout);
	OutputStream << setw(26) << left << TempDescription;
	OutputStream << "  " << right << setw(9) << S.No << "  ";
	if (S.Style == CONVERTABLE)
		OutputStream << "Convertable";
	else
		OutputStream << "Coop       ";
	return (OutputStream);
}
# pragma endregion

# pragma region AUTO_DIAGNOSTIC_LEVEL_7___Key//================================
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                     Key                                      //
//                                                                              //
//  Purpose : Explicitly Return a long integer that represents this student.    //
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
long  Auto::Key(void)
{
	return (No);
}
# pragma endregion

# pragma region AUTO_DIAGNOSTIC_LEVEL_8___Char_String_Overloads //=============
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                        char operator Overloads                               //
//                                                                              //
//  Purpose : Overload the operators in such a way that the Description         //
//            becomes the primary character key for the Auto Class.             //
//                                                                              //
//            These overloads will better enable us to search, sort, and make   // 
//            decisions involving Auto objects.                                 //
//                                                                              //
//  Written By : Dr. Tom Hicks           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 
bool Auto::operator > (const char Key[])
{
	if (strcmp(Description, Key) > 0)
		return (true);
	else
		return (false);
}

bool Auto::operator < (const char Key[])
{
	if (strcmp(Description, Key) < 0)
		return (true);
	else
		return (false);
}

bool Auto::operator <= (const char Key[])
{
	if (strcmp(Description, Key) <= 0)
		return (true);
	else
		return (false);
}

bool Auto::operator >= (const char Key[])
{
	if (strcmp(Description, Key) >= 0)
		return (true);
	else
		return (false);
}

bool Auto::operator != (const char Key[])
{
	if (strcmp(Description, Key) != 0)
		return (true);
	else
		return (false);
}

bool Auto::operator == (const char Key[])
{
	if (strcmp(Description, Key) == 0)
		return (true);
	else
		return (false);
}

void Auto::operator = (const char Key[])
{
	strcpy_s(Description, Key);
}

# pragma endregion

# pragma region AUTO_DIAGNOSTIC_LEVEL_9___Long_Integer_Overloads //===========
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                              long Overloads                                  //
//                                                                              //
//  Purpose : Overload the operators in such a way that the No becomes the      //
//            primary long integer key for the Auto Class.                      //
//                                                                              //
//            These overloads will better enable us to search, sort, and make   // 
//            decisions involving Auto objects.                                 //
//                                                                              //
//  Written By : Dr. Tom Hicks           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 
bool Auto::operator == (const long Key)
{
	if (No == Key)
		return (true);
	else
		return (false);
}

bool Auto::operator > (const long Key)
{
	if (No > Key)
		return (true);
	else
		return (false);
}

bool Auto::operator >= (const long Key)
{
	if (No >= Key)
		return (true);
	else
		return (false);
}

bool Auto::operator < (const long Key)
{
	if (No < Key)
		return (true);
	else
		return (false);
}

bool Auto::operator <= (const long Key)
{
	if (No <= Key)
		return (true);
	else
		return (false);
}

bool Auto::operator != (const long Key)
{
	if (No != Key)
		return (true);
	else
		return (false);
}

void Auto::operator = (const long Key)
{
	No = Key;
}

# pragma endregion

# pragma region AUTO_DIAGNOSTIC_LEVEL_10___Auto_Overloads //===================
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                            Auto Object Overloads                             //
//                                                                              //
//  Purpose : Overload the operators in such a way that the Description becomes //
//            the primary key when comparing two objects of Auto type.          //
//                                                                              //
//            These overloads will better enable us to search, sort, and make   // 
//            decisions involving Auto objects.                                 //
//                                                                              //
//  Written By : Dr. Tom Hicks           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 
bool Auto::operator == (const Auto & S)
{
	if (strcmp(Description, S.Description) == 0)
		return (true);
	else
		return (false);
}

bool Auto::operator > (const Auto & S)
{
	if (strcmp(Description, S.Description) > 0)
		return (true);
	else
		return (false);
}

bool Auto::operator >= (const Auto & S)
{
	if (strcmp(Description, S.Description) >= 0)
		return (true);
	else
		return (false);
}

bool Auto::operator < (const Auto & S)
{
	if (strcmp(Description, S.Description) < 0)
		return (true);
	else
		return (false);
}

bool Auto::operator <= (const Auto & S)
{
	if (strcmp(Description, S.Description) <= 0)
		return (true);
	else
		return (false);
}


bool Auto::operator != (const Auto & S)
{
	if (strcmp(Description, S.Description) != 0)
		return (true);
	else
		return (false);
}

void Auto::operator = (const Auto & S)
{
	strcpy(Description, S.Description);
	No = S.No;
	Style = S.Style;
}

# pragma endregion


# ifdef AUTO_DIAGNOSTIC_LEVEL //--------------------------------------
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                               Function TestAuto                              //
//                                                                              //
//  Purpose : Test each and every method in class Auto.                         //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
void TestAuto(void)
{
	puts("\n\n");
	puts("*******************************************************************");
	puts("*******************************************************************");
	puts("************************** Start TestAuto *************************");
	puts("*******************************************************************");
	puts("*******************************************************************");

# pragma region AUTO_DIAGNOSTIC_LEVEL_1___Constructor_Destructor //============
	if (AUTO_DIAGNOSTIC_LEVEL <= 1)
	{
		puts("\n\n");
		puts("===================================================================");
		puts("===================================================================");
		puts("===========     Testing Constructor & Destructor     ==============");
		puts("===========        AUTO_DIAGNOSTIC_LEVEL = 1         ==============");
		puts("===================================================================");
		puts("===================================================================\n");
		Auto
			Auto1,
			Auto2("Porche", 2222, COUP),
			Auto3("Mustang", 3333),
			Auto4("Audi"),
			Auto5(5555, "Ford F150 King Ranch", COUP),
			Auto6(6666, "Honda Accord"),
			Auto7(7777),
			Class[4];

		HitCarriageReturnToContinue();
	}
# pragma endregion

# pragma region AUTO_DIAGNOSTIC_LEVEL_2___Display //============================
	if (AUTO_DIAGNOSTIC_LEVEL <= 2)
	{
		puts("\n\n");
		puts("===================================================================");
		puts("===================================================================");
		puts("===========            Testing Display               ==============");
		puts("===========        AUTO_DIAGNOSTIC_LEVEL = 2         ==============");
		puts("===================================================================");
		puts("===================================================================\n");
		Auto
			Auto1,
			Auto2("Porche", 2222, COUP),
			Auto3("Mustang", 3333),
			Auto4("Audi"),
			Auto5(5555, "Ford F150 King Ranch", COUP),
			Auto6(6666, "Honda Accord"),
			Auto7(7777),
			Class[4];

		Auto1.Display("This Is Auto1");
		Auto2.Display();
		Auto3.Display("This Is Auto3");
		Auto4.Display("This Is Auto4");
		Auto5.Display("This Is Auto5");
		Auto6.Display("This Is Auto6");
		Auto7.Display("This Is Auto7");
		for (int ClassNo = 0; ClassNo <= 3; ClassNo++)
			Class[ClassNo].Display();

		HitCarriageReturnToContinue();
	}
# pragma endregion

# pragma region AUTO_DIAGNOSTIC_LEVEL_3___Set//================================
	if (AUTO_DIAGNOSTIC_LEVEL <= 3)
	{
		puts("\n\n");
		puts("===================================================================");
		puts("===================================================================");
		puts("===========              Testing Set                 ==============");
		puts("===========        AUTO_DIAGNOSTIC_LEVEL = 3         ==============");
		puts("===================================================================");
		puts("===================================================================\n");
		Auto
			Auto1,
			Auto2("Porche", 1234, COUP),
			Class[4];

		Auto1.Set("Alpha", 111, CONVERTABLE);
		Auto1.Display("Auto1 Set With Alpha, 111, CONVERTABLE");
		Class[0].Set("Beta", 222);
		Class[0].Display("Class[0] Set With Beta, 222");
		Class[1].Set("Gamma");
		Class[1].Display("Class[1] Set With Gamma");      
		Auto1.Set();
		Auto1.Display("Auto1");


		HitCarriageReturnToContinue();
	}

# pragma endregion

# pragma region AUTO_DIAGNOSTIC_LEVEL_4___Get//================================
	if (AUTO_DIAGNOSTIC_LEVEL <= 4)
	{
		puts("\n\n");
		puts("===================================================================");
		puts("===================================================================");
		puts("===========              Testing Get                 ==============");
		puts("===========        AUTO_DIAGNOSTIC_LEVEL = 4         ==============");
		puts("===================================================================");
		puts("===================================================================\n");
		Auto
			Auto1,
			Class[4];

		if (Auto1.Get())
			Auto1.Display("\nAuto1:");
		else
			puts("\nYou Chose Not To Enter Data For Auto1\n");
		if (Class[3].Get())
			Class[3].Display("\nClass[3]:");
		else
			puts("\nYou Chose Not To Enter Data For Class[3]\n");


		HitCarriageReturnToContinue();
	}

# pragma endregion

# pragma region AUTO_DIAGNOSTIC_LEVEL_5___Set//================================
	if (AUTO_DIAGNOSTIC_LEVEL <= 5)
	{
		puts("\n\n");
		puts("===================================================================");
		puts("===================================================================");
		puts("===========            Testing Display50             ==============");
		puts("===========        AUTO_DIAGNOSTIC_LEVEL = 5         ==============");
		puts("===================================================================");
		puts("===================================================================\n");
		Auto
			Auto2("Porche", 123456, COUP),
			Auto5(5, "Jaguar", CONVERTABLE);

		puts("------------------------------------------------------");
		puts("| 12345678901234567890123456789012345678901234567890 |");
		puts("------------------------------------------------------");
		printf("| ");
		Auto2.Display50();
		puts(" |");

		puts("------------------------------------------------------");
		printf("| ");
		Auto5.Display50();
		puts(" |");
		puts("------------------------------------------------------");

		HitCarriageReturnToContinue();
	}
# pragma endregion

# pragma region AUTO_DIAGNOSTIC_LEVEL_6___Cout//================================
	if (AUTO_DIAGNOSTIC_LEVEL <= 6)
	{
		puts("\n\n");
		puts("===================================================================");
		puts("===================================================================");
		puts("===========          Testing << Overload             ==============");
		puts("===========        AUTO_DIAGNOSTIC_LEVEL = 6         ==============");
		puts("===================================================================");
		puts("===================================================================\n");
		Auto
			Auto2("Porche", 123456, COUP),
			Auto5(5, "Jaguar", CONVERTABLE);

		puts("------------------------------------------------------");
		puts("| 12345678901234567890123456789012345678901234567890 |");
		puts("------------------------------------------------------");
		cout << "| " << Auto2 << " |" << endl;

		puts("------------------------------------------------------");
		cout << "| " << Auto5 << " |" << endl;
		puts("------------------------------------------------------");

		HitCarriageReturnToContinue();
	}
# pragma endregion

# pragma region AUTO_DIAGNOSTIC_LEVEL_7___Cout//================================
	if (AUTO_DIAGNOSTIC_LEVEL <= 7)
	{
		puts("\n\n");
		puts("===================================================================");
		puts("===================================================================");
		puts("===========               Testing Key                ==============");
		puts("===========        AUTO_DIAGNOSTIC_LEVEL = 7         ==============");
		puts("===================================================================");
		puts("===================================================================\n");
		Auto
			Auto2("Porche", 123456, COUP),
			Auto5(5555, "Jaguar", CONVERTABLE);

		printf("Auto2.Key() = %ld\n", Auto2.Key());
		printf("Auto5.Key() = %ld\n", Auto5.Key());

		HitCarriageReturnToContinue();
	}
# pragma endregion

# pragma region AUTO_DIAGNOSTIC_LEVEL_8___Char_String_Overloads //==============
	if (AUTO_DIAGNOSTIC_LEVEL <= 8)
	{
		puts("\n\n");
		puts("===================================================================");
		puts("===================================================================");
		puts("===========   Test Operator Comparison With Strings  ==============");
		puts("===========        AUTO_DIAGNOSTIC_LEVEL = 8         ==============");
		puts("===================================================================");
		puts("===================================================================\n");

		Auto
			Auto2("CCC", 3, COUP),
			Auto5("Doug", 20, COUP);

		Auto5.Display("Info Stored In Auto5:");
		if (Auto5 == "Doug")
			puts("CORRECT ==> Auto.Description == 'Doug'");
		else
			puts("ERROR ==> Auto.Description != 'Doug'");

		if (Auto5 == " Doug")
			puts("ERROR ==> Auto.Description == ' Doug'");
		else
			puts("CORRECT ==> Auto.Description != ' Doug'");


		if (Auto5 == "Doug ")
			puts("ERROR ==> Auto.Description == 'Doug '");
		else
			puts("CORRECT ==> Auto.Description != 'Doug '");


		if (Auto5 == "   dOuG   ")
			puts("ERROR ==> Auto.Description == '   dOuG   '");
		else
			puts("CORRECT ==> Auto.Description != '   dOuG   '");

		if (Auto5 == "Harry")
			puts("ERROR ==> Auto.Description == Harry");
		else
			puts("CORRECT ==> Auto.Description != Harry");

		Auto2.Display("\nInfo Stored In Auto2:");
		
		if (Auto2 == "AAA")                   // Test = Char
			puts("ERROR ==> True ---> CCC = AAA");
		else
			puts("CORRECT ==> False --> CCC = AAA");
		
		if (Auto2 > "AAA")                   // Test > Char
			puts("CORRECT ==> True ---> CCC > AAA");
		else
			puts("ERROR ==>  ==> False --> CCC > AAA");
		
		if (Auto2 >= "AAA")                   // Test >= Char
			puts("CORRECT ==> True ---> CCC >= AAA");
		else
			puts("ERROR ==> False --> CCC >= AAA\n");

		if (Auto2 < "AAA")                   // Test < Char
			puts("ERROR ==> True ---> CCC < AAA");
		else
			puts("CORRECT ==> False --> CCC < AAA");

		if (Auto2 <= "AAA")                   // Test <= Char
			puts("ERROR ==> True ---> CCC <= AAA\n");
		else
			puts("CORRECT ==> False --> CCC <= AAA");
		
		if (Auto2 != "AAA")                   // Test != Char
			puts("CORRECT ==> True ---> CCC != AAA");
		else
			puts("ERROR ==> False --> CCC != AAA");
		Auto2.Display("\nContents of Auto2"); // Test = Char
		Auto2 = "David";
		Auto2.Display("\nNew Contents of Auto2");

		HitCarriageReturnToContinue();
	}
# pragma endregion

# pragma region AUTO_DIAGNOSTIC_LEVEL_9___Long_Integer_Overloads //=============

	if (AUTO_DIAGNOSTIC_LEVEL <= 9)
	{
		puts("\n\n");
		puts("===================================================================");
		puts("===================================================================");
		puts("========= Test Operator Comparison With Long Integers  ============");
		puts("=========        AUTO_DIAGNOSTIC_LEVEL = 9             ============");
		puts("===================================================================");
		puts("===================================================================\n");

		Auto
			Auto5("CCC", 3, COUP);

		if (Auto5 == 5)                   // Test = Integer
			puts("ERROR ==> True ---> 3 == 5");
		else
			puts("CORRECT ==> False --> 3 == 5");
		
		if (Auto5 > 5)                   // Test > Integer
			puts("ERROR ==> True ---> 3 > 5");
		else
			puts("CORRECT ==> False --> 3 > 5");
		
		if (Auto5 >= 5)                   // Test >= Integer
			puts("ERROR ==> True ---> 3 >= 5");
		else
			puts("CORRECT ==> False --> 3 >= 5");
		
		if (Auto5 < 5)                   // Test < Integer
			puts("CORRECT ==> True ---> 3 < 5");
		else
			puts("ERROR ==> False --> 3 < 5");

		if (Auto5 <= 5)                   // Test <= Integer
			puts("CORRECT ==> True ---> 3 <= 5");
		else
			puts("ERROR ==> False --> 3 <= 5");
		
		if (Auto5 != 5)                   // Test != Integer
			puts("CORRECT ==> True ---> 3 != 5");
		else
			puts("ERROR ==> False --> 3 != 5");

		Auto5.Display("\nContents of Auto5"); // Test = Integer
		Auto5 = 21;
		Auto5.Display("\nNew Contents of Auto5");
		HitCarriageReturnToContinue();
	}

# pragma endregion

# pragma region AUTO_DIAGNOSTIC_LEVEL_10___Auto_Overloads //====================
	if (AUTO_DIAGNOSTIC_LEVEL <= 10)
	{
		puts("\n\n");
		puts("===================================================================");
		puts("===================================================================");
		puts("=======       Test Operator Comparison With Autos      ============");
		puts("=======            AUTO_DIAGNOSTIC_LEVEL = 10          ============");
		puts("===================================================================");
		puts("===================================================================\n");
		Auto
			Auto3("Jaguar", 21, COUP),
			Auto5("Audi TT", 5, COUP);

		if (Auto5 == Auto3)                 // Test == Auto
			puts("ERROR ==> True ---> Audi TT = Jaguar");
		else
			puts("CORRECT ==> False --> Audi TT = Jaguar");

		if (Auto5 > Auto3)                  // Test > Auto
			puts("ERROR ==> True ---> Audi TT > Jaguar");
		else
			puts("CORRECT ==> False --> Audi TT > Jaguar");

		if (Auto5 >= Auto3)                  // Test >= Auto
			puts("ERROR ==> True ---> Audi TT >= Jaguar");
		else
			puts("CORRECT ==> False --> Audi TT >= Jaguar");

		if (Auto5 < Auto3)                   // Test < Auto
			puts("CORRECT ==> True ---> Audi TT < Jaguar");
		else
			puts("ERROR ==> False --> Audi TT < Jaguar\n");

		if (Auto5 <= Auto3)                   // Test < Auto
			puts("CORRECT ==> True ---> Audi TT <= Jaguar");
		else
			puts("ERROR ==> False --> Audi TT <= Jaguar\n");

		if (Auto5 != Auto3)                   // Test != Auto
			puts("CORRECT ==> True ---> Audi TT != Jaguar");
		else
			puts("ERROR ==> False --> Audi TT != Jaguar\n");

		Auto5.Display("\nNew Contents of Auto5");
		Auto3.Display("New Contents of Auto3");
		Auto5 = Auto3;                        // Test = Auto
		Auto5.Display("New Contents of Auto5");
		Auto3.Display("New Contents of Auto3");
		HitCarriageReturnToContinue();

	}
# pragma endregion

# pragma region AUTO_DIAGNOSTIC_LEVEL_11___Auto_Overloads //====================
	if (AUTO_DIAGNOSTIC_LEVEL <= 11)
	{
		puts("\n\n");
		puts("===================================================================");
		puts("===================================================================");
		puts("=======              Final Testing Of Array            ============");
		puts("=======            AUTO_DIAGNOSTIC_LEVEL = 11          ============");
		puts("===================================================================");
		puts("===================================================================\n");
		long
			Counter;
		Auto
			Autos[30];
			
		Autos[0].Set("Corvette Stingray", 101, CONVERTABLE);
		Autos[1].Set("Porche 911", 102, CONVERTABLE);
		Autos[2].Set("VW", 103, CONVERTABLE);
		Autos[3].Set("Limo", 104, COUP);
		Autos[4].Set("Lincoln Continental", 105, CONVERTABLE);
		Autos[5].Set("Maxima", 106, COUP);
		Autos[6].Set("Mercury Cougar", 107, CONVERTABLE);
		Autos[7].Set("Mustang", 108, COUP);
		Autos[8].Set("Explorer", 109, CONVERTABLE);
		Autos[9].Set("Lincoln Towncar", 200, CONVERTABLE);
		Autos[10].Set("Chevrolet Capri", 201, CONVERTABLE);
		Autos[11].Set("Jaguar", 202, COUP);
		Autos[12].Set("Honda 2000", 203, CONVERTABLE);

		puts("      ------------------------------------------------------");
		puts("      | 12345678901234567890123456789012345678901234567890 |");
		puts("      ------------------------------------------------------");
		for (Counter = 0; Counter <= 12; Counter++)
		{
			printf("%5ld | ", Counter);
			flush_stream(stdout);
			cout << Autos[Counter];
			puts(" |");
		}
		puts("      ------------------------------------------------------");
		HitCarriageReturnToContinue();

	}

# pragma endregion
	
	puts("*******************************************************************");
	puts("*******************************************************************");
	puts("**************************  End TestAuto  *************************");
	puts("*******************************************************************");
	puts("*******************************************************************");
}
# endif // AUTO_DIAGNOSTIC_LEVEL -------------------------------------

