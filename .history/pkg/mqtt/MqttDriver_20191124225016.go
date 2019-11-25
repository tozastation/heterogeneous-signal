package mqtt

type (
	IMqttDriver interface{}
	Driver struct {
		host string
		username string
		password string
	}
)