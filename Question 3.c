#include <stdio.h>
#include <stdbool.h>

bool hasDuplicate(int* nums, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] == nums[j]) {
                return true;
            }
        }
    }
    return false;
int main() {
    int nums[] = {2, 2, 6, 10, 6, 4};
    int size = sizeof(nums) / sizeof(nums[0]);

    if (hasDuplicate(nums, size)) {
        printf("Array contains duplicates\n");
    } else {
        printf("All elements are distinct\n");
    }

    return 0;
}
