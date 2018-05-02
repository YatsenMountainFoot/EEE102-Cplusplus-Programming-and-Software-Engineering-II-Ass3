//class menber for Month and Date implementation
//@Zheng.Sun15	ID:1507820
#include "Month_Date.h"
#include <iostream>
#include <string>
#include <cstring>
//Default constructor set member variable as NULL
Month::Month() {
	m_m = NUL;
}
//Constructor set the month using the 1st 3 letters of a month
Month::Month(char x, char y ,char z) {

	m_m = NUL;

	for (int i = 0; i < 12 && m_m == NUL; i++){
		if (monthsAbbr[i][0] == x && monthsAbbr[i][1] == y && monthsAbbr[i][2] == z)
			m_m = (e_month)(i + 1);
	}
}
//Constructor set the month using number associated with the month
Month::Month(int x) {
	m_m = (e_month) x;
}
//Parse an integer to construct Month
Month Month::inputIntM(){
	std::cout << "Please Enter the month by number:";

	int num = intParser();
	while (num<1 || num >12){
		std::cout << "The number should be between 1 and 12:";
		num = intParser();
	} 
	return Month(num);
}
//Parse 3 characters to construct a Month
Month Month::inputAbbrM() {
	using std::cin;
	using std::string;
	using std::getline;
	string str;
	Month M;

	do {
		std::cout << "Please enter the first 3 letters of a month in Capital:";
		getline(cin, str);
		if (str.size() == 3)
			M = Month(str[0], str[1], str[2]);
	} while (M.m_m == NUL);

	return M;
}
//return the next Month of current Month
Month Month::nextMonth() {
	int x;
	if (m_m == DEC){
		std::cout << "(Happy new year!)";
		x = 1;}
	else
		x = m_m + 1;
	return Month(x);
}
//add up days of the Months before the Month 
int Month::toDays()const {
	int m_numerical = this->m_m;
	int days = 0;
	for (int i = 0; i < m_numerical; i++) {
		days += daysOfMonth[i];
	}
	return days;
}
//return the numebr representing the Month
int Month::toNum()const {
	int num = m_m;
	return num;
}
//display the full name of Month
void Month::displayFullNameM()const {
	switch (m_m)
	{
		using std::cout;
	case NUL: cout << "NULL";
		break;
	case JAN: cout << "January";
		break;
	case FEB: cout << "Feburary";
		break;
	case MAR: cout << "March";
		break;
	case APR: cout << "April";
		break;
	case MAY: cout << "May";
		break;
	case JUN: cout << "June";
		break;
	case JUL: cout << "July";
		break;
	case AUG: cout << "August";
		break;
	case SEP: cout << "September";
		break;
	case OCT: cout << "October";
		break;
	case NOV: cout << "Nobvember";
		break;
	case DEC: cout << "December";
		break;
	default: cout << "Non";
		break;
	}

}
//display the 3-char Abbr of Month
void Month::displayAbbrM()const {
	std::cout << monthsAbbr[(int)this->m_m - 1];
}
//overloeding '=' to assign the value of Month to another
Month Month::operator= (const Month& m) {
	this->m_m = m.m_m;
	return *this;
}
//overloading '++' to add current month by one
void Month::operator++ () {
	this->m_m = (e_month)(this->m_m + 1);
}
//overloading '>' to compare current month to the other
bool Month::operator> (const Month& m)const {
	if ((int)this->m_m > (int)m.m_m)
		return true;
	else
		return false;
}
//overloading '<' to compare current month to the other
bool Month::operator< (const Month& m)const {
	if ((int)this->m_m < (int)m.m_m)
		return true;
	else
		return false;
}
//overloading '==' to compare current month to the other
bool Month::operator== (const Month& m)const {
	if ((int)this->m_m == (int)m.m_m)
		return true;
	else
		return false;
}

//Date class begins
//Defult constructor to set a Date as NUL-0
Date::Date() {
	D_m_m = Month();
	date = 0;
}
//Constructor accept Month obj and int as date to construct a Date obj
Date::Date(Month m, int d) {
	D_m_m = m;
	date = d;
	this->normalize();
}
//Constructor accept emum e_month type and int as date to construct a Date obj
Date::Date(e_month m, int d) {
	D_m_m = Month(m);
	date = d;
	this->normalize();
}
//Destryctor
Date::~Date() {
	std::cout << "Bye, ";
	this->showD();
	std::cout << "!(destructor called)\n";
}
//flat current Date obj into days
int Date::toDays()const {
	int days = 0;
	days = this->D_m_m.toDays() + this->date;
	if (days > 365){
		std::cout << "(Hapy new year!)";
		return days % 365;}
	else
		return days;
}
//display Date in full format
void Date::showD()const{
	this->D_m_m.displayFullNameM();
	std::cout << " - " << this->date;
}
//display Date in abbriviation format
void Date::showAbbrD()const {

	this->D_m_m.displayAbbrM();
	std::cout << " - " << this->date;

}
//normalize Date to restricted format: the month in a year, the days of a month
void Date::normalize() {
	int days = this->toDays();
	int months_numerical = 0;
	for (int i = 0; days > daysOfMonth[i]; i++) {
		days -= daysOfMonth[i];
		months_numerical++;
	}
	this->D_m_m = Month(months_numerical);
	this->date = days;
}
//Ceate a Date obj form user input with month in int
Date Date::inputIntD() {
	Date D;
	D.D_m_m = inputIntM();
	D.date = D.dateParser();
	return D;
}
//Ceate a Date obj form user input with month in 3-char string
Date Date::inputAbbrD() {
	Date D;
	D.D_m_m = inputAbbrM();
	D.date = D.dateParser(); 
	return D;
}
//restrict date in a month, say, January has less than 31 days
int Date::dateParser() {
	
	std::cout << "Please Enter the date in "; this->D_m_m.displayFullNameM(); std::cout<<" by number:";
	int temp = intParser();
	
	while (temp<1 || temp > daysOfMonth[(int)this->D_m_m.toNum()]) {
		std::cout << "The number should be between 1 and " << daysOfMonth[(int)this->D_m_m.toNum()] <<  ":";
		temp = intParser();
	}
	return temp;
}
//overloading '=' to assign the other Date to current Date
Date Date::operator= (const Date& D) {
	this->D_m_m = D.D_m_m;
	this->date = D.date;
	return *this;
}
//overloading '>' to compare current month to the other
bool Date::operator> (const Date& D)const {
	if (this->D_m_m > D.D_m_m || (this->D_m_m == D.D_m_m&&this->date > D.date ))
		return true;
	else
		return false;
}
//overloading '<' to compare current month to the other
bool Date::operator< (const Date& D)const {
	if (this->D_m_m < D.D_m_m || (this->D_m_m == D.D_m_m && this->date < D.date))
		return true;
	else
		return false;
}
//overloading '==' to compare current month to the other
bool Date::operator== (const Date& D)const {
	if (this->D_m_m == D.D_m_m && this->date == D.date)
		return true;
	else
		return false;
}
//overloading '++' to add the date by 1
void Date::operator++ () {
	this->date++;
	this->normalize();
}