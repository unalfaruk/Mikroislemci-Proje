void motorKontrol(int uyariSeviyesi){
  //Serial.println(uyariSeviyesi);
  
  if(uyariSeviyesi==0){
    digitalWrite(MotorInput1, LOW);
    digitalWrite(MotorInput2, HIGH);
  }else if(uyariSeviyesi==1){
    digitalWrite(MotorInput1, LOW);
    digitalWrite(MotorInput2, LOW); 
  }else{
    digitalWrite(MotorInput1, HIGH);
    digitalWrite(MotorInput2, LOW); 
  }
}
