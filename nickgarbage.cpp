void loadhighscore(ALLEGRO_FONT *font, ALLEGRO_DISPLAY *display){
    al_clear_to_color(BGCOLOR);
    al_flip_display();

    int highscorenum[10];
    char highscorename[10][30];
    int num = 0;
    
    FILE *fptr;
    fptr = fopen("highscore.txt", "r");
    
    while (fscanf(fptr, "%s", highscorename[num]) != EOF) {
        fscanf(fptr, "%d", &highscorenum[num]);
        al_draw_text(font, TEXTCOLOR, 250, 70 + num*50, ALLEGRO_ALIGN_CENTRE, highscorename[num]);
        al_draw_textf(font, TEXTCOLOR, 450, 70 + num*50, ALLEGRO_ALIGN_CENTRE, "%d", highscorenum[num]);
        num++;
    }
    
    al_flip_display();
    fclose(fptr);
}
