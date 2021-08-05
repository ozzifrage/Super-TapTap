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

// possible gamemodes: centennial (highest score with 100 bricks)
//                     time attack (fastest time for 50 bricks)
//                     free play (highest score, period)

// startup procedures
void setup() {
  
  gb.begin();

  // populate array with brick pointers
  for(int i = 0; i < NUM_OF_BRICKS; i ++){
    brickStack[i] = bakeBrick(); 
  }

  // default values
  dpadInput = NO_DIRECTION;
  score = 0;
  towerHeight = 0;
  timer = MAX_TIMER;
}

void loop() {
  while (!gb.update());

  // INPUT STEP
  if (gb.buttons.released(BUTTON_LEFT)) {
    dpadInput = LEFT;
  } else if (gb.buttons.released(BUTTON_RIGHT)) {
    dpadInput = RIGHT;
  }

  // LOGIC STEP

  // decay score
  if (score > 0) {
    score --;
  }

  // timer procedure
  if (timer > 0){
    timer --;
  }

  // if input pressed, check direction for score
  if (dpadInput != NO_DIRECTION) {

    if (brickStack[0] -> getPosition() == dpadInput) {
      // correct input
      score += 15;
      towerHeight ++;
      delete brickStack[0];
      brickStack[0] = brickStack[1];
      brickStack[1] = brickStack[2];
      brickStack[2] = brickStack[3];
      brickStack[3] = bakeBrick();
      timer = MAX_TIMER;


    } else {
      // bad input, lost game
      score = 0;
      towerHeight = 0;
      timer = MAX_TIMER;
    }
    // flush input for next tick
    dpadInput = NO_DIRECTION;
  }


  // DRAW STEP
  gb.display.clear();

  // draw score
  gb.display.setColor(WHITE);
  gb.display.setCursor(0,0);
  gb.display.setFontSize(1);
  gb.display.print(score);

  // draw height
  gb.display.setColor(DARKGRAY);
  gb.display.setCursor(0,10);
  gb.display.setFontSize(1);
  gb.display.print(towerHeight);

  // draw timer
  gb.display.setColor(DARKGRAY);
  gb.display.fillRect(gb.display.width() / 2, gb.display.height() - 1, timer, 2);
  gb.display.fillRect(gb.display.width() / 2 - timer, gb.display.height() - 1, timer, 2);

  // first brick
  gb.display.setColor(brickStack[0] -> getPaint());
  if (brickStack[0]->getPosition() == LEFT) {
    gb.display.fillRect(20, 40, 20, 10);
  }
  else {  // RIGHT
    gb.display.fillRect(40, 40, 20, 10);
  }

  // second brick
  gb.display.setColor(brickStack[1] -> getPaint());
  if (brickStack[1]->getPosition() == LEFT) {
    gb.display.fillRect(20, 30, 20, 10);
  }
  else {  // RIGHT
    gb.display.fillRect(40, 30, 20, 10);
  }

  // third brick
  gb.display.setColor(brickStack[2] -> getPaint());
  if (brickStack[2]->getPosition() == LEFT) {
    gb.display.fillRect(20, 20, 20, 10);
  }
  else {  // RIGHTRIGHT
    gb.display.fillRect(40, 20, 20, 10);
  }

  // fourth brick
  gb.display.setColor(brickStack[3] -> getPaint());
  if (brickStack[3]->getPosition() == LEFT) {
    gb.display.fillRect(20, 10, 20, 10);
  }
  else {  // RIGHT
    gb.display.fillRect(40, 10, 20, 10);
  }
  
}
