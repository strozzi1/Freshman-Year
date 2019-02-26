
#include "patron.h"
#include "librarian.h"
//#include "cart.h"
//#include "structs.h"


using namespace std; 
#ifndef LIBRARY_H
#define LIBRARY_H
class Library{
	private:
		hours week[7]; //for displaying and changing hours
		int num_books; //number of books in entire library
		book *books; //all of books 
		cart c; //
		librarian l;
		patron p; 
	public:
		Library();
		Library(const Library &);	
		void display_array();
		void menu(); //good
		void patron_funcs();
		void librar_funcs();
		void p_search();
		void hours_choose();//good
		void hours_change();
		void display_daily_hours(int); //for displaying hours of operation of specific day
		void see_checked_out();
		void display_weekly_hours(); //for displaying hours of operation for all days of week
		void operator=(const Library &); //good I think
		void fill_catalog();//good
		void login();//good
		void redo_cat();
		void change_hours();
		~Library(); //for deleting allocated memory 
};

#endif
