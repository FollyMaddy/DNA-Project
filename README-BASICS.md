# Flash onboard led on MEGA :

https://www.arduino.cc/reference/en/language/functions/time/delay/

Example (tested)

Blink led.

---

int ledPin = 13;              // LED connected to digital pin 13


void setup() {

  pinMode(ledPin, OUTPUT);    // sets the digital pin as output
  
}


void loop() {

  digitalWrite(ledPin, HIGH); // sets the LED on
  
  delay(1000);                // waits for a second
  
  digitalWrite(ledPin, LOW);  // sets the LED off
  
  delay(1000);                // waits for a second
  
}

---


# PWM_explanation:

https://www.arduino.cc/en/Tutorial/PWM

PWM_frequencies:

https://www.arduino.cc/reference/en/language/functions/analog-io/analogwrite/

Mega

2 - 13, 44 - 46 -> 490 Hz (pins 4 and 13: 980 Hz)

Example(not testen):

Sets the output to the LED proportional to the value read from the potentiometer.

---

int ledPin = 9;      // LED connected to digital pin 9

int analogPin = 3;   // potentiometer connected to analog pin 3

int val = 0;         // variable to store the read value


void setup() {

  pinMode(ledPin, OUTPUT);  // sets the pin as output
  
}


void loop() {

  val = analogRead(analogPin);  // read the input pin
  
  analogWrite(ledPin, val / 4); // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
  
}

---


# PWM TEST 1:

Combined from above examples (tested):

Blink led from low to high brightness.

---

int ledPin = 13;              // LED connected to digital pin 13


void setup() {

  pinMode(ledPin, OUTPUT);    // sets the digital pin as output
  
}


void loop() {

  analogWrite(ledPin, 5); // sets the LED on
  
  delay(1000);                // waits for a second
  
  digitalWrite(ledPin, LOW);  // sets the LED off
  
  delay(1000);                // waits for a second
  
  analogWrite(ledPin, 10); // sets the LED on
  
  delay(1000);                // waits for a second
  
  digitalWrite(ledPin, LOW);  // sets the LED off
  
  delay(1000);                // waits for a second
  
  analogWrite(ledPin, 50); // sets the LED on
  
  delay(1000);                // waits for a second
  
  digitalWrite(ledPin, LOW);  // sets the LED off
  
  delay(1000);  
  
  digitalWrite(ledPin, HIGH); // sets the LED on
  
  delay(1000);                // waits for a second
  
  digitalWrite(ledPin, LOW);  // sets the LED off
  
  delay(1000);                // waits for a second
  
}

---


# NON-blocking delay:

https://www.forward.com.au/pfod/ArduinoProgramming/TimingDelaysInArduino.html

Example:

This next sketch shows you how to write a non-blocking delay that allows the code to continue to run while waiting for the delay to expire.

Added in sketch !!! -->> Serial.begin(9600);

---

int led = 13;

unsigned long delayStart = 0; // the time the delay started

bool delayRunning = false; // true if still waiting for delay to finish


void setup() {

  Serial.begin(9600);
  
  pinMode(led, OUTPUT);   // initialize the digital pin as an output.
  
  digitalWrite(led, HIGH); // turn led on
  

  delayStart = millis();   // start delay
  
  delayRunning = true; // not finished yet
  
}


void loop() {

  // check if delay has timed out after 10sec == 10000mS
  
  if (delayRunning && ((millis() - delayStart) >= 10000)) {
  
    delayRunning = false; // // prevent this code being run more then once
    
    digitalWrite(led, LOW); // turn led off
    
    Serial.println("Turned LED Off");
    
  }
  
//  Other loop code here . . .

  Serial.println("Run Other Code");
  
}

---

