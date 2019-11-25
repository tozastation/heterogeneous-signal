package mongo

import mongodb "go.mongodb.org/mongo-driver/mongo"

type (
	IMongoDriver interface {
		Client() *mongodb.Client
		Collection() *mongodb.Collection
	}
	Driver struct {
		client *mongodb.Client
		collection *mongodb.Collection
	}
)


