#include "patron.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include "library.h"

using namespace std;


/******************************************************
** Function: Constructor
** Description: Default constructs my patron class
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
*****************************************************/


patron::patron(){
    name="Doesn't exist";
    id=0;
    books_checked_out=0;
}


/******************************************************
** Function: get_books_out
** Description: returns number of books out
** Parameters: none
** Pre-conditions: patrons number of books has been set
** Post-conditions: none
*****************************************************/

int patron::get_books_out(){
    return books_checked_out;
}


/******************************************************
** Function: find_books_out
** Description: displays books that current user has out
** Parameters: none
** Pre-conditions: user is known, file with books out exists
** Post-conditions: none
*****************************************************/


void patron::find_books_out(){
    ifstream input;
    string search;
    input.open("booksout.txt");
    cout<<"Books that user "<<name<<" has out: "<<endl;
    do{
        input>>search;
        if(search.find(name)!= string::npos){
            input>>search;
            cout<<search<<endl;
        }
        else{
            input>>search;
        }

    }while(!input.eof());
    input.close();
}


/******************************************************
** Function: convert_underscore
** Description: converts strings with spaces to strings with underscores underscores
** Parameters: none
** Pre-conditions: none
** Post-conditions: none
*****************************************************/

string patron::convert_underscore(){
    string word;
    cin.ignore();
    getline(cin, word);
    for(int i=0; i<word.length() ; i++){
        if(word.at(i)==' '){
            word.at(i)='_';
        }
    }
return word;
}


/******************************************************
** Function: choose_user
** Description: picks user from user file
** Parameters: none
** Pre-conditions: There is no name for patron
** Post-conditions: patron name exists
*****************************************************/


bool patron::choose_user(){

    string search, user;
    bool exists=false;
    ifstream input;
    input.open("users.txt");

    cout<<"Enter user name here: ";
    //cin>>user;
    user=convert_underscore();
    do{
        input>>search;
        //cout<<search<<endl;
        if(search[0]=='p'){
            input>>search;
            //cout<<search<<endl;
                if(search.find(user)!= string::npos){

                    name=user;
                    exists=true;

                }
                else    
                    exists=false;
        }
    }while(!input.eof());
    if (exists==true){
        cout<<"Welcome "<<name<<endl;
    }
    else
        cout<<"That user name does not exist as a valid patron name"<<endl;
        input.close();
        return exists;

}


/******************************************************
** Function: search_title
** Description: searches array for title
** Parameters: book array, number of books
** Pre-conditions: none
** Post-conditions: none
*****************************************************/


void patron::search_title(const book *b, int n){
    string search, title;
    cout<<"What's the name of your book?: ";
    search=convert_underscore();
    for(int i=0; i<n; i++){
        title=b[i].title;
        if(title.find(search)!= string::npos){
            cout<<"["<<i<<"]"<<title<<endl;
        }
    }

}


/******************************************************
** Function: search_author
** Description: searches array for book by author
** Parameters: book array, number of books
** Pre-conditions: none
** Post-conditions: none
*****************************************************/


void patron::search_author(const book *b, int n){
    string search, author;
    cout<<"What's the name of one your book's authors?: ";
    //cout<<b[1].title<<endl;
    search=convert_underscore();
    cout<<"Books fitting your search Parameters: "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<b[i].num_authors; j++){
            author=b[i].authors[j];
                if(author.find(search)!= string::npos){
                    cout<<"["<<i<<"]"<<b[i].title<<endl;
            }
        }
    }
    cout<<endl;
}


/******************************************************
** Function: search_year
** Description: searchs book array by year 
** Parameters: book array, number of books
** Pre-conditions: none
** Post-conditions: none
*****************************************************/


void patron::search_year(const book *b, int n){
    int search, year;
    cout<<"What's the year of your books publication?: ";
    cin>>search;
    for(int i=0; i<n; i++){
        year=b[i].year;
        if(year==search){
            cout<<"["<<i<<"]"<<b[i].title<<endl;
        }
    }

}


/******************************************************
** Function: check_out
** Description: patron can check out a book
** Parameters: book array, number of books
** Pre-conditions: array has x number of copies for searched book and booksout.txt exists
** Post-conditions: array has x-1 number of copies for book searched and booksout.txt has one more entry
*****************************************************/


void patron::check_out(book *b, int n){
    bool done=false;
    char choice[5];
    string search, title;
    ofstream output;
    output.open("booksout.txt", ofstream::app);
    cout<<"What's the name of your book?: ";
    cin>>search;
    for(int i=0; i<n; i++){
        title=b[i].title;
        if(title.find(search)!= string::npos){
            cout<<"["<<i<<"]"<<title<<endl;
        }
    }

    do{
        cout<<"Input the number corresponding to the book you'd like to add to your cart: ";			cin>>choice;
	}while(atoi(choice)<0 && atoi(choice)>n);
    if(b[atoi(choice)].copies>0){
        b[atoi(choice)].copies-=1;
        //cout<<"copies for book: "<<b[atoi(choice)].copies<<endl;
        output<<name<<" "<<b[atoi(choice)].title<<" ";
    }
    else{
        cout<<"That book number doesn't correspond with any in our directory."<<endl;
    }

}


/******************************************************
** Function: check_out_finish
** Description: redoes catalog array with new alter info from book array
** Parameters: book array, number of books
** Pre-conditions: catalog file is not up t0 date
** Post-conditions: catalog is updated
*****************************************************/


void patron::check_out_finish(const book *b, int n){
    ofstream output;
    output.open("catalog.txt");
    output<<n<<endl;
    for(int i=0; i<n; i++){
       output<<b[i].title<<endl;
       output<<b[i].num_authors<<endl;
       for(int j=0; j<b[i].num_authors; j++)
            output<<b[i].authors[j]<<endl;
        output<<b[i].year<<endl;
        output<<b[i].copies<<endl;
    }
}


/******************************************************
** Function: check_in
** Description: returns 1 copy to array for a book and recreates booksout without that book
** Parameters: book array, number of books
** Pre-conditions: copies for a book n has one less copy than it could have
** Post-conditions: 1 digit is return to the copies of the book and the booksout file is updated
*****************************************************/


void patron::check_in(book *b, int n){
    ifstream input;
    ofstream output;
    input.open("booksout.txt");
    output.open("newbooksout.txt");
    string searching, previous;
    do{
        input>>searching;
            if(searching.find(name) != string::npos){
                input>>searching;
                for(int i=0; i<n; i++){
                    if(searching.find(b[i].title) != string::npos){
                        b[i].copies+=1;
                    }

                }
            }
        else{
            if(previous!=searching)
                output<<searching<<endl;

        }
        previous=searching;
    }while(!input.eof());

    remove("booksout.txt");
    rename("newbooksout.txt", "booksout.txt");
}









