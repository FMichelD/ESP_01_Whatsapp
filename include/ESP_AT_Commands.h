#ifndef ESP_AT_COMMANDS
#define ESP_AT_COMMANDS

#include <ATCommands.h>

#define WORKING_BUFFER_SIZE 255 // The size of the working buffer (ie: the expected length of the input string)

extern bool hasMessageToSend;
extern String sensorsWithError;
extern String str2;


/**
 * @brief at_run_cmd_print
 * This is called when AT+PRINT is sent and is intended to invoke a function that does
 * not require parameters or has already had them set via WRITE (see other examples)
 * @param sender 
 * @return true 
 * @return false 
 */
bool at_run_cmd_print(ATCommands *sender);

/**
 * @brief at_test_cmd_print
 * This is called when a test command is received (AT+TEST=?) and is usually invoked when
 * information needs to be retrieved (such as a list of SSIDs for WIFI) or other tests
 * not requiring parameters.
 * @param sender 
 * @return true 
 * @return false 
 */
bool at_test_cmd_print(ATCommands *sender);


/**
 * @brief at_write_cmd_print
 * This is called when a command is received (AT+SENSOR_ERROR=1,2) and is usually invoked when
 * information needs to be recorded (such as variables being set etc).  The sender object
 * will provide the list of parameters.
 * not requiring parameters.
 * @param sender 
 * @return true 
 * @return false 
 */
bool at_write_cmd_print(ATCommands *sender);



#endif