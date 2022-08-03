#include <stdio.h>

int main()
{
    int T;

    scanf("%d", &T);

    for(int i = 0; i < T; ++i)
    {
        int start = 1;

        printf("1 ");

        for(int j = 1; j < i; ++j)
        {
            start = start * (i - j + 1) / j;
            printf("%d ", start);
        }

        if(i >= 1)
            printf("1\n");
        else
            printf("\n");
    }
}