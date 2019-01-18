const int SCREEN_W = 900;       // screen width
const int SCREEN_H = 480;       // screen height
const int MID_SCREEN = (SCREEN_W) / 2;
const double fps = 60; //fps

#define TEXTCOLOR al_map_rgb(255,255,255)
#define BGCOLOR al_map_rgb(0,0,0)
#define WHITE al_map_rgb(255,255,255)
#define RED al_map_rgb(100,0,0)


//Define structs
struct Words {
    // The string that the user has typed in the box. The print words function also goes here.
    char hotbar[30];
    //words on screen
    //char OnscreenWords [20][30];
    char OnscreenWords [30][30];
    char OffscreenWords [100][30];
    //int OffscreenWordsSize;
    int wordX[30];
    int wordY[30];
};


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

struct imgData {
    //x coordinate of left side
    int left;
    //x coordinate of right side
    int right;
    //y coordinate of top side
    int top;
    //y coordinate of bottom side
    int bot;
};

//general functions
void processKeyboardEvent (const ALLEGRO_KEYBOARD_EVENT& ev, Words &game, int &score, int x, ALLEGRO_FONT *font, ALLEGRO_DISPLAY *display, ALLEGRO_MOUSE_STATE& mouseState);
void printDifficulty(ALLEGRO_FONT *font, ALLEGRO_DISPLAY *display, ALLEGRO_MOUSE_STATE& mouseState);
int checkSetup(ALLEGRO_DISPLAY *display, ALLEGRO_FONT *font);
void initializeAllegro();
void printDeath(ALLEGRO_FONT *font, ALLEGRO_DISPLAY *display, ALLEGRO_MOUSE_STATE& mouseState, int score, Words& game, ALLEGRO_EVENT_QUEUE *event_queue);
void generateWord();
void getWords(FILE *fptr, Words& game, int &wordCount);
void deleteWord();
void printTitleScreen(ALLEGRO_FONT *font, ALLEGRO_DISPLAY *display, ALLEGRO_MOUSE_STATE& mouseState);
void startGame(ALLEGRO_FONT *font, ALLEGRO_DISPLAY *display, ALLEGRO_MOUSE_STATE& mouseState, char difficulty);
int wordPerMin(int a, int b);
int scoreDeterminer(char a[30]);
char determineDifficulty();
int mouseClick(imgData& a, ALLEGRO_MOUSE_STATE& mouseState);
void chooseWord(Words& game, int wordNum, int &wordIndex);
void wordLocation(ALLEGRO_FONT *font, ALLEGRO_DISPLAY *display, int wordNum, Words& game);
bool checkDamage(ALLEGRO_FONT *font, ALLEGRO_DISPLAY *display, Words& game, int &lives, int wordNum);
int checkFile(FILE* fptr);
void highscore(int score, Words& game);
void printHTP(ALLEGRO_FONT *font, ALLEGRO_DISPLAY *display, ALLEGRO_MOUSE_STATE& mouseState);
void printCredits(ALLEGRO_FONT *font, ALLEGRO_DISPLAY *display, ALLEGRO_MOUSE_STATE& mouseState);
void loadhighscore(ALLEGRO_FONT *font, ALLEGRO_DISPLAY *display,  ALLEGRO_MOUSE_STATE& mouseState);
