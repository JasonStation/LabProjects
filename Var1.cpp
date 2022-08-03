#include <stdio.h>

//2440051574 - Jason Leonardo Sutioso

void solve()
{
    int type, n, most[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    char qual;

    scanf("%d", &n);

    for(int i = 0; i < n; ++i)
    {
        scanf("%d %c", &type, &qual);

        if(qual == 'N')
            most[type - 1]++;
    }

    int largest = most[0];

    for(int i = 0; i < 10; ++i)
        if(most[i] > largest) largest = i + 1;


    printf("%d", largest);
}

int main()
{
    solve();
}