void uyari(int uyariSeviyesi, int mesafe){

int sure,donguSayisi,i;
Serial.print("Sınır Mesafesi Deger Gelen = ");
Serial.println(sinirMesafesi);

  motorKontrol(uyariSeviyesi);
  
  switch(uyariSeviyesi){
    
    case 0:
      Serial.print("Gemi engelden kaciyor, mesafe= ");
      Serial.println(mesafe);
      digitalWrite(kirmiziLed, HIGH);
      break;
    
    case 1:      
      Serial.print("Gemi tehlikede, motorlar durdu. Mesafe = ");
      Serial.println(mesafe);
      sure=map(mesafe,(sinirMesafesi),(sinirMesafesi+50),50,250);
      donguSayisi=500/(2*sure);
      

      if(donguSayisi!=0){
        Serial.print(sure);
        Serial.print(" sns aralıklarla ");
        Serial.print(donguSayisi);
        Serial.println(" kere dönecek.");
        
        for(i=0;i<=donguSayisi;i++){
          Serial.print(i);
          Serial.println(". dongu.");
          digitalWrite(kirmiziLed, HIGH);
          digitalWrite(ses,HIGH);
          delay(sure);
          digitalWrite(kirmiziLed, LOW);
          digitalWrite(ses,LOW);
          delay(sure);
        }        
      }
      
      
      break;
    
    case 2:
      Serial.print(mesafe);
      Serial.println(" - 100 150 arası");
      sure=map(mesafe,sinirMesafesi+50,sinirMesafesi+100,50,250);
      donguSayisi=500/(2*sure);
      Serial.print(sure);
      Serial.print(" sns aralıklarla ");
      Serial.print(donguSayisi);
      Serial.println(" kere dönecek.");

      if(donguSayisi!=0){
        for(i=0;i<=donguSayisi;i++){
          Serial.print(i);
          Serial.println(". dongu.");
          digitalWrite(yesilLed, HIGH);
          delay(sure);
          digitalWrite(yesilLed, LOW);
          delay(sure);
        }        
      }
      
      break;
    
    case 3:
      Serial.print(mesafe);
      Serial.println(" - Temiz");      
      digitalWrite(yesilLed, HIGH);
      break;
    
    default:
      Serial.println("Default");
  }
  
}
