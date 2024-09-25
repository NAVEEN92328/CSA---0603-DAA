#include <stdio.h> 
 
void printPattern(int n) { 
    for (int i = 1; i <= n; i++) { 
     
        for (int j = 0; j < n - i; j++) { 
            printf(" "); 
        } 
    
        for (int k = 1; k <= i; k++) { 
            printf("%d ", k); 
        } 
        printf("\n"); 
    } 
} 
 
int main() { 
    int n; 
 
    printf("Enter the number of rows (n): "); 
    scanf("%d", &n); 
 
    printPattern(n); 
 
    return 0; 
} 
