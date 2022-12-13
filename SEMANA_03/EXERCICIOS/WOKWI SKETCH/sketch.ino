const int led1 = 7;
const int led2 = 6;
const int led3 = 5;
const int led4 = 4;
const int lightSensor = 14;
const int buzzer = 2;
const int btnRec = 15;
const int btnPlay = 16;

void setup() {
  // Setup
  Serial.begin(115200);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(lightSensor, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(btnRec, INPUT_PULLUP);
  pinMode(btnPlay, INPUT_PULLUP);
}

// Max values for reading values
const int maxValue = 8126;
const int minValue = 64;

// Function that thurns on the leds and buzzer based on given reading 
int standard(int number){
  Serial.print(number);
  int binaryValue = trunc(number);
  int recNum = binaryValue;
  int musicalNumber = binaryValue * 100;
  int binaryArray[4];
  int i = 0;
  while (binaryValue > 0) {
    binaryArray[i] = binaryValue % 2;
    binaryValue = binaryValue / 2;
    i++;
  }
  // Serial.print(i);
  while(i < 4){
    binaryArray[i] = 0;
    i++;
  }
  Serial.print(", ");
  Serial.print(binaryArray[3]);
  Serial.print(binaryArray[2]);
  Serial.print(binaryArray[1]);
  Serial.print(binaryArray[0]);
  Serial.println(" ,");

  // Turns on the leds
  if(binaryArray[3] == 1){
    digitalWrite(led1, HIGH);
  }
  else{
    digitalWrite(led1, LOW);
  }
  
  if(binaryArray[2] == 1){
    digitalWrite(led2, HIGH);
  }
  else{
    digitalWrite(led2, LOW);
  }

  if(binaryArray[1] == 1){
    digitalWrite(led3, HIGH);
  }
  else{
    digitalWrite(led3, LOW);
  }

  if(binaryArray[0] == 1){
    digitalWrite(led4, HIGH);
  }
  else{
    digitalWrite(led4, LOW);
  }
  
  // Plays the buzzer
  tone(buzzer, musicalNumber);
  delay(100);
  noTone(buzzer);
  delay(100);
  return binaryValue;
}

// Variables for button controlling
// Recording
int lastState = HIGH;
bool isRecording = false;
// Playing 
int lastStatePlay = HIGH;
bool isPlaying = false;
// Array that stores the recordings
int binaryArray[10];

// Functions that reads and normalize the LDR
int reading(){
  int rawRead = analogRead(lightSensor);
  // Serial.println(rawRead);
  int interval = maxValue - minValue;
  int analogValue = rawRead - minValue;
  float convertedPercentage = (analogValue*100)/interval;
  float convertedValue = (convertedPercentage/100) * 15;
  int binaryValueInit = convertedValue;
  return binaryValueInit;
}

void loop() {
  // Checks rec button
  int value = digitalRead((btnRec));
  if (lastState != value) {
    lastState = value;
    if (value == HIGH) {
      Serial.println(" released");
      isRecording = false;
    }
    if (value == LOW) {
      Serial.println(" pressed");
      isRecording = true;
    }
  }

  // Checks the play button
  int valuePlay = digitalRead((btnPlay));
  if (lastStatePlay != valuePlay) {
      lastStatePlay = valuePlay;
      if (valuePlay == HIGH) {
      Serial.println(" released");
      isPlaying = false;
      }
      if (valuePlay == LOW) {
      Serial.println(" pressed");
      isPlaying = true;
      }
  }

  // Checks if it's in recording, playing ou standard mode
  if(isRecording == true){
    Serial.println("RECORDING...");
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    // Records readings into an array
    for(int i = 0; i < 10; i++){
      binaryArray[i] = reading();
      Serial.print(binaryArray[i]);
      Serial.print(" , ");
      delay(1000);
    }
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    isRecording == false;
  }else if(isPlaying == true){
    // Insert array values into standard function
    Serial.println("STARTING PLAYING!");
    for(int i = 0; i<10;i++){
        standard(binaryArray[i]);
        delay(500);
    }
    isPlaying = false;
  }
  else{
    // Run the standard function, with in real time readings
    standard(reading());
  }
  delay(100);
}
