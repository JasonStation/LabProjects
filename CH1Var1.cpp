
#include <stdio.h>
#include <string.h>

int main()
{
    int T;

    scanf("%d", &T);

    char str[201], str2[201];

    for(int i = 0; i < T; ++i)
    {
        short flag = 0, flag2 = 0, flag3 = 0;

        scanf(" %[^\n]", str);

        strcpy(str2, str);


      for(int i = 0; str[i] != '\0'; ++i){
            if(str[i] >= 97 && str[i] <= 122)
                str[i] -= 32;

        }

        int firstLetter = str[0];


        int index = 1;

        while(str[index] != '\0')
        {
            flag = 0;

            if(str[index] == 32){
                flag = 1;
                flag2 = 1;
                flag3 = 1;
            }

            if(flag == 1 && flag3 == 1 && str[index + 1] == firstLetter) flag2 = 1;
            else if(flag == 1 && flag3 == 1 && str[index + 1] != firstLetter){
                    flag2 = 0;
                    break;
            }
            index++;
        }

        if(flag3 == 0)
            printf("Case #%d: %s [SKIP]\n", i + 1, str2);
        else if(flag2 == 1)
            printf("Case #%d: %s [SAME]\n", i + 1, str2);
        else
            printf("Case #%d: %s [NOT SAME]\n", i + 1, str2);

    }

    return 0;
}