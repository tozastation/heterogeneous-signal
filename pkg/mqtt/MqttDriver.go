package mqtt

import (
	"fmt"
	pmqtt "github.com/eclipse/paho.mqtt.golang"
	"github.com/tozastation/heterogeneous-signal/pkg/logging"
	"os"
	"time"
)

var (
	_host     = os.Getenv("MQTT_HOST")
	_port     = os.Getenv("MQTT_PORT")
	_username = os.Getenv("MQTT_USERNAME")
	_password = os.Getenv("MQTT_PASSWORD")
)

type (
	IMqttDriver interface {
		Client() pmqtt.Client
		establishConnection(opts *pmqtt.ClientOptions) error
	}
	Driver struct {
		client pmqtt.Client

		host     string
		port     string
		username string
		password string
	}
)

func NewMqttDriver() IMqttDriver {
	result := &Driver{
		host:     _host,
		port:     _port,
		username: _username,
		password: _password,
	}
	opts := result.newClientOptions()
	if err := result.establishConnection(opts); err != nil {
		logging.Logf("error: can not establish connection %v", err)
	}
	return result
}

func (d Driver) Client() pmqtt.Client {
	return d.client
}

func (d Driver) newClientOptions() *pmqtt.ClientOptions {
	opts := pmqtt.NewClientOptions()
	opts.AddBroker(fmt.Sprintf("tcp://%s", d.host))
	opts.SetUsername(d.username)
	opts.SetPassword(d.password)
	return opts
}

func (d *Driver) establishConnection(opts *pmqtt.ClientOptions) error {
	d.client = pmqtt.NewClient(opts)
	token := d.client.Connect()
	for !token.WaitTimeout(3 * time.Second) {
	}
	if err := token.Error(); err != nil {
		return err
	}
	return nil
}
