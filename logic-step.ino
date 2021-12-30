void LogicStep() {

  // LOGIC STEP

  // decay score
  if (score > 0) {
    score --;
  }

  // timer procedure
  if (timer > 0) {
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
      // bad input, lost game, reset everything
      Regenerate();
    }
    // flush input for next tick
    dpadInput = NO_DIRECTION;
  }

}
