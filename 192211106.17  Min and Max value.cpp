#include <stdio.h>
void findMinMax(int arr[], int left, int right, int* minVal, int* maxVal) {
    if (left == right) {
        *minVal = arr[left];
        *maxVal = arr[right];
        return;
    }

    if (right == left + 1) {
        *minVal = (arr[left] < arr[right]) ? arr[left] : arr[right];
        *maxVal = (arr[left] > arr[right]) ? arr[left] : arr[right];
        return;
    }

    int mid = (left + right) / 2;
    int minLeft, maxLeft, minRight, maxRight;

    findMinMax(arr, left, mid, &minLeft, &maxLeft);
    findMinMax(arr, mid + 1, right, &minRight, &maxRight);

    *minVal = (minLeft < minRight) ? minLeft : minRight;
    *maxVal = (maxLeft > maxRight) ? maxLeft : maxRight;
}

int main() {
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements for the array:\n", n);
    int i;
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int minVal, maxVal;

    findMinMax(arr, 0, n - 1, &minVal, &maxVal);

    printf("Minimum value: %d\n", minVal);
    printf("Maximum value: %d\n", maxVal);

    return 0;
}
