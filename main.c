#include <stdio.h>

void rotate(int* nums, int n, int k) {
    k = k % n;

    for (int i = 0, j = n - 1; i < j; i++, j--) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    for (int i = 0, j = k - 1; i < j; i++, j--) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    for (int i = k, j = n - 1; i < j; i++, j--) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
int main() {
    int nums[] = {1, 8, 2, 8, 10, 7};
    int size = sizeof(nums)/sizeof(nums[0]);
    int k = 2;

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }

    rotate(nums, size, k);

    printf("\nRotated array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}
