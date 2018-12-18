#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>               // For allegro, must be in compiler search path.
#include <allegro5/allegro_native_dialog.h> 		// for message box
#include "SummativeHeader.h"

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>               // For allegro, must be in compiler search path.
#include <allegro5/allegro_native_dialog.h> 		// for message box
#include "SummativeHeader.h"

//functions that displays title screen
void printTitleScreen(ALLEGRO_FONT *font, ALLEGRO_DISPLAY *display, ALLEGRO_MOUSE_STATE mouseState) {
    ALLEGRO_BITMAP *startButton = al_load_bitmap("Waluigi.png");

	imgData StartButton;
	StartButton.left = 338 ;
	StartButton.right = 548 ;
	StartButton.top = 64 ;
	StartButton.bot = 253 ;

	imgData QuitButton;
	QuitButton.left = 400 ;
	QuitButton.right = 500 ;
	QuitButton.top = 300 ;
	QuitButton.bot = 325 ;

    if (!startButton) {
    	al_show_native_message_box(display, "Error", "Error", "Failed to load start button image.",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);

	}

    al_draw_text(font, TEXTCOLOR, MID_SCREEN, 5, ALLEGRO_ALIGN_CENTRE, "SPACE-WORD BLASTER EXTREME");
    al_draw_bitmap(startButton, 275, 25, 0);
    al_draw_text(font, TEXTCOLOR, MID_SCREEN, 265, ALLEGRO_ALIGN_CENTRE, "LEADERBOARDS");
    al_draw_text(font, TEXTCOLOR, MID_SCREEN, 295, ALLEGRO_ALIGN_CENTRE, "QUIT");

    al_flip_display();

    while(true) {

        al_get_mouse_state(&mouseState);
        printf("%d %d %0.2f\n", mouseState.x, mouseState.y, mouseState.pressure);

	if (mouseClick(StartButton, mouseState) == 1) {
        al_clear_to_color(BGCOLOR);
        al_flip_display();
        startGame();
    }else if (mouseClick(QuitButton, mouseState) == 1){
        al_clear_to_color(BGCOLOR);
        al_flip_display();
	al_destroy_display(display);
    }

    al_rest(0.01);
    }

}

//function that starts the game
void startGame() {
    Words game;
    int counter = 0;
    FILE *fptr;
    printf("What difficulty do you want to play? Easy, Medium, Hard (e/m/h)\n");
    char difficulty = determineDifficulty();
    if (difficulty == 'e'){
        fptr = fopen("WordBankEasy.txt", "r");
    }else if (difficulty == 'm') {
        fptr = fopen("WordBankMedium.txt", "r");
    }else if (difficulty == 'h') {
        fptr = fopen("WordBankHard.txt", "r");
    }

    while (fscanf(fptr, "%s", game.OffscreenWords[counter]) != EOF){
        fscanf(fptr, "%s", game.OffscreenWords[counter]);
        counter++;
    }
        fclose(fptr);

    ALLEGRO_BITMAP *ship = al_load_bitmap("shipPlaceholder.png");
    ALLEGRO_BITMAP *gun = al_load_bitmap("cannonPlaceholder.png");

    al_convert_mask_to_alpha(ship, WHITE);
    al_convert_mask_to_alpha(gun, WHITE);
    al_draw_bitmap(ship, 250, 25, 0);
    al_draw_bitmap(gun, 300, 30, 0);

    al_flip_display();
    al_rest(20);
}

void generateWord(int &wordbank[30][35]){
    for(int i = 0; i < 31; i++){
            // while this is not the end of the file
        while(fgets(wordbank[i], 35, fptr) != NULL){
            fgets(wordbank[i], 35, fptr);
        }
    }
	ALLEGRO_BITMAP *ship = al_load_bitmap("shipPlaceholder.png");
    ALLEGRO_BITMAP *gun = al_load_bitmap("cannonPlaceholder.png");
    al_draw_bitmap(ship, 225, 50, 0);
    al_draw_bitmap(gun, 300, 30, 0);
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

	//function that determines difficulty
char determineDifficulty() {
    char a = 'e';
    return a;
}

int mouseClick(imgData a, ALLEGRO_MOUSE_STATE mouseState){
    if (mouseState.x > a.left && mouseState.x < a.right && mouseState.y > a.top && mouseState.y < a.bot && mouseState.pressure == 1.0) {
        return 1;
    }else if (mouseState.x > a.left && mouseState.x < a.right && mouseState.y > a.top && mouseState.y < a.bot && mouseState.pressure != 1.0) {
        return 0;
    }
}
