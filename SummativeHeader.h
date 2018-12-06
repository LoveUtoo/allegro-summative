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

struct Stats {
    //number of asteroids destroyed
    int destroyed;
    //duration of time alive
    int time;
    //words per minute (destroyed / time)
    int wpm;
    //score based off words typed
    int score;
}

//general functions
int readFile(WordBank w[], int &counter);
void checkDeath();
void printDeathscreen();
void generateWord();
void deleteWord();
void printTitleScreen();
void startGame();
int wordPerMin(int a, int b);
int scoreDeterminer(char a[30]);

//allegro functions
void initializeAllegro();
int checkSetup(ALLEGRO_DISPLAY *display, ALLEGRO_FONT *font);
