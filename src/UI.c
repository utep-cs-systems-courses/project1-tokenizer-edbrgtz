#include <stdio.h>
#include "history.h"
#include "tokenizer.h"

int main(){
    char userInput[100];
    do {
        printf("$ ");
        fgets(userInput, 95, stdin);
        int wordCount = count_words(userInput);
        printf("%d \n", wordCount);
        char **tokens = tokenize(userInput);
        // print_tokens(tokens);
        // free_tokens(tokens);
    } while (*userInput != 'q');
    

}