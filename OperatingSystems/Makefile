all: parent producer consumer

parent: local.h parent.cxx
	g++ parent.cxx -o parent

producer: local.h producer.cxx
	g++ producer.cxx -o producer

consumer: local.h consumer.cxx
	g++ consumer.cxx -o consumer
