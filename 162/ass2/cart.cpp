#include "cart.h"
//#include <iostream>

using namespace std;
cart::cart(){// default constructor
	num_books=0;
	books=NULL;


}


/******************************************************
** Function: copy constructor
** Description: Does a deep copy of the info 
** Parameters: cart variable
** Pre-conditions: the cart doesn't have books'
** Post-conditions: has books now
*****************************************************/


cart::cart(const cart &main){ //copy constructor
	num_books=main.num_books;
	if(num_books==0){
		books=NULL;
		num_books=0;
	}
	else{
		books=new book [main.num_books];
		num_books=main.num_books;
		for(int i=0; i<main.num_books; i++){
			books[i]=main.books[i];
			books[i].authors=new string[main.books[i].num_authors];
			for(int j=0; j< main.books[i].num_authors; j++){
				books[i].authors[j]=main.books[i].authors[j];
			}
		}
	}
}


/******************************************************
** Function: overload operator
** Description: like copy constructor but has a void return type and deletes
** Parameters: cart pointer
** Pre-conditions: idk
** Post-conditions: still don't know..this is dumb'
*****************************************************/


void cart::operator=(const cart &main){
		num_books=main.num_books;
	if(num_books==0){
		books=NULL;
		num_books=0;
	}
	else{
		books=new book [main.num_books];
		num_books=main.num_books;
		for(int i=0; i<main.num_books; i++){
			books[i]=main.books[i];
			books[i].authors=new string[main.books[i].num_authors];
			for(int j=0; j< main.books[i].num_authors; j++){
				books[i].authors[j]=main.books[i].authors[j];
			}
		}
	}

}
/*
void cart::resize_books(int ){


}

void cart::set_book(const int b, const book &books){
	
}

book cart:: *get_books()const{
	return books;
}
*/

/******************************************************
** Function: set_num_books
** Description: adds n to number of books
** Parameters: const integer n
** Pre-conditions: number of books is num_books
** Post-conditions:  number of books is num_books+n
*****************************************************/

void cart::set_num_books(const int n){//mutator
	num_books= n;
}

/******************************************************
** Function: get_num_books
** Description: returns number of books in my cart
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
*****************************************************/

int cart::get_num_books() const{//accessor
	return num_books;
}

/******************************************************
** Function: destructor
** Description: deletes allocated memory in my cart
** Parameters: none
** Pre-conditions: memory leaks
** Post-conditions: no memory leaks
*****************************************************/


cart::~cart(){
	for(int i=0; i<num_books;i++){
		delete [] books[i].authors;
	}
	delete [] books;
}
