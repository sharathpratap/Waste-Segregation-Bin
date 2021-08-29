#include "DHT.h"
#include<Servo.h>
int servoPin1=3;
int servoPin2=5;
#define DHTPIN 2     
#define DHTTYPE DHT11    

DHT dht(DHTPIN, DHTTYPE);
Servo Servo1, Servo2;
void setup() {
  Serial.begin(9600); 
  Serial.println("DHTxx test!");
 
  dht.begin();
  Servo1.attach(servoPin1);
  Servo2.attach(servoPin2);

}

void loop() {
  // Wait a few seconds between measurements.
  delay(3000);

  float h = dht.readHumidity();
 
  if (isnan(h)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity: "); 
  Serial.print(h);
  if (h>=80)
  {
    Serial.println("All clear");
    Servo2.write(0);
      delay (200);
      Servo2.write(90);
   }
   else{
     Serial.println("All clear");
    Servo1.write(90);
      delay(100);
      Servo1.write(10);
   }
  
}
