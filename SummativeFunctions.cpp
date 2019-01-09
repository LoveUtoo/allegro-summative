#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>               // For allegro, must be in compiler search path.
#include <allegro5/allegro_native_dialog.h> 		// for message box
#include "SummativeHeader.h"// the header

int lives = 3;
int printnumber = 0;
char printedcharacters[30];

//functions that displays title screen
void printTitleScreen(ALLEGRO_FONT *font, ALLEGRO_DISPLAY *display, ALLEGRO_MOUSE_STATE& mouseState) {
    ALLEGRO_BITMAP *startButton = al_load_bitmap("startButton.png");
// The position that the start button is located
	imgData StartButton;
	StartButton.left = 338 ;
	StartButton.right = 548 ;
	StartButton.top = 64 ;
	StartButton.bot = 253 ;
// the position that the quit button is located
	imgData QuitButton;
	QuitButton.left = 400 ;
	QuitButton.right = 500 ;
	QuitButton.top = 300 ;
	QuitButton.bot = 325 ;
// if the start button doesn't load
    if (!startButton) {
    	al_show_native_message_box(display, "Error", "Error", "Failed to load start button image.",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);

	}
// writing the text
    al_draw_text(font, TEXTCOLOR, MID_SCREEN, 5, ALLEGRO_ALIGN_CENTRE, "SPACE-WORD BLASTER EXTREME");
    al_draw_bitmap(startButton, 275, 25, 0);
    al_draw_text(font, TEXTCOLOR, MID_SCREEN, 265, ALLEGRO_ALIGN_CENTRE, "LEADERBOARDS");
    al_draw_text(font, TEXTCOLOR, MID_SCREEN, 295, ALLEGRO_ALIGN_CENTRE, "QUIT");

    al_flip_display();

    while(true) {
        // Getting a position of the mouse and creating the events in which to call functions
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
            break; // quit game
        }

        al_rest(0.01);
    }

}

//function that starts the game when the user presses the start image.
void startGame() {
    int wordNum = 0;
    //double = 60;
    bool alive = true;
    int diffTimer = 0;
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

    getWords(fptr, game, wordNum);

    fclose(fptr);
/*
    ALLEGRO_BITMAP *ship = al_load_bitmap("shipPlaceholder.png");
    ALLEGRO_BITMAP *gun = al_load_bitmap("cannonPlaceholder.png");

    al_convert_mask_to_alpha(ship, WHITE);
    al_convert_mask_to_alpha(gun, WHITE);
    al_draw_bitmap(gun, 600, 30, 0);
    al_draw_bitmap(ship, 250, 65, 0);
*/
    al_flip_display();

    while (alive == true) {
        printf("test");
    }


    al_rest(20);
}

void getWords(FILE *fptr, Words& game, int &count){
    //for(int i = 0; i < 31; i++){
        // while this is not the end of the file
        count = 0;
        while(fgets(game.OffscreenWords[count], 30, fptr) != NULL){
            //fgets(wordbank[i], 35, fptr);
            //int n = strlen(game.OffscreenWords[count]);
            //while(n>0 && isspace(game.OffscreenWords[count][n-1]))n--;
            //if(n<1) continue;
            count++;
            if(count>=100) break;
        }
    //}
}
// Chooses the words that the user needs to type
void chooseWord(Words& game, int wordNum, int &printnumber){
    // onScreenwords are the words we already used
    while(game.OnscreenWords[printnumber] < 1){
        int index = rand() % wordNum;
        // hotbar are the words we are about to print
        //strcpy(game.hotbar[wordNum], game.OffscreenWords[printnumber])
        // mark in OnscreenWords that we used this number/word
        game.OnscreenWords[printnumber] = index+1;
    }
}

void printDeathScreen() {
  char name[10];
  int highscore;
  FILE *fptr;
  fptr = fopen("highscore.txt", "w");
  for(int i = 0; i<10; i++){
  //fgets();
  }
}

	//function that determines difficulty
char determineDifficulty() {
    char a = 'e';
    return a;
}
// Function that checks if you clicked a button
int mouseClick(imgData& a, ALLEGRO_MOUSE_STATE& mouseState){
    if (mouseState.x > a.left && mouseState.x < a.right && mouseState.y > a.top && mouseState.y < a.bot && mouseState.pressure == 1.0) {
        return 1;
    }//else if (mouseState.x > a.left && mouseState.x < a.right && mouseState.y > a.top && mouseState.y < a.bot && mouseState.pressure != 1.0) {
        return 0;
    //}
}
// not done printword
void printword(const ALLEGRO_KEYBOARD_EVENT& ev, int index){
	char character;
	if(ev.keycode>=ALLEGRO_KEY_A && ev.keycode<=ALLEGRO_KEY_Z){
        	character = 'a' + (ev.keycode - ALLEGRO_KEY_A);
         	}
	else if(ev.keycode == ALLEGRO_KEY_SPACE{
		character = ' ';
      	}else if(ev.keycode == ALLEGRO_KEY_BACKSPACE) {
        	character = '~';
	}else if(ev.keycode == ALLEGRO_KEY_ENTER) {
        	character = '`';
	}else{
		return -1;
}
	int num = strlen(hotbar[30]);
	if
}
