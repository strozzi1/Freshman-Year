#include "list.h"
#include <stdio.h>
#include <string.h>

/************************************************
** Program: main.c or compiler
** Author: Joshua Michael Strozzi (932546124)
** Date: 10 June, 2017
** Description: checks if the users inputer of characters {} () and [] are in an compilable order
** Input: characters {([])} or whatever order
** Output: error message or confirmation message
*************************************************/



int main(){
    struct list l;
    char input[20];
    init(&l);
    int i;
    while(1){
        printf("What is your input: ");
        scanf("%s", &input); //or use fgets(name, size, std::in);
        printf("size is %d\n", strlen(input));
        if(strlen(input) % 2==0){
            if(input[0]!='q'){
                for(i=0; i<strlen(input); i++){
                    printf("Size of list is %d\n",size(l));
                    if(input[i]=='(' || input[i]=='[' || input[i]=='{'){
                        push_back(&l, input[i]);
                    }
                    else if(input[i]==')' && back(l)=='('){
                        if(size(l)>1)
                            pop_back(&l);
                        else
                            delete(&l);
                    }
                    else if(input[i]=='}' && back(l)=='{'){
                        if(size(l)>1)
                            pop_back(&l);
                        else
                            delete(&l);
                    }
                    else if(input[i]==']' && back(l)=='['){
                        if(size(l)>1)
                            pop_back(&l);
                        else
                            delete(&l);
                    }
                    else{
                        printf("It has failed\n");
                        //delete(&l);
                        break;
                    }
                        
                }
                if(size(l)==0)
                    printf("It compiles, try another\n");

            }
            else{
                break;
            }
        }
        else{
            printf("Your input has an odd number of characters and would not compile.\n");
        }
       
    }


    return 0;
}


