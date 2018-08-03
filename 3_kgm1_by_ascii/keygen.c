#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char rand_char()
{
        // printable charater 32..126
        return 32 + rand() % (126 - 32 + 1);
}

void rand_key(int key[])
{
        for (int i = 0; i < 8; ++i) {
                key[i] = rand_char();
        }
}

// check if key is correct
int check_key(int key[])
{
        int arr_8049708[] = {0x45, 0x36, 0xab, 0xc8, 0xcc, 0x11, 0xe3, 0x7a};
        key[8] = 0;
        for (int i = 0; i < 8; ++i) {
                key[8] += key[i] ^ arr_8049708[i];
        }
        key[8] &= 0xFF;
        if (key[8] <= 0x7a && key[8] >= 0x61)
                return 1;
        return 0;
}

void print_key(int key[])
{
        for (int i = 0; i < 9; ++i) {
                printf("%c", key[i]);
        }
        printf("\n");
}

int main()
{
        srand(time(NULL));

        int key[9];
        do {
                rand_key(key);
        } while (check_key(key) == 0);

        print_key(key);
        return 0;
}
