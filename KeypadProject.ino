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

boolean blink = false;
boolean ledPin_state;

int OHYEAH = 13;


char code[] = {0,0,0,0};
char cod[] = {0,0,0,0};
void setup(){
     pinMode(OHYEAH, OUTPUT);
    digitalWrite(OHYEAH, LOW);
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);              // Sets the digital pin as output.
    digitalWrite(ledPin, HIGH);           // Turn the LED on.
    ledPin_state = digitalRead(ledPin);   // Store initial LED state. HIGH when LED is on.
    keypad.addEventListener(keypadEvent); // Add an event listener for this keypad
    
    Serial.println("Input first key");
    code[0] = keypad.waitForKey();
    Serial.println(code[0]);
    Serial.println("Input next key");
    code[1] = keypad.waitForKey();
      Serial.println(code[1]);
    Serial.println("Input next key");
    code[2] = keypad.waitForKey();
      Serial.println(code[2]);
    Serial.println("Input next key");
    code[3] = keypad.waitForKey();
      Serial.println(code[3]);
}

void loop(){
    digitalWrite(OHYEAH, LOW);
    char key = keypad.getKey();
    
    if (key == '*'){
          Serial.println("Attempt!");
          Serial.println("Input first key");
          cod[0] = keypad.waitForKey();
          Serial.println(cod[0]);
          Serial.println("Input next key");
          cod[1] = keypad.waitForKey();
          Serial.println(cod[1]);
          Serial.println("Input next key");
          cod[2] = keypad.waitForKey();
          Serial.println(cod[2]);
          Serial.println("Input next key");
          cod[3] = keypad.waitForKey();
          Serial.println(cod[3]);
           if (code[0] == cod[0] && code[1] == cod[1] && code[2] == cod[2] && code[3] == cod[3]){
            Serial.println("Match!");
            digitalWrite(ledPin,!digitalRead(ledPin));
            digitalWrite(OHYEAH, HIGH);
            delay(5000);
            digitalWrite(OHYEAH, LOW);
            ledPin_state = digitalRead(ledPin);        // Remember LED state, lit or unlit.
            }
    }
       
//    if (blink){
//        digitalWrite(ledPin,!digitalRead(ledPin));    // Change the ledPin from Hi2Lo or Lo2Hi.
//        delay(100);
//    }
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
