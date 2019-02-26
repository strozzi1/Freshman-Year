

#include "main.h"
using namespace std;


//sort functions: 
/***************************************************
** Function: sn_sort
** Description: Sorts states by name
** Parameters: my state array and the number of states
** Pre-conditions: info has been transfered from the file to my states array
** Post-conditions: The states array has been alphabetized
** Return: nothing
****************************************************/
void sn_sort(state *arr, int states){ //state name sort
	state temp;
	for (int i=1; i< states; i++){
		for(int j=0; j< (states-i); j++){
			if(arr[j].name>arr[j+1].name){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}


/***************************************************
** Function: sp_sort	
** Description: Sort out states by population lowest ot highest
** Parameters: my states array, number of states
** Pre-conditions: my states array is full of info from file
** Post-conditions: the states array has been ordered by population
** Return: nothing
****************************************************/

void sp_sort(state *arr, int states){
	state temp;
	for (int i=1; i< states; i++){
		for(int j=0; j< (states-i); j++){
			if(arr[j].population>arr[j+1].population){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}

	}


}


/***************************************************
** Function: cp_sort
** Description: Sort out counties of each state by population
** Parameters: state array, the state position in the array with the counties you want to organize
** Pre-conditions: info has been transered from the file to the states array
** Post-conditions: counties for chosen state have been organized by population
** Return: nothing 
****************************************************/

void cp_sort(state *arr, int curr_state){//sort counties by pop
	state temp[1];
	temp[0].c =new county[1];
	for (int i=1; i< arr[curr_state].counties; i++){
		for(int j=0; j< (arr[curr_state].counties-i); j++){
			if(arr[curr_state].c[j].population>arr[curr_state].c[j+1].population){
				
				temp[0].c[0]=arr[curr_state].c[j];
				arr[curr_state].c[j]=arr[curr_state].c[j+1];
				arr[curr_state].c[j+1]=temp[0].c[0];

			}
		}
	}
	delete[] temp[0].c;
}


/***************************************************
** Function: cn_sort
** Description: Sort counties by name in a state 
** Parameters: state array, state position in array
** Pre-conditions: info from file is in array
** Post-conditions: counties organized by name
** Return: nothing
****************************************************/


void cn_sort(state *arr, int curr_state){//sort counties by pop
	state temp[1];
	temp[0].c =new county[1];
	for (int i=1; i< arr[curr_state].counties; i++){
		for(int j=0; j< (arr[curr_state].counties-i); j++){
			if(arr[curr_state].c[j].name>arr[curr_state].c[j+1].name){
				temp[0].c[0]=arr[curr_state].c[j];
				arr[curr_state].c[j]=arr[curr_state].c[j+1];
				arr[curr_state].c[j+1]=temp[0].c[0];
			}
		}

	}
	delete [] temp[0].c;
}


/***************************************************
** Function: avg_hshld_cost
** Description: Search for and display the avg household cost for each state, and display
** Parameters: state array, number of states
** Pre-conditions: info is in array from file	
** Post-conditions: none
** Return: nothing
****************************************************/

void avg_hshld_cost(state *arr, int states){
	int houses, prices;
	float avg;

	for (int s=0; s<states; s++){
		prices=0;
		for(int cnt=0; cnt< arr[s].counties; cnt++){
			prices+=arr[s].c[cnt].avg_house;
			avg=prices/arr[s].counties;
			
		}
	cout<<"Average household cost for "<<arr[s].name<< " is: $"<< avg<<endl;
	}



}


/***************************************************
** Function: avg_hshld_cost_out
** Description: Same as avg_hshld_cost, but for ofstream 
** Parameters: state array, number of states, ofstream
** Pre-conditions: same as avg_hshld_cost
** Post-conditions: none
** Return: none
****************************************************/


void avg_hshld_cost_out(state *arr, int states, ofstream& output){
	int houses, prices;
	float avg;

	for (int s=0; s<states; s++){
		prices=0;
		for(int cnt=0; cnt< arr[s].counties; cnt++){
			prices+=arr[s].c[cnt].avg_house;
			avg=prices/(double)arr[s].counties;
			
		}
	output<<"Average household cost for "<<arr[s].name<< " is: $"<< avg<<endl;
	}



}


/***************************************************
** Function: incomecounty
** Description: ask user for baseline income, then find counties with income higher than that, then display them
** Parameters: state struct array, number of states
** Pre-conditions: info is in state struct array
** Post-conditions: none
** Return: none
****************************************************/

void incomecounty(state *arr, int states){
	float income;
	int state, county, cnum=0;
	cout<<"What would you like the baseline income to be?"<<endl;
	cin>>income;
	cout<<" \nCounties with average income above $"<<income<<": "<<endl;
	for(int i=0; i<states; i++){
		cout<<arr[i].name<<": "<<endl;
		for(int count=0; count<arr[i].counties; count++){
			if(arr[i].c[count].avg_income>income){
				//works
				cnum++;//number of counties above income baseline
				cout<<arr[i].c[count].name<<endl; 
			}

		}
		cout<<endl;
	}

}

/***************************************************
** Function: incomecounty_out
** Description: Same as incomecounty, just for ofstream
** Parameters: state struct array, number of states, ofstream
** Pre-conditions: info in state struct array
** Post-conditions: none
** Return: none
****************************************************/

void incomecounty_out(state *arr, int states, ofstream& output){
	float income;
	int state, county, cnum=0;
	cout<<"What would you like the baseline income to be?: ";
	cin>>income;
	output<<" \nCounties with average income above $"<<income<<": "<<endl;
	for(int i=0; i<states; i++){
		output<<arr[i].name<<": "<<endl;
		for(int count=0; count<arr[i].counties; count++){
			if(arr[i].c[count].avg_income>income){
				//works
				cnum++;//number of counties above income baseline
				output<<arr[i].c[count].name<<endl; 
			}

		}
		output<<endl;
	}

}

/***************************************************
** Function: statepop
** Description: find state with most population
** Parameters: state struct array, number of states
** Pre-conditions: info in state struct array
** Post-conditions: none
** Return: return string (name of state)
****************************************************/


string statepop(state *arr, int states){ //state with largest pop
	int state=0, mostpop=0;

	for(int i=0; i<states; i++){
		if(arr[i].population>mostpop){
			mostpop=arr[i].population;
			state=i;
		}
	}

	return arr[state].name;
}


/***************************************************
** Function: countypop
** Description: same as statepop, but for county
** Parameters: state struct array, number of states
** Pre-conditions: info from file in state struct array
** Post-conditions: none
** Return: name of county
****************************************************/


string countypop (state *arr, int states){
	int state, mostpop=0, county;
	for (int i=0; i<states; i++){
		for(int count=0; count<arr[i].counties;count++){
			if(arr[i].c[count].population>mostpop){
				mostpop=arr[i].c[count].population;
				state=i;
				county=count;
			}
		}	

	}
	return arr[state].c[county].name;
}


/***************************************************
** Function: create_counties
** Description: allocate memory for struct county array
** Parameters: number of counties
** Pre-conditions: memory is allocated for state struct array
** Post-conditions: memory is allocated for county struct array in state struct array
** Return: pointer for county array of c size
****************************************************/


//required: 
county * create_counties(int c){
	int count=5;
	count=c;	
	
	county *arrc=new county[count];

	return arrc;

}


/***************************************************
** Function: get_state_data
** Description: get info from external file and put into state struct array
** Parameters: state struct array, number of states, ifstream
** Pre-conditions: file has been decided and number of states
** Post-conditions: info is in state struct array, and memory is allocated for county array
** Return: nothing
****************************************************/

void get_state_data(state *arr, int states, ifstream& input){
	
	for(int s=0; s < states; s++){
		input >> arr[s].name;
		input >> arr[s].population;
		input >> arr[s].counties;
		arr[s].c=create_counties(arr[s].counties);//set up dynamic array for counties for this state
		get_county_data(arr[s].c, arr[s].counties, input);	//pass county array in for county data

	}	

}

/***************************************************
** Function: get_county_data
** Description: input info for each county for each state
** Parameters: country struct array, number of counties, ifstream
** Pre-conditions: memory has been allocated for county array
** Post-conditions: info is put in for county and cities in county
** Return: nothing
****************************************************/


void get_county_data(county *arrc, int c, ifstream & input){
	int cities=1;
	for(int i=0; i<c ;i++){
		input >> arrc[i].name;
		input >> arrc[i].population;
		input >> arrc[i].avg_income;
		input >> arrc[i].avg_house;
		input >> arrc[i].cities;
		arrc[i].city= new string [arrc[i].cities];
			for(int j=0; j<arrc[i].cities; j++){
				input>>arrc[i].city[j];
			}
	}

}

/***************************************************
** Function: create_states
** Description: allocate memory for state struct array of s size
** Parameters: s(number of states)
** Pre-conditions: structs have been determined, number of states is knwn
** Post-conditions: memory is allocated for s number of states
** Return: state struct array
****************************************************/

state * create_states(int s){
	int states=5;
	states=s;
	
	state *arr=new state[s];
	
	return arr;

}

/***************************************************
** Function: is_valid_arguments
** Description: determines if the command line arguments are valid for program
** Parameters: argv, and argc 
** Pre-conditions: user has input command line arguments
** Post-conditions: program continues or quits
** Return: bool for if its correct (isn't actually used)
****************************************************/


bool is_valid_arguments(char *argv[], int argc){
	if(argc!=5){
		cout<<"Incorrect number of arguments"<<endl;
		return false;
	}
	else{
		if((argv[1][1]=='s' || argv[1][1]=='f')&& (argv[3][1]=='s' || argv[3][1]=='f')&& argv[1][1]!=argv[3][1] && (argv[1][0]=='-' && argv[3][0]=='-')){
			if(argv[1][1]=='s'){
				if(atoi(argv[2])>0 && atoi( argv[2])<50){
					return true;
				}
				else{
					cout<<"Your number is invalid"<<endl;
					return false;
				}
			}
			else if(argv[3][1]=='s'){
				if(atoi(argv[4])>0 && atoi(argv[4])<50){
					return true;
				}
				else{
					cout<<"Your number is invalid"<<endl;
					return false;
				}
			}
		}
		else{
			cout<<"Your arguments are invalid"<<endl;
			return false;
		}
	}
}


/***************************************************
** Function: delete_info
** Description: Frees up memory on heap, taking care of memory leaks
** Parameters: address of state struct array, number of states
** Pre-conditions: memory is being used up on the heap
** Post-conditions: memory has been removed from the heap
** Return: none
****************************************************/


void delete_info(state** arr, int states){

	
	for(int s=0; s<states; s++){
		for (int cnt=0; cnt< (*arr)[s].counties; cnt++){
				delete [] (*arr)[s].c[cnt].city;
		}
		
	}
	
	for(int s=0; s<states; s++){
			delete [] (*arr)[s].c;
	}
	delete [] *arr;
	arr =NULL;

}





