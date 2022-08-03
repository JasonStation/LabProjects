#include <stdio.h>

int main()
{
    char coordX1,coordX2;
    int coordY1, coordY2, steps;

    scanf("%d", &steps);

    scanf(" %c%d", &coordX1, &coordY1);
    scanf(" %c%d", &coordX2, &coordY2);

    coordX1 -= 65;
    coordY1 -= 1;
    coordX2 -= 65;
    coordY2 -= 1;

    short chessSize = 8;

    short chessBoard[chessSize][chessSize];

    for(int i = 0; i < chessSize; ++i)
    {
        for(int j = 0; j < chessSize; ++j)
            chessBoard[i][j] = 0;
    }

    chessBoard[coordX1][coordY1] = 1;
    chessBoard[coordX2][coordY2] = 1;

    if(coordX1 + steps < chessSize){
        chessBoard[coordX1 + steps][coordY1] += 1;
    }
    if(coordX2 + steps < chessSize){
        chessBoard[coordX2 + steps][coordY2] += 1;
    }
    if(coordX1 - steps >= 0){
        chessBoard[coordX1 - steps][coordY1] += 1;
    }
    if(coordX2 - steps >= 0){
        chessBoard[coordX2 - steps][coordY2] += 1;
    }
    if(coordY1 + steps < chessSize){
        chessBoard[coordX1][coordY1 + steps] += 1;
    }
    if(coordY2 + steps < chessSize){
        chessBoard[coordX2][coordY2 + steps] += 1;
    }
    if(coordY1 - steps >= 0){
        chessBoard[coordX1][coordY1 - steps] += 1;
    }
    if(coordY2 - steps >= 0){
        chessBoard[coordX2][coordY2 - steps] += 1;
    }

    short flag = 0;

    for(int i = 0; i < chessSize; ++i)
    {
        for(int j = 0; j < chessSize; ++j)
        {
            if(chessBoard[i][j] >= 2)
                flag = 1;
        }
    }

    if(flag == 1) printf("YES\n");
    else printf("NO\n");

    return 0;
}