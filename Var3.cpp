//2440051574 - Jason Leonardo Sutioso
#include <stdio.h>

int main()
{
    int in, pr = 0, pr2 = 1;

    scanf("%d", &in);

    for(int i = 0; i < in; ++i){

        for(int j = pr; j < in - 1; ++j)
            printf("-");

        for(int j = 0; j < pr2; ++j)
            printf("*");

        for(int j = pr; j < in - 1; ++j)
            printf("-");

        pr++;
        pr2 += 2;
        printf("\n");
    }

    int pr3 = 1, pr4 = in * 2 - 3;

    for(int i = 0; i < in - 1; ++i)
    {
        for(int j = 0; j < pr3; ++j)
            printf("-");
        for(int j = 0; j < pr4; ++j)
            printf("*");
        for(int j = 0; j < pr3; ++j)
            printf("-");

        pr3++;
        pr4-=2;

        printf("\n");
    }
}