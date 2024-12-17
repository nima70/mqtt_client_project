CC = gcc
CFLAGS = -I/usr/local/include
LDFLAGS = -L/usr/local/lib -lpaho-mqtt3c
SRC = src/mqtt_client.c
TARGET = build/mqtt_client

all: $(TARGET)

$(TARGET): $(SRC)
	@mkdir -p build
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS)

clean:
	rm -rf build/
