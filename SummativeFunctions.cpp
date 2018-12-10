#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>               // For allegro, must be in compiler search path.
#include <allegro5/allegro_native_dialog.h> 		// for message box
#include "SummativeHeader.h"

char determineDifficulty() {
    
}

void printTitleScreen(ALLEGRO_FONT *font) {
    al_draw_text(font, TEXTCOLOR, 200, 5, ALLEGRO_ALIGN_CENTRE, "Game");
    
    al_flip_display();
}

void startGame() {
    int counter = 0;
    FILE *fptr;
    printf("What difficulty do you want to play? Easy, Medium, Hard (e/m/h)\n");
    char difficulty = determineDifficulty();
    if (difficulty = 'e'){
        fptr = fopen("WordBankEasy.txt", "r");
    
        while (fscanf(fptr, "%s", game[counter].OffscreenWords) != EOF){
            fscanf(fptr, "%s", p[counter].OffscreenWords);
            counter++;
        }   
        fclose(fptr);
    }else if (difficulty = 'm') {
        fptr = fopen("WordBankMedium.txt", "r");
                 
        while (fscanf(fptr, "%s", game[counter].OffscreenWords) != EOF){
            fscanf(fptr, "%s", p[counter].OffscreenWords);
            counter++;
        }
        fclose(fptr);
    }else if (difficulty = 'h') {
        fptr = fopen("WordBankHard.txt", "r");
                 
        while (fscanf(fptr, "%s", game[counter].OffscreenWords) != EOF){
            fscanf(fptr, "%s", p[counter].OffscreenWords);
            counter++;
        }
        fclose(fptr);
    }
}

void printDeathScreen() {
  
}
