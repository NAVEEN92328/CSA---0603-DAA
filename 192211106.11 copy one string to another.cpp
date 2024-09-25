#include <stdio.h> 
#include <string.h> 
int main() { 
char source[100], destination[100]; 

printf("Enter the source string: "); 
fgets(source, sizeof(source), stdin); 

source[strcspn(source, "\n")] = '\0'; 

strcpy(destination, source); 

printf("Destination string: %s\n", destination); 
return 0; 
}
