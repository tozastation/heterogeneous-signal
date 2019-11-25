package sensor

type Repository interface {
	Subscribe(msgTopic string) error
	SaveData(msgTopic, payload string) error
}