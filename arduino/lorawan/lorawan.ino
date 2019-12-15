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
  Serial.println("lorawan ready ok");
  while (! LoRaWAN.factoryReset() );
  Serial.println("init lorawan");
  while (! LoRaWAN.join(JOIN_OTAA));
  Serial.println("joinning network");
  while (! LoRaWAN.joinResult());
  Serial.println("joined network");
  delay(4000);
}
int count = 1;
void loop() {
  // send data is current data rate
  // --- set up data rate ---
  //if (LoRaWAN.setAdr(ADR_OFF)) {}
  // --- Change data rate ---
  //if (LoRaWAN.setDataRate(2)) {}
  uint32_t data = LoRaWAN.getDataRate();
  if ( LoRaWAN.tx(TX_UCNF, 1) &&
       LoRaWAN.txData(count)     &&
       LoRaWAN.txRequest()    &&
       LoRaWAN.txResult())
  {
    Serial.println("count: " + String(count));
    Serial.println("send data: " + String(data));
    // --- enter sleep in 5 seconds ---
    pinMode(7, OUTPUT);
    digitalWrite(7, LOW);
    if (LoRaWAN.sleep(0)) {
      delay(4000);
      digitalWrite(7, HIGH);
    }
    count++;
  }
}
