#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>               // For allegro, must be in compiler search path.
#include <allegro5/allegro_native_dialog.h> 		// for message box
#include "SummativeHeader.h"

void printTitleScreen() {
    WordBank game;
    Stats player;
  
  
}

void startGame() {
    char difficulty;
    FILE *fptr;
    printf("What difficulty do you want to play? Easy, Medium, Hard (e/m/h)\n");
    scanf("%c", difficulty);
    while (true){
    if (difficulty == 'e'){
        fptr = fopen("WordBankEasy.txt", "r");
        break;
    }else if (difficulty == 'm'){
        fptr = fopen("WordBankMedium.txt", "r");
        break;
    }else if (difficulty == 'h'){
        fptr = fopen("WorkBankHard.txt", "r");
        break;
    }else{
        printf("Please type one of the 3 letters corresponding to the difficulty\n");
    }
    }
}
void printDeathScreen() {
  
}
