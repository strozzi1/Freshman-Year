#include <string>

using namespace std;
#ifndef STRUCTS_H
#define STRUCTS_H

struct hours {       //for displaying and changing hours
	int begin_time; //start time of operation for library
	int end_time;  //end time
};
struct book { 
	string title;     //name of book
	int num_authors; //number of authors for a book
	string *authors;//array of authors for said book
	int year;      //year of publication
	int copies;   //number of copies of specific book I have
};

#endif