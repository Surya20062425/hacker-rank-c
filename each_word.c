#include <stdio.h>

int main() {
    char word[1000];  /* Buffer to hold one word at a time */
    
    /* scanf returns the number of items successfully read.
       It returns 1 when it reads a word, EOF when input ends. */
    while (scanf("%s", word) == 1) {
        printf("%s\n", word);
    }
    
    return 0;
}