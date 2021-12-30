void DrawStep() {

  // DRAW STEP
  gb.display.clear();

  // draw score
  gb.display.setColor(WHITE);
  gb.display.setCursor(0, 0);
  gb.display.setFontSize(1);
  gb.display.print(score);

  // draw height
  gb.display.setColor(DARKGRAY);
  gb.display.setCursor(0, 10);
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
