#include <ESP8266WiFi.h>
#include <Firebase.h>  
#include <FirebaseArduino.h>  
#include <FirebaseCloudMessaging.h>  
#include <FirebaseError.h>  
#include <FirebaseHttpClient.h>  
#include <FirebaseObject.h>  
#include <FirebaseArduino.h>  
#define FIREBASE_HOST "xxxxxxxx.firebaseio.com"  
#define FIREBASE_AUTH "NKHNi98DNez8svgbdNU9Bjz1Ekbxxxxxxxx"  
const char *ssid =  "xxxxxxx";     
const char *pass =  "xxxxxxxxxxxx";
WiFiClient client;
void setup() 
{
       Serial.begin(9600);
       delay(10);

      wifiConnect();
      Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);  
      delay(10);
}
void loop() 
{      
  int back = Firebase.getInt("backword");
  int forward= Firebase.getInt("forward");
  int left = Firebase.getInt("left");
  int right = Firebase.getInt("right");
  if(left == 1){
    Serial.print("Moving left \n");
  }
  else if(right == 1){
    Serial.print("Moving right \n");
  }
  else if(back == 1){
    Serial.print("Moving back \n");
  }
  else if(forward == 1){
    Serial.print("Moving forward \n");
  }




  
  else if(WiFi.status() != WL_CONNECTED){
    wifiConnect();
  }
}
void wifiConnect()
{
  WiFi.begin(ssid, pass);             
  Serial.print("Connecting to ");
  Serial.print(ssid); Serial.println(" ...");

  int teller = 0;
  while (WiFi.status() != WL_CONNECTED)
  {                                       
    delay(1000);
    Serial.print(++teller); Serial.print(' ');
  }

  Serial.println('\n');
  Serial.println("Connection established!");  
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());        
}
