package mqtt

import (
	pmqtt "github.com/eclipse/paho.mqtt.golang"
)

type (
	IMqttDriver interface{}
	Driver struct {
		client pmqtt.

		host string
		port int
		username string
		password string
	}
)