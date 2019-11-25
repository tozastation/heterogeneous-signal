package gateway

import (
	"context"
	"fmt"
	pmqtt "github.com/eclipse/paho.mqtt.golang"
	"github.com/tozastation/heterogeneous-signal/internal/server/domain/sensor"
	"github.com/tozastation/heterogeneous-signal/pkg/logging"
	"github.com/tozastation/heterogeneous-signal/pkg/mongo"
	"github.com/tozastation/heterogeneous-signal/pkg/mqtt"
	"go.mongodb.org/mongo-driver/bson"
	"time"
)

type SensorGateway struct {
	MqttDriver  mqtt.IMqttDriver
	MongoDriver mongo.IMongoDriver
}

func NewSensorGateway(mqtt mqtt.IMqttDriver, mongo mongo.IMongoDriver) sensor.Repository {
	result := SensorGateway{mqtt, mongo}
	return result
}

func (s SensorGateway) Subscribe(msgTopic string) error {
	s.MqttDriver.Client().Subscribe(msgTopic, 0, func(client pmqtt.Client, msg pmqtt.Message) {
		if err := s.SaveData(msg.Topic(), string(msg.Payload())); err != nil {
			logging.Logf("error: can not insert document %v", err)
		}
		fmt.Printf("* [%s] %s\n", msg.Topic(), string(msg.Payload()))
	})
	return nil
}

func (s SensorGateway) SaveData(msgTopic, payload string) error {
	ctx, _ := context.WithTimeout(context.Background(), 30*time.Second)
	_, err := s.MongoDriver.Collection().InsertOne(ctx, bson.M{
		"topic": msgTopic,
		"payload": payload,
	})
	if err != nil {
		return err
	}
	return nil
}
