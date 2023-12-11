#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "gato_library.h"

int main(){
    char winner = ' ';
    char response; 
    do
    {   
        winner = ' ';
        response = ' ';
        resetBoard();

        while(winner == ' ' && checkFreeSpaces()!=0){
            printBoard();
            playersMove();
            winner = checkWinner();
            if(winner != ' ' || checkFreeSpaces() == 0){
                break;
            }

            computerMove();
            winner = checkWinner();
            if(winner != ' ' || checkFreeSpaces() == 0){
                break;
            }
        }
        printBoard();
        printWinner(winner);

        printf("\nWOULD YOU LIKE TO PLAY AGAIN?(Y/N): ");
        fflush(stdin); //buffer clear
        scanf("%c",&response);
        response = toupper(response); 
    } while (response == 'Y');
    
    printf("\nTHANKS FOR PLAYING!!!");

    return 0;
}

