#include <stdio.h>

int singleNum(int* nums, int n) {
    for (int i = 0; i < n; i++) {
        int count = 0;

        for (int j = 0; j < n; j++) {
            if (nums[j] == nums[i]) {
                count++;
            }
        }
        if (count == 1) {
            return nums[i];
        }
    }
    return -1;
}

int main() {
    int nums[] = {4, 8, 10, 7, 2, 10, 8, 4, 7};
    int size = sizeof(nums) / sizeof(nums[0]);

    int single = singleNum(nums, size);
    printf("The single number is: %d\n", single);

    return 0;
}
