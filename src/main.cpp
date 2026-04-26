#include <cmath>
#include <iostream>
#include <raylib.h>

int WIDTH{500};
int HEIGHT{500};

struct PendulumSection {
  Vector2 startPos;
  Vector2 endPos;
};

void draw_pendulum(Vector2 startPos, float phi1 = (90 * DEG2RAD),
                   float phi2 = (90 * DEG2RAD), float l = 100) {
  PendulumSection ps1{.startPos = startPos,
                      .endPos = {startPos.x + l * std::cosf(phi1),
                                 startPos.y + l * std::sinf(phi1)}};

  PendulumSection ps2{.startPos = {ps1.endPos},
                      .endPos = {ps1.endPos.x + l * std::cosf(phi2),
                                 ps1.endPos.y + l * std::sinf(phi2)}};

  DrawLineEx(ps1.startPos, ps1.endPos, 5.0f, WHITE);
  DrawLineEx(ps2.startPos, ps2.endPos, 5.0f, WHITE);

  DrawCircle(ps1.endPos.x, ps1.endPos.y, 10, RED);
  DrawCircle(ps2.endPos.x, ps2.endPos.y, 10, RED);
}
int main() {

  InitWindow(WIDTH, HEIGHT, "Double Pendulum");

  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);

    draw_pendulum(Vector2{WIDTH / 2.0f, 0.0f});

    EndDrawing();
  }
}
