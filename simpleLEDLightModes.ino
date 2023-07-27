/*
THIS IS JUST A SIMPLE LED LIGHTS WITH 2 LED MODES

COMPONENTS USED:
1) Arduino Uno R3
2) 3 LEDs
3) 3 Resistors
4) Jumper Wires

RESISTOR (Five band resistor)
Resistor used: 220 ohms (RED RED BLACK BLACK)
Resistor Tolerance: +- 1% (BROWN)
NOTE: 1 resistor for each LEDs

VOLTAGE SOURCE: 9V

LED Colors: Red, Yellow, Green

Connection is in Parallel
*/

// global var
byte ledPin[] = {3, 5, 6}; // the pins for the led (PINS ARE PWM)

// LED MODE 1
// One cycle: 4590 ms or 4.59 s
void slowLEDSideStart() {
  // iterates through each ledPin (3, 5, 6 in order), then increases and decreases the brightness
  for (int i = 0; i < 3; i++) {

    // increments the brightness of the LED
    for (int a = 0; a <= 255; a++) {
      analogWrite(ledPin[i], a);
      delay(1);
    }

    // decrements the brightness of the LED
    for (int a = 255; a >= 0; a--) {
      analogWrite(ledPin[i], a);
      delay(5);
    }
  }
  
}

// LED MODE 2
// One cycle: 200 ms or 0.2 s
void fastLEDSideStart() {
  // iterates through pins 3, 5, 6
  for (int i = 0; i < 3; i++) {
    // sets the led from on to off for 0.1 seconds
    digitalWrite(ledPin[i], HIGH);
    delay(100);
    digitalWrite(ledPin[i], LOW);
  }

  // iterates from pin 6, 5, 3
  for (int i = 2; i >= 0; i--) {
    // sets the led from on to off for 0.1 seconds
    digitalWrite(ledPin[i], HIGH);
    delay(100);
    digitalWrite(ledPin[i], LOW);
  }
}

void setup() {
  // Assigns the led pins to generate electricity (i.e. OUTPUT)
  for (int i = 0; i < 3; i++) {
    pinMode(ledPin[i], OUTPUT);
  }

  Serial.begin(9600); // JUST FOR DEBUGGING
}

void loop() {
  // local var
  int loop = 0;

  // Generate a random number between 2 and 3 (inclusive)
  int randomNumber = random(2, 4);
  Serial.println(randomNumber); // JUST FOR DEBUGGING
  delay(1000); // Wait for 1 second

  if (randomNumber % 2 == 0) {
    while (loop < 2) {
      // Serial.println(loop); // JUST FOR DEBUGGING
      slowLEDSideStart();
      loop++;
    }

    // resets the loop count back to 0
    loop = 0;
  } else {
    while (loop < 5) {
      // Serial.println(loop); // JUST FOR DEBUGGING
      fastLEDSideStart();
      loop++;
    }

    // resets the loop count back to 0
    loop = 0;
  }
}
