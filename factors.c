#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * factorize_number - Factorizes a number into two smaller numbers.
 * @number: The number to factorize.
 */
void factorize_number(int number)
{
int i;

for (i = 2; i <= sqrt(number); i++)
{
while (number % i == 0)
{
printf("%d=%d*%d\n", number, i, number / i);
number /= i;
}
}

if (number > 1)
{printf("%d=%d*%d\n", number, number, 1); }
}

/**
 * factorize_file - Reads a file of numbers and factorizes each number.
 * @file_path: The path to the file containing the numbers.
 */
void factorize_file(const char *file_path)
{
int number;
FILE *file = fopen(file_path, "r");
if (file == NULL)
{
printf("Failed to open the file.\n");
return;
}

while (fscanf(file, "%d", &number) == 1)
{factorize_number(number); }

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
printf("Usage: ./factors <file>\n");
return (1);
}

factorize_file(file_path);

return (0);
}
