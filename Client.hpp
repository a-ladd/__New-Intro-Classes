//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                                                              //
//                                   Client.hpp                                 //
//                                                                              //
//  Purpose    : Client Interface. The interface shall include the includes,    //
//               defines, class definition and prototypes that the compiler     //
//               needs in order to compile and execute Client objects.          //
//                                                                              //
//               Since this class is not a template class, there are no         //
//               template functions.                                            //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

# ifndef CLIENT_CLASS //============================================================

// -------------------------- Includes ----------------------------------- 
# include "Utilities.hpp"

// -------------------------- Defines ------------------------------------ 
# define CLIENT_DIAGNOSTIC_LEVEL 1
# define CLIENT_CLASS

// ---------------------- Classes & Structs ------------------------------

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                    Class Client                              //
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
class Client
{
public:
	Client (char NewName[] = "", long NewID = 0, long NewHeaderNo = 0, 
		  double NewPayRate = 0, double NewGPA = 0.0);
	~Client (void);
	void Set(char NewName[] = "", long NewID = 0, long NewHeaderNo = 0,
		double NewPayRate = 0, double NewGPA = 0.0);
	bool Get(void);
	long HeaderNo_();
	double GPA_(void);
	double PayRate_(void);
	long Key();
	void Display(char Message[] = "");
	void Display50(void);

	friend ostream & operator << (ostream & OutputStream, Client P);

// I have decided that Name is to be the Primary Character Key for this record type.   
	bool operator == (const char Key[]);
	bool operator >  (const char Key[]);
	bool operator >= (const char Key[]);
	bool operator <  (const char Key[]);
	bool operator <= (const char Key[]);
	bool operator != (const char Key[]);
	void operator =  (const char Key[]);

// I have decided that ID is to be the Primary Integer Key for this record type.   
	bool operator == (const long Key);
	bool operator >  (const long Key);
	bool operator >= (const long Key);
	bool operator <  (const long Key);
	bool operator <= (const long Key);
	bool operator != (const long Key);
	void operator =  (const long Key);

// I have decided that Name is to be the Primary Key for this record type.   
	bool operator == (const Client & P);
	bool operator >  (const Client & P);
	bool operator >= (const Client & P);
	bool operator <  (const Client & P);
	bool operator <= (const Client & P);
	bool operator != (const Client & P);
	void operator =  (const Client & P);

private:
	char 
		Name [26];
	long
		ID, 
		HeaderNo;
	double
		PayRate,
		GPA;
	};

// ------------------------- IDn-Class Functions Prototypes-----------------------

# ifdef CLIENT_DIAGNOSTIC_LEVEL //---------------------------------------------------
	void TestClient(void);
# endif // CLIENT_DIAGNOSTIC_LEVEL --------------------------------------------------


# endif // CLIENT_CLASS ============================================================