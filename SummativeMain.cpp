/*****************************************************************************
 *	Name:     Nicolas                                                        *
 *	Date:     November 2018                                                  *
 *                                                                           *
 *	Title: Space-Word Blaster                                              *
 *	                                                                         *
 *	Usage:   Allow us to show how we can use allegro to make games           *
 *	                                                                         *
 *	Revision History:                                                        *
 *	                                                                         *
 *	Known Issues:                                                            *
 *	                                                                         *
 *****************************************************************************/
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>                   // For allegro, must be in compiler search path.
#include <allegro5/allegro_native_dialog.h>		// for message box
#include <allegro5/allegro_image.h>
#include "SummativeHeader.h"

int main(int argc, char *argv[]) {
	//intialize variables
	char difficulty;
    Words game[100];
    Stats player;

   	//initialize Allegro
    initializeAllegro();

    //declare and initialize display and font, and check they have been setup properly
    ALLEGRO_DISPLAY *display = al_create_display(SCREEN_W, SCREEN_H);
    ALLEGRO_FONT *font = al_load_ttf_font("Space Age.ttf", 36, 0);
    checkSetup(display, font);

    ALLEGRO_MOUSE_STATE mouseState;

    //set window title
	al_set_window_title(display, "Space-Word Blaster");

	//prints title screen
	printTitleScreen(font, display, mouseState);

	//starts the game
	//startGame();

	//ends the game
	//printDeathScreen();

	return 0;



}







