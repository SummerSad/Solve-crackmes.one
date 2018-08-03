#include <stdio.h>

int main()
{
        char key[] = "QTBXCTU";
        for (int i = 0; key[i] != '\0'; ++i) {
                key[i] ^= 0x21;
        }
        printf("%s\n", key);
        return 0;
}
