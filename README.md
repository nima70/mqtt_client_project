# MQTT Client in C
A lightweight MQTT client implemented in C using the Eclipse Paho MQTT C library. This client connects to an MQTT broker, publishes a message to a topic, and can be extended to subscribe or handle messages.

## Features
- Connects to an MQTT broker (e.g., HiveMQ, Mosquitto).
- Publishes messages to a specified topic.
- Demonstrates clean connection, publishing, and disconnection.
- Lightweight and optimized for Linux systems and embedded devices.

## Requirements
Ensure the following dependencies are installed:

- GCC Compiler (for building the C project)
- Eclipse Paho MQTT C Library (for MQTT communication)
- CMake (optional, for building Paho MQTT library)
- OpenSSL (for secure connections, optional)

## Installation
Install Paho MQTT C Library
Follow these steps to install the Paho MQTT library:

```bash
sudo apt update
sudo apt install build-essential cmake libssl-dev git
git clone https://github.com/eclipse/paho.mqtt.c.git
cd paho.mqtt.c
cmake -Bbuild -H. -DPAHO_WITH_SSL=ON -DPAHO_BUILD_STATIC=ON
sudo cmake --build build/ --target install
sudo ldconfig  # Refresh shared libraries
```
Clone the Project
Download the project repository from GitHub:

```bash
git clone https://github.com/nima70/mqtt_client_project.git
cd mqtt-client-c
```
Build the Project
Use the provided Makefile to compile the project:

```bash
make
```
This will generate the executable in the build directory.

Run the Client
Run the MQTT client to connect to a broker and publish a message:

```bash
./build/mqtt_client
```
Example output:

```mathematica
Connected to MQTT broker at tcp://broker.hivemq.com:1883
Publishing message: Hello from C MQTT Client!
Message published, waiting for confirmation...
Message delivered successfully.
Disconnected and cleaned up.
```

License
This project is licensed under the MIT License. 