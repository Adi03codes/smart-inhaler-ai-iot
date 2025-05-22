#include <DHT.h>
#include <SoftwareSerial.h>

#define DHTPIN 25
#define DHTTYPE DHT22
#define FLOW_SENSOR A0
#define BUZZER 27
#define LED 2

DHT dht(DHTPIN, DHTTYPE);
SoftwareSerial pmSerial(16, 17); // PMS5003 TX, RX

int flowThreshold = 200;

void setup() {
  pinMode(FLOW_SENSOR, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  pmSerial.begin(9600);
  dht.begin();
}

void loop() {
  int flowValue = analogRead(FLOW_SENSOR);
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (flowValue > flowThreshold) {
    digitalWrite(BUZZER, HIGH);
    digitalWrite(LED, HIGH);
    delay(2000);
    digitalWrite(BUZZER, LOW);
    digitalWrite(LED, LOW);
  }

  if (pmSerial.available() > 0) {
    byte buffer[32];
    pmSerial.readBytes(buffer, 32);
    int pm25 = buffer[12] * 256 + buffer[13];
    int pm10 = buffer[14] * 256 + buffer[15];

    Serial.print("PM2.5: ");
    Serial.print(pm25);
    Serial.print(" | PM10: ");
    Serial.println(pm10);
  }

  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" °C, Humidity: ");
  Serial.print(h);
  Serial.println(" %");

  delay(3000);
}
