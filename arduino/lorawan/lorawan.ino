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

// Instance
LoRaWAN_TLM922S_SoftwareSerial LoRaWAN(RX_PIN, TX_PIN);

// ProtoType: Function declarations
int cmd_help();
int cmd_led();
int cmd_exit();

void setup() {
  while (!Serial);
  Serial.begin(9600);
  LoRaWAN.begin(9600);
  while (! LoRaWAN.getReady()     ) delay(1000);
  while (! LoRaWAN.factoryReset() ) delay(1000);
  while (!( LoRaWAN.join(JOIN_OTAA) &&
            LoRaWAN.joinResult() )) delay(1000);
  Serial.println(F("join accepted"));
  
  // TASK: Get DEVEUI
  if (LoRaWAN.getDevEUI() && LoRaWAN.isData()) {
    String deveui = LoRaWAN.getData();
    Serial.println("deveui:" + deveui);
  }
}

void loop() {
  // TODO: 任意のデータを調整
  // TODO: 拡散率調整
  // TODO: 送信データサイズを取得 (Sensewayは，GPS（緯度，高度，経度），10バイト(20桁の16進数表記)のデータを送信)
  uint32_t ms = millis();    // or user sensor data

  if ( LoRaWAN.tx(TX_UCNF, 1) &&
       LoRaWAN.txData(ms)     &&
       LoRaWAN.txRequest()    &&
       LoRaWAN.txResult()     )
  {
    Serial.println(F("tx_ok"));
  }
  delay(10000);
}
