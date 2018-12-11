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
    al_draw_text(font, TEXTCOLOR, MID_SCREEN, 5, ALLEGRO_ALIGN_CENTRE, "SPACE-WORD BLASTER EXTREME");
    
    al_flip_display();
}

const int WordMaxLen = 30;
const int WordLimit = 35;
struct WordBank {
    char words[WordLimit][WordMaxLen+1];
    int wordsCount;
    bool used[WordLimit];
    int usedCount;
};
struct workbank;

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
    char line[WordMaxLen+1];
    int count = 0;
    memset(&wordbank, 0, sizeof(wordbank));
    while(fgets(line, sizeof(line), fptr))
    {
        int len = strlen(line);
        while(len>0 && isspace(line[len-1])) len--;
        if(len<1) continue;
        strcpy(wordbank.words[count], line);
        count++;
        if(count>=WordLimit) break;
    }
    wordbank.wordsCount = count;
    fclose(fptr);
    return count;
}
    
int chooseNextWord(char *word)
{
    int count = wordbank.wordsCount - wordbank.usedCount;
    if (count>0) {
        int wordIndex = rand() % count;
        count = -1;
        for(int i=0; i<wordbank.wordsCount; i++) {
            if(wordbank.used[i]) continue;
            count++;
            if(count==wordIndex) {
                strcpy(word, wordbank.words[i]);
                wordbank.used[i] = true;
                wordbank.usedCount++;
                return 1;
            }
        }
    }
    return 0;
}

void printDeathScreen() {
  
}
