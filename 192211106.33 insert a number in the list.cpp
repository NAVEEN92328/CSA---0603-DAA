#include <stdio.h> 
#define MAX 100 // Define the maximum size of the list 
// Function to insert a number into the list at a specific position 
void insertNumber(int list[], int *size, int number, int position) { 
// Check if the position is valid 
if (position < 0 || position > *size) { 
printf("Invalid position!\n"); 
return; 
} 
// Check if the list has enough space 
if (*size >= MAX) { 
printf("List is full!\n"); 
return; 
} 
// Shift elements to the right to make space for the new number 
for (int i = *size; i > position; i--) { 
list[i] = list[i - 1]; 
} 
// Insert the new number at the specified position 
list[position] = number; 
// Update the size of the list 
(*size)++; 
} 
// Function to print the list 
void printList(int list[], int size) { 
printf("List elements are:\n"); 
for (int i = 0; i < size; i++) { 
printf("%d ", list[i]); 
} 
printf("\n"); 
} 
int main() { 
int list[MAX]; 
int size = 0; // Current number of elements in the list 
int number, position; 
// Input: number of elements in the list 
printf("Enter the number of initial elements in the list: "); 
scanf("%d", &size); 
// Input: elements of the list 
printf("Enter the elements of the list:\n"); 
for (int i = 0; i < size; i++) { 
scanf("%d", &list[i]); 
} 
// Input: number to insert and the position 
printf("Enter the number to insert: "); 
scanf("%d", &number); 
printf("Enter the position to insert the number at (0-based index): "); 
scanf("%d", &position); 
// Insert the number into the list 
insertNumber(list, &size, number, position); 
// Print the updated list 
printList(list, size); 
return 0; 
} 
