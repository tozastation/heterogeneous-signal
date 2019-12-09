#include <Arduino.h>
#include <SoftwareSerial.h>
#include <LoRaWAN_TLM922S_SoftwareSerial.h>

/* LoRaWAN Module
  @ D11: UART_TX 送信用
  @ D12: UART_RX 受信用
  @ PortNum 11 GPS用途に割当
  Default Connection Speed 9600kps
*/
#define TX_PIN  12  // D12: UART_RX 受信用
#define RX_PIN  11  // D11: UART_TX 送信用

// Data Rate (拡散率＋バンド幅)
#define SF_12 0 // (do not use in japan) Long Range / Low Rate
#define SF_11 1 // (do not use in japan)
#define SF_10 2
#define SF_9 3
#define SF_8 4
#define SF_7 5 // Short Range / High Rate


// Instance
LoRaWAN_TLM922S_SoftwareSerial LoRaWAN(RX_PIN, TX_PIN);

void setup() {
  while (!Serial);
  Serial.begin(9600);
  LoRaWAN.begin(9600);
  while (! LoRaWAN.getReady()     );
  while (! LoRaWAN.factoryReset() );
  while (!( LoRaWAN.join(JOIN_OTAA) &&
            LoRaWAN.joinResult() ));
  // --- set up data rate ---
  if (LoRaWAN.setAdr(ADR_OFF)) {
    Serial.println(F("adaptive rate off"));
  }
  if (LoRaWAN.setDataRate(SF_8)) {
    Serial.print(F("lora data rate is: 4"));
  }
  if (LoRaWAN.loraSave()) {
    Serial.print(F("save state"));
  }
}
int count = 1;
void loop() {
  uint32_t data = LoRaWAN.getDataRate();
  if ( LoRaWAN.tx(TX_UCNF, 1) &&
       LoRaWAN.txData(data)     &&
       LoRaWAN.txRequest()    &&
       LoRaWAN.txResult())
  {
    Serial.println("count: " + String(count));
    Serial.println("send data: " + String(data));
    // --- enter sleep in 5 minutes ---
    pinMode(7, OUTPUT);
    digitalWrite(7, LOW);
    if (LoRaWAN.sleep(0)) {
      delay(5000);
      digitalWrite(7, HIGH);
    }
    count++;
  }
}
