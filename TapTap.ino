#include <Gamebuino-Meta.h>
#include "Constants.h"
#include "Brick.cpp"

int dpadInput; // input from dpad
int score;
int towerHeight;
int timer; // time until fail, reset on hit brick, lowers with height
Brick* brickStack[NUM_OF_BRICKS];

// function prototypes
Brick* bakeBrick();
Color getRandColor();
void InputStep();
void LogicStep();
void DrawStep();
void Regenerate();

// possible gamemodes: centennial (highest score with 100 bricks)
//                     time attack (fastest time for 50 bricks)
//                     free play (highest score, period)

// TODO: round instead of towerHeight, model timer curve with function

// startup procedures
void setup() {
  
  gb.begin();

  Regenerate();
  
}

void loop() {
  while (!gb.update());

  InputStep();
  LogicStep();
  DrawStep();
  
}
