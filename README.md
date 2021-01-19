	const int screenWidth = 1280;
	const int screenHeight = 720;
	InitWindow(screenWidth, screenHeight, "Terminal Hacker -- Become the best hacker!");

	// Load assets

	// Create terminal
	Texture2D termText = LoadTexture("./resources/visuals/old_crt.png"); // 1440x1080
	int termFrameWidth = termText.width;
	int termFrameHeight = termText.height;

	Rectangle termSource = { 0.0f, 0.0f, termFrameWidth, termFrameHeight };

	Rectangle termDest = { screenWidth/2.0f, screenHeight/2.0f, 1280, 960 };
	Vector2 termOrigin = { 640, 464 };
