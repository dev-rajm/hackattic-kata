#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

char* isValid(char *s)
{
    Stack st;
    initializeStack(&st);

    for(int i=0; s[i] != '\0'; i++) {
        char curr = s[i];
        if(curr == '(') {
            push(&st, curr);
        }
        else if(curr == ')') {
            if(isEmpty(&st)) {
                return "no";
            }
            else {
                pop(&st);
            }
        }
    }
    return isEmpty(&st) ? "yes" : "no";
}

int main()
{
    char input[1024];
    while(fgets(input, sizeof(input), stdin)) {
        printf("%s\n", isValid(input));
    }
    return 0;
}
