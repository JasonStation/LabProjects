#include <stdio.h>

int main()
{
    int dim;

    scanf("%d", &dim);

    for(int i = 0; i < 5 * dim; ++i)
        if(i == 5 * dim / 2)
            printf("*");
        else printf(" ");
    printf("\n");
    int counter = 1;

    for(int i = 0; i < dim - 1; ++i)
    {
        if(i % 2 != 0){
        for(int j = 0; j < dim * 2 + 1 - counter; ++j)
            printf(" ");
        printf("*");
        for(int j = 0; j < counter * 2 + 1; ++j)
            printf(" ");
        printf("*");
        printf("\n");
        counter += 2;
        }else printf("\n");
    }

    for(int i = 0; i < dim - 1; ++i)
        printf(" ");

    for(int i = 0; i < 5 * dim - (dim - 1) * 2; ++i)
        printf("*");

    int counter2 = 0;
    printf("\n");

    for(int i = 0; i < dim / 2; ++i)
    {
        for(int j = 0; j < dim - 1 - counter2; ++j)
            printf(" ");
        printf("*");
        for(int j = 0; j < counter2; ++j)
            printf(" ");
        printf("*");
        for(int j = 0; j < 3 * dim; ++j)
            printf(" ");
        printf("*");
        for(int j = 0; j < counter2; ++j)
            printf(" ");
        printf("*");
        printf("\n");
        counter2++;

    }
    printf("  ");
    for(int i = 2; i < 5 * dim; ++i)
        printf("*");

    printf("\n");

    int counter3 = 0;


    for(int i = 0; i < dim - 2; ++i)
    {
        for(int j = 0; j < dim * 2 - 1 + (counter3 / 2); ++j)
            printf(" ");
        printf("*");

        for(int j = 0; j < dim - counter3; ++j)
            printf(" ");
        printf("*");
        counter3 += 2;
        printf("\n");
    }


    for(int i = 0; i < 5 * dim / 2; ++i)
        printf(" ");
    printf("*\n");

    printf("\n");
}