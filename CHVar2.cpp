#include <stdio.h>

int main()
{
    char adv[1001];

    scanf("%s", adv);

    int books = 0, money = 0, diamonds = 0, temp;
    int recent[1001], fail = 0, index = 0;

    for(int i = 0; adv[i] != '\0'; ++i)
    {

        if(adv[i] == '#')
        {
            books++;
            recent[index] = 0;
            index++;
        }
        else if(adv[i] == '$')
        {
            money++;
            recent[index] = 1;
            index++;
        }
        else if(adv[i] == '@')
        {
            diamonds++;
            recent[index] = 2;
            index++;
        }

        else if(adv[i] == 'G' && books >= 1 && recent[index] == 0){
            books--;
        }
        else if(adv[i] == 'B' && money >= 1 && recent[index] == 1){
            money--;
        }
        else if(adv[i] == 'W' && diamonds >= 1 && recent[index] == 2){
            diamonds--;
        }else if(adv[i] == '|'){
            if(recent[index - 1] == 0) books--;
            else if(recent[index - 1] == 1) money--;
            else if(recent[index - 1] == 2) diamonds--;
            index--;
            printf("AH: %d\n", recent[index]);
        }
        else if(adv[i] == '_' || adv[i] == '@' || adv[i] == '$' || adv[i] == '#'){

        }else{
            fail = 1;
            break;
        }

        printf("\n%d %d %d\n", books, money, diamonds);
        if(adv[index + 1] == '\0' && diamonds >= 1){
            fail = 0;
            break;
        }

    }

    if(fail == 0) printf("Ian gets the diamond an escapes the place.\n");
    else printf("Ian failed, the adventure is over.\n");
}