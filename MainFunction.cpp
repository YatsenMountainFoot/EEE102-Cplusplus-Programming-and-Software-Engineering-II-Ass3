//Main function for implementation
//@Zheng.Sun15	ID:1507820
#include "Month_Date.h"
#include <iostream>

int main() {
	{
	using std::cin;
	using std::cout;
	using std::endl;
	Month a, b, c, d, e;	//delarare class Month instances for demonstration
	a = Month('J', 'A', 'N');//constructor accept 3 chars
	b = Month(2);	//constructor accept 1 int number
	c = Month();	//default constructor
	cout << "Month('J', 'A', 'N') is "; a.displayFullNameM(); cout << endl;	//demonstration
	cout << "Month(2) is "; b.displayFullNameM(); cout << endl;
	cout << "Month() as default is "; c.displayFullNameM(); cout << endl;	
	d = Month::inputIntM();	//	prompt user to enter a number as Month
	cout << "Month set by number is "; d.displayFullNameM(); cout << endl;	
	e = Month::inputAbbrM();//	prompt user to enter 3 CAPITAL char as Month
	cout << "Month set by the first 3 char is "; e.displayFullNameM(); cout << endl;
	cout << "Month after "; e.displayFullNameM(); cout << " is "; e.nextMonth().displayFullNameM(); cout << endl << endl;// Display member function nextMonth()

	
	Date x, y, z;	//delarare class Date instances for demonstration
	cout << "Here comes Date class test:\n";
	x = Date(MAR, 20);	//Test e.g. requirememts in the assignmet
	cout << "x = Date(MAR, 20) is ";  x.showAbbrD(); cout << endl;
	y = Date::inputAbbrD();	// Test input abbr member function
	cout << "y = "; y.showAbbrD(); cout << endl; 
	z = Date::inputIntD();	// Test input integer member function
	cout << "z = "; z.showAbbrD();cout << endl<< endl;;

	// Test and overloaded oeprators
	cout << "Now, y = ";  y.showAbbrD(); cout << " and z = ";  z.showAbbrD(); cout << endl;  
	cout << "y > z";  cout << " is "; showBool(y > z); cout << endl;	
	cout << "y == z"; cout << " is "; showBool(y == z); cout << endl;
	cout << "y < z";  cout << " is "; showBool(y < z); cout << endl;
	cout << "z = "; z.showAbbrD(); cout << " and ++z is ";
	++z; z.showAbbrD(); cout << endl;

	}
	
	return 0;
}

//to Parse an int type value from the input 
int intParser() {
	using std::cin;
	using std::cout;
	int temp;
	bool isErr = true;
	//while (input failed) or (input succeeded with redundant tail, clear steream and repeat)
	while ((isErr = !(cin >> temp))||(!isErr && cin.get() != '\n')) {
		if(isErr){cin.clear();}
			//reset cin
		while (cin.get() != '\n')//clear a whole line
			continue;
		cout << "\t\tPlease enter an integer: ";
	}
	return temp;
}

//Display the truth of x on screen
void showBool(bool x) {
	if (x == true)
		std::cout << "true";
	else
		std::cout << "false";
}