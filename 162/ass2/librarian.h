//#include <string>
#include "cart.h"

using namespace std;

#ifndef LIBRARIAN_H
#define LIBRARIAN_H
class librarian {
	private: 
		string name; //name of librarian currently logged in
		int id; //the password used to login as that librarian
	public: 
		librarian();
		//void menu();
		bool choose_user();//good
		//void change_library_hours();
		//void add_new_books(const cart &);
		void add_book();
		void add_book_finish();
		void remove_old_books();
		void view_all_books_checked_out();
		void view_specific_book_checked_out(string);
		void delete_book();
};
#endif