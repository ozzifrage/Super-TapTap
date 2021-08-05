// decide on a random color, return it
Color getRandColor() {

  switch (random(0, 11)) {
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
Brick* bakeBrick() {

  int newDir = random(LEFT, RIGHT + 1);
  Color newCol = getRandColor();
  Button newAction = BUTTON_A;
  Brick* newBrickptr = new Brick(newDir, newCol, newAction);
  return newBrickptr;
}

// reset game state, make new starting bricks

void Regenerate() {

  // populate array with brick pointers
  for (int i = 0; i < NUM_OF_BRICKS; i ++) {
    brickStack[i] = bakeBrick();
  }

  // default values
  dpadInput = NO_DIRECTION;
  score = 0;
  towerHeight = 0;
  timer = MAX_TIMER;
}
