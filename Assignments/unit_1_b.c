/*A teacher wants to arrange student marks in ascending order and also measure how much
rearrangement is necessary. Write a C program using Insertion Sort that accepts n marks, displays
the array after every pass, counts the total number of element shifts, and displays the final sorted
list and shift count.*/
#include <stdio.h>
void insertionSort(int arr[], int n, int *shiftCount) {
    *shiftCount = 0; 
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; 
            j--;
            (*shiftCount)++; 
        }
        arr[j + 1] = key; 

        printf("Array after pass %d: ", i);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}
int main() {
    int n, shiftCount;
    printf("Enter the number of student marks: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d student marks:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, n, &shiftCount);

    printf("Final sorted list: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nTotal number of element shifts: %d\n", shiftCount);

    return 0;
}