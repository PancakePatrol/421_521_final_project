#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
    {'*','0','#'}
};

byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {8, 7, 6}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
byte ledPin = 13; 

//boolean blink = false;
boolean ledPin_state;

int OHYEAH = 13;
int Attempt = 0;
int WRONG = 12;

char code[] = {0,0,0,0}; // Will serve as arrary that carries passcode
char cod[] = {0,0,0,0};  // Will serve as array that carries attempted input
void setup(){
    pinMode(OHYEAH, OUTPUT);
    
    digitalWrite(OHYEAH, HIGH);
    digitalWrite(9, HIGH);
    pinMode(9, OUTPUT);
    Serial.begin(9600);
    delay(1000);
    pinMode(ledPin, OUTPUT);              // Sets the digital pin as output.
    digitalWrite(ledPin, HIGH);           // Turn the LED on.
    ledPin_state = digitalRead(ledPin);   // Store initial LED state. HIGH when LED is on.
    keypad.addEventListener(keypadEvent); // Add an event listener for this keypad
    Serial.println("Set Up Passcode");
    delay(1000);
    Serial.println("Input first key");
    code[0] = keypad.waitForKey();
    Serial.println(code[0]);
    Serial.println("Input second key");
    code[1] = keypad.waitForKey();
      Serial.println(code[1]);
    Serial.println("Input third key");
    code[2] = keypad.waitForKey();
      Serial.println(code[2]);
    Serial.println("Input fourth key");
    code[3] = keypad.waitForKey();
      Serial.println(code[3]);
      Serial.println("Passcode Set!");
}

void loop(){
    digitalWrite(OHYEAH, LOW);
    char key = keypad.getKey();
    pinMode(WRONG, OUTPUT);
    //digitalWrite(WRONG, HIGH);
    if (key == '*' && Attempt < 3){
          Serial.println("Begin Passcode Input!");
          blink();
          Serial.println("Input first key");
          cod[0] = keypad.waitForKey();
          Serial.println(cod[0]);
          blink();
          Serial.println("Input next key");
          cod[1] = keypad.waitForKey();
          Serial.println(cod[1]);
          blink();
          Serial.println("Input next key");
          cod[2] = keypad.waitForKey();
          Serial.println(cod[2]);
          blink();
          Serial.println("Input next key");
          cod[3] = keypad.waitForKey();
          Serial.println(cod[3]);
               if (code[0] == cod[0] && code[1] == cod[1] && code[2] == cod[2] && code[3] == cod[3]){
                Serial.println("Match! Opening Door!");
                Attempt = 0;
                //digitalWrite(ledPin,!digitalRead(ledPin));
                digitalWrite(OHYEAH, HIGH);
                motor();
                //delay(5000);
                digitalWrite(OHYEAH, LOW);
                ledPin_state = digitalRead(ledPin);        // Remember LED state, lit or unlit.
                }
                
                else{
                     Serial.println("No Match!");
                     digitalWrite(WRONG, HIGH);
                     delay(100);
                     blink();
                     delay(100);
                     blink();
                     delay(100);
                     blink();
                     delay(100);
                     blink();
                     delay(100);
                     blink();
                     Attempt = Attempt + 1;
                     digitalWrite(WRONG, LOW);
                 }
    }
    else if(Attempt == 3){
      Serial.println("LOCK OUT!");
      digitalWrite(WRONG, HIGH);
                           delay(100);
                     blink();
                     delay(100);
                     blink();
                     delay(100);
                     blink();
                     delay(100);
                     blink();
                     delay(100);
                     blink();
                     delay(100);
                     blink();
                     delay(100);
                     blink();
                     delay(100);
                     blink();
                     delay(100);
                     blink();
                     delay(100);
                     blink();
                     Attempt = 0;
                   digitalWrite(WRONG, LOW);  
    }

    if (key == '#'){
          Serial.println("Begin Passcode Input!");
          blink();
          Serial.println("Input first key");
          cod[0] = keypad.waitForKey();
          Serial.println(cod[0]);
          blink();
          Serial.println("Input next key");
          cod[1] = keypad.waitForKey();
          Serial.println(cod[1]);
          blink();
          Serial.println("Input next key");
          cod[2] = keypad.waitForKey();
          Serial.println(cod[2]);
          blink();
          Serial.println("Input next key");
          cod[3] = keypad.waitForKey();
          Serial.println(cod[3]);
               if (code[0] == cod[0] && code[1] == cod[1] && code[2] == cod[2] && code[3] == cod[3]){
                Serial.println("Match! Resetting passcode...");
                digitalWrite(ledPin,!digitalRead(ledPin));
                digitalWrite(OHYEAH, HIGH);
                delay(1000);
                digitalWrite(OHYEAH, LOW);
                ledPin_state = digitalRead(ledPin);        // Remember LED state, lit or unlit.
                
                    delay(1000);
                    Serial.println("Input first key");
                    code[0] = keypad.waitForKey();
                    Serial.println(code[0]);
                    blink();
                    Serial.println("Input second key");
                    code[1] = keypad.waitForKey();
                    Serial.println(code[1]);
                    blink();
                    Serial.println("Input third key");
                    code[2] = keypad.waitForKey();
                    Serial.println(code[2]);
                    blink();
                    Serial.println("Input fourth key");
                    code[3] = keypad.waitForKey();
                    Serial.println(code[3]);
                    blink();
                    Serial.println("Passcode Set!");
                
                }
                else{
                     Serial.println("No Match!");
                     digitalWrite(WRONG, HIGH);
                     delay(100);
                     blink();
                     delay(100);
                     blink();
                     delay(100);
                     blink();
                     delay(100);
                     blink();
                     delay(100);
                     blink();
                     Attempt = Attempt + 1;
                     digitalWrite(WRONG, LOW);
                 }    
       
//    if (blink){
//        digitalWrite(ledPin,!digitalRead(ledPin));    // Change the ledPin from Hi2Lo or Lo2Hi.
//        delay(100);
//    }
     }
}

void blink() {
            digitalWrite(OHYEAH, HIGH);
            delay(500);
            digitalWrite(OHYEAH, LOW);
}

void motor() {
    digitalWrite(9, HIGH);
    delay(1000);
    digitalWrite(9, LOW);
    delay(1000);
    digitalWrite(9, HIGH);
}

// Taking care of some special events.
void keypadEvent(KeypadEvent key){
    switch (keypad.getState()){
//    case PRESSED:
//        if (key == '#') {
//            digitalWrite(ledPin,!digitalRead(ledPin));
//            ledPin_state = digitalRead(ledPin);        // Remember LED state, lit or unlit.
//        }
//        break;
//
//    case RELEASED:
//        if (key == '*') {
//            digitalWrite(ledPin,ledPin_state);    // Restore LED state from before it started blinking.
//            blink = false;
//        }
//        break;
//
//    case HOLD:
//        if (key == '*') {
//            blink = true;    // Blink the LED when holding the * key.
//        }
//        break;
    }
}
