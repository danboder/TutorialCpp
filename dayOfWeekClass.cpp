/* Preface



____________
*/

///Header
#include <iostream>
using namespace std;

enum Months {January = 1, February, March, April, May, June, July, August, September, October, November, December};

///Function List
int yearsPass(int year);
int monthsPass(Months month, int year);
string whatDay(int count);

///Classes
class Year{
public:
	int index, dayCount;
	bool isLeap;

	void setLeap(){
		if(index%4 == 0){
			if(index%100 == 0){
				if(index%400 == 0){
					isLeap = true;
				} else {
					isLeap = false;
				}
			} else {
				isLeap = true;
			}
		} else {
			isLeap = false;
		}
	}

	void setDayCount(){
		if(isLeap){
			dayCount = 366;
		} else {
			dayCount = 365;
		}
	}
};
///Main
int main(){
	// AD started on Saturday, January 1st, 1 AD.

	// My birthday //
	int birthYear = 1994;
	Months birthMonth = December;
	int birthDayInt = 6; 

	cout << "I was born on a Tuesday, lets see if my function works!" << endl;
	int count = 0;
	count += yearsPass(birthYear);
	count += monthsPass(birthMonth, birthYear);
	count += birthDayInt;

	cout << "Is " << whatDay(count) << " the right day?" << endl;


	return 0;
}
///Functs

int yearsPass(int year){
	int output = 0; // This output will modify the existing counter
	for (int i = 1; i < year; i++){
		Year current;
		current.index = i;
		current.setLeap();
		current.setDayCount();
		output += current.dayCount;
	}
	return output;
}

int monthsPass(Months month, int year){
	int count = 0;
	Year current;
	current.index = year;
	current.setLeap();

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

	if(current.isLeap && (month != January || month != February)) count += 1;
}

string whatDay(int count){
	// count = 1 => Saturday
	int index = count % 7;
	switch(index){
		case 1: return "Saturday";
		case 2: return "Sunday";
		case 3: return "Monday";
		case 4: return "Tuesday";
		case 5: return "Wednesday";
		case 6: return "Thursday";
		case 0: return "Friday";

	}
}