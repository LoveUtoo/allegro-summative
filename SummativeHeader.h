const int SCREEN_W = 900;       // screen width
const int SCREEN_H = 480;       // screen height

//Define structs
stuct WordBank {
    //characters you have typed so far
    char hotbar [30];
    //words on screen
    char OnscreenWords [30][20];
    char OffscreenWords [30][100];
};

void checkDeath();
void printDeathscreen();
void generateWord();
void deleteWord();
void printTitleScreen();
void startGame();
