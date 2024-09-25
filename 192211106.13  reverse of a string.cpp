#include <stdio.h> 
#include <string.h> 
 
void printReverse(char str[]) { 
int length = strlen(str); 
for (int i = length - 1; i >= 0; i--) { 
printf("%c", str[i]); 
} 
printf("\n"); 
} 
int main() { 
char str[100]; 

printf("Enter a string: "); 
fgets(str, sizeof(str), stdin); 
 
str[strcspn(str, "\n")] = '\0'; 
 
printf("Reversed string: "); 
printReverse(str); 
return 0; 
}
