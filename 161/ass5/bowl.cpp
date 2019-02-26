/******************************************
Program Filename: bowl.cpp
Author: Joshua Michael Strozzi
Date: February 27, 2017
Description: The program emulates a game of bowling and stores and displays the score totals per frame below the bowl attempt scores 
Input: Number of players (1-5), Names of players, and pressing enter to bowl
Output: scoreboard of bowling game
******************************************/
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


using namespace std;
void name(int, char*, char*, char*, char*, char*);
void makename (char*);
void game( int, int, int*, int *, int *, int *, int *, int *, int *, int *, int*, int*,char *,char*, char*,char*,char*);
void player (int*,int*,char*,int);
void bowl_attempt(int*,int*,char*, int);
void spare_attempt(int*, int*, char*, int, int);
void display( int, int, int*, int *, int *, int *, int *, int *, int *, int *, int*, int*,char *,char*, char*,char*,char*);
int dismath(int, int*, int*);
int totmath(int, int*, int*);
int frame10(int, int*, int*);
int displaystuff(char*, int*, int*, int);
void playertots(int *);
void frame10bowl(int, int *, int*);
void spare_attempt10(int *, int, int*);
void frame10bowl2(int *, int*);
void spareattempt2frame10(int *, int, int*);
void lastbowl(int *, int*);
void distot10(int *, int);


/*****************************
Function: Main
Description: This is where all the arrays are declared and set to null, and the main round loop is set
Parameters: None
Pre-Conditions: none
Post-Conditions: The name has been finished
Return: nothing
*****************************/
int main(){
	int players;
	int play1_bowls[21],play2_bowls[21], play3_bowls[21], play4_bowls[21], play5_bowls[21];
	int play1_tot[21], play2_tot[21], play3_tot[21], play4_tot[21], play5_tot[21];
	char play1_name[12], play2_name[12], play3_name[12], play4_name[12], play5_name[12];
	
	memset(play1_bowls, '\0', 84);//setting all my array elements to null
	memset(play2_bowls, '\0', 84);
	memset(play3_bowls, '\0', 84);
	memset(play4_bowls, '\0', 84);
	memset(play5_bowls, '\0', 84);
	memset(play1_tot, '\0', 84);
	memset(play2_tot, '\0', 84);
	memset(play3_tot, '\0', 84);
	memset(play4_tot, '\0', 84);
	memset(play5_tot, '\0', 84);
	memset(play1_name, '\0', 12);
	memset(play2_name, '\0', 12);
	memset(play3_name, '\0', 12);
	memset(play4_name, '\0', 12);
	memset(play5_name, '\0', 12);
	
	cout<<"How many players: ";
	cin>>players;//get the player number
	cin.ignore();// the user will press enter to bowl
	name( players, play1_name, play2_name, play3_name, play4_name, play5_name);
	//make scoreboard here
	srand (time(NULL));
	for (int r=0;r<10; r++){
		
		game(players, r, play1_bowls, play2_bowls, play3_bowls, play4_bowls, play5_bowls, play1_tot, play2_tot, play3_tot, play4_tot, play5_tot, play1_name, play2_name, play3_name, play4_name, play5_name);
	}	

	return 0;
}
/*****************************
Function: name
Description: makename function is called for only the amount of players that have been input by the user
Parameters: all of the players name arrays, and the number of players
Pre-Conditions: Players name arrays have been declared aswell as number of players
Post-Conditions: The player names have been set
Return: nothing
*****************************/

void name(int players, char play1_name[], char play2_name[], char play3_name[], char play4_name[], char play5_name[]){
	for(int i=1; i<=players; i++){
		switch(i){// will switch between player depending on how many and who was before
			case 1:
				cout<<"Player 1: ";
				makename(play1_name);
				//cout<<endl;
				break;
			case 2:
				cout<<"Player 2: ";
				makename(play2_name);
				cout<<endl;
				break;
			case 3:
				cout<<"Player 3: ";
				makename(play3_name);
				cout<<endl;
				break;
			case 4:
				cout<<"Player 4: ";
				makename(play4_name);
				cout<<endl;
				break;
			case 5:
				cout<<"Player 5: ";
				makename(play5_name);
				cout<<endl;
				break;
		}

	}

}


/*****************************
Function: makename 
Description: The user inputs the players name and it's converted to cstyle string
Parameters: The players name array
Pre-Conditions: Players name arrays have been declared
Post-Conditions: The name array has been setup with a players name
Return: nothing
*****************************/
void makename(char play_name[]){
	char s;
	
		int i=0;
		while(i<12 and s!='\n'){
			cin.get(s);
			play_name[i]=s;
			i++;
		}
		play_name[11]='\0';
}

/*****************************
Function: game
Description: Depending on how many and which player is up, the players turn function is called
Parameters: all of the players bowl values and totals, and names
Pre-Conditions: The number of players is known, names are known, and the round number is passed into this
Post-Conditions: rounds are played by the players
Return: nothing
*****************************/



void game (int players, int round, int play1_bowls[], int play2_bowls[], int play3_bowls[], int play4_bowls[], int play5_bowls[], int play1_tot[], int play2_tot[], int play3_tot[], int play4_tot[], int play5_tot[], char play1_name[], char play2_name[], char play3_name[], char play4_name[], char play5_name[]){
	
	//int curr_play=1;
	for(int i=1; i<=players; i++){
	//display scoreboard
	switch(i){
		case 1:
			if(round<9){
			player(play1_bowls, play1_tot, play1_name, round);//point to the correct array using 2r+1 and 2r
			}
			else if(round==9){
			frame10bowl(round, play1_bowls, play1_tot);//for the tenth frame only
			}
			break;
		case 2:
			
			if(round<9){
			player(play2_bowls, play2_tot, play2_name, round);//point to the correct array using 2r+1 and 2r
			}
			else if(round==9){
			frame10bowl(round, play2_bowls, play2_tot);
			}
			break;
		case 3:
			if(round<9){
			player(play3_bowls, play3_tot, play3_name, round);//point to the correct array using 2r+1 and 2r
			}
			else if(round==9){
			frame10bowl(round, play3_bowls, play3_tot);
			}
			break;
		case 4:
			if(round<9){
			player(play4_bowls, play4_tot, play4_name, round);//point to the correct array using 2r+1 and 2r
			}
			else if(round==9){
			frame10bowl(round, play4_bowls, play4_tot);
			}
			break;
		case 5:
			if(round<9){
			player(play5_bowls, play5_tot, play5_name, round);//point to the correct array using 2r+1 and 2r
			}
			else if(round==9){
			frame10bowl(round, play5_bowls, play5_tot);
			}
			break;
		}
		
		display(players, round, play1_bowls, play2_bowls, play3_bowls, play4_bowls, play5_bowls, play1_tot, play2_tot, play3_tot, play4_tot, play5_tot, play1_name, play2_name, play3_name, play4_name, play5_name);
	}
}

/*****************************
Function: player
Description: the player whos turn it is is passed to the first bowl attempt function
Parameters: player bowl attempt array, total per frame array, name, and round number from loop in main
Pre-Conditions: player turn is determined
Post-Conditions: player has bowl and their scores for their bowls are stored
Return: nothing
*****************************/
void player(int bowl [], int tot [], char name [], int round){
	cout<<"Now, up to bowl is ";
	cout<<name;
	cout<<"Press Enter to Bowl!"<<endl;
	cin.ignore();
	
	//tot[21]+= tot[2*round+1];
	bowl_attempt(bowl, tot, name, round); //initiats bowling for any player





}
/*****************************
Function: bowl_attempt
Description: the current user presses enter to get their first bowl
Parameters: the current users bowl arrays, total per frame array, name, and round number
Pre-Conditions: the player hasn't bowl for this round yet 
Post-Conditions: the player has the first score for this round and either it's the next persons turn or they bowl again for a spare
Return: nothing
*****************************/

void bowl_attempt(int bowl [], int tot[], char name[], int round){
	int roll=rand()%11;
	if (roll==10){
		cout<<"STRIKE!"<<endl;
		bowl[2*round]=10;//2*round is what determines what element the score goes to
		bowl[2*round+1]='\0';
		//strike_to_scoreboard();
		//display();
	}
	else{
		cout<<"You knocked down "<<roll<<" pins!"<<endl;
		int x=10-roll;// use this as the mod for the next randomly gen number
		bowl[2*round]=roll;
		//diplay();
		cout<<"Press Enter again to attempt a spare!"<<endl;
		cin.ignore();
		spare_attempt(bowl, tot, name, round, x);//the player can bowl again to get a spare
		
	}
		//tot[21]+= tot[2*round+1];  //nope
}

/*****************************
Function: spare_attempt
Description: if the player didn't roll a strike first try, they get a chance to bowl a spare
Parameters: the bowl arrays for the player, the totals array, their name, the round number, and the number of pins left
Pre-Conditions: the player didn't bowl a strike
Post-Conditions: they have a second bowl score
Return: nothing
*****************************/
void spare_attempt(int bowl [], int tot[], char name[], int round, int p){
	//srand(time(NULL));
	int roll=rand()%(p+1);
	//p=p-roll;
	cout<<"You knocked down "<<roll<<" pins!"<<endl;
	if(roll==p){
		bowl[2*round+1]=10;//so I can decide later what to print out	
		bowl[2+round]=0;
	}
	else{
		bowl[2*round+1]=roll;
		//display
	}


}

/*****************************
Function: display
Description: displays the score board for the entire game
Parameters: all of the arrays for every possible player
Pre-Conditions: at least one player has bowled at least once
Post-Conditions: the scoreboard has been displayed
Return: none
*****************************/

void display (int players, int round, int play1_bowls[], int play2_bowls[], int play3_bowls[], int play4_bowls[], int play5_bowls[], int play1_tot[], int play2_tot[], int play3_tot[], int play4_tot[], int play5_tot[], char play1_name[], char play2_name[], char play3_name[], char play4_name[], char play5_name[]){
	cout<< "Name\n |  1  |  |  2  |  |  3  |  |  4  |  |  5  |  |  6  |  |  7  |  |  8  |  |  9  |  |   10   |Total"<<endl;
	cout<< "--------------------------------------------------------------------------------------"<<endl;
	for(int i=1; i<=players;i++){
	switch(i){

		case 1:
			//playertots(play1_tot);
			displaystuff(play1_name,play1_bowls, play1_tot, round);
			break;
		case 2:
//player 2
			displaystuff(play2_name,play2_bowls, play2_tot, round);
		
			break;
		case 3:
//player 3
			displaystuff(play3_name,play3_bowls, play3_tot, round);


			break;
		case 4:
//player 4
			displaystuff(play4_name,play4_bowls, play4_tot, round);

			break;
		case 5:
//player 5
			displaystuff(play5_name,play5_bowls, play5_tot, round);

			break;
		}
	}
}

/*****************************
Function: dismath
Description: the scores in the players bowl arrays are interpereted and here we determine what to display
Parameters: the round number, the playersbowls, and the players totals
Pre-Conditions: the player for the current round has bowled 
Post-Conditions: the scoreboard has been displayed
Return: nothing
*****************************/

int dismath(int round, int* playerbowls, int* playertots){
	if(playerbowls[2*round]==10)//all these are conditionals for what to print 
		cout<<" |   X  | ";
	else if(playerbowls[2*round+1]==10)
		cout<<" |    / | ";
	else if(playerbowls[2*round]==0 and playerbowls[2*round+1]==0)
		cout<<" | - - | ";
	else
		cout<<" | "<<playerbowls[2*round]<<" "<<playerbowls[2*round+1]<<" | ";
}

/*****************************
Function: totmath
Description: the players total for a given frame is determined and summed up, even in the event of a strike or spare
Parameters: the round number, the current players bowls and totals
Pre-Conditions: the player has bowled
Post-Conditions: the sum for the frame is determined
Return: none
*****************************/
int totmath(int round, int* playerbowls, int* playertots){

	if(playerbowls[2*round]==10)
		playertots[2*round+1]=playerbowls[2*round+2]+playerbowls[2*round+3]+10;
	else if( playerbowls[2*round+1]==10)
		playertots[2*round+1]=10+playerbowls[2*round+2];
	else
		playertots[2*round+1]=playerbowls[2*round]+playerbowls[2*round+1];

}

/*****************************
Function: displaystuff  ("possible functions")
Description: function that creates each players lines on the scoreboard
Parameters: the players name, bowls, totals, and the current round
Pre-Conditions: the game has called the display function
Post-Conditions: the scoreboard has been displayed
Return: nothing
*****************************/


int displaystuff(char* playername, int* playerbowls, int* playertot, int round){
		cout<<playername<<endl;
	for(int i=0; i<9; i++)
		totmath(i, playerbowls, playertot);
		playertots(playertot);
		for(int i=0; i<9; i++){
			dismath(i, playerbowls, playertot);
		}

			frame10(round, playerbowls, playertot);//just for frame ten
			cout<<endl;
		for(int i=0; i<9; i++){
			cout<<" |   "<<playertot[2*i+1]<<" | ";	
		}
			distot10(playertot, round);
			cout<<endl;
	cout<< "--------------------------------------------------------------------------------------"<<endl;

}

/*****************************
Function: playertots 
Description: calculates the players total from each frame
Parameters: the players totals array
Pre-Conditions: the player has finished at least one frame of bowling
Post-Conditions: the total has been calculated
Return: none
*****************************/
void playertots(int* tots){
	tots[21]=0;
	for(int i=0; i<10; i++){
		tots[21]+=tots[2*i+1];
	}

}


/*****************************
Function: frame10
Description: displays the 10th frame
Parameters: the current round, the players bowl attempt array, the players total	
Pre-Conditions: the player must have played at least one round for it to be displayed and 9 for it to display actual scores
Post-Conditions: the tenth frame is displayed
Return: none
*****************************/

int frame10(int round, int* playerbowl, int* playertot){
	//playertots(playertot);
	if(round<9)
		cout<<" |       | "<<playertot[21];
	else if(round==9){
		if(playerbowl[18]!=10 and playerbowl[19]!=10 and playerbowl[20]!=10)
			cout<<" | "<<playerbowl[18]<<" "<<playerbowl[19]<<" "<<playerbowl[20]<<" | "<<playertot[21];
		else if(playerbowl[18]==10 and playerbowl[19]!=10 and playerbowl[20]!=10)
			cout<<" |  X  "<<playerbowl[19]<<" "<<playerbowl[20]<<" | "<<playertot[21];
		else if(playerbowl[18]==10 and playerbowl[19]==10 and playerbowl[20]!=10)
			cout<<" |  X  X  "<<playerbowl[20]<<" | "<<playertot[21];
		else if(playerbowl[18]==10 and playerbowl[19]==10 and playerbowl[20]==10)
			cout<<" |  X  X  X  | "<<playertot[21];
		else if(playerbowl[18]==0 and playerbowl[19]==10 and playerbowl[20]!=10)
			cout<<" |    / "<<playerbowl[20]<<" | "<<playertot[21];
		else if(playerbowl[18]==10 and playerbowl[19]+playerbowl[20]==10 and playerbowl[20]!=10)
			cout<<" | X  / "<<playerbowl[20]<<" | "<<playertot[21];
	}
}
/*****************************
Function: frame10bowl
Description: the player begins bowling in the 10th frame
Parameters: the current round, the players bowl array, and the totals array
Pre-Conditions: the player has bowled 9 rounds  
Post-Conditions: the player has bowled the 10th round
Return: none
*****************************/

void frame10bowl(int round, int* bowl, int* tot){
	int roll=rand()%11;
	if (roll==10){
		cout<<"STRIKE!"<<endl;
		bowl[2*round]=10;
		bowl[2*round+1]='\0';
		cout<<"Press enter to bowl again!"<<endl;
		cin.ignore();
		frame10bowl2(bowl, tot);
		
	}
	else{

	cout<<"You knocked down "<<roll<<" pins!"<<endl;
	int x=10-roll;
	bowl[2*round]=roll;
	//diplay();
	cout<<"Press Enter again to attempt a spare!"<<endl;
	cin.ignore();
	spare_attempt10(bowl, x, tot);

	}

}
/*****************************
Function: spare_attempt10
Description: the player will attempt to get a spare in the 10th frame
Parameters: the players bowl attempt array, and the pins left from the previous bowl
Pre-Conditions: the player has made it to the 10th frame and didn't get a strike
Post-Conditions: the player either gets a spare or the game ends
Return: none
*****************************/


void spare_attempt10(int* bowl, int p, int* tot){
	//srand(time(NULL));
	int roll=rand()%(p+1);
	//p=p-roll;
	cout<<"You knocked down "<<roll<<" pins!"<<endl;
	if(roll==p){
		bowl[19]=10;	
		bowl[18]=0;
		cout<<"last bowl attempt, press enter"<<endl;
		cin.ignore();
		lastbowl(bowl, tot);
	}
	else{
		bowl[19]=roll;
		tot[19]=bowl[18]+bowl[19];
		//display
	}


}


/*****************************
Function: frame10bowl2
Description: the player will attempt to get a second strike in the 10th frame
Parameters: the players bowl arrays
Pre-Conditions: the player bowled a strike in the first attempt in the 10th frame array
Post-Conditions: the player will either try for a 3 strike or a last spare
Return: none
*****************************/
void  frame10bowl2(int* bowl, int* tot){
	int roll=rand()%11;
	int x=10-roll;
	if (roll==10){
		cout<<"Strike!"<<endl;
		bowl[19]=10;
		cin.ignore();
		cout<<"Press enter to bowl your final bowl"<<endl;
		lastbowl(bowl, tot);
	}
	else if(roll<10){
		bowl[19]=roll;
		cout<<"You knocked down "<< roll << " pins!"<<"\nPress Enter to roll again!"<<endl;
		cin.ignore();
		cout<<"Press enter for your final attempt for a spare"<<endl;
		spareattempt2frame10(bowl, x, tot);
	}	


}

/*****************************
Function: spareattempt2frame10
Description: the player will attempt to get a final spare
Parameters: the bowl array, and the pins left from frame10bowl2
Pre-Conditions: the player got a strike and then not a strike in the 10th frame and is trying to get a finals spare
Post-Conditions: the game is over
Return: none
*****************************/
void spareattempt2frame10(int *bowl, int p, int* tot){
	int roll=rand()%(p+1);
	if(roll==p){
		cout<<"Spare!"<<endl;
		bowl[20]=10;
		bowl[19]=0;
		tot[19]=20;
	}
	else{
		bowl[20]=roll;
		tot[19]=bowl[18]+bowl[19] +roll;
	}

}

/*****************************
Function: lastbowl
Description: the player goes for a final bowl
Parameters: the players bowl attempt array
Pre-Conditions: the player must have got a strike or a spare the first two times in the tenth frame
Post-Conditions: the game is over
Return: nothing
*****************************/

void lastbowl(int* bowl, int* tot){
	int roll=rand()%11;
	bowl[20]=roll;
	cout<<"You knocked down "<< roll<<" pins!"<<endl;
	if (roll==10 and bowl[18]+bowl[19]==20)
		tot[19]=30+tot[17];
	else if(roll<=9)
		tot[19]=roll + bowl[18]+bowl[19];

	


}

/*****************************
Function: distot10
Description: displays the 10th frame total
Parameters: the current round, the players  total for frame 10	
Pre-Conditions: the player must have played at least one round for it to be displayed and 9 for it to display actual scores
Post-Conditions: the tenth frame is displayed for totals
Return: none
*****************************/
void distot10(int* tot, int round){
	tot[21]+=tot[19];
	if(round<9)
		cout<<" |       | ";
	else if(round==9)
		cout<<" |  "<<tot[19]<<"   | ";

}
