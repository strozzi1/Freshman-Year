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


int main(){
	int players;
	int play1_bowls[21],play2_bowls[21], play3_bowls[21], play4_bowls[21], play5_bowls[21];
	int play1_tot[21], play2_tot[21], play3_tot[21], play4_tot[21], play5_tot[21];
	char play1_name[12], play2_name[12], play3_name[12], play4_name[12], play5_name[12];
	
	memset(play1_bowls, '\0', 84);
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
	cin>>players;
	cin.ignore();
	name( players, play1_name, play2_name, play3_name, play4_name, play5_name);
	//make scoreboard here
	for (int r=0;r<9; r++){
		game(players, r, play1_bowls, play2_bowls, play3_bowls, play4_bowls, play5_bowls, play1_tot, play2_tot, play3_tot, play4_tot, play5_tot, play1_name, play2_name, play3_name, play4_name, play5_name);
	}	

		//program segfaults right here...for some reason...


	return 0;
}

void name(int players, char play1_name[], char play2_name[], char play3_name[], char play4_name[], char play5_name[]){
	for(int i=1; i<=players; i++){
		switch(i){
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




void game (int players, int round, int play1_bowls[], int play2_bowls[], int play3_bowls[], int play4_bowls[], int play5_bowls[], int play1_tot[], int play2_tot[], int play3_tot[], int play4_tot[], int play5_tot[], char play1_name[], char play2_name[], char play3_name[], char play4_name[], char play5_name[]){
	
	//int curr_play=1;
	for(int i=1; i<=players; i++){
	//display scoreboard
	switch(i){
		case 1:
			player(play1_bowls, play1_tot, play1_name, round);//point to the correct array using 2r+1 and 2r
			break;
		case 2:
			player(play2_bowls, play2_tot, play2_name,round);
			break;
		case 3:
			player(play3_bowls, play3_tot, play3_name, round);
			break;
		case 4:
			player(play4_bowls, play4_tot, play4_name, round);
			break;
		case 5:
			player(play5_bowls, play5_tot, play5_name, round);
			break;
		}
		
		display(players, round, play1_bowls, play2_bowls, play3_bowls, play4_bowls, play5_bowls, play1_tot, play2_tot, play3_tot, play4_tot, play5_tot, play1_name, play2_name, play3_name, play4_name, play5_name);
	}
}

void player(int bowl [], int tot [], char name [], int round){
	cout<<"Now, up to bowl is ";
	cout<<name;
	cout<<"Press Enter to Bowl!"<<endl;
	cin.ignore();
	bowl_attempt(bowl, tot, name, round);
	





}

void bowl_attempt(int bowl [], int tot[], char name[], int round){
	srand (time(NULL));
	int roll=rand()%10;
	if (roll==10){
		cout<<"STRIKE!"<<endl;
		bowl[2*round]=10;
		bowl[2*round+1]='\0';
		//strike_to_scoreboard();
		//display();
	}
	else{
		cout<<"You knocked down "<<roll<<" pins!"<<endl;
		int x=10-roll;
		bowl[2*round]=roll;
		//diplay();
		cout<<"Press Enter again to attempt a spare!"<<endl;
		cin.ignore();
		spare_attempt(bowl, tot, name, round, x);

	}
}

void spare_attempt(int bowl [], int tot[], char name[], int round, int p){
	srand(time(NULL));
	int roll=rand()%(p+1);
	//p=p-roll;
	cout<<"You knocked down "<<roll<<" pins!"<<endl;
	if(roll==p){
		bowl[2*round+1]=10;	
		bowl[2+round]=0;
	}
	else{
		bowl[2*round+1]=roll;
		//display
	}


}


void display (int players, int round, int play1_bowls[], int play2_bowls[], int play3_bowls[], int play4_bowls[], int play5_bowls[], int play1_tot[], int play2_tot[], int play3_tot[], int play4_tot[], int play5_tot[], char play1_name[], char play2_name[], char play3_name[], char play4_name[], char play5_name[]){
	cout<< "Name             |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |   10   |Total"<<endl;
	cout<< "--------------------------------------------------------------------------------------"<<endl;
	for(int i=1; i<=players;i++){
	switch(i){

		case 1:
		cout<<play1_name;
		for(int i=0; i<9; i++){
			dismath(i, play1_bowls, play1_tot);
		//	cout<<" | "<<play1_bowls[2*i]<<"  "<<play1_bowls[2*i+1]<<" | ";
		}
			cout<<endl;
		for(int i=0; i<9; i++){
			totmath(i, play1_bowls, play1_tot);
			cout<<" |   "<<play1_tot[2*i+1]<<" | ";	
		}
			cout<<endl;
		break;
	case 2:
//player 2
	cout<< "--------------------------------------------------------------------------------------"<<endl;
	
		cout<<play2_name<<endl;
		for(int i=0; i<9; i++){
			dismath(i, play2_bowls, play2_tot);
		//cout<<" | "<<play2_bowls[2*i]<<"  "<<play2_bowls[2*i +1]<<" | ";
		}
			cout<<endl;
		for(int i=0; i<9; i++){
			totmath(i, play2_bowls, play2_tot);
			cout<<" |   "<<play1_tot[2*i+1]<<" | ";	
		}
			cout<<endl;

	break;
	case 3:
//player 3
	cout<< "--------------------------------------------------------------------------------------"<<endl;
		cout<<play3_name;
		for(int i=0; i<9; i++){
			dismath(i, play3_bowls, play3_tot);
		//	cout<<" | "<<play3_bowls[2*i]<<"  "<<play3_bowls[2*i+1]<<" | ";
		}
			cout<<endl;
		for(int i=0; i<9; i++){
			totmath(i, play3_bowls, play3_tot);
			cout<<" |   "<<play3_tot[2*i+1]<<" | ";	
		}
			cout<<endl;


	break;
	case 4:
//player 4
	cout<< "--------------------------------------------------------------------------------------"<<endl;
		cout<<play4_name;
		for(int i=0; i<9; i++){
			dismath(i, play4_bowls, play4_tot);
		
			//cout<<" | "<<play4_bowls[2*i]<<"  "<<play4_bowls[2*i+1]<<" | ";
		}
			cout<<endl;
		for(int i=0; i<9; i++){
			totmath(i, play4_bowls, play4_tot);
			cout<<" |   "<<play4_tot[2*i+1]<<" | ";	
		}
			cout<<endl;

	break;
	case 5:
//player 5
	cout<< "--------------------------------------------------------------------------------------"<<endl;

		cout<<play5_name;
		for(int i=0; i<9; i++){
			dismath(i, play5_bowls, play5_tot);
			//cout<<" | "<<play5_bowls[2*i]<<"  "<<play5_bowls[2*i+1]<<" | ";
		}
			cout<<endl;
		for(int i=0; i<9; i++){
			totmath(i, play5_bowls, play5_tot);
			cout<<" |   "<<play5_tot[2*i+1]<<" | ";	
		}
			cout<<endl;
	break;
		}
	}
}

/*****************************





*****************************/

int dismath(int round, int* playerbowls, int* playertots){
	if(playerbowls[2*round]==10)
		cout<<" |  X  |";
	else if(playerbowls[2*round+1]==10)
		cout<<" |    / | ";
	else if(playerbowls[2*round]==0 and playerbowls[2*round+1]==0)
		cout<<" | - - | ";
//	else if(playerbowls[2
	else
		cout<<" | "<<playerbowls[2*round]<<" "<<playerbowls[2*round+1]<<" | ";
}

int totmath(int round, int* playerbowls, int* playertots){
	




	if(playerbowls[2*round]==10)
		playertots[2*round+1]=playerbowls[2*round+2]+playerbowls[2*round+3]+10;
		//cout<<" |  "<<10+playerbowls[2*round]+(playerbowls[2*round]+1)<<" | ";
	else if( playerbowls[2*round+1]==10)
		playertots[2*round+1]=10+playerbowls[2*round+2];
		//cout<<" |  "<<10+playerbowls[2*round]<<" | ";
	//else if((playerbowls[2*round]!=10) and playerbowls[2*round +1]!=10) 
	//	playertots[2*round+1]=0;	
		//cout<<" |     | ";
	else
		playertots[2*round+1]=playerbowls[2*round]+playerbowls[2*round+1];
}
