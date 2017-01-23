//LIBRARIES
#include <Keyboard.h>
//CONSTANTS
const int pushButton1 = 2;
const int pushButton2 = 3;
const int pushButton3 = 4;
const int reedSwitch1 = 5;
const int potPin = A0;
//VARIABLES
int switchState1 = 0;
int switchState2 = 0;
int switchState3 = 0;
int reedSwitchState1 = 0;
int reedSwitchState2 = 0;
int elapsedTime = 0;
int runProgramme = 1;
int currentLevel = 1;
int isKeyPressed = 0;
int carDirection = 1; //1 = forward, 0 = backward
long keyPressedTime = 0;
long prevTime = 0;
int waitTime1 = 1000;
int waitTime2 = 1000;
int bufferTime = 0;
int a;
long releaseTime = 0;
long pressButtonTime = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pushButton1, INPUT);
  pinMode(pushButton2, INPUT);
  pinMode(pushButton3, INPUT);
  pinMode(reedSwitchState1, INPUT);
  Keyboard.begin();
}

void loop() {
  switchState1 = digitalRead(pushButton1);
  switchState2 = digitalRead(pushButton2);
  switchState3 = digitalRead(pushButton3);
  reedSwitchState1 = digitalRead(reedSwitch1);


  /*
   * The stepper swings past the reed switch twice for a single revolution.
   */
  if (reedSwitchState1 != reedSwitchState2) {
      reedSwitchState2 = reedSwitchState1;
      if (reedSwitchState1 == HIGH) {
        elapsedTime = ((millis()-prevTime));
        prevTime = millis();
        releaseTime = millis() - keyPressedTime;

        if (isKeyPressed == 1) {
          //Serial.print("Releasing button in: ");
          //Serial.println(releaseTime);
          if (releaseTime > waitTime1) {
            Serial.println("Release key e");
            Keyboard.releaseAll();
            isKeyPressed = 0;
            keyPressedTime = millis();
            pressButtonTime = millis() + waitTime2;
          }
        } else {
            //Serial.print("Pressing button in: ");
            //Seriae.println(pressButtonTime - millis());
            if ( pressButtonTime < millis() ) {
              Serial.println("Press key e");
              isKeyPressed = 1;
              keyPressedTime = millis();
              if (carDirection == 1) {
                Keyboard.press('e');
              } else {
                Keyboard.press('q');
              }
            }
        } //end Else

        /* 
           This is a simple & nasty way to test the forward/backward action of the hill climbing character.
        */
        
        if (elapsedTime >= 800) {
         Serial.println("Time 100");
          waitTime1 = 100;
          waitTime2 = 500;
          carDirection = 0;
        } else
        if (elapsedTime < 800 && elapsedTime >= 750) {
         Serial.println("Time 200");
          waitTime1 = 200;
          waitTime2 = 500;
          carDirection = 0;
        } else
        if (elapsedTime < 750 && elapsedTime >= 700) {
          Serial.println("Time 300");
          waitTime1 = 300;  
          waitTime2 = 500;
          carDirection = 1;
        } else
        if (elapsedTime < 700 && elapsedTime >= 650) {
          Serial.println("Time 400");
          waitTime1 = 400;
          waitTime2 = 500;
          carDirection = 1;
        } else 
        if (elapsedTime < 650 && elapsedTime >= 600) {
          Serial.println("Time 500");
          waitTime1 = 500;
          waitTime2 = 500;
          carDirection = 1;
        } else 
        if (elapsedTime < 600 && elapsedTime >= 550) {
          Serial.println("Time 600");
          waitTime1 = 600;
          waitTime2 = 500;
          carDirection = 1;
        } else 
        if (elapsedTime < 550 && elapsedTime >= 500) {
          Serial.println("Time 700");
          waitTime1 = 700;
          waitTime2 = 500;
          carDirection = 1;
        } else 
        if (elapsedTime < 500 && elapsedTime >= 450) {
          Serial.println("Time 800");
          waitTime1 = 800;
          waitTime2 = 500;
          carDirection = 1;
        } else 
        {
          // Serial.println("Going superman speed!");
          waitTime1 = 2000;
          waitTime2 = 0;
          carDirection = 1;
        }
        
      }
  }
  
  if (switchState1) {
    Keyboard.write('t');
    delay(500);
  } 

  if (switchState2) {
    Keyboard.write('d');
  } 

  if (switchState3) {
   Keyboard.write('a');
  } 

}
