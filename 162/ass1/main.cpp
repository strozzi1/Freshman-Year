
#include "main.h"


/************************************************
** Program: main.cpp
** Author: Joshua Michael Strozzi (932546124)
** Date: 12 April, 2017
** Description: This program takes in file date about states and their counties, sorts, then outputs statistics to the screen or a file determined by the user
** Input: The number of states and The filename
** Output: Statistics file
*************************************************/
int main(int argc, char *argv[]){
	bool b;
	int s=5, tout;
	char filename[20];
	ifstream input;

	b=is_valid_arguments(argv, argc);
	//cout<<"bool: "<<b<<endl;
	for(int i=0; i<argc; i++){
		if (argv[i][1]=='s' && argv[i][0]=='-'){
			s=atoi(argv[i+1]);//set number of states to the corresponding command line arg
		}
	}
	cout<<"number of states: " <<s<<endl;
	for (int i=0; i<argc; i++){
		if(argv[i][1]=='f' && argv[i][0]=='-'){//fine filename denoter
			strcpy(filename ,argv[i+1]);//set file name equal to coressp. command line arg
		}
	}

	
	input.open(filename);//open input file
	state * states = create_states(s);
	get_state_data(states, s, input);
	input.close();
	cout<<"Would you like to (1)print to screen or (2)output to file?: ";
	cin>>tout;
		if(tout==2){
			bool tofile=true;
			ofstream output;
			string ofile;
			cout<<" \nWhat is/will be the name of your file?: ";
			cin>>ofile;
			output.open(ofile.c_str());

			output<<"State with the largest Population: "<<statepop(states, s)<<endl;
			output<<endl;
			output<<"County with the largest Population: "<<countypop(states, s)<<endl;
			
			incomecounty_out(states, s, output);//fix for output
			
			output<<endl;
			sn_sort(states, s);
			output<<"The States listed alphabetically: "<<endl;
			for(int i=0; i<s; i++){
				output<<states[i].name<<endl;
			}
			output<<endl;
			output<<"Counties Listed in alphabetical order: "<<endl;
			for(int snum=0; snum<s; snum++){
				cn_sort(states, snum);//works
			}
			for(int i=0; i<s; i++){
				output<<states[i].name<<": "<<endl;
				for(int j=0; j<states[i].counties; j++){
					output<<states[i].c[j].name<<endl;
				}
				output<<endl;
			}
			sp_sort(states,s);
			output<<"States listen by Population (Lowest to Highest): "<<endl;
			for(int i=0; i<s; i++){
				output<<states[i].name<<": "<<states[i].population<<endl;
			}
			output<<endl;
			
			output<<"Counties listed by Population (Lowest to Highest): "<<endl;
			for (int snum=0; snum<s; snum++){
				cp_sort(states,snum);
			}
			for(int i=0; i<s; i++){
				output<<states[i].name<<": "<<endl;
				for(int j=0; j<states[i].counties; j++){
					output<<states[i].c[j].name<<": "<< states[i].c[j].population<<endl;
				}
				output<<endl;
			}



			avg_hshld_cost_out(states, s, output); 




		}
		else if(tout==1){
			bool tofile=false;
			cout<<"State with the largest Population: "<<statepop(states, s)<<endl;
			cout<<endl;
			cout<<"County with the largest Population: "<<countypop(states, s)<<endl;
			incomecounty(states, s);
			cout<<endl;
			sn_sort(states, s);
			cout<<"The States listed alphabetically: "<<endl;
			for(int i=0; i<s; i++){
				cout<<states[i].name<<endl;
			}
			cout<<endl;
			cout<<"Counties Listed in alphabetical order: "<<endl;
			for(int snum=0; snum<s; snum++){
				cn_sort(states, snum);//works
			}
			for(int i=0; i<s; i++){
				cout<<states[i].name<<": "<<endl;
				for(int j=0; j<states[i].counties; j++){
					cout<<states[i].c[j].name<<endl;
				}
				cout<<endl;
			}
			sp_sort(states,s);
			cout<<"States listen by Population (Lowest to Highest): "<<endl;
			for(int i=0; i<s; i++){
				cout<<states[i].name<<": "<<states[i].population<<endl;
			}
			cout<<endl;
			
			cout<<"Counties listed by Population (Lowest to Highest): "<<endl;
			for (int snum=0; snum<s; snum++){
				cp_sort(states,snum);
			}
			for(int i=0; i<s; i++){
				cout<<states[i].name<<": "<<endl;
				for(int j=0; j<states[i].counties; j++){
					cout<<states[i].c[j].name<<": "<< states[i].c[j].population<<endl;
				}
				cout<<endl;
			}

			avg_hshld_cost(states, s); //works
		}
	delete_info(&states, s);

	return 0;
}

