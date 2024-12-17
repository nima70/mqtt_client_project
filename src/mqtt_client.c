#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MQTTClient.h"

// MQTT Configuration
#define ADDRESS     "tcp://broker.hivemq.com:1883" // Public MQTT broker
#define CLIENTID    "C_Client_Test"               // Unique client ID
#define TOPIC       "test/topic"                 // Topic to publish/subscribe
#define PAYLOAD     "Hello from C MQTT Client!"  // Message to send
#define QOS         1                            // Quality of Service
#define TIMEOUT     10000L                       // Timeout in ms

int main() {
    MQTTClient client;
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
    int rc;

    // Create MQTT Client
    if ((rc = MQTTClient_create(&client, ADDRESS, CLIENTID, MQTTCLIENT_PERSISTENCE_NONE, NULL)) != MQTTCLIENT_SUCCESS) {
        printf("Failed to create client, return code %d\n", rc);
        return EXIT_FAILURE;
    }

    // Set connection options
    conn_opts.keepAliveInterval = 20;
    conn_opts.cleansession = 1;

    // Connect to the broker
    if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS) {
        printf("Failed to connect, return code %d\n", rc);
        return EXIT_FAILURE;
    }
    printf("Connected to MQTT broker at %s\n", ADDRESS);

    // Publish a message
    MQTTClient_message pubmsg = MQTTClient_message_initializer;
    pubmsg.payload = PAYLOAD;
    pubmsg.payloadlen = (int)strlen(PAYLOAD);
    pubmsg.qos = QOS;
    pubmsg.retained = 0;
    MQTTClient_deliveryToken token;

    printf("Publishing message: %s\n", PAYLOAD);
    MQTTClient_publishMessage(client, TOPIC, &pubmsg, &token);
    printf("Message published, waiting for confirmation...\n");
    MQTTClient_waitForCompletion(client, token, TIMEOUT);
    printf("Message delivered successfully.\n");

    // Disconnect and clean up
    MQTTClient_disconnect(client, TIMEOUT);
    MQTTClient_destroy(&client);
    printf("Disconnected and cleaned up.\n");
    return EXIT_SUCCESS;
}
