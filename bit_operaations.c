#include <stdio.h>

void calculate_the_maximum(int n, int k) {
    int max_and = 0;
    int max_or  = 0;
    int max_xor = 0;
    
    // Iterate all pairs (a, b) where 1 <= a < b <= n
    for (int a = 1; a < n; a++) {
        for (int b = a + 1; b <= n; b++) {
            int and_val = a & b;
            int or_val  = a | b;
            int xor_val = a ^ b;
            
            // Update max if current value is better AND still < k
            if (and_val > max_and && and_val < k) {
                max_and = and_val;
            }
            if (or_val > max_or && or_val < k) {
                max_or = or_val;
            }
            if (xor_val > max_xor && xor_val < k) {
                max_xor = xor_val;
            }
        }
    }
    
    printf("%d\n%d\n%d\n", max_and, max_or, max_xor);
}

int main() {
    int n, k;
    
    // Read input
    if (scanf("%d %d", &n, &k) != 2) {
        return 1; // Input error handling
    }
    
    calculate_the_maximum(n, k);
    
    return 0;
}