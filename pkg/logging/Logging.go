package logging

import (
	"log"
	"os"
)

var (
	logger   *log.Logger
)

func Logf(format string, v ...interface{}) {
	if logger == nil {
		log.Printf(format, v...)
		return
	}
	logger.Printf(format, v...)
}

func init() {
	prefix := "LOG: "
	flags := log.Ldate | log.Lmicroseconds | log.Llongfile
	logger = log.New(os.Stdout, prefix, flags)
}