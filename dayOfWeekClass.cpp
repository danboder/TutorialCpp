/* Preface



____________
*/

///Header
#include <iostream>
using namespace std;

///Function List
int yearsPass(int year);
int monthsPass(int month);
string whatDay(int input);

///Classes
class Year{
public:
	int index;
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
};
///Main
int main(){
	// AD started on Saturday, January 1st, 1 AD.

	// My birthday //
	int birthYear = 2;

	Year birth;
	birth.index = birthYear;
	birth.setLeap();

	int birthMonth = 1;
	int birthDayInt = 1; 

	cout << "I was born on a Tuesday, lets see if my function works!" << endl;
	int count = 0;
	count += yearsPass(birthYear);
	count += monthsPass(birthMonth);
	if(birth.isLeap && birthMonth != 1 && birthMonth != 2) count += 1;
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
		if(current.isLeap){
			output += 366;
		} else {
			output += 365;
		}
	}
	return output;
}

int monthsPass(int month){
	int count = 0; // Add 0 for Jan
//30 is Sept, Apr, June, Nov
	if(month > 1){ //Add: Jan
		count += 31;
		if (month > 2){ // Feb
			count += 28;
			if(month > 3){ // Mar
				count += 31;
				if(month > 4){ // Apr
					count += 30;
					if(month > 5){ // May
						count += 31;
						if(month > 6){ // June
							count += 30;
							if(month > 7){ // July
								count += 31;
								if(month > 8){ // Aug
									count += 31;
									if(month > 9){ // Sept
										count += 30;
										if(month > 10){ //Oct
											count += 31;
											if(month > 11){ // Nov
												count += 30;
											}
										}
									} 
								}
							}
						}
					}
				}
			}
		}
	}
	return count;
}

string whatDay(int input){
	// count = 1 => Saturday
	int i = input%7;
	switch(i){
		case 1: return "Saturday";
		case 2: return "Sunday";
		case 3: return "Monday";
		case 4: return "Tuesday";
		case 5: return "Wednesday";
		case 6: return "Thursday";
		case 0: return "Friday";
	}
}