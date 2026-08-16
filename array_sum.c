#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    
    /* Step 1: Read the size of the array */
    scanf("%d", &n);
    
    /* Step 2: Dynamically allocate memory for n integers */
    int *arr = (int *)malloc(n * sizeof(int));
    
    /* Step 3: Read n integers into the array */
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    /* Step 4: Calculate the sum */
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum = sum + arr[i];
    }
    
    /* Step 5: Print the result */
    printf("%d\n", sum);
    
    /* Step 6: Free the allocated memory */
    free(arr);
    
    return 0;
}
