#include <Gamebuino-Meta.h>
#include "Constants.h"
#include "Brick.cpp"

const int NUM_OF_BRICKS = 4;

Brick* brickStack[NUM_OF_BRICKS];

int dpadInput; // input from dpad
int score;

// function prototypes
Brick* bakeBrick();
Color getRandColor();

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

    if (brickStack[0]->getPosition() == dpadInput) {
      // correct input
      score += 15;

      delete brickStack[0];
      brickStack[0] = brickStack[1];
      brickStack[1] = brickStack[2];
      brickStack[2] = brickStack[3];
      brickStack[3] = bakeBrick();


    } else {
      // bad input, lost game
      score = 0;
    }
    // flush input for next tick
    dpadInput = NO_DIRECTION;
  }


  // DRAW STEP
  gb.display.clear();

  gb.display.setColor(brickStack[0]->getPaint());
  if (brickStack[0]->getPosition() == LEFT) {
    gb.display.drawRect(20, 40, 20, 10);
  }
  else {  // RIGHT
    gb.display.drawRect(40, 40, 20, 10);
  }
  
  gb.display.setColor(brickStack[1]->getPaint());
  if (brickStack[1]->getPosition() == LEFT) {
    gb.display.drawRect(20, 30, 20, 10);
  }
  else {  // RIGHT
    gb.display.drawRect(40, 30, 20, 10);
  }
  
  gb.display.setColor(brickStack[2]->getPaint());
  if (brickStack[2]->getPosition() == LEFT) {
    gb.display.drawRect(20, 20, 20, 10);
  }
  else {  // RIGHTRIGHT
    gb.display.drawRect(40, 20, 20, 10);
  }

  gb.display.setColor(brickStack[3]->getPaint());
  if (brickStack[3]->getPosition() == LEFT) {
    gb.display.drawRect(20, 10, 20, 10);
  }
  else {  // RIGHT
    gb.display.drawRect(40, 10, 20, 10);
  }

  gb.display.setColor(WHITE);
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
