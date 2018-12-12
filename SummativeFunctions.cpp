#include <stdio.h>
#include <string.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>               // For allegro, must be in compiler search path.
#include <allegro5/allegro_native_dialog.h> 		// for message box
#include "SummativeHeader.h"

void printTitleScreen(ALLEGRO_FONT *font) {
    ALLEGRO_BITMAP *startButton = al_load_bitmap("waluigi.bmp");

    al_draw_text(font, TEXTCOLOR, MID_SCREEN, 5, ALLEGRO_ALIGN_CENTRE, "SPACE-WORD BLASTER EXTREME");
    al_draw_bitmap(startButton, MID_SCREEN, 225, 0);
    al_draw_text(font, TEXTCOLOR, MID_SCREEN, 265, ALLEGRO_ALIGN_CENTRE, "LEADERBOARDS");

    al_flip_display();

    al_rest(20);
}

int wordbank[31][35];

void startGame(){
    printf("What difficulty do you want to play? Easy, Medium, Hard (e/m/h)\n");
    char difficulty;
    scanf("%c", difficulty);
    FILE *fptr;
    if (difficulty == 'e'){
        fptr = fopen("WordBankEasy.txt", "r");
    } else if (difficulty == 'm') {
        fptr = fopen("WordBankMedium.txt", "r");
    } else if (difficulty == 'h') {
        fptr = fopen("WordBankHard.txt", "r");
    }
}


void generateWord(int &wordbank[30][35]){
    for(int i = 0; i < 31; i++){
            // while this is not the end of the file
        while(fgets(wordbank[i], 35, fptr) != NULL){
            fgets(wordbank[i], 35, fptr);
        }
    }
}

void chooseWord(int wordbank[30][35], int hotbar[30], int OnscreenWords[30]){
    // printnumber represents the number in wordbank that corresponds to a word
    int printnumber = 0;
    // onScreenwords are the words we already used
    while(onScreenwords[printnumber] != 1){
        printnumber = rand() % 30;
        // hotbar are the words we are about to print
        strcpy(hotbar[30], wordbank[printnumber])
        // mark in OnscreenWords that we used this number/word 
        OnscreenWords[printnumber] = 1;
    }
}

void printDeathScreen() {
    
}
