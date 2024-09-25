#include <stdio.h> 

int binarySearch(int arr[], int size, int target) { 
int low = 0; 
int high = size - 1; 
int mid; 
while (low <= high) { 
mid = low + (high - low) / 2; 

if (arr[mid] == target) { 
return mid;  
} 
 
if (arr[mid] > target) { 
high = mid - 1; 
} 

else { 
low = mid + 1; 
} 
} 
return -1;  
} 
int main() { 
int n, target, result; 
 
printf("Enter the number of elements in the array: "); 
scanf("%d", &n); 
 
int arr[n]; 

printf("Enter the elements of the sorted array:\n"); 
for (int i = 0; i < n; i++) { 
scanf("%d", &arr[i]); 
} 
 
printf("Enter the target value to search: "); 
scanf("%d", &target); 

result = binarySearch(arr, n, target); 
 
if (result != -1) { 
printf("Element %d found at index %d.\n", target, result); 
} else { 
printf("Element %d not found in the array.\n", target); 
} 
return 0; 
} 
