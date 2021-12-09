/*  ****** ESP modüllerinin mac adresi öğrenme  ********

  MAC adresi öğrenm programı :
  • Bu program esp now özelliklerinin kullanılması için
  mac adresinin öğrenilmesi gerekliliğinden ortaya çıkmıştır.
  • Cihazların mac adresleri serial.tpint fonksiyonu ile
  serial ekrana yani bizlerin bilgisayar ekranına
  yansıtılacaktır. Her bir cihazın mac adresi farklıdır ve
  bu yüzden her cihazın mac adresini bir köşeye nor alınız.

                                     by Ali Birkan BAYRAM
*/

//━━━━━━━━━ Nodemcu için gerekli kütüphaneler ━━━━━━━━━━━━━━
#ifdef ESP32 // Mikrodenetleyicimiz eğer esp32 ise
  #include <WiFi.h>
#else // Mikrodenetleyicimiz eğer esp8266 ise
  #include <ESP8266WiFi.h>
#endif

//━━━ void setup() fonksiyonu ile kurulum yapılıyor ━━━━━━
void setup() {
  Serial.begin(115200); // Serial ekran hızı: 115200 baud
  Serial.println(); // Serial ekranı yukarıdaki hıza ayarla.
  Serial.print("ESP karımızın MAC adresi: ");
  Serial.println(WiFi.macAddress());
  delay(3000); // 3 Saniye bir gecikme yaşatıyoruz bilerek
  Serial.println("Mac adresinizi öğrenmek istiyorsanız lütfen \"m\" veya \"M\" tuşuna basınız.");
  // Serial ekranınıza wifi mac aderesiniz çıktı lütfen bir
  // köşeye not alınız daha sonrasında lazım olacaktır.
}
// herhangi bir şekilde void loop fonksiyonunun dolu olma
// zorunluluğu yoktur. Onun için böyle boş bir şekilde yazdık.
void loop() {
  if(Serial.available()){ // Kullanıcı serial bilgi gönderildiğinde çalış.
    char temp = Serial.read(); // temp değişkeninin içine gelen bilgiyi yaz
    if(temp == 'm' || temp == 'M'){ // Eğer m veya M gönderilmiş ise mac adres göster.
      Serial.print("ESP karımızın MAC adresi: ");
      Serial.println(WiFi.macAddress());
    }
    Serial.println("Mac adresinizi öğrenmek istiyorsanız lütfen \"m\" veya \"M\" tuşuna basınız.");
    delay(1000);
  }
}
