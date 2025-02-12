#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <thread>

using namespace std;

float A = 0, B = 0, C = 0;
float cubeWidth = 5;
const int width = 160, height = 44;
vector<float> zBuffer(width * height, 0);
vector<char> buffer(width * height, ' ');
char backgroundASCII = ' ';
int distanceFromCam = 60;
float K1 = 60;
float incrementSpeed = 0.6f;

float calculateX(float i, float j, float k) {
    return j * sin(A) * sin(B) * cos(C) - k * cos(A) * sin(B) * cos(C)
         + j * cos(A) * sin(C) + k * sin(A) * sin(C) + i * cos(B) * cos(C);
}

float calculateY(float i, float j, float k) {
    return j * cos(A) * cos(C) + k * sin(A) * cos(C)
         - j * sin(A) * sin(B) * sin(C) + k * cos(A) * sin(B) * sin(C)
         - i * cos(B) * sin(C);
}

float calculateZ(float i, float j, float k) {
    return k * cos(A) * cos(B) - j * sin(A) * cos(B) + i * sin(B);
}

void calculateForSurface(float cubeX, float cubeY, float cubeZ, char ch) {
    float x = calculateX(cubeX, cubeY, cubeZ);
    float y = calculateY(cubeX, cubeY, cubeZ);
    float z = calculateZ(cubeX, cubeY, cubeZ) + distanceFromCam;

    float ooz = 1 / z;
    int xp = static_cast<int>(width / 2 + K1 * ooz * x * 2);
    int yp = static_cast<int>(height / 2 + K1 * ooz * y);

    int idx = xp + yp * width;
    if (idx >= 0 && idx < width * height) {
        if (ooz > zBuffer[idx]) {
            zBuffer[idx] = ooz;
            buffer[idx] = ch;
        }
    }
}

void clearConsole() {
    cout << "\x1b[H";
}

int main() {
    while (true) {
        fill(buffer.begin(), buffer.end(), backgroundASCII);
        fill(zBuffer.begin(), zBuffer.end(), 0);

        for (float cubeX = -cubeWidth; cubeX < cubeWidth; cubeX += incrementSpeed) {
            for (float cubeY = -cubeWidth; cubeY < cubeWidth; cubeY += incrementSpeed) {
                calculateForSurface(cubeX, cubeY, -cubeWidth, '#');  // front face
                calculateForSurface(cubeX, cubeY, cubeWidth, '@');   // back face
                calculateForSurface(cubeX, -cubeWidth, cubeY, '&');  // top face
                calculateForSurface(cubeX, cubeWidth, cubeY, '$');   // bottom face
                calculateForSurface(-cubeWidth, cubeX, cubeY, '?');  // left face
                calculateForSurface(cubeWidth, cubeX, cubeY, '/');   // right face
            }
        }

        clearConsole();
        for (int i = 0; i < buffer.size(); i++) {
            if (i % width == 0) cout << endl;
            cout << buffer[i];
        }

        this_thread::sleep_for(chrono::milliseconds(1));
        
        A += 0.1f;
        B += 0.1f;
    }
    return 0;
}
