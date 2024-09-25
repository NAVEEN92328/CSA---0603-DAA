#include <stdio.h>
#include <math.h>
int isPrime(int num, int i) {
    if (i == 1) {
        return 1; 
    } else {
        if (num % i == 0 && i != num) {
            return 0; 
        } else {
            return isPrime(num, i - 1); 
        }
    }
}
void generatePrimes(int current, int limit) {
    if (current <= limit) {
        if (isPrime(current, (int)sqrt(current))) {
            printf("%d ", current);
        }
        generatePrimes(current + 1, limit);
    }
}

int main() {
    int limit;

    printf("Enter the limit to generate prime numbers: ");
    scanf("%d", &limit);

    printf("Prime numbers up to %d are: ", limit);
    generatePrimes(2, limit);

    return 0;
}
