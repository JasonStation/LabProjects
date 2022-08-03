#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minPage = 0, maxPage = 20;

int money = 1000000;

char userName[31], password[51];

int userAccounts = 0;
short flag = 0;

int hasItems[100] = {1, 1, 1, 1, 1};
int nums[100];
char gameName[100][31] =
{
    "Genshine Impact", "BlockCraft 3D", "Counter Streak", "Crossing Animal", "Super Weird Bros"
};
char genre[100][16] =
{
    "RPG", "FPS", "Shooter", "Casual", "PvP"
};
int quan[100] = {2, 5, 7, 3, 3};

int year[100] = {2020, 2009, 2012, 2020, 2018};

int price[100] = {0, 379000, 99000, 799000, 799000};

char user[100][21] =
{
    "WeebMaster420", "XxProPvPz2010xX", "CSGOLotto", "Tom Nook", "SteveInSmash21"
};

int items = 5;

char ph;

void bubbleSortYear()
{
    for(int i = 0; i < items; ++i)
    {
        int temp, temp4, temp5;
        char temp2[31], temp3[16], temp6[21];
        short con = 0;

        for(int j = 0; j < items - 1; ++j)
        {
            if(year[j] > year[j + 1])
            {
                temp = year[j];
                year[j] = year[j + 1];
                year[j + 1] = temp;

                strcpy(temp2, gameName[j]);
                strcpy(gameName[j], gameName[j + 1]);
                strcpy(gameName[j + 1], temp2);

                strcpy(temp3, genre[j]);
                strcpy(genre[j], genre[j + 1]);
                strcpy(genre[j + 1], temp3);

                temp4 = quan[j];
                quan[j] = quan[j + 1];
                quan[j + 1] = temp4;

                temp5 = price[j];
                price[j] = price[j + 1];
                price[j + 1] = temp5;

                strcpy(temp6, user[j]);
                strcpy(user[j], user[j + 1]);
                strcpy(user[j + 1], temp6);
                con = 1;
            }

            if(con == 0) break;
        }
    }
}

void shop()
{
    while(1){
        system("cls");
        printf("No.|");
        char gameNameCat[] = "Game name";
        char genreCat[] = "Genre";
        char quanCat[] = "Quantity";
        char yearCat[] = "Year";
        char priceCat[] = "Price";
        char userCat[] = "User name";
        printf(" %-30s | %-10s | %-10s| %-10s | %-10s | %-20s\n",
               gameNameCat, genreCat, quanCat, yearCat, priceCat, userCat);

        for(int i = 0; i < 105; ++i) printf("-");

        printf("\n");

        for(int i = minPage; i < maxPage; ++i)
        {
            printf("%2d | %-30s | %-10s | %-10d| %-10d | %-10d | %-20s\n",
               i + 1, gameName[i], genre[i], quan[i], year[i], price[i], user[i]);
        }

        printf("\nMoney: %d\n", money);
        printf("\nWhat would you like to do?\n");
        printf("1. Prev\n");
        printf("2. Next\n");
        printf("3. Sort\n");
        printf("4. Buy\n");
        printf("5. Back\n\nEnter >> ");

        char in;

        scanf("%c", &in);

        if(in == '1')
        {
            if(minPage >= 20)
                minPage -= 20, maxPage -= 20;
        }

        if(in == '2')
        {
            if(maxPage < 100)
                minPage += 20, maxPage += 20;
        }

        if(in == '3')
        {
            bubbleSortYear();
        }
        if(in == '4')
        {
            printf("\nInput game code [1 - %d] >> ", items);
            int in2;
            scanf("%d", &in2);
            printf("[%s] How many to buy (1 - %d) >> ", gameName[in2 - 1], quan[in2 - 1]);
            int in3;
            scanf("%d", &in3);
            if(in3 > quan[in2 - 1])
            {
                printf("\nThe store doesn't have that much in stock. >> ");
                scanf(" %c", &ph);
            }
            else if(in3 <= 0)
            {
                printf("\nYou can't buy in that amount, silly. >> ");
                scanf(" %c", &ph);
            }
            else if(money >= in3 * price[in2 - 1])
            {
                money -= (in3 * price[in2 - 1]);
                printf("\nYou have successfully bought %d %s! >> ", in3, gameName[in2 - 1]);
                scanf(" %c", &ph);
                quan[in2 - 1] -= in3;
                hasItems[in2 - 1] = 0;
            }
            else if(money < in3 * price[in2 - 1])
            {
                printf("\nSorry, but you can't afford that! >> ");
                scanf(" %c", &ph);
            }

            if(quan[in2 - 1] <= 0)
            {
                strcpy(gameName[in2 - 1], "");
                strcpy(genre[in2 - 1], "");
                quan[in2 - 1] = 0;
                year[in2 - 1] = 0;
                price[in2 - 1] = 0;
                strcpy(user[in2 - 1], "");
            }
        }
        if(in == '5') break;
    }
}

void sellGame()
{
    while(1){
        system("cls");
        printf("Hello, %s!\n====================\n", userName);
        printf("[Sell Games]\n");
        printf("1. Sell a game\n2. Add stock\n3. Back\n\nEnter >> ");
        char in;
        scanf(" %c", &in);

        if(in == '1')
        {
            printf("Enter game name >> ");
            scanf(" %[^\n]", gameName[items]);
            printf("Enter genre >> ");
            scanf(" %s", genre[items]);
            printf("Enter quantity >> ");
            scanf("%d", &quan[items]);
            while(quan[items] <= 0)
            {
                printf("Invalid quantity! >> ");
                scanf("%d", &quan[items]);
            }
            printf("Enter game year >> ");
            scanf("%d", &year[items]);
            printf("Enter game price >> ");
            scanf("%d", &price[items]);
            while(price < 0)
            {
                printf("Invalid price! >> ");
                scanf("%d", &price[items]);
            }
            hasItems[items] = 1;
            items++;
        }
        if(in == '2')
        {
            printf("Enter your game code >> ");
            int in2;
            scanf("%d", &in2);
            if(in2 <= 5 || in2 > items)
            {
                printf("That is not your game >> ");
                scanf(" %c", &ph);
            }
            else
            {
                printf("Stock to add to %s >> ", gameName[in2 - 1]);
                int in3;
                scanf("%d", &in2);
                quan[in2 - 1] += in3;
                printf("%d stock added to %s >> ", in3, gameName[in2 - 1]);
                scanf(" %c", &ph);
            }
        }
        if(in == '3') break;
    }

}

void selectionMenu()
{
    while(1){
        system("cls");
        printf("Hello, %s!\n====================\n", userName);
        printf("What would you like to do?\n");
        printf("1. Game store\n2. Sell game\n3. Back\n\nEnter >> ");
        char in;
        scanf(" %c", &in);
        if(in == '1') shop();
        if(in == '2') sellGame();
        if(in == '3') break;
    }
}

void mainMenu()
{
    while(1){
        system("cls");
        printf("T042 - Jason Leonardo Sutioso\nNIM: 244005174\n\n");
        printf("Welcome to gamestore.co!\n==============================\n");
        printf("1. Login\n2. Register\n3. Quit\n\nEnter >> ");
        char in;
        scanf(" %c", &in);
        if(in == '1')
        {
            char uIn[31], pasIn[51];
            printf("\n[LOG IN]\n");
            printf("Username >> ");
            scanf(" %[^\n]", uIn);
            printf("Password >> ");
            scanf(" %[^\n]", pasIn);

            if(strcmp(uIn, userName) == 0 && strcmp(pasIn, password) == 0){
                selectionMenu();
            }
            else
            {
                printf("\nIncorrect user name or password! >> ");
                scanf(" %c", &ph);
            }
        }
        if(in == '2')
        {
                if(flag == 1)
                {
                    printf("\nSorry only 1 account per device. >> ");
                    scanf(" %c", &ph);
                }
                if(flag == 0){
                    printf("\n[REGISTER]\nUsername >> ");
                    scanf(" %[^\n]", userName);
                    while(strlen(userName) < 4)
                    {
                        printf("Sorry, user name needs to be at least 4 characters.\nUsername >> ");
                        scanf(" %[^\n]", userName);
                    }
                    printf("Password >> ");
                    scanf(" %[^\n]", password);
                    while(strlen(password) < 4)
                    {
                        printf("Sorry, password needs to be at least 4 characters.\nPassword >> ");
                        scanf(" %[^\n]", password);
                    }
                    printf("\nAccount has been successfully created. >> ");
                    scanf(" %c", &ph);
                    flag = 1;
            }
        }
        if(in == '3') break;
    }
}

void execute()
{
    mainMenu();
}

int main()
{
    execute();
}
