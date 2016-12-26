int trigPin=7;
int echoPin=6;
int motorPin=3;
int yesilLed=12;
int kirmiziLed=13;
int oncekiDurum;
int simdikiDurum;
int sayac=0;


void uyariSistemi(int uyariSeviyesi, int mesafe=0) {

  switch(uyariSeviyesi){
    
    case 0:
      //simdikiDurum = 0; //En tehlikeli durum için 0 kodu
      Serial.println("100 altı");      
      digitalWrite(kirmiziLed, HIGH);
      break;
    
    case 1:
      //simdikiDurum = 1;
      Serial.println("100 150 arası");
      digitalWrite(kirmiziLed, HIGH);
      break;
    
    case 2:
      //simdikiDurum = 2;
      Serial.println("150 200 arası");
      digitalWrite(kirmiziLed, HIGH);
      break;
    
    case 3:
      //simdikiDurum = 3; //Tehlikeli olmayan durum için 3 kodu
      Serial.println("Temiz");      
      digitalWrite(yesilLed, HIGH);
      break;
    
    default:
      Serial.println("Default");
  }

}

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
 
    
  if(mesafe>200 || mesafe <0){
    simdikiDurum=3;
    //uyariSistemi(3);
  }else if(mesafe<200 && mesafe >150){
    simdikiDurum=2;
    //uyariSistemi(2);
  }else if(mesafe<150 && mesafe >100){
    simdikiDurum=1;
    //uyariSistemi(1);  
  }else if(mesafe<100){
    simdikiDurum=0;
    //uyariSistemi(0);
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
  
  delay(200);
  oncekiDurum = simdikiDurum;

}
