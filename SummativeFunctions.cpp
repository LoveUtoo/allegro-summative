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

// the positions of the highscore button
    imgData HighScore;
    HighScore.left = 260 ;
	HighScore.right = 640 ;
	HighScore.top = 275 ;
	HighScore.bot = 290 ;
//the position of the How to play button
	imgData HTP;
    HTP.left = 290 ;
	HTP.right = 610 ;
	HTP.top = 410 ;
	HTP.bot = 425;
//the position of the credits button
	imgData Credits;
    Credits.left = 350 ;
	Credits.right = 550 ;
	Credits.top = 440 ;
	Credits.bot = 455 ;
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
    al_draw_text(font, TEXTCOLOR, MID_SCREEN, 400, ALLEGRO_ALIGN_CENTRE, "HOW TO PLAY");
    al_draw_text(font, TEXTCOLOR, MID_SCREEN, 430, ALLEGRO_ALIGN_CENTRE, "CREDITS");

    al_flip_display();

    while(true) {
        // Getting a position of the mouse and creating the events in which to call functions
        al_get_mouse_state(&mouseState);

        if (mouseClick(StartButton, mouseState) == 1) {
            al_clear_to_color(BGCOLOR);
            al_flip_display();
            printDifficulty(font, display, mouseState);
        }else if (mouseClick(QuitButton, mouseState) == 1){
            al_clear_to_color(BGCOLOR);
            al_flip_display();
            al_destroy_display(display);
            break; // quit game
        }else if (mouseClick(HighScore, mouseState) == 1) {
            loadhighscore(font, display, mouseState);
        }else if (mouseClick(HTP, mouseState) == 1) {
            printHTP(font, display, mouseState);
        }else if (mouseClick(Credits, mouseState) == 1) {
            printCredits(font, display, mouseState);
        }

        al_rest(1 / fps);
    }

}

//function that loads highscore screen
void loadhighscore(ALLEGRO_FONT *font, ALLEGRO_DISPLAY *display, ALLEGRO_MOUSE_STATE& mouseState){
    al_clear_to_color(BGCOLOR);
    al_flip_display();

    imgData QuitButton;
	QuitButton.left = 400 ;
    QuitButton.right = 500 ;
    QuitButton.top = 355 ;
    QuitButton.bot = 380 ;

    int highscorenum[10];
    char highscorename[10][30];
    int num = 0;

    FILE *fptr;
    fptr = fopen("highscore.txt", "r");

    al_draw_text(font, TEXTCOLOR, MID_SCREEN, 350, ALLEGRO_ALIGN_CENTRE, "QUIT");

    while (fscanf(fptr, "%s", highscorename[num]) != EOF) {
        fscanf(fptr, "%d", &highscorenum[num]);
        //al_draw_text(font, TEXTCOLOR, 250, 70 + num*50, ALLEGRO_ALIGN_CENTRE, highscorename[num]);
        //al_draw_textf(font, TEXTCOLOR, 450, 70 + num*50, ALLEGRO_ALIGN_CENTRE, "%d", highscorenum[num]);
        num++;
    }

    while (true) {
        al_get_mouse_state(&mouseState);

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

//function that shows how to play screen
void printHTP(ALLEGRO_FONT *font, ALLEGRO_DISPLAY *display, ALLEGRO_MOUSE_STATE& mouseState) {
    al_clear_to_color(BGCOLOR);
    al_draw_text(font, TEXTCOLOR, MID_SCREEN, 100, ALLEGRO_ALIGN_CENTRE, "Words will fall from space");
    al_draw_text(font, TEXTCOLOR, MID_SCREEN, 130, ALLEGRO_ALIGN_CENTRE, "Type them out to destroy them");
    al_draw_text(font, TEXTCOLOR, MID_SCREEN, 160, ALLEGRO_ALIGN_CENTRE, "If you don't you lose a life");
    al_draw_text(font, TEXTCOLOR, MID_SCREEN, 190, ALLEGRO_ALIGN_CENTRE, "If you lose 3 lives you die");
    al_draw_text(font, TEXTCOLOR, MID_SCREEN, 350, ALLEGRO_ALIGN_CENTRE, "QUIT");
    al_flip_display();

    imgData QuitButton;
	QuitButton.left = 400 ;
    QuitButton.right = 500 ;
    QuitButton.top = 355 ;
    QuitButton.bot = 380 ;
    //checking for mouse input loop
    while (true) {
        al_get_mouse_state(&mouseState);

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

//function that prints credit screen
void printCredits(ALLEGRO_FONT *font, ALLEGRO_DISPLAY *display, ALLEGRO_MOUSE_STATE& mouseState)  {
    al_clear_to_color(BGCOLOR);
    al_draw_text(font, TEXTCOLOR, MID_SCREEN, 100, ALLEGRO_ALIGN_CENTRE, "Devs:");
    al_draw_text(font, TEXTCOLOR, MID_SCREEN, 130, ALLEGRO_ALIGN_CENTRE, "Nicolas Coballe and Allan Cao");
    al_draw_text(font, TEXTCOLOR, MID_SCREEN, 170, ALLEGRO_ALIGN_CENTRE, "Real OG Gangster:");
    al_draw_text(font, TEXTCOLOR, MID_SCREEN, 200, ALLEGRO_ALIGN_CENTRE, "Ms Cullum");
    al_draw_text(font, TEXTCOLOR, MID_SCREEN, 240, ALLEGRO_ALIGN_CENTRE, "Testers:");
    al_draw_text(font, TEXTCOLOR, MID_SCREEN, 270, ALLEGRO_ALIGN_CENTRE, "Blake Stanley + Simon Marcotte");
    al_draw_text(font, TEXTCOLOR, MID_SCREEN, 350, ALLEGRO_ALIGN_CENTRE, "QUIT");
    al_flip_display();

    imgData QuitButton;
	QuitButton.left = 400 ;
    QuitButton.right = 500 ;
    QuitButton.top = 355 ;
    QuitButton.bot = 380 ;
    //checking for mouse input loop
    while (true) {
        al_get_mouse_state(&mouseState);

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

//function that prints the choose difficulty screen
void printDifficulty(ALLEGRO_FONT *font, ALLEGRO_DISPLAY *display, ALLEGRO_MOUSE_STATE& mouseState) {
    //writes the difficulties
    al_draw_text(font, TEXTCOLOR, MID_SCREEN, 265, ALLEGRO_ALIGN_CENTRE, "Easy");
    al_draw_text(font, TEXTCOLOR, MID_SCREEN, 295, ALLEGRO_ALIGN_CENTRE, "Medium");
    al_draw_text(font, TEXTCOLOR, MID_SCREEN, 325, ALLEGRO_ALIGN_CENTRE, "Hard");
    al_flip_display();

    //initializes structs
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
    //initializing variables
    double timer = 0;
    int wordNum = 0;
    bool alive = true;
    Words game;
    int counter = 0;

    // initializing everything to 0 in the structure
    memset(&game , 0, sizeof(game));

    //reading in words
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

    //allowing function to read in keyboard and mouse
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    //number of words
    int wordIndex = 0;
    //lives
    int lives = 3;
    int score = 0;
    srand(time(0));

    //loop the game is running in to make animation
    while (alive == true) {

        ALLEGRO_EVENT ev;
        if(al_get_next_event(event_queue, &ev) && ev.type==ALLEGRO_EVENT_KEY_CHAR){
            processKeyboardEvent(ev.keyboard, game, score, 0, font, display, mouseState);
        }
        if(checkDamage(font, display, game, lives, wordNum)) {
            al_clear_to_color(RED);
            al_flip_display();
            al_rest(0.1);
            continue;
        }


        //creates words based off difficulty
        if (difficulty == 'e' && timer > 7) {
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

        //drawings all the updated text
        al_clear_to_color(BGCOLOR);
        al_draw_text(font, TEXTCOLOR, MID_SCREEN, 200, ALLEGRO_ALIGN_CENTRE, game.hotbar);

        al_draw_textf(font, TEXTCOLOR, 10, 10, ALLEGRO_ALIGN_LEFT, "Score: %d", score);

        al_draw_textf(font, TEXTCOLOR, 700, 10, ALLEGRO_ALIGN_LEFT, "Lives: %d", lives);

        wordLocation(font, display, wordNum, game);

        //checks for death based on if lives are zero
        if (lives == 0) {
            al_clear_to_color(BGCOLOR);
            al_flip_display();
            printDeath(font, display, mouseState, score, game, event_queue);
        }

        al_flip_display();
        timer += (1 / fps);
        al_rest(1 / fps);
    }
    //unused code for images
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
    //reseting hotbar to NULL
    game.hotbar[0] = '\0';
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    imgData QuitButton;
    QuitButton.left = 400 ;
    QuitButton.right = 500 ;
    QuitButton.top = 355 ;
    QuitButton.bot = 380 ;

    //loop that looks for keyboard and mouse inputs
    while (true) {

        al_get_mouse_state(&mouseState);

        ALLEGRO_EVENT ev;
        if(al_get_next_event(event_queue, &ev) && ev.type==ALLEGRO_EVENT_KEY_CHAR){
            processKeyboardEvent(ev.keyboard, game, score, 1, font, display, mouseState);
        }

        al_clear_to_color(BGCOLOR);

        //redrawing updated text
        al_draw_text(font, TEXTCOLOR, MID_SCREEN, 100, ALLEGRO_ALIGN_CENTER, "Name:");
        al_draw_text(font, TEXTCOLOR, MID_SCREEN, 250, ALLEGRO_ALIGN_CENTER, "You died");
        al_draw_textf(font, TEXTCOLOR, MID_SCREEN, 300, ALLEGRO_ALIGN_CENTER, "Score: %d", score);
        al_draw_text(font, TEXTCOLOR, MID_SCREEN, 350, ALLEGRO_ALIGN_CENTER, "Quit");
        al_draw_text(font, TEXTCOLOR, MID_SCREEN, 150, ALLEGRO_ALIGN_CENTRE, game.hotbar);

        //checking for quit button detection
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

//function that prints highscore to text file
void highscore(int score, Words& game) {
    FILE *fptr;
    fptr = fopen("highscore.txt", "a");
    fputs(game.hotbar, fptr);
    fputs(" ", fptr);
    fprintf(fptr, "%d", score);
    fputs("\n", fptr);
}

//function that take in keyboard inputs
void processKeyboardEvent(const ALLEGRO_KEYBOARD_EVENT& ev, Words &game, int &score, int x, ALLEGRO_FONT *font, ALLEGRO_DISPLAY *display, ALLEGRO_MOUSE_STATE& mouseState) {
	char character;
	if(ev.keycode>=ALLEGRO_KEY_A && ev.keycode<=ALLEGRO_KEY_Z){
        character = 'a' + (ev.keycode - ALLEGRO_KEY_A);
    }
    //special characters
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
                //checking for either enter means enter word or input name
                highscore(score, game);
                al_clear_to_color(BGCOLOR);
                printTitleScreen(font, display, mouseState);
            }
            else if (x == 0) {
                if(game.OnscreenWords[i][0]==0) continue;
                if(strcasecmp(game.hotbar, game.OnscreenWords[i]) != 0) continue;
                // When we find a match
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

}
