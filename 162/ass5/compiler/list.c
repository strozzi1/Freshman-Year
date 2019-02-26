#include <stdlib.h>
#include "list.h"
#include <stdio.h>

/********************************************************************************
* Description: Initializes my linked list head and tail pointers
* Parameters: the list's address
* Returns: nothing
* Pre-Conditions: The pointers weren't set'
* Post-Conditions: now they are
*********************************************************************************/

void init(struct list *l){
    (*l).head=NULL;
    (*l).tail=NULL;
}
/********************************************************************************
* Description: Runs through linked list counting nodes
* Parameters: the list
* Returns: the number of nodes
* Pre-Conditions: there's a list with any number of nodes
* Post-Conditions: nothing has changed
*********************************************************************************/

int size(struct list l){
    int count=0;
    struct node* curr=l.head;
    while(1){
        if(curr!=NULL){
            count++;
            curr=(*curr).next;
        }
        else{
         break;   
        }
    }
    return count;
}

/********************************************************************************
* Description: goes through each node and prints out the values
* Parameters: the list
* Returns: nothing
* Pre-Conditions: there is a list with nodes and values
* Post-Conditions: nothing changes
*********************************************************************************/

void print(struct list l){
    struct node* curr=l.head;
    int count=1;
    while(1){
        if(curr!=NULL){
            printf("The value at position %d is %c\n" , count++,(*curr).val);
            curr=(*curr).next;
        }
        else{
         break;   
        }
    }
}
/********************************************************************************
* Description: puts value at the front of the list
* Parameters: the address of the list and the value you wish to push to the front
* Returns: nothing
* Pre-Conditions: there is a list
* Post-Conditions: the list size is 1 greater, and the head is now a different node
*********************************************************************************/

void push_front(struct list *l, char val){
    struct node *temp=malloc(sizeof(struct node));
    (*temp).val=val;
    if(size(*l)>0){

        (*temp).next=(*l).head;
        (*l).head=temp;
    }
    else{
        (*l).head=temp;
        (*l).tail=temp;
    }
}
/********************************************************************************
* Description: makes a new node with a value and puts it at the tail, changing the tail pointer
* Parameters: the lists address and the value
* Returns: nothing
* Pre-Conditions: there is a list with a tail of size x
* Post-Conditions: the list is now size x+1 and the tail pointer points to a new node
*********************************************************************************/

void push_back(struct list *l, char val){
    struct node *temp=malloc(sizeof(struct node));
    (*temp).val=val;
    (*temp).next=NULL;
    if(size(*l)>0){
        (*l).tail->next=temp;
        (*l).tail=temp;
    }
    else{
        (*l).head=temp;
        (*l).tail=temp;
    }
}
/********************************************************************************
* Description: returns the head value
* Parameters: the list
* Returns: the value at the head
* Pre-Conditions: there is a list with a head pointer
* Post-Conditions: nothing changes
*********************************************************************************/

char front(struct list l){
    return l.head->val;
}
/********************************************************************************
* Description: returns the tail value
* Parameters: the list
* Returns: the value in the tail node
* Pre-Conditions: there is a list with a tail node
* Post-Conditions: nothing changes
*********************************************************************************/

char back(struct list l){
    return l.tail->val;
}
/********************************************************************************
* Description: deletes the tail node, sets the tail node to the last node, and returns the value
* Parameters: the list address
* Returns: the value in the tail node that was just deleted
* Pre-Conditions: there is a node list of size x
* Post-Conditions: the node list is of size x-1 and the tail pointer points to the previous node
*********************************************************************************/

char pop_back(struct list* l){

        struct node* curr=(*l).head;
        char lastval=(*l).tail->val;
        while(1){
            //if((*curr).next!=NULL){
             if((*curr).next!=(*l).tail){
                //if((*curr).next->next!=NULL){
                    curr=(*curr).next;
                }
            else{
                    break;
            }
        }
        //}
        free((*l).tail);
            if(size(*l)>0){
                (*l).tail=curr;
                curr->next=NULL;
            }

        return lastval;
        
}

/********************************************************************************
* Description: removes the head node, and sets the head pointer to the following node
* Parameters: the lists address
* Returns: the value of the old head node
* Pre-Conditions: the list is size x and has a head node pointer
* Post-Conditions: the list is size x-1 and has a different head node pointer
*********************************************************************************/


char remove_front(struct list *l){
    if(size(*l)>0){
        struct node * curr=(*l).head->next;
        char firstval=(*l).head->val;
        if((*l).head->next!=NULL){
            free((*l).head);

            (*l).head=curr;
        }
            return firstval;
    }


}
/********************************************************************************
* Description: returns 0 (false) of the head pointer points to another node
* Parameters: the list
* Returns: 1(true) or 0 (false)
* Pre-Conditions: there are or are not any nodes in the list
* Post-Conditions: nothing changes
*********************************************************************************/

int empty(struct list l){
    if(l.head!=NULL){
        return 0;
    }
    else
        return 1;
}
/********************************************************************************
* Description: runs through whole array and deletes any and all nodes
* Parameters: the lists address
* Returns: nothing
* Pre-Conditions: there is a list
* Post-Conditions: the list has a size of 0
*********************************************************************************/

void delete(struct list *l){
    if(size(*l)>0){
        struct node * curr=(*l).head->next;
    while(1){
        if((*l).head!=NULL){
            free((*l).head);
            l->head=curr;
        }
        else{
            break;
        }
    }    
    }

}

