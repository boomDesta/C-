// ..................................................  
// CDate class definitions
// Adapted from Hagit Schechter, Jan 2007 for 2014W2 
// ..................................................

#include <iostream>
#include <string>
#include "CDate.h"

CDate::CDate(void){
	m_year = m_month = m_day = 0;
}

CDate::CDate(int year, int month, int day){
	setDate( year, month, day );        
}

CDate::CDate(int year, std::string month, int day){
	setDate(year,monthStr2Num(month),day);

	// TODO you need to fill in the code here        ********
	// HINT use monthStr2Num to get the month_num 
}

bool CDate::isValidDate(int year, int month, int day){
	return(year>0 && 0<=month && month<=12 && isValidDay(year,month,day));
	// TODO you need to fill in the code here        ********
	// comment out the "return false" below 
	// then check the validity of a year, month, and day
	//return false;
}

bool CDate::isValidDate(int year, std::string month, int day){
	int month_num = monthStr2Num(month);
	return (year >0 && 0<=month_num && month_num<=12 && isValidDay(year,month_num,day));
	// TODO you need to fill in the code here        ********
	// comment out "return false" below
	// HINT use monthStr2Num to get the month_num 
	// and then reuse another function
	//return false;
}

int CDate::monthStr2Num(std::string month){
	int month_num;
	if(month=="January") month_num=1;
	if(month=="February") month_num=2;
	if(month=="March") month_num =3;
	if(month=="April")month_num=4;
	if(month =="May")month_num=5;
	if(month=="July")month_num=7;
	if(month=="June")month_num=6;
	if(month=="August")month_num=8;
	if(month=="September")month_num=9;
	if(month=="October")month_num=10;
	if(month=="November")month_num=11;
	if(month=="December")month_num=12;
	return month_num;
	// TODO you need to fill in the code here        ********
}

bool CDate::isValidDay(int year, int month, int day){
	if ((day < 1) || (day > 31)) return false;

	bool valid = false;
	switch (month) {
		case 1:valid = true;break;
		case 3:valid = true;break;
		case 5:valid = true;break;
		case 7:valid = true;break;
		case 8:valid = true;break;
		case 10:valid = true;break;
		case 12:valid = true;break;
			// TODO you need to fill in the code here        ********
		case 2:
			// Don't worry about this code too much.
			// It handles all the leap year rules for February.
			if ((year % 4) != 0) {
				valid = (day <=28);
			} else if ((year % 400) == 0) {
				valid = (day <= 29);
			} else if ((year % 100) == 0) {
				valid = (day <= 28);
			} else {
				valid = (day <= 29);
			}
			break;
		case 4:valid = (day <= 30);break;
		case 6:valid = (day <= 30);break;
		case 9:valid = (day <= 30);break;
		case 11:valid = (day <= 30);break;
			// TODO you need to fill in the code here        ********
		default:
			valid = false;
			break; 
	}
	return valid;
}

void CDate::setDate(int year, int month, int day){
	if(isValidDate(year, month, day)){    
		m_year = year;
		m_month = month;
		m_day = day;
	}
	else {
		m_year = m_month = m_day = 0;
	}
}


void CDate::setDate(int year, std::string month, int day){
	int month_num = monthStr2Num(month);
	setDate(year,month_num,day);
	// TODO you need to fill in the code here        ********
	// HINT use monthStr2Num to get the month_num 
	// and then reuse another function
}

void CDate::print(void){
	std::cout << m_year << "/" << m_month << "/" << m_day << std::endl;
}

int CDate::getDate(void){
	return (m_year * 10000) + (m_month * 100) + m_day;
}

