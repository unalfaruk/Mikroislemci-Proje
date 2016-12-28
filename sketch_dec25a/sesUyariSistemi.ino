/*
Gelen değerlere göre sesli uyarı sistemi farklı dönütler verecek
Bunun için ayrı bir fonksiyon açıyoruz.
*/
void sesUyariSistemi(int uyariSeviyesi, int mesafe){

  if(uyariSeviyesi==3){
    Serial.println(mesafe);
  }else if(mesafe <100 && mesafe >10){
    Serial.println(mesafe);
    ton(mesafe);
  }else if(mesafe <10){
    digitalWrite(ses,HIGH);
  }else{
    Serial.println(mesafe);
  }
  
}
