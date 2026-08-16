#include <stdio.h>

// Helper to find minimum of two integers
int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n;
    
    // Read input
    if (scanf("%d", &n) != 1) {
        return 1; // Input error handling
    }
    
    int size = 2 * n - 1;  // Grid dimensions
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // Distance from all four boundaries
            int top    = i;
            int left   = j;
            int bottom = size - 1 - i;
            int right  = size - 1 - j;
            
            // The cell sits on the ring determined by the nearest edge
            int min_dist = min(min(top, bottom), min(left, right));
            
            // Value decreases as we move inward
            int value = n - min_dist;
            
            // Print with single space separation
            if (j > 0) {
                printf(" ");
            }
            printf("%d", value);
        }
        printf("\n");
    }
    
    return 0;
}