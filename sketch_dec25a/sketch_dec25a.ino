int trigPin=7;
int echoPin=6;
int motorPin=3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop() {
  //digitalWrite(motorPin,HIGH);
  // put your main code here, to run repeatedly:
  long sure, mesafe;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  sure = pulseIn(echoPin, HIGH);
  mesafe = (sure/2) / 29.1;
     if (mesafe > 200 || mesafe < 0){
     digitalWrite(motorPin,HIGH);
     Serial.println("Menzil Disi");
     }
     else if(mesafe<20) {
     digitalWrite(motorPin,LOW);
     Serial.print(mesafe);
     Serial.println(" cm");
     }else{
     digitalWrite(motorPin,HIGH);
     Serial.println(mesafe);
     }
  delay(500);

}
