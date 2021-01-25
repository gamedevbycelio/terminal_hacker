/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

// builtin + lib headers here
#include <raylib.h>
#include <stdio.h>

// custom headers
#include "./game.h"
#include "./terminal.h"

const int screenWidth = 1280;
const int screenHeight = 720;
const char* title = "Terminal Hacker -- Become the best hacker!";

int main(void) {
	// Initialization
	//--------------------------------------------------------------------------------------
	SetTargetFPS(60); // Set our game to run at 60 frames-per-second

	InitAudioDevice();

	Game game = InitGame(screenWidth, screenHeight, title);
	InitWindow(game.ScreenWidth, game.ScreenHeight, game.Title);

	// Load assets

	// Create terminal
	Terminal terminal = NewTerminal(game.ScreenWidth, game.ScreenHeight);
	PlayTerminalMusic(terminal);

	//--------------------------------------------------------------------------------------
	// Main game loop
	while (!WindowShouldClose()) { // Detect window close button or ESC key
		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------
		
		// TODO: Figure out FullScreen in debian?

		UpdateTerminalMusic(terminal);

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(BLACK);	
		DrawTerminal(terminal);	
		
		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------
	UnloadTerminal(terminal);
	CloseAudioDevice();
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}
