typedef struct Game {
int ScreenWidth;
int ScreenHeight;
const char* Title;
} Game;

Game InitGame(int width, int height, const char* title);
