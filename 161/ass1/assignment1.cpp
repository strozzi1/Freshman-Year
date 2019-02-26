/***************
 **Program: assignment1.cpp
 **Author: Joshua Strozzi
 **Date: 1/12/2017
 **Description: This program returns the max and min of signed and unsigned ints, shorts, and longs.
 ********************/

#include <iostream> //this is to print and read info
#include <cmath> //allows me to use pow
#include <climits> //allows me to access INT, long, and short functions

using namespace std; //this allows me to not have to not prefix all commands with std:: 

int main() {  //declares our main function
	cout << "The maximum for an unsigned int is: "<<UINT_MAX <<endl;
	cout << "The maximum for a signed int is: "<<INT_MAX <<endl;
	cout << "The minimum for a signed int is: "<<INT_MIN <<endl;
	cout << "The minimum value for a signed short int is: " <<SHRT_MIN << endl;
	cout << "The maximum value for a signed short int is: " <<SHRT_MAX << endl;
	cout << "The Maximum value for an unsigned short int is: " <<USHRT_MAX <<endl; 
	cout << "The minimum value for a signed long int is: " <<LONG_MIN << endl;
	cout << "The maximum value for a signed long int is: " <<LONG_MAX << endl;
	cout << "The maximum value for an unsigned long int is: " <<ULONG_MAX <<endl;

	cout << "Calculated max and mins" << endl;
	cout << "The maximun for an unsigned 8-bit number is " << pow(2,8)-1<< endl; 
	cout << " The maximum for a signed 8-bit number is " << pow(2,7)-1<< endl;
	cout << " The minimun for a signed 8-bit number is " << pow(2,7)*-1 << endl;


	return 0;  //returns control to whatever called our functon
}
