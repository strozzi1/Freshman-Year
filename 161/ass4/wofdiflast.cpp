#include <iostream>   //input/output
#include <string>    //to use strings
#include <stdlib.h>  //NULL
#include <stdio.h>   //srand, rand
#include <time.h>   //time
#include <cstring>

using namespace std;


void get_string(string *phrase);
void mask_string(string, string *);
bool get_guess(string, string &, int, int &);
bool spin_wheel(string, string &, int &);
bool choose_move(string, string &, int &);
bool player(string, string &, int &);
int game(int, int &,int &, int &);
bool buy_vowel(string, string &, int &);
bool solve(string, string &);
char consonant (string);
char vowel (string);
bool get_guessv(string, string &,int &);
int winner(int, int, int);
void ignore_sol (string, string &);

int main(){
	int rounds, players;
	int mon1=0, mon2=0, mon3=0;
	//string phrase, masked;
	cout<<"How many rounds? ";
	cin>>rounds;
	cout<<"How many Players? ";
	cin>>players;
	cin.ignore();
	for(int i=0; i<rounds;i++){
	cout<<"Round "<<i+1<<endl;
	game(players, mon1, mon2, mon3);
	}
	winner(mon1, mon2, mon3);
	return 0;
}




/***************************************
** Function: get_string
** Description: the user puts in a phrase to be converted into a hidden version
** Parameters: the pointer for phrase
** Pre-Conditions: there is no phrase
** Post-Conditions: we have a phrase
** Return: none
******************************************/

void get_string(string *phrase){
	cout<<"Enter the phrase you'd like to hide: "<<endl;
	getline(cin, *phrase);
}



/****************************************
** Function: mask_string
** Description: the phrase input in the beginning is converted into a hidden version
** Parameters: the string, and the pointer for masked
** Pre-Conditions: there is a phrase input by the user
** Post-Conditions: we have a hidden version
** Return: none
*****************************************/
void mask_string(string phrase, string *masked){
	for (int i=0;i<phrase.length();i++){
		if(phrase[i]!=' ')
			phrase[i]='_';
	}
	*masked=phrase;
}




/***************************************
** Function: get_guess
** Description: the user guesses a letter in the hidden version of the phrase
** Parameters: the phrase and its hidden counterpart, the random letter from spin, and the respective users money 
** Pre-Conditions: The user has a random number...unless they spun a 21 or a zero
** Post-Conditions: money has been added to their money pot, the masked phrase has been altered
** Return:
***************************************/
//phrase(n), masked (yes), random (no), money(yes)
bool get_guess(string phrase, string &masked, int random, int &money){
	bool fail;
	char guess;
	//string guess;
	int amount=0;
	cout<<masked<<endl;
	//cin>>guess;
	guess=consonant(masked);
	for(int i=0; i<phrase.length();i++){
		if(guess==phrase.at(i) or guess+32 == phrase.at(i) or guess-32 ==phrase.at(i)){
			masked.at(i)=phrase.at(i);
			amount+=1;
		}
	}
	cout<<amount<<" letters revealed!"<<endl;
	if(amount>0){
		money+=(amount*random);
		cout<<masked<<endl;
		cout<<"Your earnings are: "<<money<<" dollars."<<endl;
		fail=false;
	}
	else	
		fail=true;
	//else
		//next players turn
		return fail;
}



/***************************************
** Function: spin_wheel
** Description: The user gets a random number and based on how many letters they reveal, they receive into their money pot the spin number multiplied by the number of letters revealed
** Parameters: the phrase and its hidden counterpart, and the respective users money
** Pre-Conditions: The user choses to spin, the game is still going, phrase hasen't been solved
** Post-Conditions: Money has been added into the users money pot
** Return:
****************************************/
//phrase (no aug), masked (aug), money (aug)
bool spin_wheel(string phrase, string &masked, int &money){
	int random;
	bool fail=false;
	srand(time(NULL));
	random=rand()%22;
	if (random >0 and random<21){
		//guess letter
		cout<<"You spun the number: "<<random<<endl;;
		fail=get_guess(phrase, masked, random, money);//this is how it's done
		
	}	
	else if(random==21){
		cout<<"You lose you turn"<<endl;		//earnings =0	
		fail=true;
	}	
	else if (random==0){
		cout<<"You've gone bankrupt"<<endl;
		money=0;
		fail=true;
	}
	return fail;
}





/*************************************
** Function: choose_move
** Description: A menu where the user chooses which action they will do at this point
** Parameters: the phrase, its hidden counterpart, and the respective users money
** Pre-Conditions: the game must still be going
** Post-Conditions: The users money may have changed, masked may have been altered
** Return: 
***************************************/
//string phrase (no aug), string masked(aug), int money(yes aug), int random (no aug)
bool choose_move(string phrase, string &masked, int &money){
	int choice;
	bool fail=false;
	cout<<"Would you like to 1) Spin the wheel   2) Buy a Vowel   or  3) Guess the phrase?: ";
	cin>>choice;
	if(choice==2){
		cout<<"What vowel would you like to buy? \n Bank Total: "<< money<<endl;
		if (money<10){
			cout<<"You don't have enough money"<<endl;
			fail=true;
		}
		else
		fail = buy_vowel(phrase, masked, money);
		//get_guessv(phrase, masked, money);	
	}
	else if ( choice==3){

		cin.ignore();
		fail=solve(phrase, masked);
	}
	else if(choice==1){ //I made spinning the wheel the default
		fail=spin_wheel(phrase, masked, money);
	}
	return fail;
	//return 0;
}



/*************************************
** Function: game
** Description: Cycles through each player
** Parameters: the number of players, and all their money
** Pre-Conditions: The rounds loop must be unfulfilled as of yet
** Post-Conditions: money amounts have been changed 
** Return: nothing
***************************************/
int game(int players, int &mon1, int &mon2, int &mon3 ){
	bool fail=false;
	string phrase, masked;
		
		get_string(&phrase);
		mask_string(phrase, &masked);
		cout<<masked<<endl;
		
		int curr_play =1;
		while(masked!=phrase){
		
		switch(curr_play){
		
		case 1:
			cout<<"Player 1"<<endl;
			cout<<"Total: "<<mon1<<endl;
			player(phrase, masked, mon1);
			break;
		case 2:
			cout<<"Player 2"<<endl;
			cout<<"Total: "<<mon2<<endl;
			player(phrase, masked, mon2);
			break;
		case 3:
			cout<<"Player 3"<<endl;
			cout<<"Total: "<<mon3<<endl;
			player(phrase, masked, mon3);
			break;
		}
			curr_play+=1;

			if(curr_play>players)
				curr_play=1;

		}







	return 0;
	}



/*************************************
** Function: Player
** Description: function where the player's money is passed in and changed based on the choice they make in the function within it
** Parameters: the phrase, its hidden counterpart, and a players respective money pot
** Pre-Conditions: The phrase has not been solved,
** Post-Conditions: The phrase may be closer to being solved and money may have grown or been made equal to 0
** Return: whether or not they failed at any point
***************************************/
bool player (string phrase, string &masked, int &mon){
	bool fail=false;
	do{
	fail=choose_move(phrase, masked, mon);
	}while(fail==false);

	return fail;




}

/*************************************
** Function: Buy Vowel
** Description: The user can buy a vowel if they so choose
** Parameters: The phrase, it's hidden counterpart, and the users money
** Pre-Conditions: The user must have at least 10 dollars
** Post-Conditions: The user has 10 less dollars and a vowel may be revealed wherever it is hidden
** Return: no return value
***************************************/

bool buy_vowel(string phrase, string &masked, int &money){
	bool fail=false;
	if(money<10){
		cout<<"You don't have enough money "<<endl;
		fail=true;
	}
	else {
		money-=10;
		fail=get_guessv(phrase, masked, money);	
		

	}
	return fail;
}



/*************************************
** Function: Solve
** Description: This function is for the user to attempt guessing the full hidden phrase
** Parameters: The phrase that we need to guess, and the hidden version of the phrase
** Pre-Conditions: Not all the letters have been revealed
** Post-Conditions: If correct, the round ends
** Return: Whether or not the user failed
***************************************/

//phrase (don't aug), masked (aug), 
bool solve(string phrase, string &masked){
	bool fail=false;
	string solution;
	cout<<"The message is "<<masked<<"\nWhat is the message?: "<<endl;
	getline(cin, solution);
	
	if (solution==phrase){
		cout<<"You are correct!"<<endl;
		masked=phrase;
		fail=true;
		
	}
	else{
		cout<<"You are incorrect"<<endl;
		fail=true;
	}
	return fail;
}



char consonant(string masked){
	string first;
	cin>>first;
	//getline(cin,first);
	first=first.at(0);
	if (first.at(0)== 'a' or first.at(0) == 'e' or first.at(0) == 'i' or first.at(0) == 'o' or first.at(0) == 'u' or first.at(0)== 'A' or first.at(0)=='E' or first.at(0)=='I' or first.at(0)=='O' or first.at(0)=='U'){
		cout<< "You input the wrong type of letter. You lose your turn."<<endl;
		first="0";
	}
	for(int i=0; i<masked.length();i++){//check if letter is already in the "revealed" string
		if (first.at(0)==masked.at(i) or first.at(0)==masked.at(i) + 32 or first.at(0)==masked.at(i)-32){
			first="0";
			cout<<"That letter has already been guessed, you lose your turn"<<endl;
		}
	}

	return first.at(0);
}


char vowel(string masked){
	string first;
	//cin.ignore();
	//cin>>first;
	cin.ignore();
	getline(cin, first);
	first=first.at(0);
	if (first.at(0)!='a' and first.at(0) != 'e' and  first.at(0) != 'i' and first.at(0) != 'o' and first.at(0) != 'u'){
		cout<< "You input the wrong type of letter. You lose your turn."<<endl;
		first="0";
	}
	for(int i=0; i<masked.length();i++){
		if (first.at(0)==masked.at(i) or first.at(0) == masked.at(i) +32 or first.at(0)== masked.at(i)-32){
			first="0";
			cout<<"That letter has already been guessed, you lose your turn"<<endl;
		}
	}

	return first.at(0);
}




bool get_guessv(string phrase, string &masked, int &money){
	bool fail;
	char guess;
	int amount=0;
	cout<<masked<<endl;
	guess=vowel(masked);
	for(int i=0; i<phrase.length();i++){
		if(guess==phrase.at(i) or guess+32 ==phrase.at(i) or guess-32 ==phrase.at(i)){
			masked.at(i)=phrase.at(i);
			amount+=1;		
		}
	}
	cout<<amount<<" letters revealed!"<<endl;
	if(amount>0){
		cout<<masked<<endl;
		fail=false;
	}
	else	
		fail=true;
		//next players turn
		return fail;
}

int winner(int mon1, int mon2, int mon3){

	cout<<"Player 1: $"<<mon1<<endl;
	cout<<"Player 2: $"<<mon2<<endl;
	cout<<"Player 3: $"<<mon3<<endl;
	if (mon1 > mon2 and mon1 > mon3)
		cout<<"Player 1 wins"<<endl;
	else if (mon2 > mon1 and mon2 > mon3)
		cout<<"Player 2 wins"<<endl;
	else if (mon3 > mon1 and mon3 > mon2)
		cout<<"Player 3 wins"<<endl;
	else
		cout<<"It's a tie!"<<endl;
	

	return 0;
}

/*
void ignore_sol(string phrase, string &masked){
	for(int i=0;i<phrase.length(); i++){
		
*/

}
