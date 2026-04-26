#include <cmath>
#include <iostream>
#include <raylib.h>

int WIDTH{500};
int HEIGHT{500};
int MASS_RADIUS{10};
float GRAVITY{1};
float L1{250};
float L2{250};
float M1 = MASS_RADIUS;
float M2 = MASS_RADIUS;

float m1, m2, l1, l2, phi1, phi2, d_phi1, d_phi2, dd_phi1, dd_phi2;

struct PendulumSection {
  Vector2 startPos;
  Vector2 endPos;
};

void draw_pendulum(Vector2 startPos, float phi1 = (90 * DEG2RAD),
                   float phi2 = (90 * DEG2RAD), float l1 = 100.0f,
                   float l2 = 100.0f) {
  PendulumSection ps1{.startPos = startPos,
                      .endPos = {startPos.x + l1 * std::sinf(phi1),
                                 startPos.y + l1 * std::cosf(phi1)}};

  PendulumSection ps2{.startPos = {ps1.endPos},
                      .endPos = {ps1.endPos.x + l2 * std::sinf(phi2),
                                 ps1.endPos.y + l2 * std::cosf(phi2)}};

  DrawLineEx(ps1.startPos, ps1.endPos, 5.0f, WHITE);
  DrawLineEx(ps2.startPos, ps2.endPos, 5.0f, WHITE);

  DrawCircle(ps1.endPos.x, ps1.endPos.y, MASS_RADIUS, RED);
  DrawCircle(ps2.endPos.x, ps2.endPos.y, MASS_RADIUS, RED);
}

void step() {
  // lower time step
  float dt = 1.0f;

  dd_phi1 = (-GRAVITY * (2 * m1 + m2) * std::sinf(phi1) -
             m2 * GRAVITY * std::sinf(phi1 - 2 * phi2) -
             2 * std::sinf(phi1 - phi2) * m2 *
                 (std::pow(d_phi2, 2) * l2 +
                  std::pow(d_phi1, 2) * l1 * std::cosf(phi1 - phi2))) /
            (l1 * (2 * m1 + m2 - m2 * std::cosf(2 * phi1 - 2 * phi2)));

  dd_phi2 = 2 * std::sinf(phi1 - phi2) *
            (std::pow(d_phi1, 2) * l1 * (m1 + m2) +
             GRAVITY * (m1 + m2) * std::cosf(phi1) +
             std::pow(d_phi2, 2) * l2 * m2 * std::cosf(phi1 - phi2)) /
            (l2 * (2 * m1 + m2 - m2 * std::cosf(2 * phi1 - 2 * phi2)));

  d_phi1 += dd_phi1 * dt;
  d_phi2 += dd_phi2 * dt;

  phi1 += d_phi1 * dt;
  phi2 += d_phi2 * dt;

  // dampen
  d_phi1 *= 0.999f;
  d_phi2 *= 0.999f;
}

void init_variables() {

  m1 = M1;
  m2 = M2;
  l1 = L1;
  l2 = L2;

  phi1 = -90 * DEG2RAD;
  phi2 = 90 * DEG2RAD;

  d_phi1 = 0;
  d_phi2 = 0;
}

int main() {

  InitWindow(WIDTH, HEIGHT, "Double Pendulum");

  SetTargetFPS(60);

  init_variables();

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);

    step();

    draw_pendulum(Vector2{WIDTH / 2.0f, 0.0f}, phi1, phi2);

    EndDrawing();
  }
}
