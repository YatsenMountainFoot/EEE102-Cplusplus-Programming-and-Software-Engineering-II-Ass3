//Header for implement Month and Date
//@Zheng.Sun15	ID:1507820
#ifndef _Month_Date_
#define _Month_Date_
	const int daysOfMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};// used to flat the Month & Date obj and retrict input
	enum e_month{NUL, JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};	// difine enum type to represent a month
	const char monthsAbbr[12][4]{ "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC" };	//abbr char strings for input check and display output

int intParser();
void showBool(bool x);
class Month {
private:
	enum e_month m_m = NUL; //Member variable of type enum to represent a month 
public:
	Month();			//default constructor
	Month(int x);		// //construct with month using integer to representing the month
	Month(char x, char y, char z); //construct with month using the first 3 letters of the month

	int toDays()const;	//flat to days
	int toNum()const;	//flat to numbers
	void displayFullNameM()const;	//display obj's full name
	void displayAbbrM()const;		//display obj's abbr name
	static Month inputIntM();	//create obj by inputed int
	static Month inputAbbrM();	//create obj by inputed 3-char abbr
	Month nextMonth();	//member function that returns the next month as a value of type Month
	void operator++();	//'++'op
	Month operator= (const Month& m);		//'='op
	bool operator> (const Month& m)const;	//'>'op
	bool operator< (const Month& m)const;	//'<'op
	bool operator== (const Month& m)const;	//'=='op
};

class Date:public Month {
private:
	Month D_m_m;	//month
	int date;		//date
public:
	Date();	//default constructor
	Date(Month m, int d); // constructor with Month obj as month and int as date
	Date(e_month m, int d); // constructor with enum e_month as month and int as date
	~Date(); //Date destructor
	int toDays()const;	//flat Date obj to
	void showD()const;	//display Date with Month abbr format
	void showAbbrD()const; // display Date with Month abbr format
	void normalize();	//normalize Date to formated Date obj
	static Date inputIntD();	//create obj by input Date with Month inputed as int
	static Date inputAbbrD();	//create obj by input Date with Month inputed as 3-char Abbr string
	int dateParser();	//parse input as date, if not, deal with error
	Date operator= (const Date& D);			//'='op
	bool operator> (const Date& D)const;	//'>'op
	bool operator< (const Date& D)const;	//'<'op
	bool operator== (const Date& D)const;	//'=='op
	void operator++ ();	//'++'op
};

#endif