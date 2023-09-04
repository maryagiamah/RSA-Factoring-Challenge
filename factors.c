#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long int ullong;

ullong my_atoi(const char *str) {
    ullong result = 0;
    int sign = 1; // Default positive sign

    if (*str == '-') {
        sign = -1;
        str++;
    }

    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }

    return result * sign;
}

/**
* factorize - finds the factor of and prints them
* @n - number to factorize 
*
* Return: Pairs of factors of n
*/
void factorize(unsigned long long int n)
{
	 unsigned long long int i;
	for (i = 2; i <= n; i++)
	{
		while (n % i == 0)
		{
			printf("%llu=%llu*%llu\n", n, n / i, i);
			return;
		}
	}
}
/**
* main - start of the program 
* @argv- array that contains command line argument 
* @argc - no of command line argument 
* Return: 0 on Success
*/
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Usage: %s <file>\n", argv[0]);
		return 1;
	}

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file)) 
    {
        unsigned long long int num = my_atoi(buffer);
        factorize(num);
    }

    fclose(file);
    return 0;
}
