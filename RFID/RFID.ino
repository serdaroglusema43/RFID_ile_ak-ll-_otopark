#include <Servo.h>
#include <SPI.h>
#include <RFID.h>

Servo servoMotor;

int trigPin = 6; 
int echoPin = 3;   

long mesafe;
long sure;

RFID rfid(10,11);
byte kart[5] = {85,30,164,133,106};
boolean deger=false;


void setup(){
  


  SPI.begin();
  rfid.init();
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin,INPUT); 
  Serial.begin(9600); 
  servoMotor.attach(5);
}
void loop()
{
  deger=false;
  //Giriş
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);   
  delayMicroseconds(10);
  sure = pulseIn(echoPin, HIGH);
  mesafe = sure/29.1/2; 
  Serial.println(mesafe);  
  delay(1000);
   if(rfid.isCard())
  {
    if(rfid.readCardSerial())
    {
      
      Serial.print("Kart bulundu ID: ");
      Serial.print(rfid.serNum[0]);
      Serial.print(",");
      Serial.print(rfid.serNum[1]);//
      Serial.print(",");
      Serial.print(rfid.serNum[2]);
      Serial.print(",");
      Serial.print(rfid.serNum[3]);
      Serial.print(",");
      Serial.println(rfid.serNum[4]);
      deger=true;
    }else{
      deger=false;
    }
   
    rfid.halt();
  }

    if(deger==true){
      servoMotor.write(90);
      delay(500); 
      
    }else{}
    if(mesafe <= 8){
           servoMotor.write(0);
           delay(2500); 
       }
 
}
