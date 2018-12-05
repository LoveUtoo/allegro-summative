/*****************************************************************************
 *	Name:     Nicolas                                                        *
 *	Date:     November 2018                                                  *
 *                                                                           *
 *	Purpose: Space-Word Blaster                                              *
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
#include <allegro5/allegro_native_dialog.h> 		// for message box
#include "SummativeHeader"

int main(int argc, char *argv[]) {
    //initialize Allegro
    initializeAllegro();
    
    //declare and initialize display and font, and check they have been setup properly
    ALLEGRO_DISPLAY *display = al_create_display(SCREEN_W, SCREEN_H);
    ALLEGRO_FONT *font = al_load_ttf_font("SF_Cartoonist_Hand.ttf", 36, 0);
    checkSetup(display, font);

    //set window title
	al_set_window_title(display, "Space-Word Blaster");
  
  
  
}
































































































































