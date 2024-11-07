import java.util.Arrays;

public class cube {
    static float A, B, C;
    static float cubeWidth = 10;
    static int width = 160, height = 44;
    static float[] zBuffer = new float[width * height];
    static char[] buffer = new char[width * height];
    static char backgroundASCII = ' ';
    static int distanceFromCam = 60;
    static float K1 = 60;

    static float incrementSpeed = 0.6f;

    static float x, y, z;
    static float ooz;
    static float xp;
    static float yp;
    static int idx;

    static float calculateX(float i, float j, float k) {
        return (float) (j * Math.sin(A) * Math.sin(B) * Math.cos(C) - k * Math.cos(A) * Math.sin(B) * Math.cos(C)
                + j * Math.cos(A) * Math.sin(C) + k * Math.sin(A) * Math.sin(C) + i * Math.cos(B) * Math.cos(C));
    }

    static float calculateY(float i, float j, float k) {
        return (float) (j * Math.cos(A) * Math.cos(C) + k * Math.sin(A) * Math.cos(C)
                - j * Math.sin(A) * Math.sin(B) * Math.sin(C) + k * Math.cos(A) * Math.sin(B) * Math.sin(C)
                - i * Math.cos(B) * Math.sin(C));
    }

    static float calculateZ(float i, float j, float k) {
        return (float) (k * Math.cos(A) * Math.cos(B) - j * Math.sin(A) * Math.cos(B) + i * Math.sin(B));
    }

    static void calculateForSurface(float cubeX, float cubeY, float cubeZ, char ch) {
        x = calculateX(cubeX, cubeY, cubeZ);
        y = calculateY(cubeX, cubeY, cubeZ);
        z = calculateZ(cubeX, cubeY, cubeZ) + distanceFromCam;

        ooz = 1 / z;
        xp = (int) (width / 2 + K1 * ooz * x * 2);
        yp = (int) (height / 2 + K1 * ooz * y);

        idx = (int) (xp + yp * width);
        if (idx >= 0 && idx < width * height) {
            if (ooz > zBuffer[idx]) {
                zBuffer[idx] = ooz;
                buffer[idx] = ch;
            }
        }
    }

    public static void main(String[] args) throws InterruptedException {
        while (true) {
            Arrays.fill(buffer, backgroundASCII);
            Arrays.fill(zBuffer, 0);

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
            for (int i = 0; i < buffer.length; i++) {
                if (i % width == 0) System.out.println();
                System.out.print(buffer[i]);
            }

            Thread.sleep(1);

            A += 0.1;
            B += 0.1;
        }
    }

    public static void clearConsole() {
        for (int i = 0; i < 50; i++) System.out.println();
    }
}