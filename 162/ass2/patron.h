//#include <string>
#include "cart.h"
#ifndef PATRON_H
#define PATRON_H

class patron {
	private:
		string name;
		int id;
		int books_checked_out;

    public:
		patron();
		//void copy_data(const book *, int);
		void find_books_out();
		int get_books_out();
		bool choose_user();
		void check_out(book *, int);
		void check_in(book *, int);
		void search_author(const book *, int);
		void search_title(const book *, int);
		void search_year(const book *, int);
		void check_out_books(const cart &);
		void check_in(const cart &);
		void view_my_books_out();
		void check_out_finish(const book *, int);
		string convert_underscore();
		//~patron();
};

#endif
