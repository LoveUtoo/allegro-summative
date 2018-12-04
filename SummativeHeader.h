const int SCREEN_W = 900;       // screen width
const int SCREEN_H = 480;       // screen height

//Define structs
stuct WordBank {
    //characters you have typed so far
    char hotbar [30];
    //words on screen
    char astWords [30][20];
};

void checkDeath (int a);
void printDeathscreen (int a);

