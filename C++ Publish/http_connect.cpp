// Caique Trivelato 
// 11/5/2024

#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>


/** All of these has to be set properly for connection
const char* ssid = "wifi";
const char* password = "*******";
const char* server = "ServerIP/directory_path/publishable.php";
*/

void setup() {
  Serial.begin(9600);
  Serial.swap();

  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  if (Serial.available() > 0) {
    String data1 = Serial.readStringUntil("\n");
    
    String table = ""; // Select Table's name
    Serial.println("Table: " + table)
    Serial.println("Data 1: " + data1);

    String data1_name = ""; // Select Metric's name
    Serial.println("Data 1 Name: " + data1_name);

    String postData = "data1_name=" + data1_name + "&table=" + table + "&data1=" + data1;
    
    publish_php(postData); 


  }
}

void publish_php(String data_value) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(serverURL);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    String postData = "data_value=" + data_value;
    int httpResponseCode = http.POST(postData);

    if (httpResponseCode > 0) {
      Serial.println("Data sent to MySQL successfully");
    } else {
      Serial.print("Error sending data: ");
      Serial.println(httpResponseCode);
    }
    http.end();
  }
}