const int led1 = 4;
const int led2 = 5;
const int led3 = 6;
const int led4 = 7;
const int lightSensor = 17;
const int buzzer = 16;

// A versão atual apresenta erros para alguns intervalos de luz

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(lightSensor, INPUT);
  pinMode(buzzer, OUTPUT);
}


void loop() {
  int analogValue = analogRead(lightSensor);
  Serial.println(analogValue);
  int analogValueDif = 4095 - analogValue;
  Serial.println(analogValueDif);
  float convertedPercentage = (analogValueDif*100)/600; // it's divided by the maximum - lower value obtainable
  float convertedValue = (convertedPercentage/100) * 15;
  int binaryValue = trunc(convertedValue);
  Serial.print(binaryValue);
  int musicalNumber = binaryValue * 250;
  int binaryArray[4];
  int i = 0;
  while (binaryValue > 0) {
    binaryArray[i] = binaryValue % 2;
    binaryValue = binaryValue / 2;
    i++;
  }
  Serial.print(i);
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
  
  tone(buzzer, musicalNumber);
  delay(100);
  noTone(buzzer);
}
