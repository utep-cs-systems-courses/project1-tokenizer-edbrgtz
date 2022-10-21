#include "tokenizer.h"
#include "stdio.h"
#include "stdlib.h"

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c){
    if (c == ' ' || c == '\t'){
        return 1;
    }
    return 0;  
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c){
    if (c == ' ' || c == '\t'){
        return 0;
    }
    return 1;
}

/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
char *word_start(char *str){
    while (*str != '\0') {
        if (non_space_char(*str))
            return str;
        str++;
    }
    return 0;
} 

/* Returns a pointer terminator char following *word */
char *word_terminator(char *word){
    while (*word != '\0') {
        if (space_char(*word)) {
            return word;
        }
        word++;  
    }
    return 0;
}

/* Counts the number of words in the string argument. */
int count_words(char *str) {
    int total = 0; 
    
    while (*str != '\0') {
        str = word_start(str);
        str = word_terminator(str);
        total++;
    }

    return total; 
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len) {
    char *copy = malloc(len * sizeof(char));
    int index = 0;
    while (len != 0) {
        copy[index] = inStr[index];
        index++;
        len -= 1;
    }
    return copy;
    
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str) {
    puts("Hello there!");
    int wordCount = count_words(str);
    puts("Past word count.");
    int index;
    char **tokens = malloc(sizeof(char*) * (wordCount + 1));
    puts("Malloc completed.");
    index = 0;

    for (;index < wordCount; index++) {
        char *start = word_start(str);
        char *end = word_terminator(str);
        tokens[index] = copy_str(str, *end - *start);
        str = word_terminator(str);
    }
    tokens[index] = '\0';
    return tokens;
}

/* Prints all tokens. */
void print_tokens(char **tokens){
    int index = 0;
    while (tokens != '\0') {
        printf("%c \n", tokens[index]);
        tokens++;
        index++;
    }
    
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens){
    int i = 0;
    while (tokens[i] != '\0') {
        free(tokens[i]);
        i++;
    }
    free(tokens);
}