/*
Gelen değerlere göre sesli uyarı sistemi farklı dönütler verecek
Bunun için ayrı bir fonksiyon açıyoruz.
*/
void sesUyariSistemi(int uyariSeviyesi, int mesafe){
  
  if(mesafe <100 && mesafe >10){
    ton(mesafe);
  }else if(mesafe <10){
    digitalWrite(ses,HIGH);
  }else{
    
  }
  
}
