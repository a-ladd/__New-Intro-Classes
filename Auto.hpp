//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                                                              //
//                                  Auto.hpp                                    //
//                                                                              //
//  Purpose    : Auto Interface. The interface shall include the includes,      //
//               defines, class definition and prototypes that the compiler     //
//               needs in order to compile and execute Auto objects.            //
//                                                                              //
//               Since this class is not a template class, there are no         //
//               template functions.                                            //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

# ifndef AUTO_CLASS //============================================================

// -------------------------- Includes ----------------------------------- 
# include "Utilities.hpp"

// -------------------------- Defines ------------------------------------ 
# define COUP true
# define CONVERTABLE false
# define AUTO_CLASS
# define AUTO_DIAGNOSTIC_LEVEL 1

// ---------------------- Classes & Structs ------------------------------
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                      Class Auto                              //
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
class Auto
{
public:

	Auto::Auto(char NewDescription[] = "", long int NewNo = 0, bool NewStyle = CONVERTABLE);
	Auto::Auto(long NewNo, char NewDescription[] = "", bool NewStyle = CONVERTABLE);
	~Auto(void);
	void Display(char Message[] = "");
	void Set(char NewDescription[] = "", long int NewNo = 0, bool NewStyle = CONVERTABLE);
	bool Get(void);
	void Display50(void);
	long  Key(void);

	friend ostream & operator << (ostream & OutputStream, Auto S);

	// I have decided that Description is to be the Primary Character Key for this record type.   
	bool operator == (const char Key[]);
	bool operator >  (const char Key[]);
	bool operator >= (const char Key[]);
	bool operator <  (const char Key[]);
	bool operator <= (const char Key[]);
	bool operator != (const char Key[]);
	void operator =  (const char Key[]);

	// I have decided that No is to be the Primary Long Integer Key for this record type.   
	bool operator >  (const long Key);
	bool operator >= (const long Key);
	bool operator <  (const long Key);
	bool operator <= (const long Key);
	bool operator != (const long Key);
	bool operator == (const long Key);
	void operator =  (const long Key);

	// I have decided that Description is to be the Primary Key for this record type.   
	bool operator == (const Auto & S);
	bool operator >  (const Auto & S);
	bool operator >= (const Auto & S);
	bool operator <  (const Auto & S);
	bool operator <= (const Auto & S);
	bool operator != (const Auto & S);
	void operator =  (const Auto & S);

private:
	char
		Description[35];	// Set To Be Empty String   
	long
		No;		            // Set To Be 0   
	bool
		Style;            // Set To COUP
};

// ------------------------- Prototypes ---------------------------------

# ifdef AUTO_DIAGNOSTIC_LEVEL //--------------------------------------
void TestAuto(void);
# endif // AUTO_DIAGNOSTIC_LEVEL -------------------------------------


# endif // AUTO_CLASS ============================================================