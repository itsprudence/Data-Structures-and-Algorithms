#include <stdio.h>
#include <stdlib.h>

int summation(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }
    return sum;
}

int maximum(int arr[], int n) {
    if (n == 0) {
        printf("Empty array. No maximum element.\n");
        return -1;
    }
    int max = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Invalid number of elements. Please enter a non-negative integer.\n");
        return 1;
    }
    int arr[n];

    if (n > 0) {
        printf("Enter %d integers:\n", n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }
    }
    int sum = summation(arr, n);
    printf("Sum of the array elements: %d\n", sum);

    int max = maximum(arr, n);
    if (max != -1) {
        printf("Maximum element in the array: %d\n", max);
    }

    return 0;
}
