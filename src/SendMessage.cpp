#include "SendMessage.h"

// +international_country_code + phone number
// Portugal +351, example: +351912345678
String phoneNumber = "+554598190552";
String apiKey = "8022224";

void sendMessage(String message){

  // Data to send with HTTP POST
    String url = "http://api.callmebot.com/whatsapp.php?phone=" + phoneNumber + "&apikey=" + apiKey + "&text=" + urlEncode(message);
    WiFiClient client;    
    HTTPClient http;
    http.begin(client, url);

    // Specify content-type header
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    // Send HTTP POST request
    int httpResponseCode = http.POST(url);
    if (httpResponseCode == 200){
        Serial.println("Message sent successfully");
    }else{
        Serial.println("Error sending the message");
        Serial.print("HTTP response code: ");
        Serial.println(httpResponseCode);
    }

    // Free resources
    http.end();
}
