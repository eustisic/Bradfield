#include<stdio.h>
int main() {
	long int decimalNumber;
	printf("Enter any decimal number: ");
	scanf("%ld",&decimalNumber);
	printf("Equivalent hexadecimal number is: %lX",decimalNumber);
	return 0;
}