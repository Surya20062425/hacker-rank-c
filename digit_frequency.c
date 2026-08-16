#include <stdio.h>

int main() {
    char s[1000];           /* String buffer */
    int count[10] = {0};    /* 10 counters, all initialized to 0 */
    int i;
    
    /* Read the string */
    scanf("%s", s);
    
    /* Scan each character */
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            count[s[i] - '0']++;
        }
    }
    
    /* Print frequencies of 0 through 9 */
    for (i = 0; i < 10; i++) {
        printf("%d", count[i]);
        if (i < 9) {
            printf(" ");
        }
    }
    
    return 0;
}