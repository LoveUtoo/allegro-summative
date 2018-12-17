#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>               // For allegro, must be in compiler search path.
#include <allegro5/allegro_native_dialog.h> 		// for message box
#include "SummativeHeader.h"

char determineDifficulty() {

}

void printTitleScreen(ALLEGRO_FONT *font, ALLEGRO_DISPLAY *display, ALLEGRO_MOUSE_STATE mouseState) {
    ALLEGRO_BITMAP *startButton = al_load_bitmap("Waluigi.png");
	
	imgData StartButton;
	StartButton.left = 338 ;
	StartButton.right = 548 ;
	StartButton.top = 64 ;
	StartButton.bot = 253 ;

    if (!startButton) {
    	al_show_native_message_box(display, "Error", "Error", "Failed to load start button image.",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);

	}

    al_draw_text(font, TEXTCOLOR, MID_SCREEN, 5, ALLEGRO_ALIGN_CENTRE, "SPACE-WORD BLASTER EXTREME");
    al_draw_bitmap(startButton, 275, 25, 0);
    al_draw_text(font, TEXTCOLOR, MID_SCREEN, 265, ALLEGRO_ALIGN_CENTRE, "LEADERBOARDS");

    al_flip_display();

    while(true) {

        al_get_mouse_state(&mouseState);
        printf("%d %d %0.2f\n", mouseState.x, mouseState.y, mouseState.pressure);
	    
	if (mouseState.x > StartButton.left && mouseState.x < StartButton.right && mouseState.y > StartButton.top && mouseState.y < StartButton.bot && mouseState.pressure == 1.0) {
            printf("test");
        }
	    
        al_rest(0.01);
    }
}

void startGame(Words game[]) {
    int counter = 0;
    FILE *fptr;
    printf("What difficulty do you want to play? Easy, Medium, Hard (e/m/h)\n");
    char difficulty = determineDifficulty();
    if (difficulty = 'e'){
        fptr = fopen("WordBankEasy.txt", "r");

        while (fscanf(fptr, "%s", game[counter].OffscreenWords) != EOF){
            fscanf(fptr, "%s", game[counter].OffscreenWords);
            counter++;
        }
        fclose(fptr);
    }else if (difficulty = 'm') {
        fptr = fopen("WordBankMedium.txt", "r");

        while (fscanf(fptr, "%s", game[counter].OffscreenWords) != EOF){
            fscanf(fptr, "%s", game[counter].OffscreenWords);
            counter++;
        }
        fclose(fptr);
    }else if (difficulty = 'h') {
        fptr = fopen("WordBankHard.txt", "r");

        while (fscanf(fptr, "%s", game[counter].OffscreenWords) != EOF){
            fscanf(fptr, "%s", game[counter].OffscreenWords);
            counter++;
        }
        fclose(fptr);
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
  char name[10];
  int highscore;
  FILE *fptr;
  fptr = fopen("highscore.txt", "w");
  for(int i = 0; i<10; i++){
  fgets()    
}

