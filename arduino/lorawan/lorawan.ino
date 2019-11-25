#include <SoftwareSerial.h>

/* LoRaWAN Module
@ D11: UART_TX 送信用
@ D12: UART_RX 受信用
@ PortNum 11 GPS用途に割当
Default Connection Speed 9600kps
*/

const int DATA_SIGNALING_RATE = 9600;
void setup() {
  Serial.begin(DATA_SIGNALING_RATE);
}

void loop() {
  // put your main code here, to run repeatedly:

}
