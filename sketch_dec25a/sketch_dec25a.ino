int trigPin=7;
int echoPin=6;
int motor=2;
int yesilLed=12;
int kirmiziLed=13;
int ses=11;

int oncekiDurum;
int simdikiDurum;
int sayac=0;


void uyariSistemi(int uyariSeviyesi, int mesafe=0) {

  switch(uyariSeviyesi){
    
    case 0:
      Serial.println("100 altı");      
      digitalWrite(kirmiziLed, HIGH);
      digitalWrite(motor, HIGH);
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

}

/*
Ana döngüden 2 döngüde bir gelen simdiki ve onceki durum değerlerini alıyoruz.
İki durumu karşılaştırıp sonuca göre uyarı sistemini çalıştıracağız.
 */

void kontrolEt(int simdiki,int onceki=3){
  digitalWrite(yesilLed, LOW);
  digitalWrite(kirmiziLed, LOW);
  digitalWrite(motor, LOW);
  
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

}

void loop() {

  long sure, mesafe;
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
  delay(200);
  oncekiDurum = simdikiDurum;

}
