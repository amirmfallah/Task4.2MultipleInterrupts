volatile bool led1State = false;  // Tracks LED1 state (push button)
volatile bool led2State = false;  // Tracks LED2 state (photocell)

const int buttonPin = 2;  // Push button on D2
const int photocellPin = 3;  // Photocell digital signal on D3
const int led1Pin = 4;    // LED1 on D4
const int led2Pin = 5;    // LED2 on D5

void setup() {
  // Initialize pins
  pinMode(buttonPin, INPUT);      // Button as input
  pinMode(photocellPin, INPUT);   // Photocell signal as input
  pinMode(led1Pin, OUTPUT);       // LED1 as output
  pinMode(led2Pin, OUTPUT);       // LED2 as output

  // Set initial LED states
  digitalWrite(led1Pin, led1State);
  digitalWrite(led2Pin, led2State);

  // Attach interrupts
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonISR, RISING);    // Interrupt on button press
  attachInterrupt(digitalPinToInterrupt(photocellPin), photocellISR, CHANGE);  // Interrupt on photocell state change

  // Start Serial Monitor
  Serial.begin(9600);
  while (!Serial);  // Wait for Serial Monitor to connect
}

void loop() {
  // Main loop remains empty as all actions are interrupt-driven
  delay(100);  // Small delay to avoid overwhelming the Serial Monitor
}

// Interrupt Service Routine (ISR) for button press
void buttonISR() {
  led1State = !led1State;              // Toggle LED1 state
  digitalWrite(led1Pin, led1State);    // Update LED1
  Serial.print("Button Pressed - LED1: ");
  Serial.println(led1State ? "ON" : "OFF");
}

// Interrupt Service Routine (ISR) for photocell
void photocellISR() {
  led2State = !led2State;              // Toggle LED2 state
  digitalWrite(led2Pin, led2State);    // Update LED2
  Serial.print("Photocell Triggered - LED2: ");
  Serial.println(led2State ? "ON" : "OFF");
}
