#include <stdio.h> 
 
int sumOfDigits(int num) { 
int sum = 0; 
while (num != 0) { 
sum += num % 10;  
num /= 10;        
} 
return sum; 
} 
int main() { 
int number; 
 
printf("Enter a number: "); 
scanf("%d", &number); 
 
if (number < 0) { 
} 
number = number; 
 
int result = sumOfDigits(number); 
printf("The sum of digits is: %d\n", result); 
return 0; 
} 
