package mqtt

type (
	IMqttDriver interface{}
	Driver struct {
		host string
		port int
		username string
		password string
	}
)