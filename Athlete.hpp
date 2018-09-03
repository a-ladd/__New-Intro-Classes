//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                                                              //
//                                    Athlete.hpp                               //
//                                                                              //
//  Purpose    : Athlete Interface. The interface shall include the includes,   //
//               defines, class definition and prototypes that the compiler     //
//               needs in order to compile and execute Athlete objects.         //
//                                                                              //
//               Since this class is not a template class, there are no         //
//               template functions.                                            //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 10               //
//  Date.......: xx/xx/xxxx              Compiler....: Visual Studio 2017 C++   //
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

# ifndef ATHLETE_CLASS //============================================================

// ----------------------------------- Includes ----------------------------------
# include "Utilities.hpp"

// ----------------------------------- Defines -----------------------------------

# define ATHLETE_DIAGNOSTIC_LEVEL 1
# define ATHLETE_CLASS

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                     Class Athlete                            //
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
class Athlete
{
public:
	Athlete (char NewName[] = "", int NewNo = 0, int NewSportNo = 0, 
			double NewEquipmentValue = 0.0);  
	Athlete ( int NewNo, char NewName[] = "", int NewSportNo = 0, 
			double NewEquipmentValue = 0.0);  
  
	~Athlete (void);
	void Set (char NewName[] = "", int NewNo = 0, int NewSportNo = 0, 
				double NewEquipmentValue = 0.0); 
	bool Get(void);
	long int  No_(void);         // Accessor Which Explicitly Returns No.
	int  SportNo_(void);         // Accessor Which Explicitly Returns SportNo.
	long int Key(void);          // Accessor Which Explicitly Returns No.
	double EquipmentValue_(void);

	void Display(char Message[] = "");
	void Display50(void);

	friend ostream & operator << (ostream & OutputStream, Athlete A);

	// I have decided that Name is to be the Primary Character Key for this record type.   
	bool operator == (const char Key[]);
	bool operator >  (const char Key[]);
	bool operator >= (const char Key[]);
	bool operator <  (const char Key[]);
	bool operator <= (const char Key[]);
	bool operator != (const char Key[]);
	void operator =  (const char Key[]);

	// I have decided that No is to be the Primary Integer Key for this record type.   
	bool operator == (const long int Key);
	bool operator >  (const long int Key);
	bool operator >= (const long int Key);
	bool operator <  (const long int Key);
	bool operator <= (const long int Key);
	bool operator != (const long int Key);
	void operator =  (const long int Key);

	// I have decided that Name is to be the Primary Key for this record type.   
	bool operator == (const Athlete & A);
	bool operator >  (const Athlete & A);
	bool operator >= (const Athlete & A);
	bool operator <  (const Athlete & A);
	bool operator <= (const Athlete & A);
	bool operator != (const Athlete & A);
	void operator =  (const Athlete & A);

private:
	char 
		Name [26];
	long int
		No, 
		SportNo;
	double
		EquipmentValue;
};

// ------------------------- Non-Class Functions Prototypes-----------------------

# ifdef ATHLETE_DIAGNOSTIC_LEVEL //---------------------------------------------------
void TestAthlete(void);
# endif // ATHLETE_DIAGNOSTIC_LEVEL --------------------------------------------------

# endif // ATHLETE_CLASS ============================================================
