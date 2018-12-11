const int SCREEN_W = 900;       // screen width
const int SCREEN_H = 480;       // screen height
const int MID_SCREEN = (SCREEN_W) / 2;

#define TEXTCOLOR al_map_rgb(255,255,255)
#define BGCOLOR al_map_rgb(0,0,0)

//Define structs
struct Words {
    //characters you have typed so far
    char hotbar [30];
    //words on screen
    char OnscreenWords [30][20];
    char OffscreenWords [30][100];
};
int lives = 3; 
struct Stats {
    //number of astroids created (counter)
    int created;
    //number of asteroids destroyed
    int destroyed;
    //duration of time alive
    int time;
    //words per minute (destroyed / time)
    int wpm;
    //score based off words typed
    int score;
};

//general functions
int checkSetup(ALLEGRO_DISPLAY *display, ALLEGRO_FONT *font);
void initializeAllegro();
void checkDeath();
void printDeathscreen();
void generateWord();
void deleteWord();
void printTitleScreen(ALLEGRO_FONT *font);
void startGame(Words game[]);
int wordPerMin(int a, int b);
int scoreDeterminer(char a[30]);
char determineDifficulty();
