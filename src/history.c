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
    Item tempItem;
    tempItem.str = list->root;
    tempItem.next = str;
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id){
    Item tempRoot;
    tempRoot.str = list->root;
    while (list->root != NULL) {
        if(tempRoot.id == id)
            return tempRoot.str;

        tempRoot.str = tempRoot.next;
    }  
}

/*Print the entire contents of the list. */
void print_history(List *list){
    Item tempRoot;
    tempRoot.str = list->root;
    while (list->root != NULL) {
        puts(tempRoot.str);
        tempRoot.str = tempRoot.next;
    } 
}

/*Free the history list and the strings it references. */
void free_history(List *list){
    Item tempRoot;
    tempRoot.str = list->root;
    if (tempRoot.next == NULL){
        list->root = NULL;
    } else {
        list->root = tempRoot.next;
        free_history(list);
    }
}
