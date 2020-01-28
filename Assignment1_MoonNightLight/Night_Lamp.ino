#include <Servo.h>

const int phototrans = A5;

const int redLED = 7;
const int greenLED = 5;
const int blueLED = 6;

Servo servo;

int angle = 0;
int readingVal = 0;

const int button = 10;

int previousState = LOW;
int currentState;

int switchState = LOW;

long time1 = 0;
long errormargin = 200;

long currentTime = 0;
long previousTime = 0;
long interval = 500;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redLED,OUTPUT);
  pinMode(greenLED,OUTPUT);
  pinMode(blueLED,OUTPUT);

  servo.attach(9);
  pinMode(button,INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  currentState = digitalRead(button);
  if(currentState == HIGH && previousState == LOW && (millis() - time1 > errormargin)){
    if(switchState == HIGH){
      switchState = LOW;
    }else{
      switchState = HIGH;
    }
    time1 = millis();
    
    Serial.print("State: ");
    Serial.println(switchState);
  }
  previousState = currentState;
  //Serial.println(millis());
  currentTime = millis();
  if(switchState == HIGH){
    readingVal = analogRead(phototrans);
    //delay(500);
    if(currentTime - previousTime > interval){
       if(readingVal < 10){
          analogWrite(redLED,255);
          analogWrite(greenLED,255);
          analogWrite(blueLED,255);
          angle += 5;
          servo.write(angle);
          if(angle > 120){
            angle = 0;
          }
        }else{
          analogWrite(redLED,0);
          analogWrite(greenLED,0);
          analogWrite(blueLED,0);
        }
        previousTime = currentTime;
    }
    Serial.println(readingVal);
    
  }else{
    analogWrite(redLED,0);
    analogWrite(greenLED,0);
    analogWrite(blueLED,0);
    servo.write(0);
  }
  
}
