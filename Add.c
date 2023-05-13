#include "simple_shell.h"

/**
 * main - main entry
 *
 * Return: Always 0
 */

int main(void)
{
	unsigned int numb1, numb2, sum;

	printf("Enter the first number: ");
	scanf("%u", &numb1);

	printf("Enter the second number: ");
	scanf("%u", &numb2);

	sum = numb1 + numb2;

	printf("The sum of %u and %u is %u\n", numb1, numb2, sum);

	return (0);
}
