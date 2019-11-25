package usecase

import "github.com/tozastation/heterogeneous-signal/internal/server/domain/sensor"

type (
	SensorReadUsecase interface {
		Execute(devEUI []string) error
	}
	SensorReadInteractor struct {
		SensorRepository sensor.Repository
	}
)