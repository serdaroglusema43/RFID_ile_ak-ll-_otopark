#include <LiquidCrystal_I2C.h>
#include <Servo.h>
Servo servoMotor;
LiquidCrystal_I2C lcd(0x3F, 16, 2);  //I2C ile Lcd tanımlama
int trigPin = 6; 
int echoPin = 3;  

long mesafe;
long sure;

int sensor0;
int sensor1;
int sensor2;
int sensor3;

int sensor0Pin = A0; // kızılötes alıcı verici sensör
int sensor1Pin = A1;
int sensor2Pin = A2;
int sensor3Pin = A3;

void setup() {
 
  lcd.begin();
  lcd.setBacklight(HIGH);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin,INPUT); 
  Serial.begin(9600); 
  servoMotor.attach(9);
      

}

void loop() {
  
   sensor0 = analogRead(sensor0Pin); // Sensorlerden gelen degerler
if (sensor0 < 900 ) // AnalogRead 1024 farkli deger okur.Yarisi kadar hassasiyetle hesaba katarak 
{ // sensorden gelen bilgi alindi. 
      sensor0=1;
      
      lcd.setCursor(0, 0);
      lcd.print("1=DOLU");
      
} 
else
{ 
      sensor0=0;
      lcd.setCursor(0, 0);
      lcd.print("1=BOS"); 
}

sensor1 = analogRead(sensor1Pin); // Sensorlerden gelen degerler
if (sensor1 < 900 ) // AnalogRead 1024 farkli deger okur.Yarisi kadar hassasiyetle hesaba katarak 
{ // sensorden gelen bilgi alindi. 
      sensor1=1;
      lcd.setCursor(8, 0);
      lcd.print("2=DOLU");
      
} 
else
{ 
      sensor1=0;
      lcd.setCursor(8, 0);
      lcd.print("2=BOS"); 
}

sensor2 = analogRead(sensor2Pin); // Sensorlerden gelen degerler
if (sensor2 < 900 ) // AnalogRead 1024 farkli deger okur.Yarisi kadar hassasiyetle hesaba katarak 
{ // sensorden gelen bilgi alindi. 
      sensor2=1;
      lcd.setCursor(0, 1);
      lcd.print("3=DOLU");
    
}
else
{ 
      sensor2=0;
      lcd.setCursor(0, 1);
      lcd.print("3=BOS");    
}

sensor3 = analogRead(sensor3Pin); // Sensorlerden gelen degerler
if (sensor3 < 900 ) // AnalogRead 1024 farkli deger okur.Yarisi kadar hassasiyetle hesaba katarak 
{ // sensorden gelen bilgi alindi. 
      sensor3=1;
      lcd.setCursor(8, 1);
      lcd.print("4=DOLU");
      
} 
else
{ 
      sensor3=0;
      lcd.setCursor(8, 1);
      lcd.print("4=BOS"); 
}
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(5);  
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);   
  delayMicroseconds(10);
  sure = pulseIn(echoPin, HIGH);
  mesafe = sure/29.1/2; 
  
  if(mesafe >= 10){
    servoMotor.write(90);
    
  }
  else{
  
    servoMotor.write(0);
     
  }
delay(1000);
lcd.clear();
}
