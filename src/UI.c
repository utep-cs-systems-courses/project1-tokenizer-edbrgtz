#include <stdio.h>
#include "history.h"
#include "tokenizer.h"

int main(){
    puts("Hello There!");

    while(1){
        fputs("$", stdout);
        fflush(stdout);
        
        int c;
        while ((c = getchar()) == '\n')
        if (c == EOF)
            goto done;

        // Process user input
        if (c == 'q'){
            puts("Program is terminating.");
            goto done;
        }
        if (space_char(c))
            puts("Whitespace detected.");
        
    }

    done:
        return 0;
}