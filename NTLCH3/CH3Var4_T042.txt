#include <stdio.h>

int main()
{
    int T;

    scanf("%d", &T);

    char chr[T + 1][11];

    for(int i = 0; i < T; ++i)
    {
        for(int j = 0; j < 10; ++j)
            scanf("%c", &chr[i][j]);
    }

    short flag[T];

    for(int i = 0; i < T; ++i)
    {
        for(int j = 0; j < 10; ++j)
        {
            if(chr[i][j] == 'X'){
                flag[i] = 1;
            }
        }
    }

    for(int i = 0; i < T; ++i)
    {
        for(int j = 0; j < 10; ++j)
        {
            if(chr[i][j] == '.' && flag[i] == 1)
                chr[i][j] = 'X';
            printf("%c", chr[i][j]);
        }
    }


    printf("\n");

    return 0;
}