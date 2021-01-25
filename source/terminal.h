#include <raylib.h>

typedef struct Terminal {
	int GameWidth;
	int GameHeight;
	Texture2D Body;
	Texture2D Screen;
	Texture2D ScreenReflection;
	Music OnSound;
} Terminal;

Terminal NewTerminal(int gameWidth, int gameHeight);
void DrawTerminal(Terminal terminal);
void PlayTerminalMusic(Terminal terminal);
void UpdateTerminalMusic(Terminal terminal);
void UnloadTerminal(Terminal terminal);
