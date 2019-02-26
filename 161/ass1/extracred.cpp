/**********
**Program: extracred.cpp
**Author: Joshua Strozzi
**Date: 1/14/2017
**Description: Converts number input by user into into the max/min number that that many bit spaces can represent
**Input: Any positive integer
**Output: Max/min that that many bit spaces can represent
**********/



#include <iostream>
#include <cmath>
using namespace std;
int main () {
	int i; //this is the variable we will be using
	cout << "How many bit spaces will your numbers have? " ;
	cin >> i; //this is where the user will put in his number
	cout << "Your max signed number is: " << pow(2,i)/2 -1<< endl; 
	cout << "Your min signed number is: " << pow(2,i)/2*-1<< endl;
	cout << "Your max unsigned number is: " << pow(2,i) -1<< endl;

	return 0;
}
