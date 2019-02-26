#include "library.h"
#include <fstream>
#include <iostream>
#include "structs.h"
#include <cstdlib>
#include "cart.h"
#include "patron.h"

using namespace std;



Library::Library(){
	for(int i=0; i<7; i++){//working
		week[i].begin_time=9;//what a
		week[i].end_time=17; //way to make a living
	}
	num_books=0;
	books=NULL;
	


}

/******************************************************
** Function: 
** Description:
** Parameters:
** Pre-conditions:
** Post-conditions:
*****************************************************/
void Library::display_array(){
	for(int i=0; i<num_books; i++){
		cout<<books[i].title<<endl;
		cout<<books[i].num_authors<<endl;
			for(int j=0; j<books[i].num_authors; j++){
				cout<<books[i].authors[j]<<endl;
			}
		cout<<books[i].year<<endl;
		cout<<books[i].copies<<endl;
	}

}

/******************************************************
** Function: 
** Description:
** Parameters:
** Pre-conditions:
** Post-conditions:
*****************************************************/

void Library::login(){
	char choice[20];
	int u;
	bool logged_in=false;

	do{
	cout<<"Would you like to login as -\n[1]Patron \nor\n[2]Librarian\nChoice:";
	cin>>choice;
	}while(atoi(choice) <1 || atoi(choice) >2);
	u=atoi(choice);

	if(u==1){
		//p.search_title(books);
		logged_in=p.choose_user();
		if(logged_in==true)
			Library::patron_funcs();
		else	
			Library::login();

	}
	else if(u==2){
		logged_in=l.choose_user();
		if(logged_in==true)
			Library::librar_funcs();
		else
			Library::login();
	}

}


/******************************************************
** Function: 
** Description:
** Parameters:
** Pre-conditions:
** Post-conditions:
*****************************************************/


void Library::hours_change(){
	char choice[5], choice2[5];
	do{
	cout<<"What day of the week would you like to change hours for?\n[0]Monday\n[1]Tuesday\n[2]Wednesday\n[3]Thursday\n[4]Friday\n[5]Saturday\n[6]Sunday\n[7]Quit\n Choice: ";
    cin>>choice;
    }while(atoi(choice) <1 || atoi(choice) >7);
	if(atoi(choice)>-1 && atoi(choice)<7){
		do{
		cout<<"What would you like start hours to be for this day?: ";
		cin>>choice2;
		}while(atoi(choice2)<0 && atoi(choice2)>23);
		week[atoi(choice)].begin_time=atoi(choice2);
		do{
			cout<<"What would you like end hours to be for this day?: ";
			cin>>choice2;
		}while(atoi(choice2)<0 && atoi(choice2)>23);
		week[atoi(choice)].end_time=atoi(choice2);
	}
	else
		cout<<"Returning to librarian menu."<<endl;

}


/******************************************************
** Function: 
** Description:
** Parameters:
** Pre-conditions:
** Post-conditions:
*****************************************************/


void Library::librar_funcs(){
	char temp[20];
	bool quit=false;

    do{
	do{

    cout<<"What would you like to do?\n[1] Change Hours\n[2] Add book\n[3] Remove Book\n[4] See what books are out\n[5] Logout\nChoice:";
    cin>>temp;
    }while(atoi(temp) <1 && atoi(temp) >4);
   
    if (temp[0]=='1'){
		hours_change();
    }
    else if(temp[0]=='2'){

		l.add_book();
		l.add_book_finish();
		Library::redo_cat();
		Library::display_array();
    }
    else if(temp[0]=='3'){
		//Library::display_array();
		l.delete_book();
		Library::redo_cat();
		//Library::display_array();
    }
    else if(temp[0]=='4'){
		see_checked_out();
    }
	else if(temp[0]=='5'){
		quit=true;
	}
    else
        cout<<"invalid"<<endl;
	}while(quit==false);
}


/******************************************************
** Function: 
** Description:
** Parameters:
** Pre-conditions:
** Post-conditions:
*****************************************************/


void Library::see_checked_out(){
	ifstream input;
	string checked;
	input.open("booksout.txt");
	cout<<"Books checked out:"<<endl;
	do{
		//cin.ignore();
		getline(input, checked);
		cout<<checked<<endl;
	}while(!input.eof());
}


//patron things

/******************************************************
** Function: 
** Description:
** Parameters:
** Pre-conditions:
** Post-conditions:
*****************************************************/


void Library::patron_funcs(){
    char temp[20];
	bool quit=false;
    do{
	do{

    cout<<"What would you like to do?\n[1] Search for book\n[2] Check out books\n[3] Check in Book\n[4] See what books are out\n[5] Exit\nChoice:";
    cin>>temp;
    }while(atoi(temp) <1 || atoi(temp) >5);
   
    if (temp[0]=='1'){
		//Library::display_array();
		Library::p_search();
    }
    else if(temp[0]=='2'){
		p.check_out(books, num_books);
		p.check_out_finish(books, num_books);
    }
    else if(temp[0]=='3'){
//		display_array();		
		p.check_in(books, num_books);
		p.check_out_finish(books, num_books);
//		cout<<"________"<<endl;
//		display_array();
	}
    else if(temp[0]=='4'){

		p.find_books_out();
    }
	else if(temp[0]=='5')
		quit=true;
    else
        cout<<"invalid"<<endl;

	}while(quit!=true);
}


/******************************************************
** Function: 
** Description:
** Parameters:
** Pre-conditions:
** Post-conditions:
*****************************************************/


void Library::p_search(){
	char choice[20];
	do{
	cout<<"What would you like to search by -\n[1] Title \n[2] Year\n[3] Author\nChoice:";
	cin>>choice;
	}while(atoi(choice) <1 || atoi(choice) >3);
	if(choice[0]=='1'){
		p.search_title(books, num_books);
	}
	else if(choice[0]=='2'){
		p.search_year(books, num_books);
	}
	else if(choice[0]=='3'){
		p.search_author(books, num_books);
	}

}


/******************************************************
** Function: 
** Description:
** Parameters:
** Pre-conditions:
** Post-conditions:
*****************************************************/


void Library::menu(){
	int choice;
	bool quit=false;
	//cout<<books[1].title<<endl;
	do{
	cout<<"Welcome to the Library. What would you like to do? \n[1] View hours \n[2] Login \n[3] Quit  "<<endl;
	do{
	cin>>choice;
	if((int)choice == 1 ){
		Library::hours_choose();
	}
	else if((int)choice== 2){
		Library::login();
	}
	else if((int)choice== 3 ){
		quit=true;
	}
	else if((int)choice<1 || (int)choice>3){
		cout<<"Your input is invalid"<<endl;
	}
	}while((int)choice<1 || (int)choice>3);
	}while(quit==false);
}


/******************************************************
** Function: 
** Description:
** Parameters:
** Pre-conditions:
** Post-conditions:
*****************************************************/


Library::Library(const Library &other){
	if(other.num_books==0){
		num_books=0;
		books=NULL;
	}
	else{
		num_books=other.num_books;
		books=new book[num_books];
		for(int i=0; i<num_books;i++){
			books[i]=other.books[i];
			books[i].authors=new string [other.books[i].num_authors];
			for(int j=0; j<other.books[i].num_authors; j++){
				books[i].authors[j]=other.books[i].authors[j];
			}

		}

	}
}
















//library things only

/******************************************************
** Function: 
** Description:
** Parameters:
** Pre-conditions:
** Post-conditions:
*****************************************************/


void Library::display_daily_hours(int d){
	cout<<"Hours for this day are "<< week[d].begin_time <<" to "<< week[d].end_time<<endl;
}

/******************************************************
** Function: 
** Description:
** Parameters:
** Pre-conditions:
** Post-conditions:
*****************************************************/


void Library::display_weekly_hours(){
	cout<<"Monday hours are from "<<week[0].begin_time<< " to "<<week[0].end_time<<endl;
	cout<<"Tuesday hours are from "<<week[1].begin_time<< " to "<<week[1].end_time<<endl;
	cout<<"Wednesday hours are from "<<week[2].begin_time<< " to "<<week[2].end_time<<endl;
	cout<<"Thursday hours are from "<<week[3].begin_time<< " to "<<week[3].end_time<<endl;
	cout<<"Friday hours are from "<<week[4].begin_time<< " to "<<week[4].end_time<<endl;
	cout<<"Saturday hours are from "<<week[5].begin_time<< " to "<<week[5].end_time<<endl;
	cout<<"Sunday hours are from "<<week[6].begin_time<< " to "<<week[6].end_time<<endl;

}

/******************************************************
** Function: 
** Description:
** Parameters:
** Pre-conditions:
** Post-conditions:
*****************************************************/


void Library::hours_choose(){
	int choice;
	cout<<"Would you like to view hours of a specific day, or all hours of the week?\n[1] Hours of specific day\n[2] All hours of the week\nChoice: "<<endl;
	cin>>choice;
	if(choice==1){
		cout<<"What day of the week would you like to view hours for?\n[0]Monday\n[1]Tuesday\n[2]Wednesday\n[3]Thursday\n[4]Friday\n[5]Saturday\n[6]Sunday\nChoice: ";
		cin>>choice;
		if(choice>=0 and choice<=6){
			Library::display_daily_hours(choice);
		}
		}
		else{
			Library::display_weekly_hours();
		}



}


/******************************************************
** Function: 
** Description:
** Parameters:
** Pre-conditions:
** Post-conditions:
*****************************************************/


void Library::fill_catalog(){
	ifstream input;
	input.open("catalog.txt");
	input>>num_books;
	books=new book[num_books];
	for (int i=0; i<num_books; i++){
		input>>books[i].title;
		input>>books[i].num_authors;
		books[i].authors=new string[books[i].num_authors];
		for(int j=0; j<books[i].num_authors; j++){
			input>>books[i].authors[j];
		}
		input>>books[i].year;
		input>>books[i].copies;
	}
}


/******************************************************
** Function: 
** Description:
** Parameters:
** Pre-conditions:
** Post-conditions:
*****************************************************/


void Library::redo_cat(){

	for(int i=0; i<num_books; i++){
		delete [] books[i].authors;
	}
	delete [] books;

	ifstream input;
	input.open("catalog.txt");
	input>>num_books;
	books=new book[num_books];
	for (int i=0; i<num_books; i++){
		input>>books[i].title;
		input>>books[i].num_authors;
		books[i].authors=new string[books[i].num_authors];
		for(int j=0; j<books[i].num_authors; j++){
			input>>books[i].authors[j];
		}
		input>>books[i].year;
		input>>books[i].copies;
	}


}


/******************************************************
** Function: 
** Description:
** Parameters:
** Pre-conditions:
** Post-conditions:
*****************************************************/


Library::~Library(){

	for(int i=0; i<num_books; i++){
		delete [] books[i].authors;
	}
	delete [] books;

}


