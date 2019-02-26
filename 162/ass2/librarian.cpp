#include "librarian.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;


/******************************************************
** Function: default constructor
** Description: sets defaults for class variables
** Parameters: none
** Pre-conditions: none
** Post-conditions: class has set defaults
*****************************************************/


librarian::librarian(){
    id=0;
    name="noname";
}


/******************************************************
** Function: choose_user
** Description: chooses an available user for librarian
** Parameters: none
** Pre-conditions: not logged in
** Post-conditions: is logged in as librarian
*****************************************************/


bool librarian::choose_user(){
    char user[25], temp[25];
    bool exists=false;
    ifstream input;
    input.open("users.txt");
    cout<<"Enter user name here: ";
    cin>>user;
    do{
        input>>temp;

        if(temp[0]=='l'){
            input>>temp;
                if(!strcmp(temp, user)){
                    
                    name=user;
                    exists=true;
                }
        }
    }while(!input.eof());
    if (exists==true){
        cout<<"Welcome "<<name<<endl;
        //librarian::menu();
    }
    else
        cout<<"That user name does not exist as a valid patron name"<<endl;
        return exists;
}


/******************************************************
** Function: delete_book
** Description: deletes book from catalog file
** Parameters: none
** Pre-conditions: there is one more book than there will be in the file
** Post-conditions: file has one less book 
*****************************************************/


void librarian::delete_book(){
    cout<<"What book would you like to delete (title):";
    string garbage, title, last;
    int num_books;
    cin>>title;
    ifstream input;
    ofstream output;
    input.open("catalog.txt");
    output.open("new.txt");
    //bool line;
    input>>num_books;
    output<<num_books-1<<endl;
    do{
        input>>garbage;
        if(garbage.find(title) != string::npos){
            for(int i=0; i<4; i++){
            input>>garbage;
            }
        }
        else{
            if(garbage!=last){
                output<<garbage<<endl;
            }
            else
                cout<<endl;
        }
        last=garbage;
    }while (!input.eof());

    input.close();
    output.close();
    remove("catalog.txt");
    rename("new.txt","catalog.txt");
}


/******************************************************
** Function: add_book
** Description: adds a book to the end of the catalog
** Parameters: none
** Pre-conditions: the file has one less book than it will
** Post-conditions: the file has one more book
*****************************************************/


void librarian::add_book(){
	string title, author;
    int num_a, copies, year;
    ofstream output;
    output.open("catalog.txt", ofstream::app);
	cout<<"What is the name of the book you'd like to add?:";
	cin.ignore();
    getline(cin, title);
    for(int i=0; i<title.length() ; i++){
        if(title.at(i)==' '){
            title.at(i)='_';
        }
    }
    output<<title<<endl;
    cout<<"Number of Authors:";
    cin>>num_a;
    output<<num_a<<" ";
    for (int i=0; i<num_a; i++){
        cout<<"\nAuthor "<< i<<":";
        cin.ignore();
        getline(cin, author);
        for(int i=0; i<author.length() ; i++){
             if(author.at(i)==' '){
                  author.at(i)='_';
            }
        }
        output<<author<<" ";
    }
    cout<<"\nYear of Publication:";
    cin>>year;
    output<<year<<endl;
    cout<<"\nNumber of copies:";
    cin>>copies;
    output<<copies<<endl;
    output.close();
    //add_book_finish();

}


/******************************************************
** Function: add_book_finish
** Description: transfers info from the catalog to a new text file so it can up date the num_books at the beginning and renames the new file, deleting the old
** Parameters: none
** Pre-conditions: the num_books number at the top is incorrect
** Post-conditions: it is now correct
*****************************************************/


void librarian::add_book_finish(){
    int num_books;
    string transfer, previous;
    ifstream input;
    ofstream output;
    input.open("catalog.txt");
    output.open("temp.txt");
    input>>num_books;
    //num_books+=2;
    cout<<"Number of Books:"<<num_books<<endl;
    output<<num_books+1<<endl;
    do{
        input>>transfer;
            if(previous!=transfer)
                output<<transfer<<endl;
            else
                cout<<endl;
        previous=transfer;
    }while(!input.eof());
    input.close();
    output.close();
    remove("catalog.txt");
    rename("temp.txt","catalog.txt");

}


