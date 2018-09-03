////////////////////////////////////////////////////////////////////////////////// 
////////////////////////////////////////////////////////////////////////////////// 
//                                                                              // 
//                                   Main.cpp                                   // 
//                                                                              // 
//  Purpose    :  Complete the functions for the Book Class and execute the     //
//                test code, written by Dr. HicksTestBook.  The code for class  // 
//                Athlete , class Auto, and class Client are included. They     // 
//                should help serve as a model to help you learn by example.    // 
//                                                                              //
//                In this lab, you are to develop the class in main.cpp         //
//                                                                              //
//                You will find that the Includes, the Defines, the Class,      //
//                the Prototypes (such as TestAthlete),and  the Template        //
//                functions (we have none yet) in the .hpp files.               //
//                                                                              //
//                You will find an Include for the class hpp, all               //
//                Non-Template Functions, and all prototyped Functions in       //
//                the .cpp files.                                               //
//                                                                              //
//  Written By : ???????????????         Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////////////////
//----------------------------------  Includes -----------------------------------
# include "Athlete.hpp"
# include "Auto.hpp"
# include "Client.hpp"
# include "Utilities.hpp"

// ---------------------------------- Defines ------------------------------------ 
# define BOOK_DIAGNOSTIC_LEVEL 1

//-----------------------------  Classes & Structs //-----------------------------
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                     Class Book                               //
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
class Book
{
public:
	Book::Book(void);
	Book(char NewTitle[], long NewNo = 0, long NewCatalogNo = 0,
		long NewQuantity = 0, double NewCost = 0.0);
	~Book(void);
	void Set(char NewTitle[] = "", long NewNo = 0, long NewCatalogNo = 0,
		long NewQuantity = 0, double NewCost = 0.0);
	bool Get(void);
	long CatalogNo_();
	double Cost_(void);
	long Quantity_(void);
	long Key();
	void Display(char Message[] = "");
	void Display50(void);

	friend ostream & operator << (ostream & OutputStream, Book B);

	// I have decided that Title is to be the primary Character Key for this record type   
	bool operator == (const char Key[]);
	bool operator >  (const char Key[]);
	bool operator >= (const char Key[]);
	bool operator <  (const char Key[]);
	bool operator <= (const char Key[]);
	bool operator != (const char Key[]);
	void operator =  (const char Key[]);

	// I have decided that No is to be the primary Integer Key for this record type   
	bool operator == (const long Key);
	bool operator >  (const long Key);
	bool operator >= (const long Key);
	bool operator <  (const long Key);
	bool operator <= (const long Key);
	bool operator != (const long Key);
	void operator =  (const long Key);

	// I have decided that Title is to be the primary Key for this record type   
	bool operator == (const Book & B);
	bool operator >  (const Book & B);
	bool operator >= (const Book & B);
	bool operator <  (const Book & B);
	bool operator <= (const Book & B);
	bool operator != (const Book & B);
	void operator =  (const Book & B);

private:
	char
		Title[26];
	long
		No,
		Quantity,
		CatalogNo;
	double
		Cost;
};

void TestBook();


# pragma region BOOK_DIAGNOSTIC_LEVEL_1___Constructor_Destructor //===========
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                    Book                                      //
//                                                                              //
//  Purpose: Constructors for Class Book. Set Title to NewTitle and No to       //
//           NewNo, CatalogNo to NewCatalogNo, Quantity to NewQuantity, and     //
//           Cost to NewCost.  Defaults for Character Data Members shall be     //
//           blank. Defaults for Numeric Data Members shall be 0.               //
//                                                                              //
//  Written By : ?????????????           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
Book::Book()
{
	strcpy_s(Title, "");
	No = 0;
	Quantity = 0;
	CatalogNo = 0;
	Cost = 0;

# ifdef BOOK_DIAGNOSTIC_LEVEL //---------------------------------------------------
	if (BOOK_DIAGNOSTIC_LEVEL <= 1)
		puts("Evoking Constructor Book (void)");
# endif // BOOK_DIAGNOSTIC_LEVEL --------------------------------------------------
}

Book::Book(char NewTitle[], long NewNo, long NewCatalogNo,
	long NewQuantity, double NewCost)
{
# ifdef BOOK_DIAGNOSTIC_LEVEL //---------------------------------------------------
	if (BOOK_DIAGNOSTIC_LEVEL <= 1)
		puts("Evoking Constructor Book (NewTitle[], NewNo, NewCatalogNo, NewQuantity, NewCost)");
# endif // BOOK_DIAGNOSTIC_LEVEL --------------------------------------------------
}

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                    ~Book                                     //
//                                                                              //
//  Purpose:  Do all that is necessary to destroy an object. In this class we   //
//            are only going to insert a diagnostic Display to verify the the   //
//            destructor is firing B.oB.rly.                                    //
//                                                                              //
//  Written By : ?????????????           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
Book::~Book(void)
{
# ifdef BOOK_DIAGNOSTIC_LEVEL //---------------------------------------------------
	if (BOOK_DIAGNOSTIC_LEVEL <= 1)
		puts("Evoking Destructor ~Book (void)");
# endif // BOOK_DIAGNOSTIC_LEVEL --------------------------------------------------

}
# pragma endregion

# pragma region BOOK_DIAGNOSTIC_LEVEL_2___Display //==========================
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                 Method Display                               //
//                                                                              //
//  Purpose: If there is a message, Display it --> Return.                      //
//           Then Display each of the private data members, one to a line.      //
//           The output should look like:                                       //
//                                                                              //
//           Optional Message .................                                 //
//              Title...........:  Bible                                        //
//              No .............:  1207                                         //
//              CatalogNo.......:  12                                           //
//              Cost ..........:$  18.99    --> (2 digits )                     //
//              Quantity .......:  164                                          //
//               ---- Skip a line ----    .                                     // 
//                                                                              //
//  Written By : ?????????????           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
void Book::Display(char Message[])
{
	if (strlen(Message) > 0)
		puts(Message);
	printf("Title...........: %s\n", Title);
	printf("No .............: %ld\n", No);
	printf("CatalogNo.......: %ld\n", CatalogNo);
	printf("Cost ..........:$ %.2f\n", Cost);
	printf("Quantity .......: %ld\n\n", Quantity);
}

# pragma endregion

# pragma region BOOK_DIAGNOSTIC_LEVEL_3___Set//================================
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                     Set                                      //
//                                                                              //
//  Purpose: Assign the following: All Character Strings shall default to       //
//                                 blank & all Numerics to 0.                   //
//           Title = NewTitle                                                   //
//           No = NewNo                                                         //
//           CatalogNo = NewCatalogNo                                           //
//           Cost = NewCost                                                     //
//           Quantity = NewQuantity                                             //
//                                                                              //
//  Written By : ?????????????           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
void Book::Set(char NewTitle[], long NewNo, long NewCatalogNo,
	long NewQuantity, double NewCost)
{
	strcpy_s(Title, NewTitle);
	No = NewNo;
	CatalogNo = NewCatalogNo;
	Cost = NewCost;
	Quantity = NewQuantity;
}
# pragma endregion

# pragma region BOOK_DIAGNOSTIC_LEVEL_4___Get//===============================
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                     Get                                      //
//                                                                              //
//  Purpose:  Set is an interactive function in which we will allow the user    //
//            enter data from keyboard.                                         //
//            The Name for the First Data Member will be:                       //
//	                                                                            //
//                  Enter Title [Hit Return/Enter To Exit]:                     //
//	                                                                            //
//	          This provides the user with an oB.ortunity to exit the function   //
//            without entering all of the data members; after all, they may     //
//            have entered this function by mistake.                            //
//                                                                              //
//            This function will Explicitly returns INVALID if user chooses to  //
//            oB. out by hitting the return key; otherwise return VALID after   //
//            the user has entered all of the data members. Your processing     //
//            must be exactly as shown below:                                   //
//	                                                                            //
//           Enter Book Title [Hit Return/Enter To Exit]..: Bible               //  
//           Enter Book No ..-............................: 1207                //
//           Enter Catalog No ............................: 12                  //
//           Enter Cost .................................:$ 18.99               //
//           Enter Quantity ..............................: 164                 //
//                                                                              //
//  Written By : ?????????????           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
bool Book::Get(void)
{
	char
		Temp[200];
//-- You Do
	return (VALID);
}
# pragma endregion

# pragma region BOOK_DIAGNOSTIC_LEVEL_5___Display50//==========================
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                 Display50                                    //
//                                                                              //
//  Purpose:  This is nothing more than a diagnostic Display utility that will  //
//            Display the most important 50 characters of the class. We will    //
//            develop several such utilities. Selecting the items to Display    //
//            will often be tough in a class with 100 data members, but it is   //
//            quite easy for this class. This function uses puts & printf.      //
//                                                                              //
//            There will be no line feed. The format is to be  [20 char for     //
//            Title,  1 blank, 6 char for No, 1 blank,  6 char for CatalogNo,   //
//            1 blank, 6 char for Quantity, 1 blank,  8 char for Cost (2 to     //
//            right of decimal point).                                          //
//                                                                              //
//           12345678901234567890123456789012345678901234567890                 //
//           --------------------------------------------------                 //
//           Dying: A Memoir      123456     22   1000   123.55                 //
//                                                                              //
//  Written By : ?????????????           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
void Book::Display50(void)
{
	//-- You Do
}
# pragma endregion

# pragma region BOOK_DIAGNOSTIC_LEVEL_6___cout//===============================
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                  << Overload                                 //
//                                                                              //
//  Purpose:  This is nothing more than a diagnostic Display utility that will  //
//            Display the most important 50 characters of the class. We will    //
//            develop several such utilities. Selecting the items to Display    //
//            will often be tough in a class with 100 data members, but it is   //
//            quite easy for this class. This function uses puts & printf.      //
//                                                                              //
//            There will be no line feed. The format is to be  [22 char for     //
//            Title,  1 blank, 6 char for No, 1 blank,  6 char for CatalogNo,   //
//            1 blank, 6 char for Quantity, 1 blank,  6 char for Cost (2 to     //
//            right of decimal point).                                          //
//                                                                              //
//           12345678901234567890123456789012345678901234567890                 //
//           --------------------------------------------------                 //
//           Dying: A Memoir      123456     22   1000   123.55                 //
//                                                                              //
//  Written By : ?????????????           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
ostream & operator << (ostream & OutputStream, Book B)
{
	char
		TempName[50];

	strncpy_s(TempName, B.Title, 19);
	TempName[19] = 0;

	OutputStream << setw(20) << left << TempName;
	//-- You Do
	return (OutputStream);
}
# pragma endregion

# pragma region BOOK_DIAGNOSTIC_LEVEL_7___Key//================================
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                     Key                                      //
//                                                                              //
//  Purpose:  Explicitly Return a long that represents this Book.               //
//            In some classes it will be difficult to determine which long      //
//            integer best represents the object; in this class we have only    //
//            a few choices. Explicitly return the No.                          //
//                                                                              //
//            Since the data members are generally private, it is not at all    //
//            to have several accessor methods                                  //
//                                                                              //
//  Written By : ?????????????           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 
long  Book::Key(void)
{
	return (5);
}
# pragma endregion

# pragma region BOOK_DIAGNOSTIC_LEVEL_8___Char_String_Overloads //=============
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                        char operator Overloads                               //
//                                                                              //
//  Purpose: Overload the operators in such a way that the Title becomes the    //
//            primary character key for the Book Class.                         //
//                                                                              //
//            These overloads will better enable us to search, sort, and make   // 
//            decisions involving Book objects.                                 //
//                                                                              //
//  Written By : ?????????????           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 
bool Book::operator == (const char Key[])
{
// You Do
		return (false);
}

bool Book::operator > (const char Key[])
{
	// You Do
		return (false);
}

bool Book::operator >= (const char Key[])
{
	// You Do
		return (false);
}

bool Book::operator < (const char Key[])
{
	// You Do
		return (false);
}

bool Book::operator <= (const char Key[])
{
	// You Do
		return (false);
}

bool Book::operator != (const char Key[])
{
	// You Do
		return (false);
}

void Book::operator = (const char Key[])
{

}
# pragma endregion

# pragma region BOOK_DIAGNOSTIC_LEVEL_9___Long_Integer_Overloads //===========
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                              long Overloads                                  //
//                                                                              //
//  Purpose:  Overload the operators in such a way that the No becomes the      //
//            primary long key for the Book Class.                              //
//                                                                              //
//            These overloads will better enable us to search, sort, and make   // 
//            decisions involving Book objects.                                 //
//                                                                              //
//  Written By : ?????????????           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 
bool Book::operator == (const long Key)
{
	// You Do
		return (false);
}

bool Book::operator > (const long Key)
{
	// You Do
		return (false);
}

bool Book::operator >= (const long Key)
{
	// You Do
		return (false);
}

bool Book::operator < (const long Key)
{
	// You Do
		return (false);
}

bool Book::operator <= (const long Key)
{
	// You Do
		return (false);
}

bool Book::operator != (const long Key)
{
	// You Do
		return (false);
}

void Book::operator = (const long Key)
{
	// You Do
}

# pragma endregion

# pragma region BOOK_DIAGNOSTIC_LEVEL_10___Book_Overloads //================
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                            Book Object Overloads                             //
//                                                                              //
//  Purpose:  Overload the operators in such a way that the Title becomes the   //
//            primary key when comparing two objects of Book type.              //
//                                                                              //
//            These overloads will better enable us to search, sort, and make   // 
//            decisions involving Book objects.                                 //
//                                                                              //
//  Written By : ?????????????           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 
bool Book::operator == (const Book & B)
{
	// You Do
		return (false);
}

bool Book::operator > (const Book & B)
{
	// You Do
		return (false);
}

bool Book::operator >= (const Book & B)
{
	// You Do
		return (false);
}

bool Book::operator < (const Book & B)
{
	// You Do
		return (false);
}

bool Book::operator <= (const Book & B)
{
	// You Do
		return (false);
}


bool Book::operator != (const Book & B)
{
	// You Do
		return (false);
}

void Book::operator = (const Book & B)
{
	// You Do
}
# pragma endregion

# pragma region BOOK_DIAGNOSTIC_LEVEL_11___Cost//==============================
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                     Cost_                                    //
//                                                                              //
//  Purpose:  Explicitly Return the Cost that represents this Book.             //
//                                                                              //
//            Since the data members are generally private, it is not at all    //
//            to have several accessor methods                                  //
//                                                                              //
//  Written By : ?????????????           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 
double  Book::Cost_(void)
{
	return (1.1);
}
# pragma endregion

# pragma region BOOK_DIAGNOSTIC_LEVEL_12___Quantity//==========================
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                  Quantity_                                   //
//                                                                              //
//  Purpose:  Explicitly Return the Quantity that represents this Book.         //
//                                                                              //
//            Since the data members are generally private, it is not at all    //
//            to have several accessor methods                                  //
//                                                                              //
//  Written By : ?????????????           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 
long  Book::Quantity_(void)
{
	return (1);
}
# pragma endregion

# pragma region BOOK_DIAGNOSTIC_LEVEL_13___CatalogNo//============================
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                   CatalogNo_                                 //
//                                                                              //
//  Purpose:  Explicitly Return the CatalogNo that represents this Book.        //
//                                                                              //
//            Since the data members are generally private, it is not at all    //
//            to have several accessor methods                                  //
//                                                                              //
//  Written By : ?????????????           Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 
long  Book::CatalogNo_(void)
{
	return (1);
}
# pragma endregion


int main(int argc, char * argv[])
{
	puts("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	puts("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	puts("++                            ????                           ++");
	puts("++                            ?????                          ++");
	puts("++                                                           ++");
	puts("++                         Writen By                         ++");
	puts("++                    ?????????????????????                  ++");
	puts("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	puts("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	puts("--------------------- Start Of Main ---------------------\n");
	
	TestBook();





	//TestAthlete();
	//TestAuto();
	//TestClient();
	puts ("----------------------- End Of Main ----------------------\n");
	HitCarriageReturnToContinue();
	return (0);
}




//===========================================================================


# ifdef BOOK_DIAGNOSTIC_LEVEL //---------------------------------------------------

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                 Function TestBook                            //
//                                                                              //
//  Purpose:  Test each and every method in class Book.                         //
//                                                                              //
//  Written By : ???????????????         Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
void TestBook(void)
{
	puts("\n\n");
	puts("*******************************************************************");
	puts("*******************************************************************");
	puts("*******************************************************************");
	puts("*******************************************************************");
	puts("************************* Start TestBook **************************");
	puts("*******************************************************************");
	puts("*******************************************************************");
	puts("*******************************************************************");
	puts("*******************************************************************");
	
# pragma region BOOK_DIAGNOSTIC_LEVEL_1___Constructor_Destructor //============
	if (BOOK_DIAGNOSTIC_LEVEL <= 1)
	{
		puts("\n\n");
		puts("===================================================================");
		puts("===================================================================");
		puts("===========     Testing Constructor & Destructor     ==============");
		puts("===========         BOOK_DIAGNOSTIC_LEVEL = 1        ==============");
		puts("===================================================================");
		puts("===================================================================\n");
		Book
			Book1,
			Book2("Harry Potter"),
			Book3("Dying: A Memoir", 111),
			Book4("The Great Quake", 222, 10),
			Book5("Dangerous", 333, 10, 25),
			Book6("Ready Player One", 444, 10, 5, 99.25),
			Library[4];
		HitCarriageReturnToContinue();
	}
# pragma endregion

# pragma region BOOK_DIAGNOSTIC_LEVEL //============================
	if (BOOK_DIAGNOSTIC_LEVEL <= 2)
	{
		puts("\n\n");
		puts("===================================================================");
		puts("===================================================================");
		puts("===========            Testing Display               ==============");
		puts("===========       BOOK_DIAGNOSTIC_LEVEL = 2          ==============");
		puts("===================================================================");
		puts("===================================================================\n");
		Book
			Book1,
			Book2("Harry Potter"),
			Book3("Dying: A Memoir", 111),
			Book4("The Great Quake", 222, 10),
			Book5("Dangerous", 333, 10, 25),
			Book6("Ready Player One", 444, 10, 5, 99.25),
			Library[4];

		Book1.Display("\nContents Of Book1");
		Book2.Display("\nContents Of Book2");
		Book3.Display("\nContents Of Book3");
		Book4.Display("\nContents Of Book4");
		Book5.Display("\nContents Of Book5");
		Book6.Display("\nContents Of Book6");
		Library[0].Display();
		Library[1].Display();
		Library[2].Display();
		Library[3].Display();
		HitCarriageReturnToContinue();
	}
# pragma endregion

# pragma region BOOK_DIAGNOSTIC_LEVEL_3___Set//================================
	if (BOOK_DIAGNOSTIC_LEVEL <= 3)
	{
		puts("\n\n");
		puts("===================================================================");
		puts("===================================================================");
		puts("===========              Testing Set                 ==============");
		puts("===========       BOOK_DIAGNOSTIC_LEVEL = 3          ==============");
		puts("===================================================================");
		puts("===================================================================\n");
		Book
			Book1;

		Book1.Set("Harry Potter");
		Book1.Display("Harry Potter");
		Book1.Set("Dying: A Memoir", 111);
		Book1.Display("Dying: A Memoir - 111");
		Book1.Set("The Great Quake", 222, 10);
		Book1.Display("The Great Quake - 222 - 10");
		Book1.Set("Dangerous", 333, 10, 25);
		Book1.Display("Dangerous - 333 - 10 - 25");
		Book1.Set("Ready Player One", 444, 10, 5, 99.25);
		Book1.Display("Ready Player One - 444 - 10 - 5 - 99.25");

		HitCarriageReturnToContinue();
	}

# pragma endregion

# pragma region BOOK_DIAGNOSTIC_LEVEL_4___Get//================================
	if (BOOK_DIAGNOSTIC_LEVEL <= 4)
	{
		puts("\n\n");
		puts("===================================================================");
		puts("===================================================================");
		puts("===========              Testing Get                 ==============");
		puts("===========       BOOK_DIAGNOSTIC_LEVEL = 4          ==============");
		puts("===================================================================");
		puts("===================================================================\n");
		Book
			Book1,
			Class[4];

		if (Book1.Get())
			Book1.Display("\nBook1:");
		else
			puts("\nYou Chose Not To Enter Data For Book1\n");
		if (Class[3].Get())
			Class[3].Display("\nClass[3]:");
		else
			puts("\nYou Chose Not To Enter Data For Class[3]\n");


		HitCarriageReturnToContinue();
	}

# pragma endregion

# pragma region BOOK_DIAGNOSTIC_LEVEL_5___Set//================================
	if (BOOK_DIAGNOSTIC_LEVEL <= 5)
	{
		puts("\n\n");
		puts("===================================================================");
		puts("===================================================================");
		puts("===========            Testing Display50             ==============");
		puts("===========        BOOK_DIAGNOSTIC_LEVEL = 5         ==============");
		puts("===================================================================");
		puts("===================================================================\n");
		Book
			Book2("Ready Player One", 444, 10, 5, 99.25),
			Book5("The Great Quake", 1234, 12, 1, 123.5);

		puts("------------------------------------------------------");
		puts("| 12345678901234567890123456789012345678901234567890 |");
		puts("------------------------------------------------------");
		printf("| ");
		Book2.Display50();
		puts(" |");

		puts("------------------------------------------------------");
		printf("| ");
		Book5.Display50();
		puts(" |");
		puts("------------------------------------------------------");

		HitCarriageReturnToContinue();
	}
# pragma endregion

# pragma region BOOK_DIAGNOSTIC_LEVEL_6___Cout//================================
	if (BOOK_DIAGNOSTIC_LEVEL <= 6)
	{
		puts("\n\n");
		puts("===================================================================");
		puts("===================================================================");
		puts("===========          Testing << Overload             ==============");
		puts("===========        BOOK_DIAGNOSTIC_LEVEL = 6         ==============");
		puts("===================================================================");
		puts("===================================================================\n");
		Book
			Book2("Ready Player One", 444, 10, 5, 99.25),
			Book5("The Great Quake", 1234, 12, 1, 123.5);

		puts("------------------------------------------------------");
		puts("| 12345678901234567890123456789012345678901234567890 |");
		puts("------------------------------------------------------");
		cout << "| " << Book2 << " |" << endl;

		puts("------------------------------------------------------");
		cout << "| " << Book5 << " |" << endl;
		puts("------------------------------------------------------");

		HitCarriageReturnToContinue();
	}
# pragma endregion

# pragma region BOOK_DIAGNOSTIC_LEVEL_7___Key//================================
	if (BOOK_DIAGNOSTIC_LEVEL <= 7)
	{
		puts("\n\n");
		puts("===================================================================");
		puts("===================================================================");
		puts("===========                Testing Key               ==============");
		puts("===========        BOOK_DIAGNOSTIC_LEVEL = 7         ==============");
		puts("===================================================================");
		puts("===================================================================\n");
		Book
			Book1,
			Book2("Harry Potter", 22, 1, 4, 22.50),
			Book3("Softball", 33, 1, 6, 10.10),
			Book5("Ready Player OneBall", 44, 1, 5, 7.70),
			Book4("SoccerBall", 11, 1, 10, 15.15),
			Library[4];

		printf("Book1.Key() = %ld\n", Book1.Key());
		printf("Book2.Key() = %ld\n", Book2.Key());
		printf("Book3.Key() = %ld\n", Book3.Key());
		printf("Book4.Key() = %ld\n", Book4.Key());
		printf("Book5.Key() = %ld\n", Book5.Key());
		printf("Library[1].Key() = %ld\n\n\n", Library[1].Key());
		HitCarriageReturnToContinue();

		HitCarriageReturnToContinue();
	}
# pragma endregion

# pragma region BOOK_DIAGNOSTIC_LEVEL_8___Char_String_Overloads //=============
	if (BOOK_DIAGNOSTIC_LEVEL <= 8)
	{
		puts("\n\n");
		puts("===================================================================");
		puts("===================================================================");
		puts("===========   Test operator Comparison With Strings  ==============");
		puts("===========      BOOK_DIAGNOSTIC_LEVEL = 8           ==============");
		puts("===================================================================");
		puts("===================================================================\n");

		Book
			Book3("Harry Potter", 44),
			Book5("CCC", 3);

		Book3.Display("\nInfo Stored In Book3:");
		if (Book3 == "Harry Potter")
			puts("CORRECT ==> Book.Title == 'Harry Potter'");
		else
			puts("ERROR ==> Book.Title != 'Harry Potter'");
		if (Book3 == "Harry Potter ")
			puts("ERROR ==> Book.Title == 'Harry Potter '");
		else
			puts("CORRECT ==> Book.Title != 'Harry Potter '");
		if (Book3 == " Harry Potter")
			puts("ERROR ==> Book.Title == ' Harry Potter'");
		else
			puts("CORRECT ==> Book.Title != ' Harry Potter'");


		if (Book3 == "   Harry Potter   ")
			puts("ERROR ==> Book.Title == ' Harry Potter '");
		else
			puts("CORRECT ==> Book.Title != '   Harry Potter   '");

		if (Book3 == "The Great QuakeBall")
			puts("ERROR ==> Book.Title == The Great QuakeBall");
		else
			puts("CORRECT ==> Book.Title != The Great QuakeBall");

		if (Book5 == "AAA")                   // Test = Char
			puts("ERROR ==> True ---> CCC = AAA");
		else
			puts("CORRECT ==> False --> CCC = AAA");
		if (Book5 > "AAA")                   // Test > Char
			puts("CORRECT ==> True ---> CCC > AAA");
		else
			puts("ERROR ==> False --> CCC > AAA");
		if (Book5 >= "AAA")                   // Test >= Char
			puts("CORRECT ==> True ---> CCC >= AAA");
		else
			puts("CORRECT ==> False --> CCC >= AAA");
		if (Book5 < "AAA")                   // Test < Char
			puts("ERROR ==> True ---> CCC < AAA");
		else
			puts("CORRECT ==> False --> CCC < AAA");
		if (Book5 <= "AAA")                   // Test <= Char
			puts("ERROR ==> True ---> CCC <= AAA");
		else
			puts("CORRECT ==> False --> CCC <= AAA");
		if (Book5 != "AAA")                   // Test != Char
			puts("CORRECT ==> True ---> CCC != AAA");
		else
			puts("ERROR ==> False --> CCC != AAA");

		Book5.Display("\n\nContents of Book5"); // Test = Char
		Book5 = "Ready Player OneBall";
		Book5.Display("New Contents of Book5");

		HitCarriageReturnToContinue();
	}
# pragma endregion

# pragma region BOOK_DIAGNOSTIC_LEVEL_9___Long_Integer_Overloads //============

	if (BOOK_DIAGNOSTIC_LEVEL <= 9)
	{
		puts("\n\n");
		puts("===================================================================");
		puts("===================================================================");
		puts("========= Test operator Comparison With Long Integers  ============");
		puts("=========        BOOK_DIAGNOSTIC_LEVEL = 9             ============");
		puts("===================================================================");
		puts("===================================================================\n");

		Book
			Book3("SoccerBall", 44),
			Book5("Harry Potter", 55);

		Book5.Set("CCC", 3);
		if (Book5 == 5)                   // Test = Integer
			puts("ERROR ==> True ---> 3 == 5");
		else
			puts("CORRECT ==> False --> 3 == 5");
		if (Book5 > 5)                   // Test > Integer
			puts("ERROR ==> True ---> 3 > 5");
		else
			puts("CORRECT ==> False --> 3 > 5");
		if (Book5 >= 5)                   // Test >= Integer
			puts("ERROR ==> True ---> 3 >= 5");
		else
			puts("CORRECT ==> False --> 3 >= 5");
		if (Book5 < 5)                   // Test < Integer
			puts("CORRECT ==> True ---> 3 < 5");
		else
			puts("ERROR ==> False --> 3 < 5");
		if (Book5 <= 5)                   // Test <= Integer
			puts("CORRECT ==> True ---> 3 <= 5");
		else
			puts("ERROR ==> False --> 3 <= 5");
		if (Book5 != 5)                   // Test != Integer
			puts("CORRECT ==> True ---> 3 != 5");
		else
			puts("ERROR ==> False --> 3 != 5");
		Book5.Display("\n\nContents of Book5"); // Test = Integer
		Book5 = 21;
		Book5.Display("New Contents of Book5");
		HitCarriageReturnToContinue();

	}

# pragma endregion

# pragma region BOOK_DIAGNOSTIC_LEVEL_10___Book_Overloads //===================
	if (BOOK_DIAGNOSTIC_LEVEL <= 10)
	{
		puts("\n\n");
		puts("===================================================================");
		puts("===================================================================");
		puts("=======       Test operator Comparison With Books      ============");
		puts("=======            BOOK_DIAGNOSTIC_LEVEL = 10          ============");
		puts("===================================================================");
		puts("===================================================================\n");
		Book
			Book3("SoccerBall", 44),
			Book5("Harry Potter", 55);

		Book5.Set("BaseBall", 5);
		Book3.Set("The Great QuakeBall", 21);

		if (Book5 == Book3)                 // Test == Book
			puts("ERROR ==> True ---> BaseBall = The Great QuakeBall");
		else
			puts("CORRECT ==> False --> BaseBall = The Great QuakeBall");

		if (Book5 > Book3)                  // Test > Book
			puts("ERROR ==> True ---> BaseBall > The Great QuakeBall");
		else
			puts("CORRECT ==> False --> BaseBall > The Great QuakeBall");

		if (Book5 >= Book3)                  // Test >= Book
			puts("ERROR ==> True ---> BaseBall >= The Great QuakeBall");
		else
			puts("CORRECT ==> False --> BaseBall >= The Great QuakeBall");

		if (Book5 < Book3)                   // Test < Book
			puts("CORRECT ==> True ---> BaseBall < The Great QuakeBall");
		else
			puts("ERROR ==> False --> BaseBall < The Great QuakeBall");

		if (Book5 <= Book3)                   // Test < Book
			puts("CORRECT ==> True ---> BaseBall <= The Great QuakeBall");
		else
			puts("ERROR ==> False --> BaseBall <= The Great QuakeBall");

		if (Book5 != Book3)                   // Test != Book
			puts("CORRECT ==> True ---> BaseBall != The Great QuakeBall");
		else
			puts("ERROR ==> False --> BaseBall != The Great QuakeBall");

		Book5.Display("\nNew Contents of Book5");
		Book3.Display("\nNew Contents of Book3");
		Book5 = Book3;                        // Test = Book
		Book5.Display("\nNew Contents of Book5");
		Book3.Display("\nNew Contents of Book3");
		HitCarriageReturnToContinue();
	}
# pragma endregion

# pragma region BOOK_DIAGNOSTIC_LEVEL_11___Cost//==============================
	if (BOOK_DIAGNOSTIC_LEVEL <= 11)
	{
		puts("\n\n");
		puts("===================================================================");
		puts("===================================================================");
		puts("===========                Testing Cost_             ==============");
		puts("===========        BOOK_DIAGNOSTIC_LEVEL = 11        ==============");
		puts("===================================================================");
		puts("===================================================================\n");
		Book
			Book1,
			Book2("Harry Potter", 22, 1, 4, 22.50),
			Book3("Softball", 33, 1, 6, 10.10),
			Book5("Ready Player OneBall", 44, 1, 5, 7.70),
			Book4("SoccerBall", 11, 1, 10, 15.15),
			Library[4];

		printf("Book1.Cost_() = %lf\n", Book1.Cost_());
		printf("Book2.Cost_() = %lf\n", Book2.Cost_());
		printf("Book3.Cost_() = %lf\n", Book3.Cost_());
		printf("Book4.Cost_() = %lf\n", Book4.Cost_());
		printf("Book5.Cost_() = %lf\n", Book5.Cost_());
		printf("Library[1].Cost_() = %lf\n\n\n", Library[1].Cost_());
		HitCarriageReturnToContinue();
	}
# pragma endregion

# pragma region BOOK_DIAGNOSTIC_LEVEL_12___Quantity//==========================
	if (BOOK_DIAGNOSTIC_LEVEL <= 12)
	{
		puts("\n\n");
		puts("===================================================================");
		puts("===================================================================");
		puts("===========             Testing Quantity_            ==============");
		puts("===========        BOOK_DIAGNOSTIC_LEVEL = 12        ==============");
		puts("===================================================================");
		puts("===================================================================\n");
		Book
			Book1,
			Book2("Harry Potter", 22, 1, 4, 22.50),
			Book3("Softball", 33, 1, 6, 10.10),
			Book5("Ready Player OneBall", 44, 1, 5, 7.70),
			Book4("SoccerBall", 11, 1, 10, 15.15),
			Library[4];

		printf("Book1.Quantity_() = %ld\n", Book1.Quantity_());
		printf("Book2.Quantity_() = %ld\n", Book2.Quantity_());
		printf("Book3.Quantity_() = %ld\n", Book3.Quantity_());
		printf("Book4.Quantity_() = %ld\n", Book4.Quantity_());
		printf("Book5.Quantity_() = %ld\n", Book5.Quantity_());
		printf("Library[1].Quantity_() = %ld\n\n\n", Library[1].Quantity_());
		HitCarriageReturnToContinue();
	}
# pragma endregion

# pragma region BOOK_DIAGNOSTIC_LEVEL_13___CatalogNo//============================
	if (BOOK_DIAGNOSTIC_LEVEL <= 13)
	{
		puts("\n\n");
		puts("===================================================================");
		puts("===================================================================");
		puts("===========              Testing CatalogNo_             ==============");
		puts("===========        BOOK_DIAGNOSTIC_LEVEL = 13        ==============");
		puts("===================================================================");
		puts("===================================================================\n");
		Book
			Book1,
			Book2("Harry Potter", 22, 1, 4, 22.50),
			Book3("Softball", 33, 2, 6, 10.10),
			Book5("Ready Player OneBall", 44, 3, 5, 7.70),
			Book4("SoccerBall", 11, 4, 10, 15.15),
			Library[4];

		printf("Book1.CatalogNo_() = %ld\n", Book1.CatalogNo_());
		printf("Book2.CatalogNo_() = %ld\n", Book2.CatalogNo_());
		printf("Book3.CatalogNo_() = %ld\n", Book3.CatalogNo_());
		printf("Book4.CatalogNo_() = %ld\n", Book4.CatalogNo_());
		printf("Book5.CatalogNo_() = %ld\n", Book5.CatalogNo_());
		printf("Library[1].CatalogNo_() = %ld\n\n\n", Library[1].CatalogNo_());
		HitCarriageReturnToContinue();
	}
# pragma endregion

# pragma region BOOK_DIAGNOSTIC_LEVEL_14___Book_Arrays //======================

	if (BOOK_DIAGNOSTIC_LEVEL <= 14)
	{
	puts("\n\n===================================================================");
	puts("===================================================================");
	puts("=================     Final Testing Of Array     ==================");
	puts("=================   BOOK_DIAGNOSTIC_LEVEL = 14   ==================");
	puts("===================================================================");
	puts("===================================================================\n");
	long
		Counter;
	Book
		Library[30];

		Library[0].Set("Bible",                 100, 1,  10,   14.99);
		Library[1].Set("The Great Gatsby",      101, 1, 100,   33.30);
		Library[2].Set("Lolita",                102, 2,   1,   12.00);
		Library[3].Set("Brave New World",       103, 3,   1,    1.00);
		Library[4].Set("Catch-22",              104, 3,  10,   75.50);
		Library[5].Set("Ulysses",               105, 2,   1,   80.01);
		Library[6].Set("Sons and Lovers",       106, 2,  500,  17.00);
		Library[7].Set("Dying: A Memoir",       107, 1,  10,   25.50);
		Library[8].Set("Darkness at Noon",      108, 1,  10,    6.50);
		Library[9].Set("The Great Quake",       109, 1,  10,    3.50);

		Library[10].Set("The Grapes of Wrath",  119, 1,  10,   25.50);
		Library[11].Set("The Way of All Flesh", 118, 2,  10,   21.21);
		Library[12].Set("1984",                 117, 2,   1,    4.40);
		Library[13].Set("To the Lighthouse",    116, 2,  10,  123.00);
		Library[14].Set("An American Tragedy",  115, 3,  10,   25.50);
		Library[15].Set("Slaughterhouse Five",  114, 2, 100,   10.00);
		Library[16].Set("A Passage to India",   113, 1,  10,    7.50);
		Library[17].Set("The Ambassadors",      112, 1,  10,    2.50);
		Library[18].Set("The Good Soldier",     111, 1,  10,   65.00);
		Library[19].Set("Animal Farm",          110, 1,  10,    5.00);
		Library[19].Set("Sister Carrie",        120, 4,  10,   15.00);

		puts("      ------------------------------------------------------");
		puts("      | 12345678901234567890123456789012345678901234567890 |");
		puts("      ------------------------------------------------------");
		for (Counter = 0; Counter <= 20; Counter ++)
		{
			printf("%5ld | ", Counter);
			flush_stream(stdout);
			cout << Library[Counter];
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
	puts("*************************** End TestBook **************************");
	puts("*******************************************************************");
	puts("*******************************************************************");
	puts("*******************************************************************");
	puts("*******************************************************************\n\n");
}

# endif // BOOK_DIAGNOSTIC_LEVEL --------------------------------------------------

