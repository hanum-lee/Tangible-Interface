const int flexpin = A0;
const int heaterpin = 9;
const int ledpin = 7;

const int flexpin2 = A4;
void setup() {
  // put your setup code here, to run once:
  pinMode(heaterpin,OUTPUT);
  pinMode(ledpin,OUTPUT);
  
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int flexposition = analogRead(flexpin);
  int pressure_sensor_sec = analogRead(flexpin2);
  Serial.print("Sensor: ");
  Serial.print(flexposition);
  Serial.print(", ");
  Serial.println(pressure_sensor_sec);
  if(flexposition < 1010 && pressure_sensor_sec < 1010){
    digitalWrite(heaterpin,HIGH);
    digitalWrite(ledpin,HIGH);
  }else{
    digitalWrite(heaterpin,LOW);
    digitalWrite(ledpin,LOW);
  }
  delay(500);
}                                                 
