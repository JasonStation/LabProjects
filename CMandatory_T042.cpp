#include <stdio.h>
#include <ctime>
#include <stdlib.h>

short cheat = 0; // Set to 1 to see where fossils are located.

char dirt = '.', dugged = 'X', fossil = '#';

int remaining = 0, chances;

char field[31][31];

short foss[31][31];

short flag = 0, flag2 = 0;

char * placeHolder;

void fossilPlacement(int x)
{
    srand(time(NULL));
    for(int i = 0; i < x; ++i)
    {
        for(int j = 0; j < x; ++j)
        {
            int random = rand()%15;
            if(random <= 1){
                foss[i][j] = 1;
                remaining++;
            }
            if(cheat == 1)
                printf("%d ", foss[i][j]);
        }
        if(cheat == 1)
            printf("\n");
    }
}

void generateField(int x, int y, int tries, int remain)
{
    if(flag == 0){
        chances = tries;
        remaining = remain;
        flag = 1;
    }

    for(int i = 0; i < x; ++i)
    {
        if(flag2 == 0){
            for(int j = 0; j < y; ++j)
                field[i][j] = dirt;
        }
        for(int j = 0; j < y; ++j)
            printf("%c ", field[i][j]);
        printf("%d\n", i + 1);
    }

    flag2 = 1;

    printf("\n[Legend]\n[.] Dirt\n[X] Dugged Dirt\n[#] Fossil\n");
    printf("\nFossils to be found: %d\n", remaining);
    printf("Dig chance(s): %d\n", chances);

    int coordX, coordY;
    printf("\nEnter coordinates (Format: X Y) >> ");
    scanf("%d %d", &coordY, &coordX);

    if(foss[coordX - 1][coordY - 1] == 1 && field[coordX - 1][coordY - 1] != fossil
       && field[coordX - 1][coordY - 1] != dugged && coordX >= 1 && coordX <= x && coordY >= 1 && coordY <= y){
        chances--;
        remaining--;
        foss[coordX][coordY] = 0;
        field[coordX - 1][coordY - 1] = fossil;
    }
    else if(field[coordX - 1][coordY - 1] != fossil && field[coordX - 1][coordY - 1] != dugged
            && coordX >= 1 && coordX <= x && coordY >= 1 && coordY <= y)
    {
        chances--;
        field[coordX - 1][coordY - 1] = dugged;
    }



}

int winOrLose()
{
    if(remaining <= 0)
        return 1;

    if(chances <= 0)
        return 0;
}

void playEasy()
{
    fossilPlacement(10);
    int remain = 10;
    if(remaining < 10)
        remain = remaining;

    while(1){
        if(cheat == 0) system("cls");
        printf("[EASY - Fossil Diggers]\n\n");
        for(int i = 1; i < 10; ++i) printf("%d ", i);
        printf("0\n");

        generateField(10, 10, 50, remain);
        system("cls");

        if(winOrLose() == 1)
        {
            system("cls");
            printf("[YOU WIN]\nYou found all the fossils. Nice!\n\nType in any key to dismiss >> ");
            scanf(" %c", &placeHolder);
            break;
        }
        else if(winOrLose() == 0)
        {
            system("cls");
            printf("[YOU LOSE]\nYou didn't find all the fossils.\n\nType in any key to dismiss >> ");
            scanf(" %c", &placeHolder);
            break;
        }
    }

}

void playMedium()
{
    fossilPlacement(20);
    int remain = 20;
    if(remaining < 20)
        remain = remaining;
    while(1){
        if(cheat == 0)system("cls");
        printf("[MEDIUM - Fossil Diggers]\n\n");
        for(int i = 1; i < 10; ++i) printf("%d ", i);
        printf("0 ");
        for(int i = 1; i < 10; ++i) printf("%d ", i);
        printf("0\n");

        generateField(20, 20, 150, remain);
        system("cls");

        if(winOrLose() == 1)
        {
            system("cls");
            printf("[YOU WIN]\nYou found all the fossils. Nice!\n\nType in any key to dismiss >> ");
            scanf(" %c", &placeHolder);
            break;
        }
        else if(winOrLose() == 0)
        {
            system("cls");
            printf("[YOU LOSE]\nYou didn't find all the fossils.\n\nType in any key to dismiss >> ");
            scanf(" %c", &placeHolder);
            break;
        }

    }
}

void playHard()
{
    fossilPlacement(30);
    int remain = 30;
    if(remaining < 30)
        remain = remaining;
    while(1){
        if(cheat == 0) system("cls");
        printf("[HARD - Fossil Diggers]\n\n");
        for(int i = 1; i < 10; ++i) printf("%d ", i);
        printf("0 ");
        for(int i = 1; i < 10; ++i) printf("%d ", i);
        printf("0 ");
        for(int i = 1; i < 10; ++i) printf("%d ", i);
        printf("0\n");

        generateField(30, 30, 200, remain);
        system("cls");

        if(winOrLose() == 1)
        {
            system("cls");
            printf("[YOU WIN]\nYou found all the fossils. Nice!\n\nType in any key to dismiss >> ");
            scanf(" %c", &placeHolder);
            break;
        }
        else if(winOrLose() == 0)
        {
            system("cls");
            printf("[YOU LOSE]\nYou didn't find all the fossils.\n\nType in any key to dismiss >> ");
            scanf(" %c", &placeHolder);
            break;
        }
    }
}

void mainMenu()
{
    while(1){
        remaining = 0, flag = 0, flag2 = 0;

        printf("T042 - Jason Leonardo Sutioso\nNIM: 2440051574\n\n");
        printf("   F O S S I L\n");
        printf("  D I G G E R S\n");

        printf("\n");
        printf("    [1] Play\n");
        printf("    [2] Help\n");
        printf("    [3] Quit\n");
        printf("\n");
        printf("   Enter >> ");

        int input;

        scanf("%d", &input);

        if(input == 1)
        {
            system("cls");
            printf("[Please select game difficulty]\n\n");
            printf("[1] EASY - 10 x 10, 10 fossils, 50 dig chances\n");
            printf("[2] MEDIUM - 20 x 20, 20 fossils, 150 dig chances\n");
            printf("[3] HARD - 30 x 30, 30 fossils, 200 dig chances\n\n");
            int input2;
            printf("Enter difficulty (1-3) >> ");
            scanf("%d", &input2);
            if(input2 == 1) playEasy();
            else if(input2 == 2) playMedium();
            else if(input2 == 3) playHard();
        }
        else if(input == 2)
        {
            system("cls");
            printf("[Help]\n\n");
            printf("1. Your objective is to find fossils in the dirt.\n");
            printf("2. You have to find a specific number of fossils in order to win the game.\n");
            printf("3. If you run out of chances, and still have fossils to find, you will lose.\n");
            printf("4. To dig a dirt lot, input two coordinates (X and Y) in this format: X Y.\n");
            printf("5. Fossil placements are truly random.\n");
            printf("6. The harder the difficulty, the more fossils you need to find.\n");
            printf("7. 0 in the X coordinate marker above is 10 and so on.\n");
            printf("8. Here are the different icons you should know:\n");
            printf("[.] Dirt\n[X] Dugged dirt\n[#] Fossil\n\n");
            printf("Sorry, I can't use the icons based on the question.\nMy IDE doesn't support it.\n\n");
            printf("Type any key to continue >> ");
            scanf(" %c", &placeHolder);
        }else if(input == 3)
        {
            printf("\n   [Game quit]\n");
            break;
        }
        system("cls");
    }
}

int main()
{

    mainMenu();

    return 0;
}
