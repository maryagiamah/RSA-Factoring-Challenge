#include <stdio.h>
#include <stdlib.h>

void factorize(int n) {
    for (int i = 2; i <= n; i++) {
        while (n % i == 0) {
            printf("%d=%d*%d\n", n, i, n / i);
            return;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file)) {
        unsigned long int num = atoi(buffer);
        factorize(num);
    }

    fclose(file);
    return 0;
}
