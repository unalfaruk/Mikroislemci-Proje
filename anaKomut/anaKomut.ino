int trigPin=7;
int echoPin=6;
int yesilLed=12;
int kirmiziLed=13;
int MotorInput1=2;
int MotorInput2=3;
int sistemAcKapa=8;
int ses=11;
int pot=0;

int oncekiDurum;
int simdikiDurum;
int sayac=0;
int sinirMesafesi;


long mesafe;



/*
Ana döngüden 2 döngüde bir gelen simdiki ve onceki durum değerlerini alıyoruz.
İki durumu karşılaştırıp sonuca göre uyarı sistemini çalıştıracağız.
 */

void kontrolEt(int simdiki,int onceki=3){
  digitalWrite(yesilLed, LOW);
  digitalWrite(kirmiziLed, LOW);  
  
  if(onceki==simdiki){
    uyari(simdiki,mesafe);
  }else{
    if(simdiki<onceki){
      uyari(simdiki,mesafe);
    }else{
      uyari(onceki,mesafe);
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
  pinMode(MotorInput1, OUTPUT);
  pinMode(MotorInput2, OUTPUT);
  pinMode(sistemAcKapa, INPUT);
  Serial.println("Pinler ayarlandı.");
}

void loop() {

  if(sistemAcikMi()==true){
    sinirMesafesi = analogRead(pot);
    Serial.print("Pot Değeri: ");
    Serial.print(sinirMesafesi);
    sinirMesafesi = map(sinirMesafesi,0,1023,5,50);
    Serial.print(" - Map Değeri: ");
    Serial.println(sinirMesafesi);
    
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
      
    if(mesafe>sinirMesafesi+150 || mesafe <0){
      simdikiDurum=3;
    }else if(mesafe<sinirMesafesi+150 && mesafe >sinirMesafesi+100){
      simdikiDurum=2;
    }else if(mesafe<sinirMesafesi+50 && mesafe >sinirMesafesi){
      simdikiDurum=1;
    }else if(mesafe<sinirMesafesi){
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
    delay(500);
    oncekiDurum = simdikiDurum;
    
  }else{
    digitalWrite(ses,LOW);
    digitalWrite(kirmiziLed, LOW);
    digitalWrite(yesilLed, LOW);
    digitalWrite(MotorInput1, LOW);
    digitalWrite(MotorInput2, LOW); 
    delay(250);
  }

  

}
