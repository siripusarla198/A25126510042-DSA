/*A company stores employee IDs in ascending order. Write a C program that accepts n employee
IDs, searches for a required ID using Binary Search, displays its position when found, reports
when it is absent, and counts the number of comparisons. Test the program for both successful
and unsuccessful searches.*/
#include <stdio.h>
int binarySearch(int arr[], int size, int target, int *comparisons) {
    int left = 0;
    int right = size - 1;
    *comparisons = 0; 

    while (left <= right) {
        (*comparisons)++; 
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; 
        } else if (arr[mid] < target) {
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }
    return -1; 
}
int main() {
    int n, target, comparisons;
    printf("Enter the number of employee IDs: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d employee IDs in ascending order:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the employee ID to search for: ");
    scanf("%d", &target);

    int result = binarySearch(arr, n, target, &comparisons);
    if (result != -1) {
        printf("Employee ID %d found at position %d.\n", target, result + 1);
    } else {
        printf("Employee ID %d not found.\n", target);
    }
    printf("Number of comparisons made: %d\n", comparisons);

    return 0;
}