// contains all properties and methods of a brick

class Brick {

  private:
  int myPos;
  Color paint;
  Button specialAction;

  public:
  int getPosition(){
    return myPos;
  }
  void setPosition(int newPos){
    myPos = newPos;
  }
  Color getPaint(){
    return paint;
  }
  void setPaint(Color newPaint){
    paint = newPaint;
  }
  Button getAction(){
    return specialAction;
  }
  void setAction(Button newAction){
    specialAction = newAction;
  }
  

  Brick(int startPos, Color startPaint, Button startAction){

    myPos = startPos;
    paint = startPaint;
    specialAction = startAction;
    
  }

};
