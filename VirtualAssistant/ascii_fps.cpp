#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <thread>
#include <conio.h>  // Windows-specific keyboard input
#define CLEAR_SCREEN "cls"

using namespace std;

const int SCREEN_WIDTH = 120;
const int SCREEN_HEIGHT = 30;
const float FOV = 3.14159 / 3.0;
const float DEPTH = 16.0;

vector<string> simMap = {
    "################",
    "#..............#",
    "#..............#",
    "#..............#",
    "#..............#",
    "#.....#..#.....#",
    "#..............#",
    "#..............#",
    "#..............#",
    "#..............#",
    "################"
};

float playerX = 2.0, playerY = 2.0;
float playerA = 0.0;

void render() {
    vector<char> screen(SCREEN_WIDTH * SCREEN_HEIGHT, ' ');

    for (int x = 0; x < SCREEN_WIDTH; x++) {
        float rayAngle = (playerA - FOV / 2.0) + ((float)x / (float)SCREEN_WIDTH) * FOV;
        float distanceToWall = 0.0;
        bool hitWall = false;
        bool isVerticalHit = false;  // Track if it's a vertical wall hit
        float eyeX = cos(rayAngle), eyeY = sin(rayAngle);

        while (!hitWall && distanceToWall < DEPTH) {
            distanceToWall += 0.1;
            int testX = (int)(playerX + eyeX * distanceToWall);
            int testY = (int)(playerY + eyeY * distanceToWall);

            if (testX < 0 || testX >= simMap[0].size() || testY < 0 || testY >= simMap.size()) {
                hitWall = true;
                distanceToWall = DEPTH;
            } else if (simMap[testY][testX] == '#') {
                hitWall = true;
            }

            // Determine if it's a vertical or horizontal hit
            float hitX = playerX + eyeX * distanceToWall - testX;
            float hitY = playerY + eyeY * distanceToWall - testY;    

            // If hitX is closer to the edge, it's a vertical wall
            isVerticalHit = (hitX < 0.1 || hitX > 0.9);
        }

        int ceiling = (SCREEN_HEIGHT / 2.0) - (SCREEN_HEIGHT / distanceToWall);
        int floor = SCREEN_HEIGHT - ceiling;

        char wallSymbol = isVerticalHit ? '|' : '=';

        for (int y = 0; y < SCREEN_HEIGHT; y++) {
            if (y < ceiling)
                screen[y * SCREEN_WIDTH + x] = ' ';
            else if (y >= ceiling && y < floor)
                screen[y * SCREEN_WIDTH + x] = wallSymbol;
            else
                screen[y * SCREEN_WIDTH + x] = '.';
        }
    }

    // Efficient buffer-based console update
	cout.write(screen.data(), SCREEN_WIDTH * SCREEN_HEIGHT);
	cout << "\n";
}

bool update() {
    if (_kbhit()) {
        char key = _getch();
        float speed = 0.05f;  // Increase movement speed
        switch (key) {
            case 'a': playerA -= 0.05f; break;  // Faster turning
            case 'd': playerA += 0.05f; break;
            case 'w': 
                playerX += cos(playerA) * speed; 
                playerY += sin(playerA) * speed; 
                break;
            case 's': 
                playerX -= cos(playerA) * speed; 
                playerY -= sin(playerA) * speed; 
                break;
            case ' ': 
                cout << "\nSpace key pressed. Exiting game.\n";
                return false;
        }
    }
    return true;
}