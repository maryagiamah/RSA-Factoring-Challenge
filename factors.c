#include <stdio.h>
#include <stdlib.h>

/**
* factorize - finds the factor of and prints them
* @n - number to factorize 
*
* Return: Pairs of factors of n
*/
void factorize(unsigned long int n)
{
	 unsigned long int i;
	for (i = 2; i <= n; i++)
	{
		while (n % i == 0)
		{
			printf("%lu=%lu*%lu\n", n, n / i, i);
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
        unsigned long int num = atoi(buffer);
        factorize(num);
    }

    fclose(file);
    return 0;
}
