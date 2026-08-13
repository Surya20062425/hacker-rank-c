#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int sum = 0;
    while (n > 0) {
        sum += n % 10;  // extract last digit
        n /= 10;        // remove last digit
    }
    
    printf("%d", sum);
    return 0;
}
