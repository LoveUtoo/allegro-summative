!summativefunctions - difficulty screen

void printDifficulty(ALLEGRO_FONT *font, ALLEGRO_DISPLAY *display, ALLEGRO_MOUSE_STATE& mouseState);

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
        printf("%d %d %0.2f\n", mouseState.x, mouseState.y, mouseState.pressure);

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

!summativeheader - new constant double for frames per second

const double fps = 60; //fps

!summativefunctions - changing func arguments for startGame *change this in actual function and in prototyping

void startGame(ALLEGRO_FONT *font, ALLEGRO_DISPLAY *display, ALLEGRO_MOUSE_STATE& mouseState, char difficulty);
