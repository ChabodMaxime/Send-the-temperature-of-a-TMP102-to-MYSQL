#include "Wire.h" 
#include <UIPEthernet.h> 
#define TMP102_ADDRESS 72

EthernetClient client;
byte foctet, soctet; 
int val; 
float temp;
float final; 
 
void setup() 
{
  byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };  
  IPAddress ip(192, 168, 0, 5);
  Wire.begin();
  Serial.begin(115200);
  while(!Serial); 
  Ethernet.begin(mac, ip);
}

void loop() 
{
    Wire.beginTransmission(TMP102_ADDRESS);
    Wire.write(0x00);
    Wire.endTransmission();
    Wire.requestFrom(TMP102_ADDRESS, 2);
    Wire.endTransmission();
    
    foctet = (Wire.read()); 
    soctet = (Wire.read()); 
    val = foctet;
    if ((foctet & 0x80) > 0) 
    {
        val |= 0x0F00;
    } 
    val <<= 4; 
    val |= (soctet >> 4);    
    temp = val * 0.0625;
    final = temp - 5;
    
    int sync = client.connect("192.168.0.1", 80);
    if(sync == 1)
    {
        client.print("GET /temp.php?v=");
        client.print(final);
        client.print(" ");
        client.print("HTTP/1.1");
        client.println();
        client.println("Host: 192.168.0.1");
        client.println("Connection: close");
        client.println();
  
     }
     else
     {
         Serial.println(F("NOK"));
     }
     delay(5000);
}
 
