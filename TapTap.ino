#include <Gamebuino-Meta.h>

const int NUM_OF_BRICKS = 4;

int bricks[NUM_OF_BRICKS];

// definitions of left and right for bricks
const int LEFT = 1;
const int RIGHT = 2;
const int NO_DIRECTION = 3;

int dpadInput; // input from dpad
int score;

void setup() {
  // put your setup code here, to run once:
  gb.begin();

  bricks[0] = random(LEFT, RIGHT + 1);
  bricks[1] = random(LEFT, RIGHT + 1);
  bricks[2] = random(LEFT, RIGHT + 1);
  bricks[3] = random(LEFT, RIGHT + 1);

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


  if (bricks[0] == LEFT) {
    gb.display.drawRect(20, 40, 20, 10);
  }
  else {  // RIGHT
    gb.display.drawRect(40, 40, 20, 10);
  }
  if (bricks[1] == LEFT) {
    gb.display.drawRect(20, 30, 20, 10);
  }
  else {  // RIGHT
    gb.display.drawRect(40, 30, 20, 10);
  }
  if (bricks[2] == LEFT) {
    gb.display.drawRect(20, 20, 20, 10);
  }
  else {  // RIGHTRIGHT
    gb.display.drawRect(40, 20, 20, 10);
  }
  if (bricks[3] == LEFT) {
    gb.display.drawRect(20, 10, 20, 10);
  }
  else {  // RIGHT
    gb.display.drawRect(40, 10, 20, 10);
  }

  gb.display.print(score);

}
