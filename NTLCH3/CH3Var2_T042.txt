#include <stdio.h>

int main()
{
    int T;
    char chr[101];

    scanf("%d", &T);

    for(int i = 0; i < T; ++i)
    {
        int length = 0;
        scanf("%s", chr);
        for(int j = 0; chr[j] != '\0'; ++j)
            length++;
        printf("%s %d\n", chr, length);
    }

    return 0;
}