/********
Program name: Assign3
Author: Joshua Michael Strozzi
Date: January 28th 2017
Description: This program calculates the users grade in CS based on their inputs for scores and weights
Input: The user picks each respective section to find the grade, puts in number of scores, their score, then what the scores out of, and they repeat this til they get all the grades, then the last part calculates the grade in the class based on the weights provided by the user.
Output: The users grade in the class in percent.
*******/



#include <string>
#include <iostream>
#include <cstdlib>
#include <cmath>



using namespace std;
bool quit=false;
double recite();//prototype for my recitation function
double idiot();//prototype for function that tells the user they provided the wrong data typeand asks them to retry
double rloop(int n);//prototype for grading the other 3 sections
double grade(double labs, double ass, double rec, double test);//prototype for function that calculates entire class grade


//program begins here.
int main(){
		int start,n;
		float all;
		double labs=0, ass=0, rec=0, test=0;
	do{
		cout<< "lab= "<<labs<<endl;//these print out the grade in that secion for refer.
		cout<< "ass= "<<ass<<endl;
		cout<< "rec= "<<rec<<endl;
		cout<< "test="<<test<<endl;
		cout<<"Would you like to calculate an average for 1) labs 2) assignments, 3) recitations, 4)tests, 5) the class, or 0) to quit?"<<endl;
		cin>>start;
			if (start==1) {
				cout<<"How many labs?"<<endl;
				n=idiot();
				labs=rloop(n);
				cout<<"Your lab average is: "<<labs<<endl;
					
				
			}
			else if(start==2){
				cout<<"How many assignments?"<<endl;
				n=idiot();
				ass=rloop(n);
				cout<<"Your assignments average is: "<<ass<<endl;

			}
			else if (start==3){
				rec=recite();
			}
			else if (start==4){
				cout<<"How many tests?"<<endl;
				n=idiot();
				test=rloop(n);
				cout<<"Your test average is: "<<test<<endl;

			}
			else if (start==5){
          			float fin;
				fin=grade(labs, ass, rec, test);
				cout<<"Your grade in the calss is "<<fin<<"%"<<endl;
			}
			else if(start==0){
				cout<<"You've exited the program"<<endl;
       				 quit=true;
			}


	}
	while (quit==false);

	return 0;
}


/************************
Function: grade
Description: This function calculates the final grade for the class
Parameters: labs, ass(ignments), rec, test (the numbers connected to these)
Pre-conditions: All the grades for each section
Post-conditions: The grade for the class is provided
Return: fin (final grade)
************************/

double grade(double labs, double ass, double rec, double test){
	float fin;
	float wlabs, wass, wrec, wtest,wtotal;
	cout<<"Weight of labs out of 100: ";
	wlabs=idiot();
	cout<<"Weight of assignments out of 100: ";
	wass=idiot();
	cout<<"Weight of recitations out of 100: ";
	wrec=idiot();
	cout<<"Weight of tests out of 100: ";
	wtest=idiot();
	wlabs=wlabs/100;
	wass=wass/100;
	wrec=wrec/100;
	wtest=wtest/100;
	wtotal=wlabs+wass+wrec+wtest;
	labs=labs*wlabs;
	ass=ass*wass;
	rec=rec*wrec;
	test=test*wtest;
	fin=(labs+ass+rec+test)/wtotal;
	return fin;
}

/************************
Function: rloop
Description: It calculates the score for each class section and each part of recitation
Parameters: It requires n amount of scores that the user decides
Pre-conditions: n number of scores is asked by the user
Post-conditions: Scores that get averaged
Return: "Score" for each class section or part in recitation
************************/

double rloop(int n){
	double score=0;
	for(int i=0;i<n;i++){
	float numer, denom;
	cout<<"Score "<<i+1<<" : ";
	numer=idiot();
	cout<<"Out of: ";
	denom=idiot();
	score=score+(numer/denom);





	}
	if(n>0){
		score=(score/n)*100;
	}
	else{
		score=100;
	}
	return score;
	
}

/************************
Function: recite
Description: Calculates a grade for recitation
Parameters: None necessary going into it
Pre-conditions: none
Post-conditions: Recitation grade is created for use by class grade calculating portion
Return: reciteavg
************************/

double recite(){
	int n;
	double reciteavg;
	float quizw, desw, critw;
	float totalw;
	cout<<"Quiz weight: ";
	quizw=idiot();
	quizw=quizw/100;
	cout<<"\nDesign weight: ";
	desw=idiot();
	desw=desw/100;
	cout<<"\nCritique weight: ";
	critw=idiot();
	critw=critw/100; //will multiply grade in this respective category by a percent
	totalw=critw+desw+quizw;
	cout<<"How many quizes do you have?"<<endl;
	n=idiot();
	quizw=quizw*rloop(n);
	cout<<quizw<<endl;

	cout<<"How many designs so you have? "<<endl;
	n=idiot();
	desw=desw*rloop(n);
	cout<<desw<<endl;
	
	cout<<"How many critiques do you have? "<<endl;
	n=idiot();
	critw=critw*rloop(n);
	cout<<critw<<endl;
	
	reciteavg=(quizw+desw+critw)/totalw; //now that we have the percents, we add them together to get a grade in recitation

	return reciteavg;
}


/************************
Function: idiot
Description: This gives gives the user an error message and tells them to try again
Parameters: None going into it necessary
Pre-conditions: None
Post-conditions: The user has a number that can be used by other portions of the program
Return: correct
************************/

double idiot(){
	bool bad_input;
	string derp;

	do{
		bad_input=false;
		cin>> derp;
		for (int i=0; i<derp.size(); i++){
			if(!(derp.at(i) >= '0' and derp.at(i) <= '9')){
				bad_input=true;
				cout<< "Bad input please try again"<<endl;
				break;
			}
		}
	}while(bad_input);	

	double correct=atof(derp.c_str());
	return correct;
}





