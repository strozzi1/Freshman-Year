#include <iostream>
#include <cstring>

#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;


struct county{
	string name; //name of county
	string *city; //name of cities in county
	int cities; //number of cities
	int population; //total population of county
	float avg_income; // avg household income
	float avg_house; //avg household price
};

struct state {
	string name; //name of state
	struct county *c; //array of counties
	int counties; //number of counties
	int population; //total population of state
};
//required
bool is_valid_arguments(char*[], int);
state * create_states(int); //create state array
void get_state_data(state *, int, ifstream &); //fill state array
county * create_counties(int);
void get_county_data(county *, int, ifstream &);
void delete_info (state **, int);
//custom
string countypop(state *, int);
string statepop(state *, int);
void incomecounty(state*, int);
void incomecounty_out(state *, int, ofstream&);
void avg_hshld_cost(state *, int);//make another for output
void avg_hshld_cost_out(state*, int, ofstream&);
void sn_sort(state*, int);
void sp_sort(state*, int);
void cn_sort(state*, int);
void cp_sort(state*, int);