#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * is_prime - Checks if a number is prime.
 * @number: The number to check.
 *
 * Return: 1 if prime, 0 otherwise.
 */
int is_prime(int number)
{
int i;

if (number < 2)
{return (0); }

for (i = 2; i <= sqrt(number); i++)
{
if (number % i == 0)
{return (0); }
}

return (1);
}

/**
 * factorize_rsa_number - Factorizes an RSA number into prime factors.
 * @number: The RSA number to factorize.
 * @p: Pointer to store the first prime factor.
 * @q: Pointer to store the second prime factor.
 *
 * Return: 1 if successful, 0 otherwise.
 */
int factorize_rsa_number(int number, int *p, int *q)
{
int i;

for (i = 2; i <= sqrt(number); i++)
{
if (number % i == 0 && is_prime(i) && is_prime(number / i))
{
*p = i;
*q = number / i;
return (1);
}
}

return (0);
}

/**
 * factorize_file - Reads a file containing an RSA number and factorizes it.
 * @file_path: The path to the file containing the RSA number.
 */
void factorize_file(const char *file_path)
{
int p, q;
int number;
FILE *file = fopen(file_path, "r");
if (file == NULL)
{
printf("Failed to open the file.\n");
return;
}

if (fscanf(file, "%d", &number) != 1)
{
printf("Invalid file format.\n");
fclose(file);
return;
}


if (factorize_rsa_number(number, &p, &q))
{printf("%d=%d*%d\n", number, p, q); }
else
{printf("Unable to factorize %d into prime numbers.\n", number); }

fclose(file);
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: Array of command-line arguments.
 *
 * Return: 0 on success, 1 on failure.
 */
int main(int argc, char *argv[])
{
const char *file_path = argv[1];
if (argc < 2)
{
printf("Usage: ./rsa <file>\n");
return (1);
}

factorize_file(file_path);

return (0);
}