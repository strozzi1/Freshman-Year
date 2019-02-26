#include "musician.h"

musician::musician(string s){
	name=s;
}

string musician::get_name() const {
	return name;
}

void musician::set_name(const string &s){
	name=s;
}
