# Mikroislemci-Proje
Gazi Üni. Mikroislemci Proje Odevi

İnsan kaynaklı gemi kazalarının önüne geçmek için oluşturulmuş giriş seviyesinde proje.

Ultrasonik sensör ile engel tespit eden ve mesafeye göre kademe kademe tepki veren bir araç hedeflenmiştir. Kademeler şimdilik sabit olmak üzere, tehlike mesafesi değişken değerli direnç(potansiyometre) ile kontrol edilebilir.

Güvenli durumdan tehlikeli duruma doğru 3,2,1,0 sıralaması yapılırsa;

3. Kademe - Araç seyrinde ilerler, yeşil led sürekli yanarak tehlikeli durumun olmadığını ifade eder.
2. Kademe - Araç seyrinde ilerler ancak çok uzakta bir mesafe tespit edildiği içi yeşil led yanıp söner.
1. Kademe - Araç motorların gücünü keser ve mesafenin kısalığıyla doğru orantılı olacak şekilde kırmızı led yanar söner. Ayrıca sesli uyarı sisteme devreye girer ve led ile birlikte tepki verir.
0. Kademe - Araç motorları engelden uzaklaşacak yönde çevirir. Kırmızı led sürekli yanan haldedir.

0. Kademenin mesafe değeri devre üzerindeki değişken değerli direnç ile belirlenir ancak diğer kademeler kendinden bir önceki kademeye +50 cm değeri eklenerek devam eder.