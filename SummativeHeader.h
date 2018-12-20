const int SCREEN_W = 900;       // screen width
const int SCREEN_H = 480;       // screen height
const int MID_SCREEN = (SCREEN_W) / 2;

#define TEXTCOLOR al_map_rgb(255,255,255)
#define BGCOLOR al_map_rgb(0,0,0)
#define WHITE al_map_rgb(255,255,255)

// Initializing more variables
int lives = 3; 
// The string that the user has typed in the box. The print words function also goes here. 
char printedcharacters[30];
//Define structs
struct Words {
    //characters you have typed so far
    char hotbar [30];
    //words on screen
    char OnscreenWords [20][30];
    char OffscreenWords [100][30];
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
int checkSetup(ALLEGRO_DISPLAY *display, ALLEGRO_FONT *font);
void initializeAllegro();
void checkDeath();
void printDeathscreen();
void generateWord();
void getWords(FILE *fptr, char wordbank[][30], int &a);
void deleteWord();
void printTitleScreen(ALLEGRO_FONT *font, ALLEGRO_DISPLAY *display, ALLEGRO_MOUSE_STATE mouseState);
void startGame(Words game[]);
int wordPerMin(int a, int b);
int scoreDeterminer(char a[30]);
char determineDifficulty();
int mouseClick(imgData a, ALLEGRO_MOUSE_STATE mouseState);
