# Mikroislemci-Proje


İnsan kaynaklı gemi kazalarının önüne geçmek için oluşturulmuş giriş seviyesinde bir projedir.

  - Gelen veri doğruluk kontrolü,
  - Ayarlanabilir tehlikeli mesafe seviyesi,
  - Işıklı ve sesli uyarı sistemi

Ultrasonik sensör ile engel tespit eden ve mesafeye göre kademe kademe tepki veren bir araç hedeflenmiştir. Kademeler arası mesafe sabittir, tehlike mesafesi ise değişken değerli direnç(potansiyometre) ile kontrol edilebilirdir.

> Güvenli durumdan tehlikeli duruma doğru 3,2,1,0 sıralaması yapılırsa;

Kademe 3 - Araç seyrinde ilerler, yeşil led sürekli yanarak tehlikeli durumun olmadığını ifade eder.
Kademe 2 - Araç seyrinde ilerler ancak çok uzakta bir mesafe tespit edildiği içi yeşil led yanıp söner.
Kademe 1 - Araç motorların gücünü keser ve mesafenin kısalığıyla doğru orantılı olacak şekilde kırmızı led yanar söner. Ayrıca sesli uyarı sisteme devreye girer ve led ile birlikte tepki verir.
Kademe 0 (Tehlikeli) - Araç motorları engelden uzaklaşacak yönde çevirir. Kırmızı led sürekli yanan haldedir.

### Kurulum ve Yukleme

Devre kurulumuna ait ekran görüntüleri yüklenecektir.

### Malzemeler

Bu proje için kullanmanız gereken malzemeler,


* Arduino UNO R3
* HC-SR04 veya JSN - SR04T ultrasonik sensör. (Algoritmada HC-SR04 takılı)
* Kırmızı ve Yeşil Led (Ledler için birer tane 220 ohm direnç)
* Buzzer
* Potansiyometre
* L293D Motor Sürücü Entegresi
