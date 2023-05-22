#include "ESP_AT_Commands.h"
#include "SendMessage.h"

bool hasMessageToSend = false;
String sensorsWithError = "1";
String str2;

// bool at_run_cmd_print(ATCommands *sender)
// {
//     if (sensorsWithError.length() > 0)
//     {
//         sender->serial->print(sensorsWithError);
//         sender->serial->print(" ");
//         return true; // tells ATCommands to print OK
//     }
//     return false;
// }
bool at_run_cmd_print(ATCommands *sender)
{
    sender->serial->println(F("Hello World!"));
    return true; // tells ATCommands to print OK
}

bool at_test_cmd_print(ATCommands *sender)
{
    sender->serial->print(sender->command);
    Serial.println(F("=<TEXT:STRING[RO]>"));
    Serial.println(F("Prints \"Hello World\" to the terminal"));
    return true; // tells ATCommands to print OK
}

bool at_write_cmd_print(ATCommands *sender)
{
    // sender->next() is NULL terminated ('\0') if there are no more parameters
    // so check for that or a length of 0.
    while(sender->next().length() > 0)
    {
        sensorsWithError = sensorsWithError + ", " + sender->next();
    }
    Serial.println(sensorsWithError);
    // hasMessageToSend = true;
    sendMessage("Sensores com falha: " + sensorsWithError);
    return true; // tells ATCommands to print OK
}

// // declare the commands in an array to be passed during initialization
// // at_command_t commands[] = {
// //     {"+SENSOR_ERROR", at_run_cmd_print, at_test_cmd_print, NULL, at_write_cmd_print},
// // };
// at_command_t commands[] = {
//     {"+PRINT", at_run_cmd_print, at_test_cmd_print, NULL, NULL},
// };