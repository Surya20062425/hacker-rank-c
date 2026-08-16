#include <stdio.h>

/* Recursive function to find nth term */
int find_nth_term(int n, int a, int b, int c) {
    /* Base cases: first three terms are given */
    if (n == 1) return a;
    if (n == 2) return b;
    if (n == 3) return c;
    
    /* Recursive step: sum of previous three terms */
    return find_nth_term(n - 1, a, b, c) + 
           find_nth_term(n - 2, a, b, c) + 
           find_nth_term(n - 3, a, b, c);
}

int main() {
    int n, a, b, c;
    
    scanf("%d", &n);
    scanf("%d %d %d", &a, &b, &c);
    
    printf("%d", find_nth_term(n, a, b, c));
    
    return 0;
}