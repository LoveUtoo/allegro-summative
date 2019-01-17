#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
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
        //printf("%d %d %0.2f\n", mouseState.x, mouseState.y, mouseState.pressure);

        if (mouseClick(StartButton, mouseState) == 1) {
            al_clear_to_color(BGCOLOR);
            al_flip_display();
            printDifficulty(font, display, mouseState);
        }else if (mouseClick(QuitButton, mouseState) == 1){
            al_clear_to_color(BGCOLOR);
            al_flip_display();
            al_destroy_display(display);
            break; // quit game
        }

        al_rest(1 / fps);
    }

}

//function that prints the choose difficulty screen
void printDifficulty(ALLEGRO_FONT *font, ALLEGRO_DISPLAY *display, ALLEGRO_MOUSE_STATE& mouseState) {
    //writes the difficulties
    al_draw_text(font, TEXTCOLOR, MID_SCREEN, 265, ALLEGRO_ALIGN_CENTRE, "Easy");
    al_draw_text(font, TEXTCOLOR, MID_SCREEN, 295, ALLEGRO_ALIGN_CENTRE, "Medium");
    al_draw_text(font, TEXTCOLOR, MID_SCREEN, 325, ALLEGRO_ALIGN_CENTRE, "Hard");
    al_flip_display();


    imgData Easy;
    Easy.left = 385;
    Easy.right = 515;
    Easy.top = 270;
    Easy.bot = 290;

    imgData Medium;
    Medium.left = 360;
    Medium.right = 535;
    Medium.top = 300;
    Medium.bot = 320;

    imgData Hard;
    Hard.left = 390;
    Hard.right = 510;
    Hard.top = 330;
    Hard.bot = 350;

    //assigns difficulty based off of click
    while(true) {
        // Getting a position of the mouse and creating the events in which to call functions
        al_get_mouse_state(&mouseState);
        //printf("%d %d %0.2f\n", mouseState.x, mouseState.y, mouseState.pressure);

        //easy
        if (mouseClick(Easy, mouseState) == 1) {
            al_clear_to_color(BGCOLOR);
            al_flip_display();
            startGame(font, display, mouseState, 'e');
        //medium
        }else if (mouseClick(Medium, mouseState) == 1){
            al_clear_to_color(BGCOLOR);
            al_flip_display();
            startGame(font, display, mouseState, 'm');
        //hard
        }else if (mouseClick(Hard, mouseState) == 1){
            al_clear_to_color(BGCOLOR);
            al_flip_display();
            startGame(font, display, mouseState, 'h');
        }

        al_rest(1 / fps);
    }
}

//function that starts the game when the user presses the start image.
void startGame(ALLEGRO_FONT *font, ALLEGRO_DISPLAY *display, ALLEGRO_MOUSE_STATE& mouseState, char difficulty){
    double timer = 0;
    int wordNum = 0;
    //double = 60;
    bool alive = true;
    Words game;
    // initializing everything to 0 in the structure
    memset(&game , 0, sizeof(game));
    int counter = 0;
    FILE *fptr;
    if (difficulty == 'e'){
        fptr = fopen("WordBankEasy.txt", "r");
    }else if (difficulty == 'm') {
        fptr = fopen("WordBankMedium.txt", "r");
    }else if (difficulty == 'h') {
        fptr = fopen("WordBankHard.txt", "r");
    }

    getWords(fptr, game, wordNum);
    fclose(fptr);

    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    //number of words
    int wordIndex = 0;
    //lives
    int lives = 3;
    int score = 0;

    while (alive == true) {
        ALLEGRO_EVENT ev;
        if(al_get_next_event(event_queue, &ev) && ev.type==ALLEGRO_EVENT_KEY_CHAR){
            processKeyboardEvent(ev.keyboard, game, score, 0);
        }
        if(checkDamage(font, display, game, lives, wordNum)) {
            al_clear_to_color(RED);
            al_flip_display();
            al_rest(0.1);
            continue;
        }


        if (difficulty == 'e' && timer > 1) {
            chooseWord(game, wordNum, wordIndex);
            timer = 0;
        }

        if (difficulty == 'm' && timer > 5) {
            chooseWord(game, wordNum, wordIndex);
            timer = 0;
        }

        if (difficulty == 'h' && timer > 3) {
            chooseWord(game, wordNum, wordIndex);
            timer = 0;
        }

        al_clear_to_color(BGCOLOR);
        al_draw_text(font, TEXTCOLOR, MID_SCREEN, 200, ALLEGRO_ALIGN_CENTRE, game.hotbar);

        al_draw_textf(font, TEXTCOLOR, 10, 10, ALLEGRO_ALIGN_LEFT, "Score: %d", score);

        al_draw_textf(font, TEXTCOLOR, 700, 10, ALLEGRO_ALIGN_LEFT, "Lives: %d", lives);

        wordLocation(font, display, wordNum, game);

        if (lives == 0) {
            al_clear_to_color(BGCOLOR);
            al_flip_display();
            printDeath(font, display, mouseState, score, game, event_queue);
        }

        al_flip_display();
        timer += (1 / fps);
        al_rest(1 / fps);
    }
/*
    ALLEGRO_BITMAP *ship = al_load_bitmap("shipPlaceholder.png");
    ALLEGRO_BITMAP *gun = al_load_bitmap("cannonPlaceholder.png");
    al_convert_mask_to_alpha(ship, WHITE);
    al_convert_mask_to_alpha(gun, WHITE);
    al_draw_bitmap(gun, 600, 30, 0);
    al_draw_bitmap(ship, 250, 65, 0);
*/

}

//function that puts the words from the text file into offscreenwords
void getWords(FILE *fptr, Words& game, int &count){
    //for(int i = 0; i < 31; i++){
        // while this is not the end of the file
        count = 0;
        while(fgets(game.OffscreenWords[count], 30, fptr) != NULL){
                // remove ending cr/lf chars
            int n = strlen(game.OffscreenWords[count]);
            while(n>0 && isspace(game.OffscreenWords[count][n-1])) n--;
            game.OffscreenWords[count][n] = 0;
            //printf("%d: %s(%d)\n", count,game.OffscreenWords[count], strlen(game.OffscreenWords[count]));
            //fgets(wordbank[i], 35, fptr);
            //int n = strlen(game.OffscreenWords[count]);
            //while(n>0 && isspace(game.OffscreenWords[count][n-1]))n--;
            //if(n<1) continue;
            count++;
            if(count>=100) break;
        }
    //}
}

//function that changes and prints the words based off their location
void wordLocation(ALLEGRO_FONT *font, ALLEGRO_DISPLAY *display, int wordNum, Words& game) {
    char holder[30];
    for (int i=0; i<30; i++) {
            if(game.OnscreenWords[i][0]==0) continue; // valid on screen word?
            game.wordY[i] += 1;
            al_draw_text(font, TEXTCOLOR, game.wordX[i], game.wordY[i], ALLEGRO_ALIGN_CENTRE, game.OnscreenWords[i]);
    }
}

// Chooses the words that the user needs to type
void chooseWord(Words& game, int wordNum, int &wordIndex) {
    if (wordIndex >= 30) {
        wordIndex = 0;
    }
    srand(time(NULL));
    int pos = 0;
    int randPos = rand() % 3;
    if (randPos == 0) {
        pos = 150;
    } else if (randPos == 1) {
        pos = 400;
    } else if (randPos == 2) {
        pos = 700;
    }
    int random = rand() % wordNum;
    char holder[30];
    for (int i = 0; i<30; i++) {
        strcpy(holder, game.OffscreenWords[random]);
        if ((strcmp(holder, game.OnscreenWords[i])) == 0) {
           i = 0;
           random = rand() % wordNum;
           printf("change");
        }
    }
    strcpy(game.OnscreenWords[wordIndex], holder);
    if(strlen(game.OnscreenWords[wordIndex]) >= 10){
        pos = 400;
    }
    game.wordY[wordIndex] = 20;
    game.wordX[wordIndex] = pos;
    wordIndex++;
}

void printDeath(ALLEGRO_FONT *font, ALLEGRO_DISPLAY *display, ALLEGRO_MOUSE_STATE& mouseState, int score, Words& game, ALLEGRO_EVENT_QUEUE *event_queue) {
    game.hotbar[0] = '\0';
    al_get_mouse_state(&mouseState);
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    imgData QuitButton;
    QuitButton.left = 400 ;
    QuitButton.right = 500 ;
    QuitButton.top = 355 ;
    QuitButton.bot = 380 ;

    while (true) {

        printf("%d %d %0.2f\n", mouseState.x, mouseState.y, mouseState.pressure);

        ALLEGRO_EVENT ev;
        if(al_get_next_event(event_queue, &ev) && ev.type==ALLEGRO_EVENT_KEY_CHAR){
            processKeyboardEvent(ev.keyboard, game, score, 1);
        }

        al_clear_to_color(BGCOLOR);

        al_draw_text(font, TEXTCOLOR, MID_SCREEN, 100, ALLEGRO_ALIGN_CENTER, "Name:");
        al_draw_text(font, TEXTCOLOR, MID_SCREEN, 250, ALLEGRO_ALIGN_CENTER, "You died");
        al_draw_textf(font, TEXTCOLOR, MID_SCREEN, 300, ALLEGRO_ALIGN_CENTER, "Score: %d", score);
        al_draw_text(font, TEXTCOLOR, MID_SCREEN, 350, ALLEGRO_ALIGN_CENTER, "Quit");
        al_draw_text(font, TEXTCOLOR, MID_SCREEN, 150, ALLEGRO_ALIGN_CENTRE, game.hotbar);

//        for (int i=0)


        if (mouseClick(QuitButton, mouseState) == 1){
            al_clear_to_color(BGCOLOR);
            al_flip_display();
            printTitleScreen(font, display, mouseState);
            break; // quit game
        }

        al_flip_display();
        al_rest(1 / fps);
    }
}

//checks to see if words reach the bottom of the screen and applies damage
bool checkDamage(ALLEGRO_FONT *font, ALLEGRO_DISPLAY *display, Words& game, int &lives, int wordNum) {
    int lives_saved = lives;
    for (int i=0; i<30; i++) {
        if (game.OnscreenWords[i][0] && game.wordY[i] >= 500) {
            lives = lives - 1;
            game.OnscreenWords[i][0] = 0;
        }
    }
    return (lives_saved>lives);
}

// Function that checks if you clicked a button
int mouseClick(imgData& a, ALLEGRO_MOUSE_STATE& mouseState){
    if (mouseState.x > a.left && mouseState.x < a.right && mouseState.y > a.top && mouseState.y < a.bot && mouseState.pressure == 1.0) {
        return 1;
    }//else if (mouseState.x > a.left && mouseState.x < a.right && mouseState.y > a.top && mouseState.y < a.bot && mouseState.pressure != 1.0) {
        return 0;
    //}
}

void highscore(int score, Words& game) {
    FILE *fptr;
    fptr = fopen("highscore.txt", "a");
    fputs(game.hotbar, fptr);
    fputs(" ", fptr);
    fputs(score, fptr);
    fputs("\n", fptr);
}

//function that take in keyboard inputs
void processKeyboardEvent(const ALLEGRO_KEYBOARD_EVENT& ev, Words &game, int &score, int x){
	char character;
	if(ev.keycode>=ALLEGRO_KEY_A && ev.keycode<=ALLEGRO_KEY_Z){
        	character = 'a' + (ev.keycode - ALLEGRO_KEY_A);
         	}
	else if(ev.keycode == ALLEGRO_KEY_SPACE){
		character = ' ';
      	}else if(ev.keycode == ALLEGRO_KEY_BACKSPACE) {
        	character = '~';
	}else if(ev.keycode == ALLEGRO_KEY_ENTER) {
        	character = '`';
	}else{
}
	int num = strlen(game.hotbar);
	if(character == '~'){
        if (num > 0) game.hotbar[num-1] = '\0';
	}else if(character == '`'){
	    if(num<=0) return;
		for(int i = 0; i<30; i++){
            if (x == 1) {
                highscore(score, game);
            }
            else if (x == 0) {
                if(game.OnscreenWords[i][0]==0) continue;
                if(strcasecmp(game.hotbar, game.OnscreenWords[i]) != 0) continue;
                // When we find a match
                //printf("found match at %d %s\n", i, game.OnscreenWords[i]);
                score += strlen(game.OnscreenWords[i]) * 100;
                game.OnscreenWords[i][0] = 0;
                game.hotbar[0] = '\0';
                break;
            }
		}
	}else{
	game.hotbar[num] = character;
	game.hotbar[num+1] = '\0';
	}

	//printf("hotbar: %d %c %s\n", num, character, game.hotbar);
}

void loadhighscore(ALLEGRO_FONT *font, ALLEGRO_DISPLAY *display){
    al_clear_to_color(BGCOLOR);
    al_flip_display();

    int highscorenum[10];
    char highscorename[10][30];
    FILE *fptr;
    fptr = fopen("highscore.txt", "r");
    for(int i = 0; i<10; i++){
        fscanf(fptr, "%s", highscorename[i]);
        fscanf(fptr, "%d", highscorenum[i]);
        al_draw_text(font, TEXTCOLOR, 250, 70 + i*50, ALLEGRO_ALIGN_CENTRE, highscorename[i]);
        al_draw_text(font, TEXTCOLOR, 265, 70 + i*50, ALLEGRO_ALIGN_CENTRE, highscorenum[i]);
    }
}

