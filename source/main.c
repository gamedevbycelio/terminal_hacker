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

const int screenWidth = 1280;
const int screenHeight = 720;
const char* title = "Terminal Hacker -- Become the best hacker!";



int main(void) {
	// Initialization
	//--------------------------------------------------------------------------------------
	Game game = InitGame(screenWidth, screenHeight, title);

	InitWindow(game.ScreenWidth, game.ScreenHeight, game.Title);

	// Load assets

	// Create terminal
	Texture2D termText = LoadTexture("./resources/visuals/old_crt.png"); // 1440x1080
	int termFrameWidth = termText.width;
	int termFrameHeight = termText.height;

	Rectangle termSource = { 0.0f, 0.0f, termFrameWidth, termFrameHeight };

	Rectangle termDest = { screenWidth/2.0f, screenHeight/2.0f, 1280, 960 };
	Vector2 termOrigin = { 638, 464 };

	Texture2D screen = LoadTexture("./resources/visuals/old_crt_screen.png");
	Rectangle screenSource = { 0.0f, 0.0f, termFrameWidth, termFrameHeight };
	Rectangle screenDest = { screenWidth/2.0f, screenHeight/2.0f, 1280, 960 };
	Vector2 screenOrigin = { 638, 464 };

	Texture2D screenReflection = LoadTexture("./resources/visuals/old_crt_sreen_reflection_weak.png");


	SetTargetFPS(60); // Set our game to run at 60 frames-per-second

	InitAudioDevice();

	Music music = LoadMusicStream("./resources/audio/digital_hum.wav");

	music.looping = true;

	SetMusicVolume(music, 0.25f);
	PlayMusicStream(music);
	//--------------------------------------------------------------------------------------
	// Main game loop
	while (!WindowShouldClose()) { // Detect window close button or ESC key
		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------
		if (GetKeyPressed() == 70) {
			ToggleFullscreen();
		}

		UpdateMusicStream(music);

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();
		ClearBackground(BLACK);

		DrawTexturePro(screen, screenSource, screenDest, screenOrigin, 0.0f, WHITE);
		DrawTexturePro(screenReflection, screenSource, screenDest, screenOrigin, 0.0f, WHITE);
		DrawTexturePro(termText, termSource, termDest, termOrigin, 0.0f, WHITE);

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------
	UnloadMusicStream(music);
	CloseAudioDevice();
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}
