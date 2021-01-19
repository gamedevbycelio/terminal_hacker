#include "./game.h"

Game InitGame(int width, int height, const char* title) {
	Game g;
	g.ScreenWidth = width;
	g.ScreenHeight = height;
	g.Title = title;
	return g;	
} 
