#include <stdio.h>
#include <ctime>
#include <stdlib.h>
#include <string.h>

short diceControl = 0; //All players are able to control the dice value if set to 1.

char format[2] = "";
char ownedBy[31][3] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "",
"", "", "", "", "", "", "", "", "", "", "", "", "", ""};
char ic1 = '#', ic2 = '$', ic3 = '%', ic4 = '&';
char p1[31], p2[31], p3[31], p4[31];
int coord1 = 0, coord2 = 0, coord3 = 0, coord4 = 0;
char cityNames[31][16] =
{
    //Cities 1-8
    "GO!--->", "Flores", "Free", "Borneo", "Madagascar", "Baffin", "Sumatra", "Jail",
    //Cities 9-16
    "Chance Card", "Sulawesi", "Java", "Luzon", "Kotelny", "Sumba", "Festival", "Cuba",
    //Cities 19 - 28
    "Chance Card", "Tasmania", "Ireland", "Hokkaido", "Sri Lanka", "Travel", "Hawaii",
    "Iceland", "Sicily", "Maldives", "Tax", "Shikoku"

};
int turn = 0, tempDice = 0;
int money1 = 1000, money2 = 1000, money3 = 1000, money4 = 1000;
char name1[31] = "Player 1", name2[31] = "Player 2", name3[31] = "Player 3", name4[31] = "Player 4";
short playersInGame = 4;
char lastPlayer[31] = "No one";
int lastDice = 0;
char ph;
short lotIsOwned[30] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0};
short gameOver = 0;
short lotMult[30] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
int rentFormula = 15 * 1.1;
short hasAngel[4] = {0, 0, 0, 0};
short jailTime[4] = {0, 0, 0, 0};

void board();

void setup()
{
    for(int i = 0; i < 30; ++i)
    {
        p1[i] = ' ';
        p2[i] = ' ';
        p3[i] = ' ';
        p4[i] = ' ';
    }
}

void buyLot(int playerID, int coord)
{
    int price = coord * 10 * 1.1;
    char in = ' ';
    if(lotIsOwned[coord] == 0 && strcmp(cityNames[coord], "Free") != 0 && strcmp(cityNames[coord], "Jail") != 0 && strcmp(cityNames[coord], "Tax")
      && strcmp(cityNames[coord], "Festival") != 0 && strcmp(cityNames[coord], "Travel") != 0 && strcmp(cityNames[coord], "GO!--->") != 0 && strcmp(cityNames[coord], "Chance Card")){
        if(playerID == 1)
        {
            if(money1 >= price){
                printf("[%s] Do you want to buy %s for %dK?\n", name1, cityNames[coord], price);
                printf("[y] Yes [Other] No\nEnter >> ");
                scanf(" %c", &in);
                if(in == 'y')
                {
                    money1 -= price;
                    strcpy(ownedBy[coord], "P1");
                    lotIsOwned[coord] = 1;
                }
            }
            else{
                printf("You don't have enough money to buy %s. Cost: $%dK\nType in any key to continue >> ", cityNames[coord], price);
                scanf(" %c", &ph);
            }
        }
        else if(playerID == 2)
        {
            if(money2 >= price){
                printf("[%s] Do you want to buy %s for %dK?\n", name2, cityNames[coord], price);
                printf("[y] Yes [Other] No\nEnter >> ");
                scanf(" %c", &in);
                if(in == 'y')
                {
                    money2 -= price;
                    strcpy(ownedBy[coord], "P2");
                    lotIsOwned[coord] = 2;
                }
            }
            else{
                printf("You don't have enough money to buy %s. Cost: $%dK\nType in any key to continue >> ", cityNames[coord], price);
                scanf(" %c", &ph);
            }
        }
        else if(playerID == 3)
        {
            if(money3 >= price){
                printf("[%s] Do you want to buy %s for %dK?\n", name3, cityNames[coord], price);
                printf("[y] Yes [Other] No\nEnter >> ");
                scanf(" %c", &in);
                if(in == 'y')
                {
                    money3 -= price;
                    strcpy(ownedBy[coord], "P3");
                    lotIsOwned[coord] = 3;
                }
            }
            else{
                printf("You don't have enough money to buy %s. Cost: $%dK\nType in any key to continue >> ", cityNames[coord], price);
                scanf(" %c", &ph);
            }
        }
        else if(playerID == 4)
        {
            if(money4 >= price){
                printf("[%s] Do you want to buy %s for %dK?\n", name4, cityNames[coord], price);
                printf("[y] Yes [Other] No\nEnter >> ");
                scanf(" %c", &in);
                if(in == 'y')
                {
                    money4 -= price;
                    strcpy(ownedBy[coord], "P4");
                    lotIsOwned[coord] = 4;
                }
            }
            else{
                printf("You don't have enough money to buy %s. Cost: $%dK\nType in any key to continue >> ", cityNames[coord], price);
                scanf(" %c", &ph);
            }
        }
}
}

void bankrupt(int playerID, int coord, int owe)
{
    int paid = 0;
    while(1){
        system("cls");
        board();
        int cityWorth = 1 * 10 * 1.1;

        ///player 1
        if(playerID == 1)
        {
            for(int i = 0; i < 28; ++i)
            {
                if(lotIsOwned[i] == 1)
                {
                    printf("%d. %s: %dK\n", i + 1, cityNames[i], cityWorth * (i + 1));
                }
            }
                printf("0. Bankrupt\nLeft to owe: $%dK\nChoose what lot to sell >> ", owe - paid);
                int lotID;
                scanf("%d", &lotID);
                if(lotID <= 0 || lotID > 28){
                    gameOver = 1;
                    money1 = 0;
                    if(lotIsOwned[coord] == 2) money2 += owe;
                    else if(lotIsOwned[coord] == 3) money3 += owe;
                    else if(lotIsOwned[coord] == 4) money4 += owe;
                    break;
                }
                else{
                    lotID--;
                    if(lotIsOwned[lotID] == 1)
                    {
                        printf("Successfully sold %s for %dK! >> ", cityNames[lotID], cityWorth * (lotID + 1));
                        paid += cityWorth * (lotID + 1);
                        lotIsOwned[lotID] = 0;
                        strcpy(ownedBy[lotID], " ");
                        scanf(" %c", &ph);
                    }
                    else
                    {
                        printf("Invalid lot! >> ");
                        scanf(" %c", &ph);
                    }
                }
                if(paid >= owe){
                    printf("Successfully paid rent! >> ");
                    scanf(" %c", &ph);
                    money1 += (paid - owe);
                    if(lotIsOwned[coord] == 2) money2 += owe;
                    else if(lotIsOwned[coord] == 3) money3 += owe;
                    else if(lotIsOwned[coord] == 4) money4 += owe;
                    break;
                }
            }


        ///player 2
        if(playerID == 2)
        {
            for(int i = 0; i < 28; ++i)
            {
                if(lotIsOwned[i] == 2)
                {
                    printf("%d. %s: %dK\n", i + 1, cityNames[i], cityWorth * (i + 1));
                }
            }
                printf("0. Bankrupt\nLeft to owe: $%dK\nChoose what lot to sell >> ", owe - paid);
                int lotID;
                scanf("%d", &lotID);
                if(lotID <= 0 || lotID > 28){
                    gameOver = 1;
                    money2 = 0;
                    if(lotIsOwned[coord] == 1) money1 += owe;
                    else if(lotIsOwned[coord] == 3) money3 += owe;
                    else if(lotIsOwned[coord] == 4) money4 += owe;
                    break;
                }
                else{
                    lotID--;
                    if(lotIsOwned[lotID] == 2)
                    {
                        printf("Successfully sold %s for %dK! >> ", cityNames[lotID], cityWorth * (lotID + 1));
                        paid += cityWorth * (lotID + 1);
                        lotIsOwned[lotID] = 0;
                        strcpy(ownedBy[lotID], " ");
                        scanf(" %c", &ph);
                    }
                    else
                    {
                        printf("Invalid lot! >> ");
                        scanf(" %c", &ph);
                    }
                }
                if(paid >= owe){
                    printf("Successfully paid rent! >> ");
                    scanf(" %c", &ph);
                    money2 += (paid - owe);
                    if(lotIsOwned[coord] == 1) money1 += owe;
                    else if(lotIsOwned[coord] == 3) money3 += owe;
                    else if(lotIsOwned[coord] == 4) money4 += owe;
                    break;
                }
            }



        ///player 3
        if(playerID == 3)
        {
            for(int i = 0; i < 28; ++i)
            {
                if(lotIsOwned[i] == 3)
                {
                    printf("%d. %s: %dK\n", i + 1, cityNames[i], cityWorth * (i + 1));
                }
            }
                printf("0. Bankrupt\nLeft to owe: $%dK\nChoose what lot to sell >> ", owe - paid);
                int lotID;
                scanf("%d", &lotID);
                if(lotID <= 0 || lotID > 28){
                    gameOver = 1;
                    money3 = 0;
                    if(lotIsOwned[coord] == 1) money1 += owe;
                    else if(lotIsOwned[coord] == 2) money2 += owe;
                    else if(lotIsOwned[coord] == 4) money4 += owe;
                    break;
                }
                else{
                    lotID--;
                    if(lotIsOwned[lotID] == 3)
                    {
                        printf("Successfully sold %s for %dK! >> ", cityNames[lotID], cityWorth * (lotID + 1));
                        paid += cityWorth * (lotID + 1);
                        lotIsOwned[lotID] = 0;
                        strcpy(ownedBy[lotID], " ");
                        scanf(" %c", &ph);
                    }
                    else
                    {
                        printf("Invalid lot! >> ");
                        scanf(" %c", &ph);
                    }
                }
                if(paid >= owe){
                    printf("Successfully paid rent! >> ");
                    scanf(" %c", &ph);
                    money3 += (paid - owe);
                    if(lotIsOwned[coord] == 2) money2 += owe;
                    else if(lotIsOwned[coord] == 1) money1 += owe;
                    else if(lotIsOwned[coord] == 4) money4 += owe;
                    break;
                }
            }

        if(playerID == 4)
        {
            for(int i = 0; i < 28; ++i)
            {
                if(lotIsOwned[i] == 4)
                {
                    printf("%d. %s: %dK\n", i + 1, cityNames[i], cityWorth * (i + 1));
                }
            }
                printf("0. Bankrupt\nLeft to owe: $%dK\nChoose what lot to sell >> ", owe - paid);
                int lotID;
                scanf("%d", &lotID);
                if(lotID <= 0 || lotID > 28){
                    gameOver = 1;
                    money4 = 0;
                    if(lotIsOwned[coord] == 1) money1 += owe;
                    else if(lotIsOwned[coord] == 3) money3 += owe;
                    else if(lotIsOwned[coord] == 2) money2 += owe;
                    break;
                }
                else{
                    lotID--;
                    if(lotIsOwned[lotID] == 4)
                    {
                        printf("Successfully sold %s for %dK! >> ", cityNames[lotID], cityWorth * (lotID + 1));
                        paid += cityWorth * (lotID + 1);
                        lotIsOwned[lotID] = 0;
                        strcpy(ownedBy[lotID], " ");
                        scanf(" %c", &ph);
                    }
                    else
                    {
                        printf("Invalid lot! >> ");
                        scanf(" %c", &ph);
                    }
                }
                if(paid >= owe){
                    printf("Successfully paid rent! >> ");
                    scanf(" %c", &ph);
                    money4 += (paid - owe);
                    if(lotIsOwned[coord] == 2) money2 += owe;
                    else if(lotIsOwned[coord] == 3) money3 += owe;
                    else if(lotIsOwned[coord] == 1) money1 += owe;
                    break;
            }
        }
    }
}

void specialLot(int playerID, int coord)
{
    board();
    if(playerID == 1)
    {
        if(strcmp(cityNames[coord], "Travel") == 0)
        {
            int travelCoord;
                printf("[Travel] Welcome to ShangHai Airports! Enter lot ID to travel there.\n");
                printf("[1-28] Travel! [0] Cancel\nEnter >> ");
                scanf("%d", &travelCoord);
                if(travelCoord >= 1 && travelCoord <= 28){
                travelCoord--;
                p1[coord1] = ' ';
                coord1 = travelCoord;
                printf("\n[Travel] You Landed on %s!\n\n", cityNames[coord1]);
            }
        }
        else if(strcmp(cityNames[coord], "Festival") == 0)
        {
            for(int i = 0; i < 28; ++i)
                if(lotIsOwned[i] == 1 && lotMult[i] != 2)
                    printf("%d. %s: %dK -> %dK\n", i + 1, cityNames[i], (i + 1) * rentFormula, (i + 1) * rentFormula * 2);
            printf("0. Cancel\nWhich lot do you want to double the rent fee?\nEnter >> ");
            int lotID;
            scanf("%d", &lotID);
            if(lotIsOwned[lotID] == 1)
                lotMult[lotID] = 2;


        }
        else if(strcmp(cityNames[coord], "Chance Card") == 0)
        {
            srand(time(NULL));
            int chance = rand()%5;
            if(chance == 0){
                hasAngel[0] = 1;
                printf("[Chance Card] You got an angel card! Wow! >> \n");
                scanf(" %c", &ph);
            }
            else{
                printf("[Chance Card] Oof! It looks like you didn't get anything from the chance box! >> ");
                scanf(" %c", &ph);
            }
        }
        else if(strcmp(cityNames[coord], "Tax") == 0)
        {
            int tax = 0.2 * money1;
            printf("[Tax] It's time to pay up! You owe $%dK! >> ", tax);
            scanf(" %c", &ph);
            money1 -= tax;
        }
        else if(strcmp(cityNames[coord], "Jail") == 0)
        {
            jailTime[0] = 3;
            printf("Uh oh! Looks like you landed in Jail! You can't move for 3 turns. >> ");
            scanf(" %c", &ph);
        }
    }
    ///PLAYER 2
    if(playerID == 2)
    {
        if(strcmp(cityNames[coord], "Travel") == 0)
        {
            int travelCoord;
                printf("[Travel] Welcome to ShangHai Airports! Enter lot ID to travel there.\n");
                printf("[1-28] Travel! [0] Cancel\nEnter >> ");
                scanf("%d", &travelCoord);
                if(travelCoord >= 1 && travelCoord <= 28){
                travelCoord--;
                p2[coord2] = ' ';
                coord2 = travelCoord;
                printf("\n[Travel] You Landed on %s!\n\n", cityNames[coord2]);
            }
        }
        else if(strcmp(cityNames[coord], "Festival") == 0)
        {
            for(int i = 0; i < 28; ++i)
                if(lotIsOwned[i] == 2 && lotMult[i] != 2)
                    printf("%d. %s: %dK -> %dK\n", i + 1, cityNames[i], (i + 1) * rentFormula, (i + 1) * rentFormula * 2);
            printf("0. Cancel\nWhich lot do you want to double the rent fee?\nEnter >> ");
            int lotID;
            scanf("%d", &lotID);
            if(lotIsOwned[lotID] == 2)
                lotMult[lotID] = 2;


        }
        else if(strcmp(cityNames[coord], "Chance Card") == 0)
        {
            srand(time(NULL));
            int chance = rand()%5;
            if(chance == 0){
                hasAngel[1] = 1;
                printf("[Chance Card] You got an angel card! Wow! >> \n");
                scanf(" %c", &ph);
            }
            else{
                printf("[Chance Card] Oof! It looks like you didn't get anything from the chance box! >> ");
                scanf(" %c", &ph);
            }
        }
        else if(strcmp(cityNames[coord], "Tax") == 0)
        {
            int tax = 0.2 * money2;
            printf("[Tax] It's time to pay up! You owe $%dK! >> ", tax);
            scanf(" %c", &ph);
            money2 -= tax;
        }
        else if(strcmp(cityNames[coord], "Jail") == 0)
        {
            jailTime[1] = 3;
            printf("Uh oh! Looks like you landed in Jail! You can't move for 3 turns. >> ");
            scanf(" %c", &ph);
        }
    }
    ///PLAYER 3
    if(playerID == 3)
    {
        if(strcmp(cityNames[coord], "Travel") == 0)
        {
            int travelCoord;
                printf("[Travel] Welcome to ShangHai Airports! Enter lot ID to travel there.\n");
                printf("[1-28] Travel! [0] Cancel\nEnter >> ");
                scanf("%d", &travelCoord);
                if(travelCoord >= 1 && travelCoord <= 28){
                travelCoord--;
                p3[coord3] = ' ';
                coord3 = travelCoord;
                printf("\n[Travel] You Landed on %s!\n\n", cityNames[coord3]);
            }
        }
        else if(strcmp(cityNames[coord], "Festival") == 0)
        {
            for(int i = 0; i < 28; ++i)
                if(lotIsOwned[i] == 3 && lotMult[i] != 2)
                    printf("%d. %s: %dK -> %dK\n", i + 1, cityNames[i], (i + 1) * rentFormula, (i + 1) * rentFormula * 2);
            printf("0. Cancel\nWhich lot do you want to double the rent fee?\nEnter >> ");
            int lotID;
            scanf("%d", &lotID);
            if(lotIsOwned[lotID] == 3)
                lotMult[lotID] = 2;


        }
        else if(strcmp(cityNames[coord], "Chance Card") == 0)
        {
            srand(time(NULL));
            int chance = rand()%5;
            if(chance == 0){
                hasAngel[2] = 1;
                printf("[Chance Card] You got an angel card! Wow! >> \n");
                scanf(" %c", &ph);
            }
            else{
                printf("[Chance Card] Oof! It looks like you didn't get anything from the chance box! >> ");
                scanf(" %c", &ph);
            }
        }
        else if(strcmp(cityNames[coord], "Tax") == 0)
        {
            int tax = 0.2 * money3;
            printf("[Tax] It's time to pay up! You owe $%dK! >> ", tax);
            scanf(" %c", &ph);
            money3 -= tax;
        }
        else if(strcmp(cityNames[coord], "Jail") == 0)
        {
            jailTime[2] = 3;
            printf("Uh oh! Looks like you landed in Jail! You can't move for 3 turns. >> ");
            scanf(" %c", &ph);
        }
    }
    if(playerID == 4)
    {
        if(strcmp(cityNames[coord], "Travel") == 0)
        {
            int travelCoord;
                printf("[Travel] Welcome to ShangHai Airports! Enter lot ID to travel there.\n");
                printf("[1-28] Travel! [0] Cancel\nEnter >> ");
                scanf("%d", &travelCoord);
                if(travelCoord >= 1 && travelCoord <= 28){
                travelCoord--;
                p4[coord4] = ' ';
                coord4 = travelCoord;
                printf("\n[Travel] You Landed on %s!\n\n", cityNames[coord4]);
            }
        }
        else if(strcmp(cityNames[coord], "Festival") == 0)
        {
            for(int i = 0; i < 28; ++i)
                if(lotIsOwned[i] == 4 && lotMult[i] != 2)
                    printf("%d. %s: %dK -> %dK\n", i + 1, cityNames[i], (i + 1) * rentFormula, (i + 1) * rentFormula * 2);
            printf("0. Cancel\nWhich lot do you want to double the rent fee?\nEnter >> ");
            int lotID;
            scanf("%d", &lotID);
            if(lotIsOwned[lotID] == 4)
                lotMult[lotID] = 2;


        }
        else if(strcmp(cityNames[coord], "Chance Card") == 0)
        {
            srand(time(NULL));
            int chance = rand()%5;
            if(chance == 0){
                hasAngel[3] = 1;
                printf("[Chance Card] You got an angel card! Wow! >> \n");
                scanf(" %c", &ph);
            }
            else{
                printf("[Chance Card] Oof! It looks like you didn't get anything from the chance box! >> ");
                scanf(" %c", &ph);
            }
        }
        else if(strcmp(cityNames[coord], "Tax") == 0)
        {
            int tax = 0.2 * money4;
            printf("[Tax] It's time to pay up! You owe $%dK! >> ", tax);
            scanf(" %c", &ph);
            money4 -= tax;
        }
        else if(strcmp(cityNames[coord], "Jail") == 0)
        {
            jailTime[3] = 3;
            printf("Uh oh! Looks like you landed in Jail! You can't move for 3 turns. >> ");
            scanf(" %c", &ph);
        }
    }
}

void lotAct(int playerID, int coord)
{
    short skip = 0;
    char inp = ' ';

    if(lotIsOwned[coord] != 0 && lotIsOwned[coord] != playerID){
        for(int i = 0; i < 4; ++i){
            if(playerID == i + 1 && hasAngel[i] == 1)
            {
                printf("Use Angel Card to avoid rent fee? [y] Yes [Other] No\n");
                printf("Enter >> ");
                scanf(" %c", &inp);
                if(inp == 'y'){
                    skip = 1;
                    hasAngel[i] = 0;
                }
            }
        }
    }

    if(lotIsOwned[coord] != 0 && skip == 0){
        int payFee = coord * rentFormula * lotMult[coord];

        if(playerID == 1)
        {
            if(lotIsOwned[coord] != 1)
            {
                if(money1 >= payFee)
                {
                    if(lotIsOwned[coord] == 2)
                    {
                        printf("[%s] You landed on %s! %s's lot. You paid a fee of %dK >> \n",
                               name1, cityNames[coord], name2, payFee);
                        scanf(" %c", &ph);
                        money1 -= payFee;
                        money2 += payFee;
                    }
                    else if(lotIsOwned[coord] == 3)
                    {
                        printf("[%s] You landed on %s! %s's lot. You paid a fee of %dK >> \n",
                               name1, cityNames[coord], name3, payFee);
                        scanf(" %c", &ph);
                        money1 -= payFee;
                        money3 += payFee;
                    }
                    else if(lotIsOwned[coord] == 4)
                    {
                        printf("[%s] You landed on %s! %s's lot. You paid a fee of %dK >> \n",
                               name1, cityNames[coord], name4, payFee);
                        scanf(" %c", &ph);
                        money1 -= payFee;
                        money4 += payFee;
                    }
                }
                else if(money1 < payFee)
                {
                    printf("You don't have enough money to buy rent fee.\n");
                    scanf(" %c", &ph);
                    bankrupt(1, coord, payFee);
                }
            }
        }

        if(playerID == 2)
        {
            if(lotIsOwned[coord] != 2)
            {
                if(money2 >= payFee)
                {
                    money2 -= payFee;
                    if(lotIsOwned[coord] == 1)
                    {
                        printf("[%s] You landed on %s! %s's lot. You paid a fee of %dK >> \n",
                               name2, cityNames[coord], name1, payFee);
                        scanf(" %c", &ph);
                        money2 -= payFee;
                        money1 += payFee;
                    }
                    else if(lotIsOwned[coord] == 3)
                    {
                        printf("[%s] You landed on %s! %s's lot. You paid a fee of %dK >> \n",
                               name2, cityNames[coord], name3, payFee);
                        scanf(" %c", &ph);
                        money2 -= payFee;
                        money3 += payFee;
                    }
                    else if(lotIsOwned[coord] == 4)
                    {
                        printf("[%s] You landed on %s! %s's lot. You paid a fee of %dK >> \n",
                               name2, cityNames[coord], name4, payFee);
                        scanf(" %c", &ph);
                        money2 -= payFee;
                        money4 += payFee;
                    }
                }
                else if(money2 < payFee)
                {
                    printf("You don't have enough money to buy rent fee.\n");
                    scanf(" %c", &ph);
                    bankrupt(2, coord, payFee);
                }
            }
        }

        if(playerID == 3)
        {
            if(lotIsOwned[coord] != 3)
            {
                if(money3 >= payFee)
                {
                    money3 -= payFee;
                    if(lotIsOwned[coord] == 1)
                    {
                        printf("[%s] You landed on %s! %s's lot. You paid a fee of %dK >> \n",
                               name3, cityNames[coord], name1, payFee);
                        scanf(" %c", &ph);
                        money3 -= payFee;
                        money1 += payFee;
                    }
                    else if(lotIsOwned[coord] == 2)
                    {
                        printf("[%s] You landed on %s! %s's lot. You paid a fee of %dK >> \n",
                               name3, cityNames[coord], name2, payFee);
                        scanf(" %c", &ph);
                        money3 -= payFee;
                        money2 += payFee;
                    }
                    else if(lotIsOwned[coord] == 4)
                    {
                        printf("[%s] You landed on %s! %s's lot. You paid a fee of %dK >> \n",
                               name3, cityNames[coord], name4, payFee);
                        scanf(" %c", &ph);
                        money3 -= payFee;
                        money4 += payFee;
                    }
                }
                else if(money3 < payFee)
                {
                    printf("You don't have enough money to buy rent fee.\n");
                    scanf(" %c", &ph);
                    bankrupt(3, coord, payFee);
                }
            }
        }

        if(playerID == 4)
        {
            if(lotIsOwned[coord] != 4)
            {
                if(money4 >= payFee)
                {
                    money4 -= payFee;
                    if(lotIsOwned[coord] == 1)
                    {
                        printf("[%s] You landed on %s! %s's lot. You paid a fee of %dK >> \n",
                               name4, cityNames[coord], name1, payFee);
                        scanf(" %c", &ph);
                        money4 -= payFee;
                        money1 += payFee;
                    }
                    else if(lotIsOwned[coord] == 3)
                    {
                        printf("[%s] You landed on %s! %s's lot. You paid a fee of %dK >> \n",
                               name4, cityNames[coord], name3, payFee);
                        scanf(" %c", &ph);
                        money4 -= payFee;
                        money3 += payFee;
                    }
                    else if(lotIsOwned[coord] == 2)
                    {
                        printf("[%s] You landed on %s! %s's lot. You paid a fee of %dK >> \n",
                               name4, cityNames[coord], name2, payFee);
                        scanf(" %c", &ph);
                        money4 -= payFee;
                        money2 += payFee;
                    }
                }
                else if(money4 < payFee)
                {
                    printf("You don't have enough money to buy rent fee.\n");
                    scanf(" %c", &ph);
                    bankrupt(4, coord, payFee);
                }
            }
        }
    }
}

void board()
{


        system("cls");
        p1[coord1] = ic1, p2[coord2] = ic2, p3[coord3] = ic3, p4[coord4] = ic4;

        for(int i = 0; i < 121; ++i) printf("-");
        printf("\n");

        //top
        for(int i = 0; i < 4; ++i)
        {
            if(i == 0){
                for(int j = 0; j < 8; ++j)
                {
                    printf("|%2d%-10s%-2s", j + 1, format, ownedBy[j]);
                }
            }

            if(i == 1)
            {
                for(int j = 0; j < 8; ++j)
                {
                    printf("| %c %c %c %c%-6s", p1[j], p2[j], p3[j], p4[j], format);
                }
            }
            if(i == 2)
            {
                for(int j = 0; j < 8; ++j)
                    printf("|%-14s", format);
            }
            if(i == 3)
            {
                for(int j = 0; j < 8; ++j)
                    printf("|%-14s", cityNames[j]);
            }
            printf("|\n");
        }

        for(int i = 0; i < 121; ++i) printf("-");
        printf("\n");

        //sides
        for(int i = 0; i < 7; ++i)
        {
            if(i == 1)
                for(int j = 27, k = 8; j >= 22; --j, ++k)
                {
                    printf("|%2d%-10s%-2s|%89s|%2d%-10s%-2s%|\n", j + 1, format, ownedBy[j],
                           format, k + 1, format, ownedBy[k]);
                     printf("| %c %c %c %c%-6s|%89s| %c %c %c %c%-6s|\n",
                           p1[j], p2[j], p3[j], p4[j], format, format, p1[k], p2[k], p3[k], p4[k], format);
                    printf("|%-14s|%89s%|%-14s|\n", format, format, format);
                    printf("|%-14s|%89s|%-14s|\n", cityNames[j], format, cityNames[k]);
                    if(j > 22)
                        printf("----------------%89s----------------\n", format);
                }
        }

        for(int i = 0; i < 121; ++i) printf("-");
        printf("\n");

        //bottom
        for(int i = 0; i < 4; ++i)
        {
            if(i == 0){
                for(int j = 21; j >= 14; --j)
                {
                    printf("|%2d%-10s%-2s", j + 1, format, ownedBy[j]);
                }
            }

            if(i == 1)
            {
                for(int j = 21; j >= 14; --j)
                {
                    printf("| %c %c %c %c%-6s", p1[j], p2[j], p3[j], p4[j], format);
                }
            }
            if(i == 2)
            {
                for(int j = 21; j >= 14; --j)
                    printf("|%-14s", format);
            }
            if(i == 3)
            {
                for(int j = 21; j >= 14; --j)
                    printf("|%-14s", cityNames[j]);
            }
            printf("|\n");
        }
        for(int i = 0; i < 121; ++i) printf("-");
        printf("\n");

}

void rollMessage(char currPlayer[], int rollD)
{
    board();
    printf("%s rolled %d!\nType in any key to continue >> ", currPlayer, rollD);
    scanf(" %c");
    board();
}

void displayWinners()
{
    system("cls");
    char players[4][31];
    strcpy(players[0], name1);
    strcpy(players[1], name2);
    strcpy(players[2], name3);
    strcpy(players[3], name4);
    int money[4] = {money1, money2, money3, money4};

    for(int i = 0; i < playersInGame; ++i)
    {
        int temp;
        char temp2[31];
        for(int j = 0; j < playersInGame - 1; ++j)
        {
            if(money[j] < money[j + 1])
            {
                temp = money[j];
                money[j] = money[j + 1];
                money[j + 1] = temp;
                strcpy(temp2, players[j]);
                strcpy(players[j], players[j + 1]);
                strcpy(players[j + 1], temp2);
            }
        }
    }

    printf("[GAME OVER]\nStandings:\n\n");

    for(int i = 0; i < playersInGame; ++i)
    {
        printf("%d. %s - $%dK", i + 1, players[i], money[i]);
        if(i == 0) printf(" (WINNER!)");
        printf("\n");
    }
    printf("\nType in any key to continue. >> ");
    scanf(" %c", &ph);
}

void play()
{
    char currPlayer[31] = "No one";
    setup();
    while(1){

        turn = turn % playersInGame;
        if(gameOver == 1) {
            displayWinners();
            break;
        }

        char in = ' ';
        board();
        if(turn == 0) strcpy(currPlayer, name1);
        else if(turn == 1) strcpy(currPlayer, name2);
        else if(turn == 2) strcpy(currPlayer, name3);
        else if(turn == 3) strcpy(currPlayer, name4);
        srand(time(NULL));
        int diceRoll = rand()%11 + 2;

        printf("[a] Roll dice [q] Quit [Other] Skip turn\n");

        if(jailTime[turn] <= 0){
        printf("%s(%c): $%dK | %s(%c): $%dK ",
               name1, ic1,  money1, name2, ic2, money2);
        if(playersInGame >= 3)
        {
            printf("| %s(%c): $%dK ",
            name3, ic3, money3);
            if(playersInGame == 4)
            {
                printf("| %s(%c): $%dK ",
                name4, ic4, money4);
            }
        }

        printf("(%s's turn)\nEnter >> ", currPlayer);

        scanf(" %c", &in);

        if(in == 'q')
        {
            printf("\n[Quit] Are you sure you want to quit? [y/n] >> ");
            char acc;
            scanf(" %c", &acc);
            if(acc == 'y') gameOver = 1;
            else turn--;
        }

            if(diceControl == 1){
                printf("[Dice Control] Dice Roll >> ");
                scanf("%d", &diceRoll);
            }
        }
        else{
            printf("[Jail] %s >> You're still stuck in jail! %d more turns and you're out! >> ", currPlayer, jailTime[turn]);
            jailTime[turn]--;
            scanf( "%c", &ph);
        }

        if(in == 'a' && turn == 0){
            p1[coord1] = ' ';
            coord1 += diceRoll;
            if(coord1 > 28) money1 += 200;
            coord1 = coord1 % 28;
            p1[coord1] = ic1;
            strcpy(lastPlayer, name1);
            rollMessage(currPlayer, diceRoll);
            specialLot(1, coord1);
            lotAct(1, coord1);
            buyLot(1, coord1);
        }
        if(in == 'a' && turn == 1){
            p2[coord2] = ' ';
            coord2 += diceRoll;
            if(coord2 > 28) money2 += 200;
            coord2 = coord2 % 28;
            p2[coord2] = ic2;
            strcpy(lastPlayer, name2);
            rollMessage(currPlayer, diceRoll);
            specialLot(2, coord2);
            lotAct(2, coord2);
            buyLot(2, coord2);
        }
        if(in == 'a' && turn == 2){
            p3[coord3] = ' ';
            coord3 += diceRoll;
            if(coord3 > 28) money3 += 200;
            coord3 = coord3 % 28;
            p3[coord3] = ic3;
            strcpy(lastPlayer, name3);
            rollMessage(currPlayer, diceRoll);
            specialLot(3, coord3);
            lotAct(3, coord3);
            buyLot(3, coord3);
        }
        if(in == 'a' && turn == 3){
            p4[coord4] = ' ';
            coord4 += diceRoll;
            if(coord4 > 28) money4 += 200;
            coord4 = coord4 % 28;
            p4[coord4] = ic4;
            strcpy(lastPlayer, name4);
            rollMessage(currPlayer, diceRoll);
            specialLot(4, coord4);
            lotAct(4, coord4);
            buyLot(4, coord4);
        }
        turn++;
        tempDice = diceRoll;
    }

}

void reset()
{
    for(int i = 0; i < 28; ++i){
        strcpy(ownedBy[i], "");
        lotIsOwned[i] = 0;
        lotMult[i] = 1;

    }

    for(int i = 0; i < 3; ++i)
    {
        hasAngel[i] = 0;
        jailTime[i] = 0;
    }

    turn = 0, tempDice = 0;
    money1 = 1000, money2 = 1000, money3 = 1000, money4 = 1000;
    playersInGame = 4;
    lastDice = 0;
    gameOver = 0;


}

void mainMenu()
{
    while(1)
    {
        reset();
        system("cls");
        printf("T042 - JASON LEONARDO SUTIOSO\nNIM: 2440051574\n\n");
        printf("     M O N O P O L Y\n");
        printf("      A T  H O M E!\n\n");
        printf("         [1] Play\n");
        printf("         [2] Help\n");
        printf("         [3] Exit\n\n");
        char inp;
        printf("        Enter >> ");
        scanf(" %c", &inp);
        if(inp == '1'){
            system("cls");
            printf("[PLAY]\n\nEnter player amount (1-4) >> ");
            scanf("%d", &playersInGame);
            while(playersInGame < 2 || playersInGame > 4)
            {
                printf("[Come on, be serious!] Enter player amount (2-4) >> ");
                scanf("%d", &playersInGame);
            }
            printf("Enter name for player 1 >> ");
            scanf(" %[^\n]", name1);
            printf("Enter name for player 2 >> ");
            scanf(" %[^\n]", name2);
            ic3 = ' ';
            ic4 = ' ';
            if(playersInGame >= 3){
                printf("Enter name for player 3 >> ");
                scanf(" %[^\n]", name3);
                ic3 = '%';
                if(playersInGame == 4){
                    printf("Enter name for player 4 >> ");
                    scanf(" %[^\n]", name4);
                }
                ic4 = '&';
            }
            play();

        }
        if(inp == '2')
        {
            system("cls");
            printf("[HELP]\n\n");
            printf("1. Welcome to Monopoly at Home! Monopoly game on the Console Command Prompt!\n");
            printf("2. You can play up to 4 players!\n");
            printf("3. Your objective is to buy lots and avoid bankruptcy.\n");
            printf("4. You can buy a lot which has a rent fee that other players has to pay.\n");
            printf("5. If they can't afford the rent fee they can choose to sell their assets or go bankrupt.\n");
            printf("6. Special Lots have special events in them.\n");
            printf("Festival - You can double the rent fee for one of your lots.\n");
            printf("Jail - You will not be able to move for 3 turns.");
            printf("Travel - The airport can take you anywhere all around the world!\n");
            printf("Chance Card - A chance that you will get an angel card. Angel cards allow you to avoid rent fees.");
            printf("GO! - If you pass this block, you will get $200K!\n\nType in any key to dismiss >> ");
            scanf(" %c", &ph);

        }
        if(inp == '3') break;
    }
}


int main()
{
    mainMenu();
}
