int trigPin=7;
int echoPin=6;
int yesilLed=12;
int kirmiziLed=13;

int ses=11;
int oncekiDurum;
int simdikiDurum;
int sayac=0;

long mesafe;



void uyariSistemi(int uyariSeviyesi) {

  switch(uyariSeviyesi){
    
    case 0:
      Serial.println("100 altı");      
      digitalWrite(kirmiziLed, HIGH);
      break;
    
    case 1:
      Serial.println("100 150 arası");
      digitalWrite(kirmiziLed, HIGH);
      break;
    
    case 2:
      Serial.println("150 200 arası");
      digitalWrite(kirmiziLed, HIGH);
      break;
    
    case 3:
      Serial.println("Temiz");      
      digitalWrite(yesilLed, HIGH);
      break;
    
    default:
      Serial.println("Default");
  }
  
  sesUyariSistemi(uyariSeviyesi,mesafe);
  
}

/*
Ana döngüden 2 döngüde bir gelen simdiki ve onceki durum değerlerini alıyoruz.
İki durumu karşılaştırıp sonuca göre uyarı sistemini çalıştıracağız.
 */

void kontrolEt(int simdiki,int onceki=3){
  digitalWrite(yesilLed, LOW);
  digitalWrite(kirmiziLed, LOW);  
  
  if(onceki==simdiki){
    uyariSistemi(simdiki);
  }else{
    if(simdiki<onceki){
      uyariSistemi(simdiki);
    }else{
      uyariSistemi(onceki);
    }
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(kirmiziLed, OUTPUT);
  pinMode(yesilLed, OUTPUT);
  pinMode(ses, OUTPUT);
  Serial.println("Pinler ayarlandı.");
}

void loop() {
  long sure;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  sure = pulseIn(echoPin, HIGH);
  mesafe = (sure/2) / 29.1;

/*
Mesafeye göre durumun aciliyetini belirliyoruz.
*/
    
  if(mesafe>200 || mesafe <0){
    simdikiDurum=3;
  }else if(mesafe<200 && mesafe >150){
    simdikiDurum=2;
  }else if(mesafe<150 && mesafe >100){
    simdikiDurum=1;
  }else if(mesafe<100){
    simdikiDurum=0;
  }  

/*
Her iki dönütte bir kontrol ediyoruz. Sensörümüzden gelebilecek olan hatalı veriyi kontrol
etmek için yapıyoruz bunu. Gelen değer bir önceki değer ile aynı değilse stabile olana kadar
bekleriz, ve bu süreçte de ikisi arasında tehlikeli olana göre işlem yaparız. Stabileyse doğrudan
uyarı sistemi ne yapması gerekiyorsa onu yapmalı.
*/  
  sayac++;  
  if(sayac%2==0){
    kontrolEt(simdikiDurum,oncekiDurum);
  }

/*
Şimdiki durum bir sonraki döngüde eski(önceki) durum olacak.
 */
  delay(250);
  oncekiDurum = simdikiDurum;

}
