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



int main(){
	int players;
	int play1_bowls[21],play2_bowls[21], play3_bowls[21], play4_bowls[21], play5_bowls[21];
	int play1_tot[21], play2_tot[21], play3_tot[21], play4_tot[21], play5_tot[21];
	char play1_name[12], play2_name[12], play3_name[12], play4_name[12], play5_name[12];
	cout<<"How many players: ";
	cin>>players;
	
	//make scoreboard here
	for (int r=0;r<9; r++){
		game(players, r, play1_bowls, play2_bowls, play3_bowls, play4_bowls, play5_bowls, play1_tot, play2_tot, play3_tot, play4_tot, play5_tot, play1_name, play2_name, play3_name, play4_name, play5_name);
	}	





	return 0;
}

void name(int players, char play1_name[], char play2_name[], char play3_name[], char play4_name[], char play5_name[]){
	for(int i=1; i<=players; i++){
		switch(i){
			case 1:
				makename(play1_name);
				break;
			case 2:
				makename(play2_name);
				break;
			case 3:
				makename(play3_name);
				break;
			case 4:
				makename(play4_name);
				break;
			case 5:
				makename(play5_name);
				break;
		}

	}

}


void makename(char play_name[]){//this is code that Jennifer gave the class
	char s;//read one char at a time
	char *str=new char[1];//creat smallest c-string, which is just null char '\0'
	char *temp; //need to capture old string in pointer

	str[0]= '\0';

	cin.get(s);
	while (s!= '\n'){
		temp=str;
		str=new char [strlen(temp)+2];
		strcpy(str,temp);
		str[strlen(temp)]=s;
		str[strlen(temp)+1]='\0';
		delete [] temp;
		cin.get(s);
	}
	//HOW DO I GET PLAY_NAME TO GET THE STRING AT THE END?
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
	}
}

void player(int bowl [], int tot [], char name [], int round){
	cout<<name<<"'s turn!" <<endl;
	bowl_attempt(bowl, tot, name, round);
	





}

void bowl_attempt(int bowl [], int tot[], char name[], int round){
	srand (time(NULL));
	int roll=rand()%10;
	if (roll==10){
		cout<<"STRIKE!"<<endl;
		//strike_to_scoreboard();
		//display();
	}
	else{
		cout<<"You knocked down "<<bowl<<" pin!"<<endl;
		int x=10-roll;
		bowl[2*round]=roll;
		//diplay();
		spare_attempt(bowl, tot, name, round, x);

	}
}

void spare_attempt(int bowl [], int tot[], char name[], int round, int p){
	srand(time(NULL));
	int roll=rand()%p;
	p=p-roll;
	if(p==0){
		//spare_to_scoreboard();
		//display();
	}
	else{
		bowl[2*round+1]=p;
		//display
	}


}


void display (int players, int round, int play1_bowls[], int play2_bowls[], int play3_bowls[], int play4_bowls[], int play5_bowls[], int play1_tot[], int play2_tot[], int play3_tot[], int play4_tot[], int play5_tot[], char play1_name[], char play2_name[], char play3_name[], char play4_name[], char play5_name[]){

	for(int i=1; i<=players;i++){
	switch(i){

	cout<< "Name             |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |   10   |Total"<<endl;
	cout<< "--------------------------------------------------------------------------------------"<<endl;
	case 1:
	cout<< play1_name<<"| "<<play1_bowls[0]<<" "<<play1_bowls[1]<<" | "<<play1_bowls[3]<<" "<<play1_bowls[4]<<" | "<<play1_bowls[5]<<" "<<play1_bowls[6]<<" | "<<play1_bowls[7]<<" "<<play1_bowls[8]<<" | "<<play1_bowls[9]<<" "<<play1_bowls[10]<<" | "<<play1_bowls[11]<<" "<<play1_bowls[12]<<" | "<<play1_bowls[13]<<" "<<play1_bowls[14]<<" | "<<play1_bowls[15]<<" "<<play1_bowls[16]<<" | "<<play1_bowls[17]<<" "<<play1_bowls[18]<<" | "<<play1_bowls[19]<<" "<<play1_bowls[20]<<" | "<<play1_bowls[21]<<endl;


	cout<<"            |   "<<play1_tot[0]<<" |     "<<play1_tot[2]<<" |     "<<play1_tot[4]<<" |     "<<play1_tot[6]<<" |     "<<play1_tot[8]<<" |     "<<play1_tot[10]<<" |     "<<play1_tot[12]<<" |     "<<play1_tot[14]<<" |     "<<play1_tot[16]<<" |     "<<play1_tot[18]<<" |     "<<play1_tot[20]<<" |     "<<play1_tot[21]<<endl;
	break;
	case 2:
//player 2
	cout<< "--------------------------------------------------------------------------------------"<<endl;
	cout<< play2_name<<"| "<<play2_bowls[0]<<" "<<play2_bowls[1]<<" | "<<play2_bowls[3]<<" "<<play2_bowls[4]<<" | "<<play2_bowls[5]<<" "<<play2_bowls[6]<<" | "<<play2_bowls[7]<<" "<<play2_bowls[8]<<" | "<<play2_bowls[9]<<" "<<play2_bowls[10]<<" | "<<play2_bowls[11]<<" "<<play2_bowls[12]<<" | "<<play2_bowls[13]<<" "<<play2_bowls[14]<<" | "<<play2_bowls[15]<<" "<<play2_bowls[16]<<" | "<<play2_bowls[17]<<" "<<play2_bowls[18]<<" | "<<play2_bowls[19]<<" "<<play2_bowls[20]<<" | "<<play2_bowls[21]<<endl;


	cout<<"            |   "<<play2_tot[0]<<" |     "<<play2_tot[2]<<" |     "<<play2_tot[4]<<" |     "<<play2_tot[6]<<" |     "<<play2_tot[8]<<" |     "<<play2_tot[10]<<" |     "<<play2_tot[12]<<" |     "<<play2_tot[14]<<" |     "<<play2_tot[16]<<" |     "<<play2_tot[18]<<" |     "<<play2_tot[20]<<" |     "<<play2_tot[21]<<endl;
	break;
	case 3:
//player 3
	cout<< "--------------------------------------------------------------------------------------"<<endl;
	cout<< play3_name<<"| "<<play3_bowls[0]<<" "<<play3_bowls[1]<<" | "<<play3_bowls[3]<<" "<<play3_bowls[4]<<" | "<<play3_bowls[5]<<" "<<play3_bowls[6]<<" | "<<play3_bowls[7]<<" "<<play3_bowls[8]<<" | "<<play3_bowls[9]<<" "<<play3_bowls[10]<<" | "<<play3_bowls[11]<<" "<<play3_bowls[12]<<" | "<<play3_bowls[13]<<" "<<play3_bowls[14]<<" | "<<play3_bowls[15]<<" "<<play3_bowls[16]<<" | "<<play3_bowls[17]<<" "<<play3_bowls[18]<<" | "<<play3_bowls[19]<<" "<<play3_bowls[20]<<" | "<<play3_bowls[21]<<endl;


	cout<<"            |   "<<play3_tot[0]<<" |     "<<play3_tot[2]<<" |     "<<play3_tot[4]<<" |     "<<play3_tot[6]<<" |     "<<play3_tot[8]<<" |     "<<play3_tot[10]<<" |     "<<play3_tot[12]<<" |     "<<play3_tot[14]<<" |     "<<play3_tot[16]<<" |     "<<play3_tot[18]<<" |     "<<play3_tot[20]<<" |     "<<play3_tot[21]<<endl;
	break;
	case 4:
//player 4
	cout<< "--------------------------------------------------------------------------------------"<<endl;
	cout<< play4_name<<"| "<<play4_bowls[0]<<" "<<play4_bowls[1]<<" | "<<play4_bowls[3]<<" "<<play4_bowls[4]<<" | "<<play4_bowls[5]<<" "<<play4_bowls[6]<<" | "<<play4_bowls[7]<<" "<<play4_bowls[8]<<" | "<<play4_bowls[9]<<" "<<play4_bowls[10]<<" | "<<play4_bowls[11]<<" "<<play4_bowls[12]<<" | "<<play4_bowls[13]<<" "<<play4_bowls[14]<<" | "<<play4_bowls[15]<<" "<<play4_bowls[16]<<" | "<<play4_bowls[17]<<" "<<play4_bowls[18]<<" | "<<play4_bowls[19]<<" "<<play4_bowls[20]<<" | "<<play4_bowls[21]<<endl;


	cout<<"            |   "<<play4_tot[0]<<" |     "<<play4_tot[2]<<" |     "<<play4_tot[4]<<" |     "<<play4_tot[6]<<" |     "<<play4_tot[8]<<" |     "<<play4_tot[10]<<" |     "<<play4_tot[12]<<" |     "<<play4_tot[14]<<" |     "<<play4_tot[16]<<" |     "<<play4_tot[18]<<" |     "<<play4_tot[20]<<" |     "<<play4_tot[21]<<endl;
	break;
	case 5:
//player 5
	cout<< "--------------------------------------------------------------------------------------"<<endl;
	cout<< play5_name<<"| "<<play5_bowls[0]<<" "<<play5_bowls[1]<<" | "<<play5_bowls[3]<<" "<<play5_bowls[4]<<" | "<<play5_bowls[5]<<" "<<play5_bowls[6]<<" | "<<play5_bowls[7]<<" "<<play5_bowls[8]<<" | "<<play5_bowls[9]<<" "<<play5_bowls[10]<<" | "<<play5_bowls[11]<<" "<<play5_bowls[12]<<" | "<<play5_bowls[13]<<" "<<play5_bowls[14]<<" | "<<play5_bowls[15]<<" "<<play5_bowls[16]<<" | "<<play5_bowls[17]<<" "<<play5_bowls[18]<<" | "<<play5_bowls[19]<<" "<<play5_bowls[20]<<" | "<<play5_bowls[21]<<endl;


	cout<<"            |   "<<play5_tot[0]<<" |     "<<play5_tot[2]<<" |     "<<play5_tot[4]<<" |     "<<play5_tot[6]<<" |     "<<play5_tot[8]<<" |     "<<play5_tot[10]<<" |     "<<play5_tot[12]<<" |     "<<play5_tot[14]<<" |     "<<play5_tot[16]<<" |     "<<play5_tot[18]<<" |     "<<play5_tot[20]<<" |     "<<play5_tot[21]<<endl;
	break;
		}
	}
}
