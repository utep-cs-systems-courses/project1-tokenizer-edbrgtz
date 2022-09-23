#include <stdio.h>
#include "history.h"
#include "tokenizer.h"

int main(){
    char userInput[100];
    do {
        puts("$");
        fgets(userInput, 95, stdin);
        char **tokens = tokenize(userInput);
        print_tokens(tokens);
        free_tokens(tokens);
    } while (*userInput != 'q');
    

}