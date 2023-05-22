#include "ESP_AT_Commands.h"
#include "SendMessage.h"

ATCommands AT; // create an instance of the class
// extern at_command_t *commands;

const char* ssid = "virustroll";
const char* password = "malwaretrolandokaka";

// declare the commands in an array to be passed during initialization
at_command_t commands[] = {
    {"+SENSOR_ERROR", at_run_cmd_print, at_test_cmd_print, NULL, at_write_cmd_print},
    {"+PRINT", at_run_cmd_print, at_test_cmd_print, NULL, NULL},
};

void setup() {
    Serial.begin(115200);

    AT.begin(&Serial, commands, sizeof(commands), WORKING_BUFFER_SIZE);

    WiFi.begin(ssid, password);
    Serial.println("Connecting");
    while(WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.print("Connected to WiFi network with IP Address: ");
    Serial.println(WiFi.localIP());

    // Send Message to WhatsAPP
    // sendMessage("Hello from ESP8266!");
}

void loop() {
    AT.update();

    // if(hasMessageToSend)
    //     sendMessage("Sensores com falha: ");
    // hasMessageToSend = false;
}