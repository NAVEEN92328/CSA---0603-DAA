#include <stdio.h> 
#include <string.h> 
int main() { 
char str[100]; 
 
printf("Enter a string: "); 
fgets(str, sizeof(str), stdin); 
 
str[strcspn(str, "\n")] = '\0'; 
 
int length = strlen(str); 

printf("Length of the string: %d\n", length); 
return 0; 
} 
