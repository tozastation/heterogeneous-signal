package mqtt

import (
	mqtt "github.com/eclipse/paho.mqtt.golang"
)

type (
	IMqttDriver interface{}
	Driver struct {
		Client

		host string
		port int
		username string
		password string
	}
)