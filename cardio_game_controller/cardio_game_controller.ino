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
long prevTime = 0;
int potVal;
int bufferTime = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pushButton1, INPUT);
  pinMode(pushButton2, INPUT);
  pinMode(pushButton3, INPUT);
  pinMode(reedSwitchState1, INPUT);
  Keyboard.begin();
}

/*
 * Used to test basic components of the controller 
 */

void loop() {
  switchState1 = digitalRead(pushButton1);
  switchState2 = digitalRead(pushButton2);
  switchState3 = digitalRead(pushButton3);
  reedSwitchState1 = digitalRead(reedSwitch1);
  potVal = analogRead(potPin) + 1;

  if (reedSwitchState1 != reedSwitchState2) {
    reedSwitchState2 = reedSwitchState1;
    if (reedSwitchState1 == HIGH) {
      /*
      Serial.print("Current time: "); 
      Serial.println(millis());
      Serial.print("Previous time: ");
      Serial.println(prevTime);
      */
      elapsedTime = ((millis()-prevTime));
      prevTime = millis();
      if (elapsedTime >= 700) {
        Serial.print("Level is 1 with time: ");
        if (currentLevel != 1) {
          currentLevel = 1;
          Keyboard.write('1');
        }
        Serial.println(elapsedTime);
      } else

      if (elapsedTime < 700 && elapsedTime >= 550) {
        if (currentLevel != 2) {
          currentLevel = 2;
          Keyboard.write('2');
        }
        Serial.print("Level is 2 with time: ");
        Serial.println(elapsedTime);
      } else

      if (elapsedTime < 550 && elapsedTime >= 450) {
       if (currentLevel != 3) {
          currentLevel = 3;
          Keyboard.write('3');
        }
        Serial.print("Level is 3 with time: ");
        Serial.println(elapsedTime);
      } else 

      {
        if (currentLevel != 4) {
          currentLevel = 4;
          Keyboard.write('4');
        }
        Serial.print("Level is 4 with time: ");
        Serial.println(elapsedTime);
      }
      
      
    }

  }

  //Serial.println(potVal);

  if (potVal < 412) {
    //Serial.println("Move right...");
    //Keyboard.write('d');
  }
  
  if (potVal > 612) {
    //Serial.println("Move left...");
    //Keyboard.write('a');
    
  }

  if (potVal >= 412  && potVal <= 612) {
    //Serial.println("Steering forward ");
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
   /*
    runProgramme = 0; 
    Serial.println("Abort programme.");
    while (!runProgramme) {
      delay(2000);
      switchState3 = digitalRead(pushButton3);
      if (switchState3) {
        Serial.println("Re-initialising the programme, take finder off the button!");
        runProgramme = 1; 
        delay(2000);
      } else {
        Serial.println("Status in abort mode.");
      }
      
    }
    */
  } 

  //delay(50);

}
