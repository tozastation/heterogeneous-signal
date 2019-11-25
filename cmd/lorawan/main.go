package main

import(
	"machine"
)

// change these to test a different UART or pins if available
var (
	uart = machine.UART
	tx   = machine.UART_TX_PIN
	rx   = machine.UART_RX_PIN
)