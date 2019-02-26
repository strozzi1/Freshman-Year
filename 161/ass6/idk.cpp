#include <iostream>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {	
	
		//char str[20]; //hardcode the number of letters for the name to like 12
        char s; //because we read a char at a time
	char *str=new char[1];//we are making the string a variable length
	char *temp;//need to cature old string in pointer

	//add '\0' to smallest c-string with length zero, but with one element
	str[0]='\0';	
	
	cout<<"enter a string of chars: " << endl;
	//cin>>str;
	
	//read one character from input and add to string if it is not the newline/enter
	cin.get(s);
	cout<<"s contents: " << s<<endl;
	while(s!= '\n'){
		temp=str; //point to the old string, so we don't lose it
		str=new char[strlen(temp)+2];//add space to the array, strlen doesn't count null char+extra
		strcpy(str, temp); //copy old string into new string (destination, source)
		str[strlen(temp)]=s;	//add new character where nuyll was in the old string
		str[strlen(temp)+1]='\0';//add null character to the last element in array
		delete [] temp;//get rid of old array, so we don't have a memory leak
		cin.get(s);//get another character to make sure it isn't '\n' to stop reading input

	}



	cout<< "Length: "<< strlen(str) <<endl;
	cout<< "The string: " <<str <<endl;
	cout<< "The string Begin Address: "<<(void *)str <<endl;





	//int *a;
	//a= new int[10000000];
	//cout<<a<<endl;


	
	
	return 0;
}
