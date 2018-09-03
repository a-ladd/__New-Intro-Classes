//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                                                              //
//                                  Client.cpp                                  //
//                                                                              //
//  Purpose    : Include all of the non-template methods & functions that       //
//               support the Client Class --> Including the test code.          //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

# include "Client.hpp"

# pragma region CLIENT_DIAGNOSTIC_LEVEL_1___Constructor_Destructor //===========
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                    Client                                    //
//                                                                              //
//  Purpose : Constructors for Class Client. Set Name to NewName and ID to      //
//           NewID, HeaderNo to NewHeaderNo, PayRate to NewPayRate, and GPA to  //
//           NewGPA.  Defaults for Character Data Members shall be blank.       //
//           Defaults for Numeric Data Members shall be 0.                      //
//                                                                              //
//  Written By : Dr. Tom Hicks           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
Client::Client(char NewName[] , long NewID, long NewHeaderNo,
	double NewPayRate, double NewGPA)
{
# ifdef CLIENT_DIAGNOSTIC_LEVEL //---------------------------------------------------
	if (CLIENT_DIAGNOSTIC_LEVEL <= 1)
		puts("Evoking Constructor Client (NewName[], NewID, NewHeaderNo, NewPayRate, NewGPA)");
# endif // CLIENT_DIAGNOSTIC_LEVEL --------------------------------------------------

	strcpy(Name, NewName);
	ID = NewID;
	HeaderNo = NewHeaderNo;
	GPA = NewGPA;
	PayRate = NewPayRate;
}

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                    ~Client                                     //
//                                                                              //
//  Purpose : Do all that is necessary to destroy an object. In this class we   //
//            are only going to insert a diagnostic display to verify the the   //
//            destructor is firing properly.                                    //
//                                                                              //
//  Written By : Dr. Tom Hicks           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
Client::~Client(void)
{
# ifdef CLIENT_DIAGNOSTIC_LEVEL //---------------------------------------------------
	if (CLIENT_DIAGNOSTIC_LEVEL <= 1)
		puts("Evoking Destructor ~Client (void)");
# endif // CLIENT_DIAGNOSTIC_LEVEL --------------------------------------------------

}
# pragma endregion

# pragma region CLIENT_DIAGNOSTIC_LEVEL_2___Display //==========================
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                 Method Display                               //
//                                                                              //
//  Purpose : If there is a message, display it --> Return.                     //
//           Then display each of the private data members, one to a line. The  //
//           output should look like:                                           //
//                                                                              //
//           Optional Message .................                                 //
//              Name...........: John Doe                                       //
//              ID ............: 1207                                           //
//              HeaderNo.......: 12                                             //
//              GPA ...........: 3.30   --> (2 digit )                          //
//              PayRate ......:$ 16.25  --> (2 digits)                          //
//               ---- Skip a line ----    .                                     // 
//                                                                              //
//  Written By : Dr. Tom Hicks           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
void Client::Display(char Message[])
{
	if (strlen(Message) > 0)
		puts(Message);
	printf("Name...........: %s\n", Name);
	printf("ID ............: %ld\n", ID);
	printf("HeaderNo.......: %ld\n", HeaderNo);
	printf("GPA ...........: %.2lf\n", GPA);
	printf("PayRate ......:$ %.2lf\n\n", PayRate);
}

# pragma endregion

# pragma region CLIENT_DIAGNOSTIC_LEVEL_3___Set//================================
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                     Set                                      //
//                                                                              //
//  Purpose : Assign the following: All Character Strings shall default to      //
//                                  blank & all Numerics to 0.                  //
//           Name = NewName                                                     //
//           ID = NewID                                                         //
//           HeaderNo = NewHeaderNo                                             //
//           GPA = NewGPA                                                       //
//           PayRate = NewPayRate                                               //
//                                                                              //
//  Written By : Dr. Tom Hicks           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

void Client::Set(char NewName[], long NewID, long NewHeaderNo,
	double NewPayRate, double NewGPA)
{
	strcpy(Name, NewName);
	ID = NewID;
	HeaderNo = NewHeaderNo;
	GPA = NewGPA;
	PayRate = NewPayRate;
}
# pragma endregion

# pragma region CLIENT_DIAGNOSTIC_LEVEL_4___Get//===============================
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
//           Enter Client Name [Hit Return/Enter To Exit]..: John Doe           //  
//           Enter Client ID ..............................: 1207               //
//           Enter HeaderNo ...............................: 12                 //
//           Enter GPA ....................................: 3.3                //
//           Enter PayRate ...............................:$ 16.25              //
//                                                                              //
//  Written By : Dr. Tom Hicks           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
bool Client::Get(void)
{
	char
		Temp[200];

	flush_stream(stdin);
	printf ("\nEnter Client Name [Hit Return/Enter To Exit]..: ");
	gets_s(Temp);
	if (strlen(Temp) == 0)
		return (INVALID);
	strncpy_s(Name, Temp, 25);
	Name[25] = 0;
	
	flush_stream(stdin);
	printf ("\nEnter Client ID ..............................: ");
	scanf ("%ld", &ID);

	flush_stream(stdin);
	printf ("\nEnter HeaderNo ...............................: ");
	scanf ("%ld", &HeaderNo);

	flush_stream(stdin);
	printf ("\nEnter GPA ....................................: ");
	scanf ("%lf", &GPA);

	flush_stream(stdin);
	printf ("\nEnter PayRate ...............................:$ ");
	scanf ("%lf", &PayRate);
	flush_stream(stdin);

	flush_stream(stdin);
	return (VALID);
}
# pragma endregion

# pragma region CLIENT_DIAGNOSTIC_LEVEL_5___Display50//==========================
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
//            There will be no line feed. The format is to be  [20 char for     //
//            Name,  1 blank, 8 char for ID, 1 blank,  6 char for HeaderNo,     //
//            1 blank, 7 char for PayRate (2 to right of decimal point),        //
//            1 blanks,  5 char for GPA (2 to right of decimal point).          //
//                                                                              //
//           12345678901234567890123456789012345678901234567890                 //
//           --------------------------------------------------                 //
//           John Doe                  111     22    3.00  2.97                 //
//                                                                              //
//  Written By : Dr. Tom Hicks           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
void Client::Display50(void)
{
	printf("%-20s %8ld %6ld %7.2lf %5.2lf", Name, ID, HeaderNo, PayRate, GPA);
}
# pragma endregion

# pragma region CLIENT_DIAGNOSTIC_LEVEL_6___cout//===============================
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
//            There will be no line feed. The format is to be  [20 char for     //
//            Name,  1 blank, 8 char for ID, 1 blank,  6 char for HeaderNo,     //
//            1 blank, 7 char for PayRate (2 to right of decimal point),        //
//            1 blanks,  5 char for GPA (2 to right of decimal point).          //
//                                                                              //
//           12345678901234567890123456789012345678901234567890                 //
//           --------------------------------------------------                 //
//           John Doe                  111     22    3.00  2.97                 //
//                                                                              //
//  Written By : Dr. Tom Hicks           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
ostream & operator << (ostream & OutputStream, Client P)
{
	char
		TempName[50];

	strncpy_s(TempName, P.Name, 19);
	TempName[19] = 0;

	OutputStream << setw(20) << left << TempName;
	OutputStream << " " << right << setw(6) << P.ID;
	OutputStream << " " << setw(6) << P.HeaderNo;
	OutputStream.setf(ios::fixed);
	OutputStream.precision(2);
	OutputStream << " " << setw(6) << P.PayRate;
	OutputStream.setf(ios::fixed);
	OutputStream.precision(2);
	OutputStream << " " << setw(8) << P.GPA;
	return (OutputStream);
}
# pragma endregion

# pragma region CLIENT_DIAGNOSTIC_LEVEL_7___Key//================================
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                     Key                                      //
//                                                                              //
//  Purpose:  Explicitly Return a long that represents this Client.             //
//            In some classes it will be difficult to determine which long      //
//            integer best represents the object; in this class we have only    //
//            a few choices. Explicitly return the ID.                          //
//                                                                              //
//            Since the data members are generally private, it is not at all    //
//            to have several accessor methods                                  //
//                                                                              //
//  Written By : Dr. Tom Hicks           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              ComB.ler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 
long  Client::Key(void)
{
	return (ID);
}
# pragma endregion

# pragma region CLIENT_DIAGNOSTIC_LEVEL_8___Char_String_Overloads //=============
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                        char operator Overloads                               //
//                                                                              //
//  Purpose : Overload the operators in such a way that the Name becomes the    //
//            primary character key for the Client Class.                       //
//                                                                              //
//            These overloads will better enable us to search, sort, and make   // 
//            decisions involving Client objects.                               //
//                                                                              //
//  Written By : Dr. Tom Hicks           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 
bool Client::operator == (const char Key[])
{
	if (strcmp(Name, Key) == 0)
		return (true);
	else
		return (false);
}

bool Client::operator > (const char Key[])
{
	if (strcmp(Name, Key) > 0)
		return (true);
	else
		return (false);
}

bool Client::operator >= (const char Key[])
{
	if (strcmp(Name, Key) >= 0)
		return (true);
	else
		return (false);
}

bool Client::operator < (const char Key[])
{
	if (strcmp(Name, Key) < 0)
		return (true);
	else
		return (false);
}

bool Client::operator <= (const char Key[])
{
	if (strcmp(Name, Key) <= 0)
		return (true);
	else
		return (false);
}

bool Client::operator != (const char Key[])
{
	if (strcmp(Name, Key) != 0)
		return (true);
	else
		return (false);
}

void Client::operator = (const char Key[])
{
	strcpy(Name, Key);
}


# pragma endregion

# pragma region CLIENT_DIAGNOSTIC_LEVEL_9___Long_Integer_Overloads //===========
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                              long Overloads                                  //
//                                                                              //
//  Purpose : Overload the operators in such a way that the ID becomes the      //
//            primary longeger key for the Client Class.                        //
//                                                                              //
//            These overloads will better enable us to search, sort, and make   // 
//            decisions involving Client objects.                               //
//                                                                              //
//  Written By : Dr. Tom Hicks           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 
bool Client::operator == (const long Key)
{
	if (ID == Key)
		return (true);
	else
		return (false);
}

bool Client::operator > (const long Key)
{
	if (ID > Key)
		return (true);
	else
		return (false);
}

bool Client::operator >= (const long Key)
{
	if (ID >= Key)
		return (true);
	else
		return (false);
}

bool Client::operator < (const long Key)
{
	if (ID < Key)
		return (true);
	else
		return (false);
}

bool Client::operator <= (const long Key)
{
	if (ID <= Key)
		return (true);
	else
		return (false);
}

bool Client::operator != (const long Key)
{
	if (ID != Key)
		return (true);
	else
		return (false);
}

void Client::operator = (const long Key)
{
	ID = Key;
}

# pragma endregion

# pragma region CLIENT_DIAGNOSTIC_LEVEL_10___Client_Overloads //================
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                            Client Object Overloads                           //
//                                                                              //
//  Purpose : Overload the operators in such a way that the Name becomes the    //
//            primary key when comparing two objects of Client type.            //
//                                                                              //
//            These overloads will better enable us to search, sort, and make   // 
//            decisions involving Client objects.                               //
//                                                                              //
//  Written By : Dr. Tom Hicks           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 
bool Client::operator == (const Client & P)
{
	if (strcmp(Name, P.Name) == 0)
		return (true);
	else
		return (false);
}

bool Client::operator > (const Client & P)
{
	if (strcmp(Name, P.Name) > 0)
		return (true);
	else
		return (false);
}

bool Client::operator >= (const Client & P)
{
	if (strcmp(Name, P.Name) >= 0)
		return (true);
	else
		return (false);
}

bool Client::operator < (const Client & P)
{
	if (strcmp(Name, P.Name) < 0)
		return (true);
	else
		return (false);
}

bool Client::operator <= (const Client & P)
{
	if (strcmp(Name, P.Name) <= 0)
		return (true);
	else
		return (false);
}


bool Client::operator != (const Client & P)
{
	if (strcmp(Name, P.Name) != 0)
		return (true);
	else
		return (false);
}

void Client::operator = (const Client & P)
{
	strcpy(Name, P.Name);
	ID = P.ID;
	GPA = P.GPA;
	PayRate = P.PayRate;
	HeaderNo = P.HeaderNo;
}
# pragma endregion

# pragma region CLIENT_DIAGNOSTIC_LEVEL_11___GPA//==============================
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                     GPA_                                     //
//                                                                              //
//  Purpose : Explicitly Return the GPA that represents this part.              //
//                                                                              //
//            Since the data members are generally private, it is not at all    //
//            to have several accessor methods                                  //
//                                                                              //
//  Written By : Dr. Tom Hicks           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 
double  Client::GPA_(void)
{
	return (GPA);
}
# pragma endregion

# pragma region CLIENT_DIAGNOSTIC_LEVEL_12___PayRate//==========================
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                  PayRate_                                    //
//                                                                              //
//  Purpose : Explicitly Return the PayRate that represents this part.          //
//                                                                              //
//            Since the data members are generally private, it is not at all    //
//            to have several accessor methods                                  //
//                                                                              //
//  Written By : Dr. Tom Hicks           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 
double Client::PayRate_(void)
{
	return (PayRate);
}
# pragma endregion

# pragma region CLIENT_DIAGNOSTIC_LEVEL_13___HeaderNo//============================
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                    HeaderNo_                                 //
//                                                                              //
//  Purpose : Explicitly Return the HeaderNo that represents this part.         //
//                                                                              //
//            Since the data members are generally private, it is not at all    //
//            to have several accessor methods                                  //
//                                                                              //
//  Written By : Dr. Tom Hicks           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 
long  Client::HeaderNo_(void)
{
	return (HeaderNo);
}
# pragma endregion

# ifdef CLIENT_DIAGNOSTIC_LEVEL //---------------------------------------------------

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                 Function TestClient                            //
//                                                                              //
//  Purpose : Test each and every method in class Client.                         //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
void TestClient(void)
{
	puts("\n\n*******************************************************************");
	puts("*******************************************************************");
	puts("*******************************************************************");
	puts("*******************************************************************");
	puts("*********************** Start TestClient **************************");
	puts("*******************************************************************");
	puts("*******************************************************************");
	puts("*******************************************************************");
	puts("*******************************************************************");

	
# pragma region CLIENT_DIAGNOSTIC_LEVEL_1___Constructor_Destructor //============
	if (CLIENT_DIAGNOSTIC_LEVEL <= 1)
	{
		puts("\n\n");
		puts("===================================================================");
		puts("===================================================================");
		puts("===========     Testing Constructor & Destructor     ==============");
		puts("===========         CLIENT_DIAGNOSTIC_LEVEL = 1        ==============");
		puts("===================================================================");
		puts("===================================================================\n");
		Client
			Client1,
			Client2("Jane Doe"),
			Client3("John Doe", 111),
			Client4("Road Runner", 222, 10),
			Client5("Mickey Mouse", 333, 2, 25),
			Client6("Pluto", 444, 10, 5, 3.25),
			Company[4];
		HitCarriageReturnToContinue();
	}
# pragma endregion

# pragma region CLIENT_DIAGNOSTIC_LEVEL_2___Display //============================
	if (CLIENT_DIAGNOSTIC_LEVEL <= 2)
	{
		puts("\n\n");
		puts("===================================================================");
		puts("===================================================================");
		puts("===========            Testing Display               ==============");
		puts("===========       CLIENT_DIAGNOSTIC_LEVEL = 2        ==============");
		puts("===================================================================");
		puts("===================================================================\n");
		Client
			Client1,
			Client2("Jane Doe"),
			Client3("John Doe", 111),
			Client4("Road Runner", 222, 10),
			Client5("Mickey Mouse", 333, 2, 25),
			Client6("Pluto", 444, 10, 5, 3.25),
			Company[4];

		Client1.Display("\nContents Of Client1");
		Client2.Display("\nContents Of Client2");
		Client3.Display("\nContents Of Client3");
		Client4.Display("\nContents Of Client4");
		Client5.Display("\nContents Of Client5");
		Client6.Display("\nContents Of Client6");
		Company[0].Display();
		Company[1].Display();
		Company[2].Display();
		Company[3].Display();
		HitCarriageReturnToContinue();
	}
# pragma endregion

# pragma region CLIENT_DIAGNOSTIC_LEVEL_3___Set//================================
	if (CLIENT_DIAGNOSTIC_LEVEL <= 3)
	{
		puts("\n\n");
		puts("===================================================================");
		puts("===================================================================");
		puts("===========              Testing Set                 ==============");
		puts("===========       CLIENT_DIAGNOSTIC_LEVEL = 3        ==============");
		puts("===================================================================");
		puts("===================================================================\n");
		Client
			Client1;

		Client1.Set("Jane Doe");
		Client1.Display("Jane Doe");
		Client1.Set("John Doe", 111);
		Client1.Display("John Doe - 111");
		Client1.Set("Road Runner", 222, 10);
		Client1.Display("Road Runner - 222 - 10");
		Client1.Set("Mickey Mouse", 333, 10, 2.2);
		Client1.Display("Mickey Mouse - 333 - 10 - 2.2");
		Client1.Set("Pluto", 444, 10, 5, 3.99);
		Client1.Display("Pluto - 444 - 10 - 5 - 3.99");

		HitCarriageReturnToContinue();
	}

# pragma endregion

# pragma region CLIENT_DIAGNOSTIC_LEVEL_4___Get//================================
	if (CLIENT_DIAGNOSTIC_LEVEL <= 4)
	{
		puts("\n\n");
		puts("===================================================================");
		puts("===================================================================");
		puts("===========              Testing Get                 ==============");
		puts("===========       CLIENT_DIAGNOSTIC_LEVEL = 4        ==============");
		puts("===================================================================");
		puts("===================================================================\n");
		Client
			Client1,
			Class[4];

		if (Client1.Get())
			Client1.Display("\nClient1:");
		else
			puts("\nYou Chose IDt To Enter Data For Client1\n");
		if (Class[3].Get())
			Class[3].Display("\nClass[3]:");
		else
			puts("\nYou Chose IDt To Enter Data For Class[3]\n");


		HitCarriageReturnToContinue();
	}

# pragma endregion

# pragma region CLIENT_DIAGNOSTIC_LEVEL_5___Set//================================
	if (CLIENT_DIAGNOSTIC_LEVEL <= 5)
	{
		puts("\n\n");
		puts("===================================================================");
		puts("===================================================================");
		puts("===========            Testing Display50             ==============");
		puts("===========        CLIENT_DIAGNOSTIC_LEVEL = 5       ==============");
		puts("===================================================================");
		puts("===================================================================\n");
		Client
			Client2("John Doe", 111, 22, 3, 2.97),
			Client5("Pluto", 444, 10, 39.41, 3.);

		puts("------------------------------------------------------");
		puts("| 12345678901234567890123456789012345678901234567890 |");
		puts("------------------------------------------------------");
		printf("| ");
		Client2.Display50();
		puts(" |");

		puts("------------------------------------------------------");
		printf("| ");
		Client5.Display50();
		puts(" |");
		puts("------------------------------------------------------");

		HitCarriageReturnToContinue();
	}
# pragma endregion

# pragma region CLIENT_DIAGNOSTIC_LEVEL_6___Cout//================================
	if (CLIENT_DIAGNOSTIC_LEVEL <= 6)
	{
		puts("\n\n");
		puts("===================================================================");
		puts("===================================================================");
		puts("===========          Testing << Overload             ==============");
		puts("===========        CLIENT_DIAGNOSTIC_LEVEL = 6       ==============");
		puts("===================================================================");
		puts("===================================================================\n");
		Client
			Client2("John Doe", 111, 22, 3, 2.97),
			Client5("Pluto", 444, 10, 39.41, 3.);

		puts("------------------------------------------------------");
		puts("| 12345678901234567890123456789012345678901234567890 |");
		puts("------------------------------------------------------");
		cout << "| " << Client2 << " |" << endl;

		puts("------------------------------------------------------");
		cout << "| " << Client5 << " |" << endl;
		puts("------------------------------------------------------");

		HitCarriageReturnToContinue();
	}
# pragma endregion

# pragma region CLIENT_DIAGNOSTIC_LEVEL_7___Key//================================
	if (CLIENT_DIAGNOSTIC_LEVEL <= 7)
	{
		puts("\n\n");
		puts("===================================================================");
		puts("===================================================================");
		puts("===========                Testing Key               ==============");
		puts("===========        CLIENT_DIAGNOSTIC_LEVEL = 7       ==============");
		puts("===================================================================");
		puts("===================================================================\n");
		Client
			Client1,
			Client2("Jane Doe", 155),
			Client3("John Doe", 111, 123),
			Client4("Road Runner", 222, 10),
			Client5("Mickey Mouse", 333, 2, 25),
			Client6("Pluto", 444, 10, 5, 3.25),
			Company[4];

		printf("Client1.Key() = %ld\n", Client1.Key());
		printf("Client2.Key() = %ld\n", Client2.Key());
		printf("Client3.Key() = %ld\n", Client3.Key());
		printf("Client4.Key() = %ld\n", Client4.Key());
		printf("Client5.Key() = %ld\n", Client5.Key());
		printf("Company[1].Key() = %ld\n\n\n", Company[1].Key());
		HitCarriageReturnToContinue();

		HitCarriageReturnToContinue();
	}
# pragma endregion

# pragma region CLIENT_DIAGNOSTIC_LEVEL_8___Char_String_Overloads //=============
	if (CLIENT_DIAGNOSTIC_LEVEL <= 8)
	{
		puts("\n\n");
		puts("===================================================================");
		puts("===================================================================");
		puts("===========   Test Operator Comparison With Strings  ==============");
		puts("===========      CLIENT_DIAGNOSTIC_LEVEL = 8         ==============");
		puts("===================================================================");
		puts("===================================================================\n");

		Client
			Client3("Jane Doe", 44),
			Client5("CCC", 3);

		Client3.Display("\nInfo Stored In Client3:");
		if (Client3 == "Jane Doe")
			puts("CORRECT ==> Client.Name == 'Jane Doe'");
		else
			puts("ERROR ==> Client.Name != 'Jane Doe'");
		if (Client3 == "Jane Doe ")
			puts("ERROR ==> Client.Name == 'Jane Doe '");
		else
			puts("CORRECT ==> Client.Name != 'Jane Doe '");
		if (Client3 == " Jane Doe")
			puts("ERROR ==> Client.Name == ' Jane Doe'");
		else
			puts("CORRECT ==> Client.Name != ' Jane Doe'");


		if (Client3 == "jane doe")
			puts("ERROR ==> Client.Name == 'jane doe'");
		else
			puts("CORRECT ==> Client.Name != 'jane doe'");

		if (Client3 == "JANE DOE")
			puts("ERROR ==> Client.Name == JANE DOE");
		else
			puts("CORRECT ==> Client.Name != JANE DOE");

		if (Client5 == "AAA")                   // Test = Char
			puts("ERROR ==> True ---> CCC = AAA");
		else
			puts("CORRECT ==> False --> CCC = AAA");
		if (Client5 > "AAA")                   // Test > Char
			puts("CORRECT ==> True ---> CCC > AAA");
		else
			puts("ERROR ==> False --> CCC > AAA");
		if (Client5 >= "AAA")                   // Test >= Char
			puts("CORRECT ==> True ---> CCC >= AAA");
		else
			puts("CORRECT ==> False --> CCC >= AAA");
		if (Client5 < "AAA")                   // Test < Char
			puts("ERROR ==> True ---> CCC < AAA");
		else
			puts("CORRECT ==> False --> CCC < AAA");
		if (Client5 <= "AAA")                   // Test <= Char
			puts("ERROR ==> True ---> CCC <= AAA");
		else
			puts("CORRECT ==> False --> CCC <= AAA");
		if (Client5 != "AAA")                   // Test != Char
			puts("CORRECT ==> True ---> CCC != AAA");
		else
			puts("ERROR ==> False --> CCC != AAA");

		Client5.Display("\n\nContents of Client5"); // Test = Char
		Client5 = "PlutoBall";
		Client5.Display("New Contents of Client5");

		HitCarriageReturnToContinue();
	}
# pragma endregion

# pragma region CLIENT_DIAGNOSTIC_LEVEL_9___Long_Integer_Overloads //============

	if (CLIENT_DIAGNOSTIC_LEVEL <= 9)
	{
		puts("\n\n");
		puts("===================================================================");
		puts("===================================================================");
		puts("========= Test Operator Comparison With Long Integers  ============");
		puts("=========        CLIENT_DIAGNOSTIC_LEVEL = 9           ============");
		puts("===================================================================");
		puts("===================================================================\n");

		Client
			Client3("Roger Rabbit", 44),
			Client5("Jane Doe", 55);

		Client5.Set("CCC", 3);
		if (Client5 == 5)                   // Test = Integer
			puts("ERROR ==> True ---> 3 == 5");
		else
			puts("CORRECT ==> False --> 3 == 5");
		if (Client5 > 5)                   // Test > Integer
			puts("ERROR ==> True ---> 3 > 5");
		else
			puts("CORRECT ==> False --> 3 > 5");
		if (Client5 >= 5)                   // Test >= Integer
			puts("ERROR ==> True ---> 3 >= 5");
		else
			puts("CORRECT ==> False --> 3 >= 5");
		if (Client5 < 5)                   // Test < Integer
			puts("CORRECT ==> True ---> 3 < 5");
		else
			puts("ERROR ==> False --> 3 < 5");
		if (Client5 <= 5)                   // Test <= Integer
			puts("CORRECT ==> True ---> 3 <= 5");
		else
			puts("ERROR ==> False --> 3 <= 5");
		if (Client5 != 5)                   // Test != Integer
			puts("CORRECT ==> True ---> 3 != 5");
		else
			puts("ERROR ==> False --> 3 != 5");
		Client5.Display("\n\nContents of Client5"); // Test = Integer
		Client5 = 21;
		Client5.Display("New Contents of Client5");
		HitCarriageReturnToContinue();

	}

# pragma endregion

# pragma region CLIENT_DIAGNOSTIC_LEVEL_10___Client_Overloads //===================
	if (CLIENT_DIAGNOSTIC_LEVEL <= 10)
	{
		puts("\n\n");
		puts("===================================================================");
		puts("===================================================================");
		puts("=======       Test Operator Comparison With Clients    ============");
		puts("=======            CLIENT_DIAGNOSTIC_LEVEL = 10        ============");
		puts("===================================================================");
		puts("===================================================================\n");
		Client
			Client3("John Doe", 44),
			Client5("Jane Doe", 55);

		if (Client5 == Client3)                 // Test == Client
			puts("ERROR ==> True ---> John Doe = Jane Doe");
		else
			puts("CORRECT ==> False --> John Doe = Jane Doe");

		if (Client5 > Client3)                  // Test > Client
			puts("ERROR ==> True ---> John Doe > Jane Doe");
		else
			puts("CORRECT ==> False --> John Doe > Jane Doe");

		if (Client5 >= Client3)                  // Test >= Client
			puts("ERROR ==> True ---> John Doe >= Jane Doe");
		else
			puts("CORRECT ==> False --> John Doe >= Jane Doe");

		if (Client5 < Client3)                   // Test < Client
			puts("CORRECT ==> True ---> John Doe < Jane Doe");
		else
			puts("ERROR ==> False --> John Doe < Jane Doe");

		if (Client5 <= Client3)                   // Test < Client
			puts("CORRECT ==> True ---> John Doe <= Jane Doe");
		else
			puts("ERROR ==> False --> John Doe <= Jane Doe");

		if (Client5 != Client3)                   // Test != Client
			puts("CORRECT ==> True ---> John Doe != Jane Doe");
		else
			puts("ERROR ==> False --> John Doe != Jane Doe");

		Client5.Display("\nNew Contents of Client5");
		Client3.Display("\nNew Contents of Client3");
		Client5 = Client3;                        // Test = Client
		Client5.Display("\nNew Contents of Client5");
		Client3.Display("\nNew Contents of Client3");
		HitCarriageReturnToContinue();
	}
# pragma endregion

# pragma region CLIENT_DIAGNOSTIC_LEVEL_11___GPA//==============================
	if (CLIENT_DIAGNOSTIC_LEVEL <= 11)
	{
		puts("\n\n");
		puts("===================================================================");
		puts("===================================================================");
		puts("===========               Testing GPA_               ==============");
		puts("===========       CLIENT_DIAGNOSTIC_LEVEL = 11       ==============");
		puts("===================================================================");
		puts("===================================================================\n");
		Client
			Client1,
			Client2("Jane Doe", 22, 1, 4, 1.1),
			Client3("Daffy", 33, 1, 6, 2.2),
			Client5("Donald", 44, 1, 5, 3),
			Client4("John Doe", 11, 1, 10, 3.99),
			Company[4];

		printf("Client1.GPA_() = %lf\n", Client1.GPA_());
		printf("Client2.GPA_() = %lf\n", Client2.GPA_());
		printf("Client3.GPA_() = %lf\n", Client3.GPA_());
		printf("Client4.GPA_() = %lf\n", Client4.GPA_());
		printf("Client5.GPA_() = %lf\n", Client5.GPA_());
		printf("Company[1].GPA_() = %lf\n\n\n", Company[1].GPA_());
		HitCarriageReturnToContinue();
	}
# pragma endregion

# pragma region CLIENT_DIAGNOSTIC_LEVEL_12___PayRate//==========================
	if (CLIENT_DIAGNOSTIC_LEVEL <= 12)
	{
		puts("\n\n");
		puts("===================================================================");
		puts("===================================================================");
		puts("===========             Testing PayRate_             ==============");
		puts("===========        CLIENT_DIAGNOSTIC_LEVEL = 12      ==============");
		puts("===================================================================");
		puts("===================================================================\n");
		Client
			Client1,
			Client2("Jane Doe", 22, 2, 9.99, 1.1),
			Client3("Daffy", 33, 1, 19.99, 2.2),
			Client4("John Doe", 11, 1, 1000, 3.99),
			Client5("Donald", 44, 1, 29.99, 3),
			Company[4];

		printf("Client1.PayRate_() = %.2lf\n", Client1.PayRate_());
		printf("Client2.PayRate_() = %.2lf\n", Client2.PayRate_());
		printf("Client3.PayRate_() = %.2lf\n", Client3.PayRate_());
		printf("Client4.PayRate_() = %.2lf\n", Client4.PayRate_());
		printf("Client5.PayRate_() = %.2lf\n", Client5.PayRate_());
		printf("Company[1].PayRate_() = %.2lf\n\n\n", Company[1].PayRate_());
		HitCarriageReturnToContinue();
	}
# pragma endregion

# pragma region CLIENT_DIAGNOSTIC_LEVEL_13___HeaderNo//============================
	if (CLIENT_DIAGNOSTIC_LEVEL <= 13)
	{
		puts("\n\n");
		puts("===================================================================");
		puts("===================================================================");
		puts("===========              Testing HeaderNo_           ==============");
		puts("===========        CLIENT_DIAGNOSTIC_LEVEL = 13      ==============");
		puts("===================================================================");
		puts("===================================================================\n");
		Client
			Client1,
			Client2("Jane Doe", 22, 1, 9.99, 1.1),
			Client3("Daffy"   , 33, 2, 19.99, 2.2),
			Client4("John Doe", 11, 3, 1000, 3.99),
			Client5("Donald"  , 44, 4, 29.99, 3),
			Company[4];

		printf("Client1.HeaderNo_() = %ld\n", Client1.HeaderNo_());
		printf("Client2.HeaderNo_() = %ld\n", Client2.HeaderNo_());
		printf("Client3.HeaderNo_() = %ld\n", Client3.HeaderNo_());
		printf("Client4.HeaderNo_() = %ld\n", Client4.HeaderNo_());
		printf("Client5.HeaderNo_() = %ld\n", Client5.HeaderNo_());
		printf("Company[1].HeaderNo_() = %ld\n\n\n", Company[1].HeaderNo_());
		HitCarriageReturnToContinue();
	}
# pragma endregion

# pragma region CLIENT_DIAGNOSTIC_LEVEL_14___Client_Arrays //======================

	if (CLIENT_DIAGNOSTIC_LEVEL <= 14)
	{
	puts("\n\n===================================================================");
	puts("===================================================================");
	puts("=================     Final Testing Of Array       ================");
	puts("==================  CLIENT_DIAGNOSTIC_LEVEL = 14   ================");
	puts("===================================================================");
	puts("===================================================================\n");
	long
		Counter;
	Client
		Company[30];

		Company[0].Set("Yu",       100, 1,  100.00,    4.0);
		Company[1].Set("Adam",     101, 1,     100,    4.0);
		Company[2].Set("Seth",     102, 2,     100,    4.0);
		Company[3].Set("Paul",     103, 3,     100,    4.0);
		Company[4].Set("Tom",      104, 3,     100,    4.0);
		Company[5].Set("Mark",     105, 2,     100,    4.0);
		Company[6].Set("Berna",    106, 2,     100,    4.0);
		Company[7].Set("Albert",   107, 1,      90,    4.0);
		Company[8].Set("Matt",     108, 1,     100,    4.0);
		Company[9].Set("Karen",    109, 1,      70,    3.50);

		Company[10].Set("Wanda",   119, 1,    10.5,   2.50);
		Company[11].Set("Jane",    118, 2,   19.99,   3.00);
		Company[12].Set("Judy",    117, 2,    17.3,   2.00);
		Company[13].Set("Beth",    116, 2,   66.01,   1.00);
		Company[14].Set("Robin",   115, 3,      10,   1.50);
		Company[15].Set("Cara",    114, 2,      10,   2.00);
		Company[16].Set("Tina",    113, 1,   10.21,   1.50);
		Company[17].Set("Georgia", 112, 1,    10.3,   2.50);
		Company[18].Set("Alex",    111, 3,      1,    3.00);
		Company[19].Set("Sarah",   110, 1,      0,    3.00);

		puts("      ------------------------------------------------------");
		puts("      | 12345678901234567890123456789012345678901234567890 |");
		puts("      ------------------------------------------------------");
		for (Counter = 0; Counter <= 19; Counter ++)
		{
			printf("%5ld | ", Counter);
			flush_stream(stdout);
			cout << Company[Counter];
			puts(" |");
		}
		puts("      ------------------------------------------------------");
		HitCarriageReturnToContinue();
	}
# pragma endregion

	puts("\n\n*******************************************************************");
	puts("*******************************************************************");
	puts("*******************************************************************");
	puts("*******************************************************************");
	puts("************************* End TestClient **************************");
	puts("*******************************************************************");
	puts("*******************************************************************");
	puts("*******************************************************************");
	puts("*******************************************************************\n\n");
}

# endif // CLIENT_DIAGNOSTIC_LEVEL --------------------------------------------------
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                