#include <Gamebuino-Meta.h>
#include "Constants.h"
#include "Brick.cpp"

const int NUM_OF_BRICKS = 4;

int bricks[NUM_OF_BRICKS];

Brick* brickStack[NUM_OF_BRICKS];

int dpadInput; // input from dpad
int score;

Brick* bakeBrick();
Color getRandColor();

void setup() {
  
  gb.begin();

  // populate array with brick pointers
  for(int i = 0; i < NUM_OF_BRICKS; i ++){
    brickStack[i] = bakeBrick(); 
  }
  
  dpadInput = NO_DIRECTION;
  score = 0;
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

  // if input pressed, check direction for score
  if (dpadInput != NO_DIRECTION) {

    if (bricks[0]  == dpadInput) {
      // correct input
      score += 15;

      bricks[0] = bricks[1];
      bricks[1] = bricks[2];
      bricks[2] = bricks[3];
      bricks[3] = random(LEFT, RIGHT + 1);


    } else {
      // bad input, lost game
      score = 0;
    }
    // flush input for next tick
    dpadInput = NO_DIRECTION;
  }


  // DRAW STEP
  gb.display.clear();

  gb.display.setColor(getRandColor());
  if (bricks[0] == LEFT) {
    gb.display.drawRect(20, 40, 20, 10);
  }
  else {  // RIGHT
    gb.display.drawRect(40, 40, 20, 10);
  }
  
  gb.display.setColor(getRandColor());
  if (bricks[1] == LEFT) {
    gb.display.drawRect(20, 30, 20, 10);
  }
  else {  // RIGHT
    gb.display.drawRect(40, 30, 20, 10);
  }
  
  gb.display.setColor(getRandColor());
  if (bricks[2] == LEFT) {
    gb.display.drawRect(20, 20, 20, 10);
  }
  else {  // RIGHTRIGHT
    gb.display.drawRect(40, 20, 20, 10);
  }

  gb.display.setColor(getRandColor());
  if (bricks[3] == LEFT) {
    gb.display.drawRect(20, 10, 20, 10);
  }
  else {  // RIGHT
    gb.display.drawRect(40, 10, 20, 10);
  }

  gb.display.print(score);

}

// decide on a random color, return it
Color getRandColor(){

  switch(random(0,11)){
    case 0:
      return WHITE;
      break;
    case 1:
      return PINK;
      break;
    case 2:
      return RED;
      break;
    case 3:
      return ORANGE;
      break;
    case 4:
      return YELLOW;
      break;
    case 5:
      return LIGHTGREEN;
      break;
    case 6:
      return PURPLE;
      break;
    case 7:
      return LIGHTBLUE;
      break;
    case 8:
      return BLUE;
      break;
    case 9:
      return BEIGE;
      break;
    case 10:
      return GREEN;
      break;
    
  }
  return GRAY;
}

// make and return reference to a new brick object
Brick* bakeBrick(){

  int newDir = random(LEFT, RIGHT + 1);
  Color newCol = getRandColor();
  Button newAction = BUTTON_A;
  Brick* newBrickptr = new Brick(newDir, newCol, newAction);
  return newBrickptr;
}
