#include <stdio.h>

int main()
{
    char chr[101], length = 0;

    scanf("%s", chr);

    for(int i = 0; chr[i] != '\0'; ++i)
        length++;

    for(int i = 0; i < length; ++i)
    {
        for(int j = 0; j < length - i; ++j){
            for(int k = j; k < j + i + 1; ++k)
                printf("%c", chr[k]);
            printf("\n");
        }
    }

    return 0;
}