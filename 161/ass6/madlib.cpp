/**************************************
Program Filename: madlib.cpp
Author: Joshua Michael Strozzi
Date: March 15, 2017
Description: This program reads in words from an outside textfile, puts them in arrays, then randomly chooses and displays them inside of a little story
Input: [executable] [story number] [<] [textfile]
Output: Madlibs story
***************************************/
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;


void trans_words(char **&, char**&, char**&, char**&, char**& ,char *, int&, int&, int&, int&, int&);
void madlibs(int, char *[], char **, char**, char**, char**, char**, int&, int&, int&, int&, int&);
void rando(char**&, int);
void del_funk(char**, int, char**, int, char**, int, char**, int, char**, int, char* );

int main(int argc, char *argv[]){//argc=is the number of arguments, argv is the values of the args, its an array of the args
	srand(time(NULL));
	int verbnumber=0, nounnumber=0, adjnumber=0, nounsnumber=0, verbingnumber=0;//the amount of words per each type, decided in transwords and used for mod	
	cout<<argc<<endl;

	char *unsorted=new char [30];
	char **sortednoun, **sortedverb, **sortedadj, **sortednouns, **sortedverbing;
	
	trans_words(sortednoun, sortedverb, sortedadj, sortednouns, sortedverbing, unsorted, verbnumber, nounnumber, adjnumber, nounsnumber, verbingnumber);
	
	//cout<<sortedverbing[0]<<endl;
	cout<<endl;
	if (argc==2)//even though it should be 4, it's two
		madlibs(argc, argv, sortednoun, sortedverb, sortedadj, sortednouns, sortedverbing, verbnumber, nounnumber, adjnumber, nounsnumber, verbingnumber);
	else
		cout<<"You don't have the right amount, please try again with \" [executable] [story number] < [filename] \" "<<endl;

	del_funk(sortednoun, nounnumber, sortedverb, verbnumber, sortedadj, adjnumber, sortednouns, nounsnumber, sortedverbing, verbingnumber, unsorted);

	return 0;
}
/**********************************************************************
Function: del_funk
Description: This fuction cleans up all the possible memory leaks
Parameters: All of the arrays and the number of words that I've added to each array
Pre-Conditions: the program has run and displayed the message,
Post-Conditions: there are no possible memory leacks
Return: nothing
*********************************************************************/

void del_funk(char **sortednoun, int nounnumber, char **sortedverb, int verbnumber, char **sortedadj, int adjnumber, char** sortednouns, int nounsnumber, char** sortedverbing, int verbingnumber, char* unsorted){
	for(int i=0; i<nounnumber; i++)
		delete [] sortednoun[i];
 	delete [] sortednoun;
	
	for(int i=0; i<verbnumber; i++)
		delete [] sortedverb[i];
 	delete [] sortedverb; 
	
	for(int i=0; i<adjnumber; i++)
		delete [] sortedadj[i];
 	delete [] sortedadj;
	
	for(int i=0; i<nounsnumber; i++)
		delete [] sortednouns[i];
 	delete [] sortednouns;
	
	for(int i=0; i<verbingnumber; i++)
		delete [] sortedverbing[i];
 	delete [] sortedverbing;//=new char*[50];//if you have any more than 25 words per type, you need to edit this number as it does not grow
	//sortedverb=new char*[50]; 
	//sortedadj=new char*[50]; 
	//sortednouns=new char*[50];
	//sortedverbing=new char*[50];
	delete[] unsorted;
}


/**********************************************************************
Function: trans_words
Description: This fuction transfers the words into their respective word type banks
Parameters:All of my arrays and the word number variable
Pre-Conditions: The user has executed the program with a wordfile in the 
Post-Conditions: The words have been put into their rightful arrays to be used later
Return: nothing
*********************************************************************/


void trans_words(char **&sortednoun, char **&sortedverb, char **&sortedadj, char **&sortednouns, char **&sortedverbing, char *unsorted, int &verbnumber, int &nounnumber, int &adjnumber, int &nounsnumber, int &verbingnumber){
	//int verbnumber=0, nounnumber=0, adjnu&mber=0, nounsnumber=0, verbingnumber=0;
	sortednoun=new char*[50];//if you have any more than 25 words per type, you need to edit this number as it does not grow
	sortedverb=new char*[50]; //
	sortedadj=new char*[50]; //
	sortednouns=new char*[50];
	sortedverbing=new char*[50];
	//issues starting here
	for(int i=0; i< 125; i++){ //125 words change for whatever length the list is
		cin>>unsorted;//tells me the type as the first word is always the type, the second is the actual word
		//cout << "worked: "  << i << endl;
	
		//cout<<unsorted<<endl;
		if(unsorted[0]=='n' and unsorted[1]=='o' and unsorted[2]=='u' and unsorted[3]=='n'){ //using the type, I decide where to send it
			cin>>unsorted; //now I take in the actual word
			if(unsorted[strlen(unsorted)-1]=='s'){
				sortednouns[nounsnumber]=new char [strlen(unsorted)];// i had [strlen(unsorted)+1]
				strcpy(sortednouns[nounsnumber++], unsorted); //now it stores the word into it's rightful array and at the same time iterates my variable that keeps track of the number of words in an array, by one for use later
			}
			else{
			sortednoun[nounnumber] = new char [strlen(unsorted)]; //now I'm allocating enough space for it in my sorted array using strlen

			strcpy(sortednoun[nounnumber++], unsorted);//now I copy the word into my sorted array and increment a variable that tells me how many I have
			}	

		}
		else if(unsorted[0]=='v' and unsorted [1]=='e' and unsorted[2]=='r' and unsorted[3]=='b'){
			cin>>unsorted;
			//cout<<"The last letter is "<<unsorted[strlen(unsorted)-1]<<endl;

			if (unsorted[strlen(unsorted)-1]=='g' and unsorted[strlen(unsorted)-2]=='n' and unsorted[strlen(unsorted)-3]=='i'){
					sortedverbing[verbingnumber] = new char [strlen(unsorted)];
					strcpy(sortedverbing[verbingnumber++], unsorted);

			}
			else{ 
				sortedverb[verbnumber]= new char [strlen(unsorted)];

				strcpy(sortedverb[verbnumber++], unsorted);
			}
			// cout<<"finished"<<endl;
		}
		else if(unsorted[0]=='a' and unsorted [1]=='d' and unsorted[2]=='j' and unsorted[3]=='e'){
			cin>>unsorted;
			sortedadj[adjnumber]= new char [strlen(unsorted)];

			strcpy(sortedadj[adjnumber++], unsorted);


		}
	


	
	}		
	//cout<<sortedadj[0]<<endl;
	//cout<<sortedadj[3]<<endl;
	//cout<<sortedadj[4]<<endl;
	//cout<<sortedadj[5]<<endl;
	//cout<<sortedverb[13]<<endl;
	//cout<<sortedverbing[verbingnumber-1]<<endl;
	//cout<<sortedverb[0]<<endl;
}


/**********************************************************************
Function: madlibs
Description: This fuction displays the story with the variable words
Parameters: all the of the word type bank arrays and the numbertypes
Pre-Conditions: the words are in their arrays already and you know the number of words in each array and the user has specified the story number to by shown
Post-Conditions: the madlibbed story has been chosen and displayed
Return: nothing
*********************************************************************/


void madlibs(int argc, char *argv[], char **sortednoun, char ** sortedverb, char** sortedadj, char** sortednouns, char** sortedverbing, int &verbnumber, int &nounnumber, int &adjnumber, int &nounsnumber, int &verbingnumber){
	//cout<<sortedverbing[0]<<endl;
	if ((int)*argv[1]-48==1 and strlen(argv[1])==1){ //because askiivalues bruh
		cout<<"Most doctors agree that bicycle ";
		rando(sortedverbing, verbingnumber);//this function will pick a random element in the array that I need and display it 
		cout<<" is a/an "; 
		rando(sortedadj, adjnumber);
		cout<<" form of exercise. ";
		rando(sortedverbing, verbingnumber);
		cout<<" a bicycle enables you to develop your ";
		rando(sortednoun, nounnumber);
		cout<<" muscles, as well as increase the rate of your "; 
		rando(sortednoun, nounnumber);
		cout<<" beat. More ";
		rando(sortednouns, nounsnumber);
		cout<<" around the world ";
		rando(sortedverb, verbnumber);
		cout<<" bicycles than drive ";
		rando(sortednouns, nounsnumber);
		cout<<". No matter what kind of ";
		rando(sortednoun, nounnumber);
		cout<<" you ";
		rando(sortedverb, verbnumber);
		cout<<", always be sure to wear a/an ";
		rando(sortedadj, adjnumber);
		cout<<" helmet. Make sure to have ";
		rando(sortedadj, adjnumber);
		cout<<" reflectors too!"<<endl;

	}
	else if((int) *argv[1]-48==2 and strlen(argv[1])==1){
		cout<<"Yesterday, ";
		rando(sortednoun, nounnumber);
		cout<<" and I went to the park. On our way to the ";
		rando(sortedadj, adjnumber);
		cout<<" park, we saw a ";
		rando(sortedadj, adjnumber);
		cout<< " ";
		rando(sortednoun, nounnumber);
		cout<< " on a bike. We also saw big ";
		rando(sortedadj, adjnumber);
		cout<<" balloons tied to a ";
		rando(sortednoun, nounnumber);
		cout<<". Once we got to the ";
		rando(sortedadj, adjnumber);
		cout<<" park, the sky turned ";
		rando(sortedadj, adjnumber);
		cout<< ". It started to ";
		rando(sortedverb, verbnumber);
		cout<<" and ";
		rando(sortedverb, verbnumber);
		cout<<". "; 
		rando(sortednoun, nounnumber);
		cout<< " and I "; 
		rando(sortedverb, verbnumber);
		cout<<" all the way home. Tomorrow we will try to go to the ";
		rando(sortedadj, adjnumber);
		cout<<" park again and hope it doesn't ";
		rando(sortedverb, verbnumber);
		cout<<"."<<endl;


	}
	else if((int) *argv[1]-48==3 and strlen(argv[1])==1){ 
		cout<<"Spring break 2017, oh how I have been waiting for you! Spring break is when you go to some ";
		rando(sortedadj, adjnumber);
		cout<<" place to spend time with ";
		rando(sortednoun,nounnumber);
		cout<<". Getting to ";
		rando(sortednoun, nounnumber);
		cout<< " is going to take ";
		rando(sortedadj, adjnumber);
		cout<<" hours. My favorite part of spring break is ";
		rando(sortedverbing, verbingnumber);
		cout<<" in the "; 
		rando(sortednoun, nounnumber);
		cout<<". During spring break, ";
		rando(sortednoun, nounnumber);
		cout<<" and I plan to ";
		rando(sortedverb, verbnumber);
		cout<<" all the way to ";
		rando(sortednoun, nounnumber);
		cout<< ". After spring break, I will be ready to return to ";
		rando(sortednoun, nounnumber);
		cout<<" and ";
		rando(sortedverb, verbnumber);
		cout<<" hard to finish ";
		rando(sortednoun, nounnumber);
		cout<<". Thanks spring break 2017!"<<endl;
	

	}
	else
		cout<<"You have input a number incompatible with my program, please try again with a numbers 1, 2, or 3."<<endl;

}

/**********************************************************************
Function: rando
Description: This fuction picks a random word from the specified word type bank and displays it
Parameters: the word bank array for the specific type needed
Pre-Conditions: the number of words in each array is known
Post-Conditions: a random words has been chosen from an array
Return: nothing
*********************************************************************/


void rando(char **&sorted, int num){
	int r=rand()%num; //don't have to do plus one because the number is already 1 greater than the number because it iterates at the end of each loop where it's used

	cout<< sorted[r]; //showing the random word of the array
	//cout<<r;

}
