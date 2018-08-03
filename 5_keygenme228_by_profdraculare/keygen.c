#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char rand_char()
{
        // printable charater 32..126
        return 32 + rand() % (126 - 32 + 1);
}

void rand_key(int key[], int len)
{
        for (int i = 0; i < len; ++i) {
                key[i] = rand_char();
        }
}

int check_key(int key[], int len)
{
        int correct = 1;
        for (int i = 0; i < len - 1; ++i) {
                if (key[i] - key[i + 1] > 0) {
                        correct = 0;
                        break;
                }
        }
        if (correct != 0)
                return correct;

        correct = -1;
        for (int i = len - 2; i > 0; --i) {
                if (key[i] - key[i + 1] < 0) {
                        correct = 0;
                        break;
                }
        }
        return correct;
}

void print_key(int key[], int len)
{
        for (int i = 0; i < len; ++i) {
                printf("%c", key[i]);
        }
        printf("\n");
}

int main()
{
        srand(time(NULL));
        printf("Input length: ");
        int len;
        scanf("%d", &len);
        if (len <= 2) {
                printf("length must greater than 2\n");
                return 0;
        }

        int *key = malloc(len * sizeof(int));
        do {
                rand_key(key, len);
        } while (check_key(key, len) == 0);
        print_key(key, len);
        free(key);

        return 0;
}
