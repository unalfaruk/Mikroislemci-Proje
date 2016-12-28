void motorKontrol(int uyariSeviyesi){
  Serial.println(uyariSeviyesi);
  if(uyariSeviyesi==0){
    digitalWrite(sagMotorInput1, LOW);
    digitalWrite(sagMotorInput2, HIGH);
    digitalWrite(solMotorInput1, LOW);
    digitalWrite(solMotorInput2, HIGH);
  }else if(uyariSeviyesi==1){
    digitalWrite(sagMotorInput1, LOW);
    digitalWrite(sagMotorInput2, LOW); 
  }else{
    digitalWrite(sagMotorInput1, HIGH);
    digitalWrite(sagMotorInput2, LOW); 
  }
}
