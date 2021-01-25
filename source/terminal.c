#include <raylib.h>
#include "./terminal.h"

Terminal NewTerminal(int gameWidth, int gameHeight) {
	Terminal terminal;
	
	// Load the resources that compose a terminal
	terminal.GameWidth = gameWidth;
	terminal.GameHeight = gameHeight;
	terminal.Body = LoadTexture("./resources/visuals/old_crt.png");
	terminal.Screen = LoadTexture("./resources/visuals/old_crt_screen.png");
	terminal.ScreenReflection = LoadTexture("./resources/visuals/old_crt_sreen_reflection_weak.png");
	terminal.OnSound = LoadMusicStream("./resources/audio/digital_hum.wav");

	return terminal;
}

void DrawTerminal(Terminal terminal) {
	// Create terminal
	int termFrameWidth = terminal.Body.width;
	int termFrameHeight = terminal.Body.height;

	Rectangle termSource = { 0.0f, 0.0f, termFrameWidth, termFrameHeight };
	Rectangle termDest = { terminal.GameWidth/2.0f, terminal.GameHeight/2.0f, 1280, 960 };
	Vector2 termOrigin = { 638, 464 };
	
	DrawTexturePro(terminal.Screen, termSource, termDest, termOrigin, 0.0f, WHITE);
	DrawTexturePro(terminal.ScreenReflection, termSource, termDest, termOrigin, 0.0f, WHITE);
	DrawTexturePro(terminal.Body, termSource, termDest, termOrigin, 0.0f, WHITE);
}

void PlayTerminalMusic(Terminal terminal) {
	terminal.OnSound.looping = true;
	SetMusicVolume(terminal.OnSound, 0.25f);
	PlayMusicStream(terminal.OnSound);
}

void UpdateTerminalMusic(Terminal terminal) {
	UpdateMusicStream(terminal.OnSound);
}

void UnloadTerminal(Terminal terminal) {
	UnloadTexture(terminal.Body);
	UnloadTexture(terminal.Screen);
	UnloadTexture(terminal.ScreenReflection);

	UnloadMusicStream(terminal.OnSound);
}
