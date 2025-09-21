#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compress(char* s)
{
    int i=0;
    int len = strlen(s);

    while(i<len) {
        char curr = s[i];
        int count = 1;
        while(i+count < len && s[i+count] == curr) {
            count++;
        }

        if(count > 2) {
            printf("%d%c", count, curr);
        }
        else {
            for(int j=0; j<count; j++) {
                printf("%c", curr);
            }
        }
        i += count;
    }
}

int main(int argc, char *argv[])
{
    char input[1024];
    while(fgets(input, sizeof(input), stdin)) {
        compress(input);
        printf("\n");
    }
    return 0;
}
