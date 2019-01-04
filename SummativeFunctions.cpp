#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>               // For allegro, must be in compiler search path.
#include <allegro5/allegro_native_dialog.h> 		// for message box
#include "SummativeHeader.h"// the header

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>               // For allegro, must be in compiler search path.
#include <allegro5/allegro_native_dialog.h> 		// for message box
#include "SummativeHeader.h"

//functions that displays title screen
void printTitleScreen(ALLEGRO_FONT *font, ALLEGRO_DISPLAY *display, ALLEGRO_MOUSE_STATE mouseState) {
    ALLEGRO_BITMAP *startButton = al_load_bitmap("Waluigi.png");
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
    }

    al_rest(0.01);
    }

}

//function that starts the game when the user presses the start image.
void startGame() {
    int wordNum = 0;
    double = 60;
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

    getWords(fptr, game.OffscreenWords, wordNum);

    fclose(fptr);

    ALLEGRO_BITMAP *ship = al_load_bitmap("shipPlaceholder.png");
    ALLEGRO_BITMAP *gun = al_load_bitmap("cannonPlaceholder.png");

    al_convert_mask_to_alpha(ship, WHITE);
    al_convert_mask_to_alpha(gun, WHITE);
    al_draw_bitmap(gun, 600, 30, 0);
    al_draw_bitmap(ship, 250, 65, 0);
    al_flip_display();

    while (alive == true) {
        printf("test");
    }


    al_rest(20);
}

void getWords(FILE *fptr, char wordbank[][30], int &a){
    for(int i = 0; i < 31; i++){
            // while this is not the end of the file
        while(fgets(wordbank[i], 35, fptr) != NULL){
            fgets(wordbank[i], 35, fptr);
	    a++;
        }
    }
}

void chooseWord(int wordbank[wordNum][35], int hotbar[wordnum], int OnscreenWords[wordNum], int printnumber){
    // printnumber represents the number in wordbank that corresponds to a word
    // onScreenwords are the words we already used
    while(onScreenwords[printnumber] != 1){
        printnumber = rand() % wordNum;
        // hotbar are the words we are about to print
	    
        if (strcpy(hotbar[wordNum], wordbank[printnumber])){
        // mark in OnscreenWords that we used this number/word 
        OnscreenWords[printnumber] = 1;
	}
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
// Function that checks if you clicked a button
int mouseClick(imgData a, ALLEGRO_MOUSE_STATE mouseState){
    if (mouseState.x > a.left && mouseState.x < a.right && mouseState.y > a.top && mouseState.y < a.bot && mouseState.pressure == 1.0) {
        return 1;
    }else if (mouseState.x > a.left && mouseState.x < a.right && mouseState.y > a.top && mouseState.y < a.bot && mouseState.pressure != 1.0) {
        return 0;
    }
}
	
void printword(){
int holder = 0;
ALLEGRO_EVENT_QUEUE *event_queue = nullptr;
ALLEGRO_EVENT ev;
al_wait_for_event(event_queue, &ev);
for(int i = 0; i < 30; i++){
    if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
        	break;
      	}
      	else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
         	switch(ev.keyboard.keycode) {
            	case ALLEGRO_KEY_A:
               		printedcharacters[holder] = 'a';
               		holder++;
                case ALLEGRO_KEY_B:
               		printedcharacters[holder] = 'b';
               		holder++;
                case ALLEGRO_KEY_C:
               		printedcharacters[holder] = 'c';
               		holder++;
                case ALLEGRO_KEY_D:
               		printedcharacters[holder] = 'd';
               		holder++;
                case ALLEGRO_KEY_E:
               		printedcharacters[holder] = 'e';
               		holder++;
                case ALLEGRO_KEY_F:
               		printedcharacters[holder] = 'f';
               		holder++;
                case ALLEGRO_KEY_G:
               		printedcharacters[holder] = 'g';
               		holder++;
                case ALLEGRO_KEY_H:
               		printedcharacters[holder] = 'h';
               		holder++;
                case ALLEGRO_KEY_I:
               		printedcharacters[holder] = 'i';
               		holder++;
                case ALLEGRO_KEY_J:
               		printedcharacters[holder] = 'j';
               		holder++;
                case ALLEGRO_KEY_K:
               		printedcharacters[holder] = 'k';
               		holder++;
                case ALLEGRO_KEY_L:
               		printedcharacters[holder] = 'l';
               		holder++;
                case ALLEGRO_KEY_M:
               		printedcharacters[holder] = 'm';
               		holder++;
                case ALLEGRO_KEY_N:
               		printedcharacters[holder] = 'n';
               		holder++;
                case ALLEGRO_KEY_O:
               		printedcharacters[holder] = 'o';
               		holder++;
                case ALLEGRO_KEY_P:
               		printedcharacters[holder] = 'p';
               		holder++;
                case ALLEGRO_KEY_Q:
               		printedcharacters[holder] = 'q';
               		holder++;
                case ALLEGRO_KEY_R:
               		printedcharacters[holder] = 'r';
               		holder++;
                case ALLEGRO_KEY_S:
               		printedcharacters[holder] = 's';
               		holder++;
                case ALLEGRO_KEY_T:
               		printedcharacters[holder] = 't';
               		holder++;
                case ALLEGRO_KEY_U:
               		printedcharacters[holder] = 'u';
               		holder++;
                case ALLEGRO_KEY_V:
               		printedcharacters[holder] = 'v';
               		holder++;
                case ALLEGRO_KEY_W:
               		printedcharacters[holder] = 'w';
               		holder++;
                case ALLEGRO_KEY_X:
               		printedcharacters[holder] = 'x';
               		holder++;
                case ALLEGRO_KEY_Y:
               		printedcharacters[holder] = 'y';
               		holder++;
                case ALLEGRO_KEY_Z:
               		printedcharacters[holder] = 'z';
               		holder++;
         	}
      	}
}
}
