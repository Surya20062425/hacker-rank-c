#include <stdio.h>
#include <stdlib.h>

int main() {
    int num, i;
    
    /* Read array size */
    scanf("%d", &num);
    
    /* Dynamically allocate array */
    int *arr = (int *)malloc(num * sizeof(int));
    
    /* Read elements */
    for (i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }
    
    /* ========== WRITE THE LOGIC HERE ========== */
    
    int left = 0;
    int right = num - 1;
    int temp;
    
    while (left < right) {
        /* Swap elements at left and right */
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        
        left++;
        right--;
    }
    
    /* ========================================== */
    
    /* Print reversed array */
    for (i = 0; i < num; i++) {
        printf("%d ", *(arr + i));
    }
    
    free(arr);
    return 0;
}