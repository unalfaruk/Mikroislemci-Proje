boolean sistemAcikMi(){
  if(digitalRead(sistemAcKapa)==HIGH){
    Serial.println("Sistem aktif.");
    return true;
  }else{
    Serial.println("Sistem devre disi.");
    return false;
  }
}

