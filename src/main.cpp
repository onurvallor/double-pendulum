#include <cmath>
#include <iostream>
#include <raylib.h>

int WIDTH{500};
int HEIGHT{500};

void draw_pendulum(Vector2 startPos, float phi1, float l) {

  Vector2 endPos{startPos.x + l * std::cosf(phi1),
                 startPos.y + l * std::sinf(phi1)};
  DrawLineEx(startPos, endPos, 5.0f, WHITE);
  DrawCircle(endPos.x, endPos.y, 10, RED);
}

int main() {

  InitWindow(WIDTH, HEIGHT, "Double Pendulum");

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);

    draw_pendulum(Vector2{WIDTH / 2.0f, 0.0f}, 90 * DEG2RAD, 100);

    EndDrawing();
  }
}
