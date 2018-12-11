#include <stdio.h>
#include <string.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>               // For allegro, must be in compiler search path.
#include <allegro5/allegro_native_dialog.h> 		// for message box
#include "SummativeHeader.h"

char determineDifficulty() {
    
}

void printTitleScreen(ALLEGRO_FONT *font) {
    al_draw_text(font, TEXTCOLOR, 200, 5, ALLEGRO_ALIGN_CENTRE, "Game");
    
    al_flip_display();
}

const int WordMaxLen = 30;
const int WordLimit = 35;
char wordbank[WordLimit][word_max_len+1];
int wordCount = 0;

void startGame()
{
    printf("What difficulty do you want to play? Easy, Medium, Hard (e/m/h)\n");
    char difficulty = determineDifficulty();
    const char *file = NULL;
    if (difficulty == 'e'){
        file = "WordBankEasy.txt";
    } else if (difficulty == 'm') {
        file = "WordBankMedium.txt";
    } else if (difficulty == 'h') {
        file = "WordBankHard.txt";
    }
    loadWords(file);
}
void loadWords(const char *file)
{
    FILE *fptr = fopen(file, "r");
    if(!fptr) {
        printf("cannot open file %s. %s\n", file, strerror(errno));
        return -1;
    }
    char line[word_max_len+1];
    wordCount = 0;
    while(fgets(line, sizeof(line), fptr))
    {
        int len = strlen(line);
        while(len>0 && isspace(line[len-1])) len--;
        if(len<1) continue;
        strcpy(wordbank[wordCount], line);
        wordCount++;
        if(wordCount>=WordLimit) break;
    }
    fclose(fptr);
    return wordCount;
}
    
    
    int rnd = 0;
    int question = 0;
    while (fgets(wordbank[35] , 30, fptr) != EOF){
        for(int i = 0; i < 35; i++){
            fgets(wordbank[i], 30, fptr);
            counter = i;
        }
    }
    fclose(fptr);
    rnd = rand() % counter;
    strcpy (OnscreenWords[rnd][20], wordbank[rnd][30]);
    }
}

void printDeathScreen() {
  
}
