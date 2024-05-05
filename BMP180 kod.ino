#include <Adafruit_BMP085.h>


Adafruit_BMP085 bmp;
  
void setup() {
  Serial.begin(9600);
  if (!bmp.begin()) {        // Burda bmp`nin başlayıp başlamadığını kontrol ediyoruz.
  Serial.println("Could not find a valid BMP085 sensor, check wiring!");      // Eğer başlamadı ise cihazın bulumadığını söyluyor.
  while (1) {}
  }
}
  
void loop() {
    Serial.print("Sicaklik = ");  // Sıcaklık ekrana yazdırıyor.
    Serial.print(bmp.readTemperature()); // Sıcaklık değerini okuyor burada.
    Serial.println(" *C"); // Ekrana c tipini yazıyor.
    
    Serial.print("Basinc = ");    // Basıç ekrana yazdırıyor.
    Serial.print(bmp.readPressure());   // Basıç değerini okuyor burada.
    Serial.println(" Pa");   // Ekrana Pa tipini yazıyor.
    
    // Calculate altitude assuming 'standard' barometric
    // pressure of 1013.25 millibar = 101325 Pascal

    Serial.print("Rakım = ");   // Rakım(Yükseklik) ekrana yazdırıyor.
    Serial.print(bmp.readAltitude()); // Rakım değerini okuyor burada.
    Serial.println(" metre");  // Ekrana metre tipini yazıyor.

    Serial.print("Deniz Seviyesinden Yükseklik Basinc (calculated) = ");  //  Deniz Seviyesinden Yükseklik Basinc ekrana yazdırıyor.
    Serial.print(bmp.readSealevelPressure());  // Deniz Seviyesinden Yükseklik Basincdeğerini okuyor burada.
    Serial.println(" Pa"); // Ekrana Pa tipini yazıyor.

  // you can get a more precise measurement of altitude
  // if you know the current sea level pressure which will
  // vary with weather and such. If it is 1015 millibars
  // that is equal to 101500 Pascals.

    Serial.print("Gercek Rakım = "); // Daha doğru rakımı yazdıyor ekrana.
    Serial.print(bmp.readAltitude(101500)); // Eğer bulunduğunuz yerin rakımı biliyorsak daha doğru sonuç elde ediyoruz rakımda.
    Serial.println(" meters");  // Ekrana metre tipini yazıyor.
    
    Serial.println();
    delay(500); // Zamanlama
}
