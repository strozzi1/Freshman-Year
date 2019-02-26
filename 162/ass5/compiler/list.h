struct node {
   char val;
   struct node *next;
};

struct list {
   struct node *head;
   struct node *tail;
};

void init(struct list *); //initialize empty list    //
int size(struct list); //return number of nodes in list  //
void print(struct list); //print the values in list //
void push_front(struct list *, char);//push to front of list  //
void push_back(struct list *, char); //push to end of list //
char front(struct list);  //returns value at the front of the  list  //
char back(struct list);  //returns value at the back of the list //
char pop_back(struct list *); //remove node from back and return value of old tail //
char remove_front(struct list *);//remove node from front and return value //
int empty(struct list);  //returns true if list is empty //
void delete(struct list *);  //remove all nodes from list//

//queue is fi/fo  stack is fi/lo

//worked on this with Chongxian Chen

