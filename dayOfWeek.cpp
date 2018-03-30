#include <iostream>
using namespace std;

// global types & variables //
typedef unsigned int Year;
enum Months {January = 1, February, March, April, May, June, July, August, September, October, November, December};

// function list //
void dayOfWeek(int year, Months month, int day);


int main()
{
	/*
	Day Of Week will take parameters year, month, day (integer) and return the day of the week in a console output.

	note that 1 AD began on Saturday, January 1st
	*/

	// My birthday //
	Year birthYear = 1;
	Months birthMonth = January;
	int birthDayInt = 1; 

	cout << "I was born on a Tuesday, lets see if my function works!" << endl;

	// call the function //
	dayOfWeek(birthYear, birthMonth, birthDayInt);

	return 0;
}

void dayOfWeek(int year, Months month, int day)
{
	int count = 1; // count will save how many days have passed since 1/1/1

	// determine if this year is a leap year & how many leap years have passed //
	int leap = year % 4;
	bool isLeap = false;
	if(leap == 0) isLeap = true;

	int leaps = year / 4; // when 2 integers are divided, the result is rounded down ( like Math.floor() )

	count = count + (365 * (year - 1)) + leaps; // This would be a good place to debug (WHY?)

	// SANITY CHECK //
	cout << count << "<- Count, " << leap << "<- Leap, " << isLeap << "<- isLeap, " << leaps << "<- Leaps." << endl;

	// determine the day that have passed since January 1 //
	//		What structure should this code take
	//		We could go with a very long if/else if/... 
	if (month == February) count += 31;
	if (month == March) count += (31 + 28);
	if (month == April) count += ((2 * 31) + 28);
	if (month == May) count += ((3 * 31) + 28);
	if (month == June) count += ((3 * 31) + 30 + 28);
	if (month == July) count += ((3 * 31) + (2 * 30) + 28);
	if (month == August) count += ((4 * 31) + (2 * 30) + 28);
	if (month == September) count += ((5 * 31) + (2 * 30) + 28);
	if (month == October) count += ((5 * 31) + (3 * 30) + 28);
	if (month == November) count += ((6 * 31) + (3 * 30) + 28);
	if (month == December) count += ((6 * 31) + (4 * 30) + 28);
	// What are we missing??? LEAP YEAR! //
	bool afterLeapDay = false;
	if ((month != January) && (month != February)) afterLeapDay = true;
	if (isLeap && afterLeapDay) count++;

	// SANITY CHECK //

	cout << count << "<- New Count " << endl;

	// Finally, how do we deal with the day?
	count += day;

	cout << count << "<- New Count" << endl;

	// Finally, what day of the Week does that correspond to? //
	int rm = count % 7; // rm will correspond to the index of days of the week

	// we could use a array of type string to store the days of week, and use the index to print the correct day of the week
	string week[] = {"Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday"};

	string dayName = week[rm];

	cout << "The corrsponding day of the week associated with that date is: " << dayName << endl;
}

/*
	Can you identify problems with the code?
		- What happens for 1/1/1?
		- User input?
		- How easy to use?
*/