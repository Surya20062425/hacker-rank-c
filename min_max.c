#include <stdarg.h>
#include <stdio.h>

/* ========== SUM ========== */
int sum(int count, ...) {
    va_list args;
    va_start(args, count);
    
    int total = 0;
    for (int i = 0; i < count; i++) {
        total += va_arg(args, int);
    }
    
    va_end(args);
    return total;
}

/* ========== MINIMUM ========== */
int min(int count, ...) {
    va_list args;
    va_start(args, count);
    
    /* First element becomes the initial min */
    int minimum = va_arg(args, int);
    
    for (int i = 1; i < count; i++) {
        int current = va_arg(args, int);
        if (current < minimum) {
            minimum = current;
        }
    }
    
    va_end(args);
    return minimum;
}

/* ========== MAXIMUM ========== */
int max(int count, ...) {
    va_list args;
    va_start(args, count);
    
    /* First element becomes the initial max */
    int maximum = va_arg(args, int);
    
    for (int i = 1; i < count; i++) {
        int current = va_arg(args, int);
        if (current > maximum) {
            maximum = current;
        }
    }
    
    va_end(args);
    return maximum;
}

/* The main() is handled by the test framework */