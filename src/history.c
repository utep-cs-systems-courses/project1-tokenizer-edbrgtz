#include "history.h"
#include "stdio.h"

typedef struct s_Item {
  int id;
  char *str;
  struct s_Item *next;
} Item;

typedef struct s_List {
  struct s_Item *root;
} List;

/* Initialize the linked list to keep the history. */
List* init_history(){
    List history;
    return history.root;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str){
    Item *tempItem;
    Item *newItem;
    newItem->str = str;
    tempItem = list->root;
    
    while (tempItem) {
        if (!tempItem->next) {
            tempItem->next = newItem;
        }
        tempItem = tempItem->next;
    }
    
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id){
    Item *tempRoot;
    tempRoot = list->root;
    while (list->root) {
        if(tempRoot->id == id)
            return tempRoot->str;

        tempRoot = tempRoot->next;
    }  
}

/*Print the entire contents of the list. */
void print_history(List *list){
    Item *tempRoot;
    tempRoot = list->root;
    while (list->root != NULL) {
        puts(tempRoot->str);
        puts(tempRoot->id);
        tempRoot->str = tempRoot->next;
    } 
}

/*Free the history list and the strings it references. */
void free_history(List *list){
    while(list->root){
        Item *p = list->root;
        list->root = list->root->next;
        Free(p->str);
        Free(p->next);
        Free(p->id);
        Free(p);
    }
}
