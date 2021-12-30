void InputStep() {

  // INPUT STEP
  if (gb.buttons.released(BUTTON_LEFT)) {
    dpadInput = LEFT;
  } else if (gb.buttons.released(BUTTON_RIGHT)) {
    dpadInput = RIGHT;
  }

}
