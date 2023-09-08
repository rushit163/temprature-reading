
#define BLYNK_TEMPLATE_ID "TMPL3JEroQw45"
#define BLYNK_TEMPLATE_NAME "DHT Sensor Template"
#define BLYNK_AUTH_TOKEN "KuhbgcIjacRj7J58Ra-_8wojxCakP0UQ"

#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

#define DHTPIN 4 // Data pin is connected to D2 on ESP
#define DHTTYPE DHT11 // Name the sensor as an object


char auth[] = "KuhbgcIjacRj7J58Ra-_8wojxCakP0UQ";
char ssid[] = "wifi";
char pass[] = "123456678";

DHT dht(DHTPIN, DHTTYPE);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("DHT Test Successful!");

  Blynk.begin(auth, ssid, pass);
  Serial.println("Connected to Blynk!");
  dht.begin();
}
// t.ly/netnex
void loop() {
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f))
  {
    Serial.println("Something is not working as intended.");
    return; 
  }
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.println("%");
  Serial.print("Temperature");
  Serial.print(t);
  Serial.println("degrees celsius.");
  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);
  delay(1000);
}
