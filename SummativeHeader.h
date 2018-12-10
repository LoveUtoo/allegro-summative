const int SCREEN_W = 900;       // screen width
const int SCREEN_H = 480;       // screen height

#define TEXTCOLOR al_map_rgb(255,255,255)
#define BGCOLOR al_map_rgb(0,0,0)

//Define structs
stuct Words {
    //characters you have typed so far
    char hotbar [30];
    //words on screen
    char OnscreenWords [30][20];
    char OffscreenWords [30][100];
};

struct Stats {
    //number of astroids created (counter)
    int created
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
char determineDifficulty();
