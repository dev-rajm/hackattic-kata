#include <stdio.h>
#include <stdlib.h>

int almost_binary(char *s)
{
    long long result = 0;
    for(int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        result <<= 1; // multiply by 2

        if(c == '#') {
            result |= 1; // set bit = 1
        }
        else if(c == '.') {

        }
        else if(c == '\n') {
            break; // end of line
        }
        else {
            fprintf(stderr, "Invalid character: %c\n", c);
            exit(1);
        }
    }
    return result;
}

int main()
{
    char input[17];

    // get input string line by line
    while(fgets(input, sizeof(input), stdin)) {
        long long decimal = almost_binary(input);
        printf("%lld\n", decimal);
    }

    return 0;
}
