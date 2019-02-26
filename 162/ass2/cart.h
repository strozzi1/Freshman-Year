#include "structs.h"
using namespace std;

#ifndef CART_H
#define CART_H

class cart{
	private:
		book *books; //all books in cart
		int num_books; //number of books in cart
		void resize_books(int); //change number of books in cart
	public: 
		cart();
		cart(const cart &);//set books to NULL and num_books to zero//done automatically
		~cart();//delete memory allocated//done as leaving program automatically
		void operator=(const cart &);
		void set_book(const int, const book ); //book index to set & books
		book * get_books() const; //return address of array of books
		void set_num_books(const int); //set num_books and make book array
		int get_num_books() const; //return number of books in cart

};

#endif


